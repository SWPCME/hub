/******************************************************************************
 * $Id: ogr_ctl.cpp 2016-08 $
 *
 * Project:  Ogr (OpenGIS Simple Features Reference Implementation) library.
 * Purpose:  Ogr Control.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016, Weiwei Huang
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ****************************************************************************/

#include "ogr_ctl.hpp"

// Ogr library.
#include "ogr_api.h"

// Module
#include "ogr_datasrcctl.hpp"

/**
 * \brief Constructor.
 */
COgrCtl::COgrCtl()
{
    m_dataSrc = new COgrDataSrcCtl;
    m_mDHName.Init(UContainerMap);
    m_mDHSuffix.Init(UContainerMap);
}

/**
 * \brief Destructor.
 */
COgrCtl::~COgrCtl()
{
    CleanupAll();
    delete m_dataSrc;
}

/**
 * \brief Initialize.
 *
 * Register the drivers of ogr, and initialize the handle of driver.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT COgrCtl::Init()
{
    OGRRegisterAll();
    InitDriver();

    return UErrFalse;
}

/**
 * \brief Cleanup All.
 *
 * Cleanup all the driver of ogr.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT COgrCtl::CleanupAll()
{
    OGRCleanupAll();

    return UErrFalse;
}

/**
 * \brief Attach driver
 *
 * @param aDriverName Name of driver that you need to attach.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT COgrCtl::Attach(const UStringT* aDriverName)
{
    m_driver = (OgrDriverHT) m_mDHName.Content(*aDriverName);

    return UErrFalse;
}

/**
 * \brief Create Datasource.
 *
 * Get a handle of datasource that point to this file.
 *
 * @param aFile The file that you want to create.
 * @param aDName The name of the driver, the default value is NULL.
 *
 * @return Handle of ogr data source, if successful; NULL, if failed.
 */
COgrDataSrcCtl* COgrCtl::Create(UStringT* aFile, const UStringT* aDriverName)
{
    char** options = NULL;
    const char* file = aFile->ToA();
    OgrDataSrcHT dataSrcH = (OgrDataSrcHT) OGR_Dr_CreateDataSource
        ((OGRSFDriverH) m_driver, file, options);
    m_dataSrc->Attach(dataSrcH);

    return m_dataSrc;
}

/**
 * \brief Load file and get the handle of data source.
 *
 * @return Hanle of data source, if successful; NULL, if failed.
 */
COgrDataSrcCtl* COgrCtl::Load(UStringT* aFile, const UStringT* aDriverName)
{
    UIntT update = 1;
    const char* file = aFile->ToA();
    OgrDataSrcHT dataSrcH = (OgrDataSrcHT) OGR_Dr_Open
        ((OGRSFDriverH) m_driver, file, update);
    m_dataSrc->Attach(dataSrcH);

    return m_dataSrc;
}

/**
 * \brief Close file.
 */
UErrCodeT COgrCtl::Close(OgrDataSrcHT aHandle)
{
    OGR_DS_Destroy((OGRDataSourceH) aHandle);

    return UErrFalse;
}

/***** Private A *****/

/**
 * \brief Initialize Driver.
 *
 * Initialize driver of the handle.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT COgrCtl::InitDriver()
{
    UStringT defnName[OGR_VECTOR_FORMATS_COUNT] =
        {
            OGR_VECTOR_TAB_NAME, OGR_VECTOR_SHP_NAME, OGR_VECTOR_CSV_NAME,
            OGR_VECTOR_XLS_NAME, OGR_VECTOR_XLSX_NAME, OGR_VECTOR_SQLITE_NAME
        };
    UStringT defnSuffix[OGR_VECTOR_FORMATS_COUNT] =
        {
            OGR_VECTOR_TAB_SUFFIX, OGR_VECTOR_SHP_SUFFIX, OGR_VECTOR_CSV_SUFFIX,
            OGR_VECTOR_XLS_SUFFIX, OGR_VECTOR_XLSX_SUFFIX,
            OGR_VECTOR_SQLITE_SUFFIX
        };
    for (UIntT i= 0; i < OGR_VECTOR_FORMATS_COUNT; ++i)
    {
        UHandleT handle = NULL;
        GetDriver((OgrDriverHT) handle, &defnName[i]);
        m_mDHName.Add(&handle, &defnName[i]);
        m_mDHSuffix.Add(&handle, &defnSuffix[i]);
    }

    return UErrFalse;
}

/**
 * \brief Get Driver.
 *
 * Get driver by name of the format.
 *
 * @param aHandle The handle of driver.
 * @param aName The name of driver.
 *
 * @return UErrFalse, if successful; Others, if failed.
 */
UErrCodeT COgrCtl::GetDriver(OgrDriverHT aHandle, UStringT* aName)
{
    aHandle = (OgrDriverHT) OGRGetDriverByName(aName->ToA());

    return UErrFalse;
}

/***** Private B *****/
