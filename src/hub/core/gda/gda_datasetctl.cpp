/******************************************************************************
 * $Id: gda_datasetctl.cpp 2017-05 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Gda dataset control.
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

#include "gda_datasetctl.hpp"

// Hub
#include "gda_typectl.hpp"
#include "gda_rasterbandctl.hpp"

// Module
#include "gdal.h"

/**
 * \brief Constructor.
 */
CGdaDatasetCtl::CGdaDatasetCtl(GdaDatasetHT aHandle)
{
    mHandle = aHandle;
}

/**
 * \brief Destructor.
 */
CGdaDatasetCtl::~CGdaDatasetCtl()
{
    Close();
}

/**
 * \brief Initialize.
 */
UErrCodeT CGdaDatasetCtl::Init(UStringT *aFile, UAccessCodeT aCode)
{
    return UErrFalse;
}

/**
 * \brief Flush all write cached to disk.
 */
UErrCodeT CGdaDatasetCtl::Save()
{
    GDALFlushCache((GDALDatasetH) mHandle);

    return UErrFalse;
}

/**
 * \brief Add Band.
 */
UErrCodeT CGdaDatasetCtl::AddBand(UDataTCodeT aDataT, UStringT *aOption)
{
    GDALDataType dataType;
    mType->ToDataType(&dataType, aDataT);
    char** option;
    GDALAddBand((GDALDatasetH) mHandle, dataType, option);
    *aOption = *option;

    return UErrFalse;
}

/**
 * \brief Raster count.
 */
UErrCodeT CGdaDatasetCtl::Count(UIntT *aNum)
{
    *aNum = GDALGetRasterCount((GDALDatasetH) mHandle);

    return UErrFalse;
}

/**
 * \brief Raster band.
 */
CGdaRasterbandCtl* CGdaDatasetCtl::Band(UIntT aId)
{
    GdaRasterBandHT rasterBandH = (GdaRasterBandHT) GDALGetRasterBand((GDALDatasetH) mHandle, aId);
    CGdaRasterbandCtl *rasterBandCtl = new CGdaRasterbandCtl(rasterBandH);
    mBandCtn.Add(rasterBandCtl, aId);

    return rasterBandCtl;
}

/**
 * \brief Raster x size.
 */
UErrCodeT CGdaDatasetCtl::XSize(UIntT *aNum)
{
    *aNum = GDALGetRasterXSize((GDALDatasetH) mHandle);

    return UErrFalse;
}

/**
 * \brief Projection reference.
 */
// UErrCodeT CGdaDatasetCtl::PrjRef()
// {
//     return UErrFalse;
// }

/***** Private A *****/

/**
 * \brief Close.
 */
UErrCodeT CGdaDatasetCtl::Close()
{
    GDALClose((GDALDatasetH) mHandle);

    return UErrFalse;
}

/***** Private B *****/
