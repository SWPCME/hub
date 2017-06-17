/******************************************************************************
 * $Id: gda_rasterbandctl.cpp 2017-05 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Gda raster band control.
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

#include "gda_rasterbandctl.hpp"

// Module.
#include "gda_typectl.hpp"
#include "gdal.h"

/**
 * \brief Constructor.
 */
CGdaRasterbandCtl::CGdaRasterbandCtl(GdaRasterBandHT aHandle)
{
    mHandle = aHandle;
}

/**
 * \brief Destructor.
 */
CGdaRasterbandCtl::~CGdaRasterbandCtl()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CGdaRasterbandCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Block size.
 */
UErrCodeT CGdaRasterbandCtl::BlockSize(UIntT *aX, UIntT *aY)
{
    GDALGetBlockSize((GDALRasterBandH) mHandle, (int *) aX, (int *) aY);

    return UErrFalse;
}

/**
 * \brief Minimum.
 */
UErrCodeT CGdaRasterbandCtl::Min(UFloatT *aVal)
{
    UIntT flag;
    *aVal = GDALGetRasterMinimum((GdaRasterBandHT) mHandle, (int *) &flag);
    if (flag == FALSE)
    {
        return UErrTrue;
    }

    return UErrFalse;
}

/**
 * \brief Maximum.
 */
UErrCodeT CGdaRasterbandCtl::Max(UFloatT *aVal)
{
    UIntT flag;
    *aVal = GDALGetRasterMaximum((GdaRasterBandHT) mHandle, (int *)  &flag);
    if (flag == FALSE)
    {
        return UErrTrue;
    }

    return UErrFalse;
}

/**
 * \brief X size.
 */
UErrCodeT CGdaRasterbandCtl::XSize(UIntT *aSize)
{
    *aSize = GDALGetRasterBandXSize((GDALRasterBandH) mHandle);

    return UErrFalse;
}

/**
 * \brief Y size.
 */
UErrCodeT CGdaRasterbandCtl::YSize(UIntT *aSize)
{
    *aSize = GDALGetRasterBandYSize((GDALRasterBandH) mHandle);

    return UErrFalse;
}

/**
 * \brief Read a region of image data for this band.
 *
 * @param aXOff 
 */
UErrCodeT CGdaRasterbandCtl::Read(UIntT aXOff, UIntT aYOff, UIntT aXSize,
                                  UIntT aYSize, void *aData, UIntT aBufXSize,
                                  UIntT aBufYSize, UDataTCodeT aDataT,
                                  UIntT aPixelSpace, UIntT aLineSpace)
{
    GDALDataType dataType;
    mType->ToDataType(&dataType, aDataT);
    GDALRWFlag rwFlag = GF_Read;
    GDALRasterIO((GDALRasterBandH) mHandle, rwFlag, aXOff, aYOff, aXSize,
                 aYSize, aData, aBufXSize, aBufYSize, dataType, aPixelSpace,
                 aLineSpace);

    return UErrFalse;
}

/**
 * \brief Read a block.
 */
UErrCodeT CGdaRasterbandCtl::ReadBlock(UDataT aData, UIntT aXOff, UIntT aYOff)
{
    GDALReadBlock((GDALRasterBandH) mHandle, aXOff, aYOff, aData);

    return UErrFalse;
}

/**
 * \brief Write a region of image data for this band.
 */
UErrCodeT CGdaRasterbandCtl::Write(UIntT aXOff, UIntT aYOff, UIntT aXSize,
                                   UIntT aYSize, void *aData, UIntT aBufXSize,
                                   UIntT aBufYSize, UDataTCodeT aDataT,
                                   UIntT aPixelSpace, UIntT aLineSpace)
{
    GDALDataType dataType;
    mType->ToDataType(&dataType, aDataT);
    GDALRWFlag rwFlag = GF_Write;
    GDALRasterIO((GDALRasterBandH) mHandle, rwFlag, aXOff, aYOff, aXSize,
                 aYSize, aData, aBufXSize, aBufYSize, dataType, aPixelSpace,
                 aLineSpace);

    return UErrFalse;
}
