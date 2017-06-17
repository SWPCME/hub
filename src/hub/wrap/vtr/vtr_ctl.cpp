/******************************************************************************
 * $Id: vtr_ctl.cpp 2016-08 $
 *
 * Project:  Vector Info Process.
 * Purpose:  Vector control.
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

#include "vtr_ctl.hpp"

// Module
#include "base_ctl.hpp"
#include "core_ctl.hpp"
#include "ogr_ctl.hpp"
#include "vtr_datasrcctl.hpp"

/**
 * \brief Constructor
 */
CVtrCtl::CVtrCtl()
{
    m_mDataSrc = new MVtrDataSrcT;
}

/**
 * \brief Destructor
 */
CVtrCtl::~CVtrCtl()
{
    delete m_mDataSrc;
}

/**
 * \brief Initialization
 *
 * \return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CVtrCtl::Init()
{
    CBaseCtl *baseCtl = CBaseCtl::Base();
    CCoreCtl* coreCtl = baseCtl->Core();
    m_ogr = coreCtl->Ogr();
    m_mDataSrc->Init(UContainerMap);

    return UErrFalse;
}

/**
 * \brief Cleanup All.
 *
 * Cleanup all driver of ogr.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CVtrCtl::CleanupAll()
{
    m_ogr->CleanupAll();

    return UErrFalse;
}

/**
 * \brief Create a file.
 *
 * Create a file for the format of vector, or any other relation table.
 *
 * @param aFile The file that contain complete path.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
CVtrDataSrcCtl* CVtrCtl::Create(UStringT* aFile)
{
    UStringT driverName = OGR_VECTOR_TAB_NAME;
    m_ogr->Attach(&driverName);
    COgrDataSrcCtl* ogrDataSrc = m_ogr->Create(aFile);
    CVtrDataSrcCtl* dataSrc = new CVtrDataSrcCtl(ogrDataSrc);
    m_mDataSrc->Add(dataSrc, *aFile);

    return dataSrc;
}

/**
 * \brief Load a file.
 *
 * Load a file for the format of vector, or any other relation table.
 *
 * @param aFile The file that contain complete path.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
CVtrDataSrcCtl* CVtrCtl::Load(UStringT* aFile)
{
    UStringT driverName = OGR_VECTOR_TAB_NAME;
    m_ogr->Attach(&driverName);
    COgrDataSrcCtl* ogrDataSrc = m_ogr->Load(aFile);
    CVtrDataSrcCtl* dataSrc = new CVtrDataSrcCtl(ogrDataSrc);
    m_mDataSrc->Add(dataSrc, *aFile);

    return dataSrc;
}

/**
 * \brief Close a file.
 *
 * Close a file that you load before.
 *
 * @param aFile The file that contain complete path.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CVtrCtl::Close(UStringT* aFile)
{
    // const CVtrDataSrcCtl* dataSrc = (*m_mDataSrc)[*aFile];
    // m_ogr->Close(dataSrc->Handle());

    return UErrFalse;
}

/**
 * \brief Close all file.
 *
 * Close file that all you load before.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CVtrCtl::CloseAll()
{
    return UErrFalse;
}
