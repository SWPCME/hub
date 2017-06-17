/******************************************************************************
 * $Id: gda_driverctl.cpp 2017-05 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Gda driver control.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016 ~ 2017, Weiwei Huang
 *
 * This program is free software; you can redistribute it and/or modify it 
 * under the terms of the GNU General Public License as published by the Free 
 * Software Foundation, either version 3 of the License, or (at your option) 
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT 
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for 
 * more details.
 *
 * You should have received a copy of the GNU General Public License along 
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 ****************************************************************************/

#include "gda_driverctl.hpp"

// Hub
#include "gda_typectl.hpp"
#include "gda_datasetctl.hpp"
// Module
#include "gdal.h"

CGdaDriverCtl::CGdaDriverCtl(GdaDriverHT aHandle)
{
    mHandle = aHandle;
    mMDataset.Init(UContainerMap);
}

CGdaDriverCtl::~CGdaDriverCtl()
{
    CloseAll();
}

UErrCodeT CGdaDriverCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Create file.
 *
 * @param aFile File name that create.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
CGdaDatasetCtl *CGdaDriverCtl::Create(const UStringT *aFile, UIntT aXSize,
                                      UIntT aYSize, UIntT aNBands,
                                      UDataTCodeT aDataT, char **aOption)
{
    GDALDataType dataType;
    mType->ToDataType(&dataType, aDataT);
    GDALDatasetH dataset;
    dataset = GDALCreate((GDALDriverH) mHandle, aFile->ToA(), aXSize, aYSize,
                         aNBands, dataType, aOption);
    CGdaDatasetCtl *datasetCtl = new CGdaDatasetCtl((GdaDatasetHT) dataset);

    return datasetCtl;
}

/**
 * \brief Open file.
 */
CGdaDatasetCtl *CGdaDriverCtl::Open(const UStringT *aFile,
                                    const UAccessCodeT aAccess)
{
    GDALAccess access;
    mType->ToAccess(&access, aAccess);
    UHandleT handle = (UHandleT) GDALOpen(aFile->ToA(), access);
    CGdaDatasetCtl *datasetCtl = new CGdaDatasetCtl(handle);
    mMDataset.Add(&datasetCtl, aFile);

    return datasetCtl;
}

/**
 * \brief Close file.
 */
UErrCodeT CGdaDriverCtl::Close(const UStringT *aFile)
{
    // GDAL_DS_Destroy((GDAL) aHandle);
    const CGdaDatasetCtl *datasetCtl = mMDataset.Content(aFile);
    if (datasetCtl != NULL)
    {
        delete datasetCtl;
        return UErrFalse;
    }

    return UErrTrue;
}

/**
 * \brief Delete file.
 */
UErrCodeT CGdaDriverCtl::Delete(const UStringT *aFile)
{
    GDALDeleteDataset(mHandle, aFile->ToA());

    return UErrFalse;
}

/***** Private A *****/

/**
 * \brief CloseAll().
 */
UErrCodeT CGdaDriverCtl::CloseAll()
{
    MDatasetCtlItT *it = mMDataset.Iterator();

    for (it->Head(); it->State() == UErrFalse; it->Next())
    {
        const UStringT file = it->Key();
        Close(&file);
    }

    return UErrFalse;
}

/***** Private B *****/
