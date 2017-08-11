/******************************************************************************
 * $Id: gda_driverctl.cpp 2017-08 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Gda driver control.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-05 ~ 2017, Weiwei Huang
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

/**
 * \brief Constructor.
 */
CGdaDriverCtl::CGdaDriverCtl(const UStringT *aName) : mMDataset(UContainerMap)
{
    BMD_POINTER_INIT(mDriverH);
    SetHandle(aName);
}

/**
 * \brief Destructor.
 */
CGdaDriverCtl::~CGdaDriverCtl()
{
    CloseAll();
    BMD_POINTER_INIT(mDriverH);
}

/**
 * \brief Initialize.
 */
UErrCodeT CGdaDriverCtl::Init()
{
    if (mDriverH == NULL)
    {
        return UErrTrue;
    }

    CloseAll();

    return UErrFalse;
}

/**
 * \brief Create file.
 *
 * @param aFile   File name that create.
 * @param aXSize  Width of raster in pixels.
 * @param aYSize  Height of raster in pixels.
 * @param aNBands Number of bands.
 * @param aDataT  Type of raster.
 * @param aOption List of driver specific control parameters.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
CGdaDatasetCtl *CGdaDriverCtl::Create(const UStringT *aFile, UIntT aXSize,
                                      UIntT aYSize, UIntT aNBands,
                                      UDataTCodeT aDataT, char **aOption)
{
    GdaDatasetAttrT attr;
    attr.xSize = aXSize;
    attr.ySize = aYSize;
    attr.nBands = aNBands;
    attr.dataT = aDataT;
    attr.option = aOption;

    return DatasetCtl(aFile, UFileOperCreate, &attr, NULL);
}

/**
 * \brief Load file.
 */
CGdaDatasetCtl *CGdaDriverCtl::Load(const UStringT *aFile,
                                    const UAccessCodeT aAccess)
{
    return DatasetCtl(aFile, UFileOperLoad, NULL, &aAccess);
}

/**
 * \brief Close file.
 */
UErrCodeT CGdaDriverCtl::Close(const UStringT *aFile)
{
    MDatasetItT *it = mMDataset.Iterator();
    if (it->Goto(aFile) == UErrTrue)
    {
        return UErrTrue;
    }
    CGdaDatasetCtl *datasetCtl = it->Content();
    delete datasetCtl;
    mMDataset.DelByKey(aFile);

    return UErrFalse;
}

/**
 * \brief Delete file.
 */
UErrCodeT CGdaDriverCtl::Delete(const UStringT *aFile)
{
    Close(aFile);
    GDALDeleteDataset(mDriverH, aFile->ToA());

    return UErrFalse;
}

/***** Private A *****/

/**
 * \brief Set handle.
 */
UErrCodeT CGdaDriverCtl::SetHandle(const UStringT *aName)
{
    mDriverH = GDALGetDriverByName(aName->ToA());
    if (mDriverH == NULL)
    {
        return UErrTrue;
    }

    return UErrFalse;
}

/**
 * \brief Dataset controler.
 */
CGdaDatasetCtl *CGdaDriverCtl::DatasetCtl(const UStringT *aFile,
                                          UFileOperCodeT aFileOper,
                                          const GdaDatasetAttrT *aAttr,
                                          const UAccessCodeT *aAccess)
{
    MDatasetItT *it = mMDataset.Iterator();
    if (it->Goto(aFile) == UErrFalse)
    {
        return it->Content();
    }
    CGdaDatasetCtl *datasetCtl = NULL;
    switch (aFileOper)
    {
    case UFileOperCreate:
    {
        BMD_CLASS_NEW_A_3(datasetCtl, CGdaDatasetCtl, aFile, aAttr, mDriverH);
        break;
    }
    case UFileOperLoad:
    {
        BMD_CLASS_NEW_A_2(datasetCtl, CGdaDatasetCtl, aFile, *aAccess);
        break;
    }
    default:
        break;
    }
    if (datasetCtl != NULL)
    {
        mMDataset.Add(&datasetCtl, aFile);
    }

    return datasetCtl;
}

/**
 * \brief Close all.
 */
UErrCodeT CGdaDriverCtl::CloseAll()
{
    MDatasetItT *it = mMDataset.Iterator();

    for (it->Head(); it->State() == UErrFalse; it->Next())
    {
        const UStringT file = it->Key();
        Close(&file);
    }

    return UErrFalse;
}

/***** Private B *****/
