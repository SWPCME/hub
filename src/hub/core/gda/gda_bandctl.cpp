/******************************************************************************
 * $Id: gda_bandctl.cpp 2017-08 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Gda band control.
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

#include "gda_bandctl.hpp"

// base
#include "base_ctl.hpp"
// core
#include "core_ctl.hpp"
// gda
#include "gda_ctl.hpp"
#include "gda_datasetctl.hpp"
#include "gda_typectl.hpp"
#include "gda_bandcolor.hpp"

// Module.
#include "gdal.h"

/**
 * \brief Constructor.
 * Create.
 */
CGdaBandCtl::CGdaBandCtl(UDataTCodeT aDataT,
                         const UStringT *aOption,
                         CGdaDatasetCtl *aDsCtl)
{
    mDs = aDsCtl;
    InitPointer();
    CreateBand(aDataT, aOption);
}

/**
 * \brief Constructor.
 * Load.
 */
CGdaBandCtl::CGdaBandCtl(UIntT aId, CGdaDatasetCtl *aDsCtl)
{
    mDs = aDsCtl;
    InitPointer();
    LoadBand(aId);
}

/**
 * \brief Destructor.
 */
CGdaBandCtl::~CGdaBandCtl()
{
    InitPointer();
}

/**
 * \brief Initialize.
 */
UErrCodeT CGdaBandCtl::Init()
{
    if (mBandH == NULL)
    {
        return UErrTrue;
    }

    GDA_TYPE_CTL(mType);

    return UErrFalse;
}

/**
 * \brief Handle.
 *
 * @return Handle of band.
 */
GdaBandHT CGdaBandCtl::Handle()
{
    return mBandH;
}

/**
 * \brief Dataset controler.
 */
CGdaDatasetCtl *CGdaBandCtl::Up()
{
    return mDs;
}

/**
 * \brief Color table.
 */
CGdaBandColor *CGdaBandCtl::Color()
{
    BMD_CLASS_NEW_A_1(mColor, CGdaBandColor, mBandH);

    return mColor;
}

/**
 * \brief Set color table.
 */
UErrCodeT CGdaBandCtl::SetColor(CGdaBandColor *aColor)
{
    CPLErr err = GDALSetRasterColorTable(mBandH, aColor->Handle());

    if (err == CE_None)
    {
        return UErrFalse;
    }

    return UErrTrue;
}

/**
 * \brief Block size.
 */
UErrCodeT CGdaBandCtl::BlockSize(UIntT *aX, UIntT *aY)
{
    GDALGetBlockSize((GDALRasterBandH) mBandH, (int *) aX, (int *) aY);

    return UErrFalse;
}

/**
 * \brief Minimum.
 */
UErrCodeT CGdaBandCtl::Min(UFloatT *aVal)
{
    UIntT flag;
    *aVal = GDALGetRasterMinimum((GdaBandHT) mBandH, (int *) &flag);
    if (flag == FALSE)
    {
        return UErrTrue;
    }

    return UErrFalse;
}

/**
 * \brief Maximum.
 */
UErrCodeT CGdaBandCtl::Max(UFloatT *aVal)
{
    UIntT flag;
    *aVal = GDALGetRasterMaximum((GdaBandHT) mBandH, (int *)  &flag);
    if (flag == FALSE)
    {
        return UErrTrue;
    }

    return UErrFalse;
}

/**
 * \brief X size.
 */
UErrCodeT CGdaBandCtl::XSize(UIntT *aSize)
{
    *aSize = GDALGetRasterBandXSize((GDALRasterBandH) mBandH);

    return UErrFalse;
}

/**
 * \brief Y size.
 */
UErrCodeT CGdaBandCtl::YSize(UIntT *aSize)
{
    *aSize = GDALGetRasterBandYSize((GDALRasterBandH) mBandH);

    return UErrFalse;
}

/**
f * \brief Read a region of image data for this band.
 *
 * @param aXOff 
 */
UErrCodeT CGdaBandCtl::Read(UIntT aXOff, UIntT aYOff, UIntT aXSize,
                            UIntT aYSize, void *aData, UIntT aBufXSize,
                            UIntT aBufYSize, UDataTCodeT aDataT,
                            UIntT aPixelSpace, UIntT aLineSpace)
{
    GDALDataType dataType;
    mType->ToDataType(&dataType, aDataT);
    GDALRWFlag rwFlag = GF_Read;
    CPLErr err = GDALRasterIO((GDALRasterBandH) mBandH, rwFlag, aXOff, aYOff,
                              aXSize, aYSize, aData, aBufXSize, aBufYSize,
                              dataType, aPixelSpace, aLineSpace);
    if (err == CE_None)
    {
        return UErrFalse;
    }

    return UErrTrue;
}

/**
 * \brief Read a block.
 */
UErrCodeT CGdaBandCtl::ReadBlock(UDataT aData, UIntT aXOff, UIntT aYOff)
{
    CPLErr err = GDALReadBlock((GDALRasterBandH) mBandH, aXOff, aYOff, aData);
    if (err == CE_None)
    {
        return UErrFalse;
    }

    return UErrTrue;
}

/**
 * \brief Write a region of image data for this band.
 */
UErrCodeT CGdaBandCtl::Write(UIntT aXOff, UIntT aYOff, UIntT aXSize,
                             UIntT aYSize, void *aData, UIntT aBufXSize,
                             UIntT aBufYSize, UDataTCodeT aDataT,
                             UIntT aPixelSpace, UIntT aLineSpace)
{
    GDALDataType dataType;
    mType->ToDataType(&dataType, aDataT);
    GDALRWFlag rwFlag = GF_Write;
    CPLErr err = GDALRasterIO((GDALRasterBandH) mBandH, rwFlag, aXOff, aYOff,
                              aXSize, aYSize, aData, aBufXSize, aBufYSize,
                              dataType, aPixelSpace, aLineSpace);

    if (err == CE_None)
    {
        return UErrFalse;
    }

    return UErrTrue;
}

/***** Private A *****/

/**
 * \brief Init pointer.
 */
UErrCodeT CGdaBandCtl::InitPointer()
{
    BMD_POINTER_INIT(mBandH);
    BMD_POINTER_INIT(mType);
    BMD_POINTER_INIT(mColor);

    return UErrFalse;
}

/**
 * \brief Create raster band.
 */
UErrCodeT CGdaBandCtl::CreateBand(UDataTCodeT aDataT,
                                  const UStringT *aOption)
{
    GDALDatasetH datasetH = mDs->Handle();
    GDALDataType dataType;
    mType->ToDataType(&dataType, aDataT);
    char** option = NULL;
    GDALAddBand(datasetH, dataType, option);
    // *aOption = *option;

    return UErrFalse;
}

/**
 * \brief Load raster band.
 */
UErrCodeT CGdaBandCtl::LoadBand(UIntT aId)
{
    GDALDatasetH datasetH = mDs->Handle();
    mBandH = (GdaBandHT) GDALGetRasterBand(datasetH, aId);

    return UErrFalse;
}

/***** Private B *****/
