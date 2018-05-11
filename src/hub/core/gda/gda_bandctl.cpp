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
 * \brief Get data type.
 */
UDataTCodeT CGdaBandCtl::DataT()
{
    UDataTCodeT dst;
    GDALDataType src = GDALGetRasterDataType((GDALRasterBandH) mBandH);
    mType->ToDataType(&dst, src);

    return dst;
}

/**
 * \brief Unit type.
 */
UDataTCodeT CGdaBandCtl::UnitT()
{
    UStringT strUnitT = GDALGetRasterUnitType((GDALRasterBandH) mBandH);
    strUnitT.ToConsole();
    UDataTCodeT unitT;
    mType->ToDataType(&unitT, &strUnitT);

    return unitT;
}

/**
 * \brief Set unit type.
 */
UErrCodeT CGdaBandCtl::SetUnitT(UDataTCodeT aUnitT)
{
    UStringT unitT;
    mType->ToDataType(&unitT, aUnitT);
    CPLErr err = GDALSetRasterUnitType((GDALRasterBandH) mBandH, unitT.ToA());

    if (err == CE_None)
    {
        return UErrFalse;
    }

    return UErrTrue;
}

/**
 * \brief Get no data value.
 */
UFloatT CGdaBandCtl::NoDataVal(UErrCodeT *aErr)
{
    UErrCodeT err = UErrTrue;
    int gdalErr;
    UFloatT val = GDALGetRasterNoDataValue((GDALRasterBandH) mBandH, &gdalErr);
    if (gdalErr == CE_None)
    {
        err = UErrFalse;
    }

    if (aErr != NULL)
    {
        *aErr = err;
    }

    return val;
}

/**
 * \brief Set no data value.
 */
UErrCodeT CGdaBandCtl::SetNoDataVal(const UFloatT aVal)
{
    UIntT err = GDALSetRasterNoDataValue((GDALRasterBandH) mBandH, aVal);

    if (err == CE_None)
    {
        return UErrFalse;
    }

    return UErrTrue;
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
    CPLErr err = GDALSetRasterColorTable((GDALRasterBandH) mBandH,
                                         aColor->Handle());

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
 * \brief Read a region of image data for this band.
 */
UErrCodeT CGdaBandCtl::Read(GdaBandDataT *aData)
{
    UAccessCodeT access = UAccessRead;

    return Io(aData, access);
}

/**
 * \brief Read a block.
 */
UErrCodeT CGdaBandCtl::ReadBlock(UDataHT aDataH, UIntT aXOff, UIntT aYOff)
{
    CPLErr err = GDALReadBlock((GDALRasterBandH) mBandH, aXOff, aYOff, aDataH);
    if (err == CE_None)
    {
        return UErrFalse;
    }

    return UErrTrue;
}

/**
 * \brief Write a region of image data for this band.
 */
UErrCodeT CGdaBandCtl::Write(GdaBandDataT *aData)
{
    UAccessCodeT access = UAccessWrite;

    return Io(aData, access);
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
    // if (aOption != NULL)
    // {
    //     *option = (char *) aOption->ToA();
    // }
    GDALAddBand(datasetH, dataType, option);

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

/**
 * \brief Input and output.
 */
UErrCodeT CGdaBandCtl::Io(GdaBandDataT *aData, const UAccessCodeT aAccess)
{
    UDataTCodeT type = aData->Type();
    BMathCsC2dT *begin = aData->Begin();
    BMathCsC2dT *end = aData->End();
    UIntT xOff = begin->X();
    UIntT yOff = begin->Y();
    UIntT xSize = end->X() - begin->X() + 1;
    UIntT ySize = end->Y() - begin->Y() + 1;
    UDataHT dataH = aData->Handle();
    UIntT bufXSize = xSize;
    UIntT bufYSize = ySize;
    UIntT pixelSpace = 0;
    UIntT lineSpace = 0;
    GDALDataType dataType;
    mType->ToDataType(&dataType, type);
    GDALRWFlag rwFlag = GF_Read;
    if (aAccess == UAccessWrite)
    {
        rwFlag = GF_Write;
    }
    CPLErr err = GDALRasterIO((GDALRasterBandH) mBandH, rwFlag, xOff, yOff,
                              xSize, ySize, dataH, bufXSize, bufYSize,
                              dataType, pixelSpace, lineSpace);
    if (err == CE_None)
    {
        return UErrFalse;
    }

    return UErrTrue;
}

/***** Private B *****/
