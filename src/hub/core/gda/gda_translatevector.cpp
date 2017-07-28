/******************************************************************************
 * $Id: gda_translatevector.cpp 2017-07 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Translate vector implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-07 ~ 2017, Weiwei Huang
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
 *****************************************************************************/

#include "gda_translatevector.hpp"

// GDAL
#include "gdal_utils.h"

// gda
#include "gda_datasetctl.hpp"
#include "gda_bandctl.hpp"
// ogr
#include "ogr_datasrcctl.hpp"
#include "ogr_layerctl.hpp"

/**
 * \brief Constructor.
 */
CGdaTranslateVector::CGdaTranslateVector()
{
}

/**
 * \brief Destructor.
 */
CGdaTranslateVector::~CGdaTranslateVector()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CGdaTranslateVector::Init()
{
    return UErrFalse;
}

/**
 * \brief To vector.
 */
UErrCodeT CGdaTranslateVector::ToVtr()
{
    return UErrFalse;
}

/**
 * \brief To raster.
 */
UErrCodeT CGdaTranslateVector::ToRst(CGdaBandCtl *aBand,
                                     COgrLayerCtl *aLayer,
                                     const UStringT *aFieldName)
{
    UStringT dstDir;
    CGdaDatasetCtl *dstDsCtl = aBand->Up();
    GdaDatasetHT dstDsH = dstDsCtl->Handle();
    COgrDatasrcCtl *srcDsCtl = aLayer->Up();
    GdaDatasetHT srcDsH = srcDsCtl->Handle();
    GdaRasterizeOptHT opt = NULL;
    Rasterize(&dstDir, dstDsH, srcDsH, opt);

    return UErrFalse;
}

/***** Private A *****/

/**
 * \brief Rasterize.
 */
UErrCodeT CGdaTranslateVector::Rasterize(const UStringT *aDstDir,
                                         GdaDatasetHT aDstDsH,
                                         GdaDatasetHT aSrcDsH,
                                         const GdaRasterizeOptHT aOpt)
{
    char *dstDir = NULL;
    if (aDstDir->IsNull() == UErrTrue)
    {
        dstDir = (char *) aDstDir->ToA();
    }
    GDALDatasetH dstDsH = (GDALDatasetH) aDstDsH;
    GDALDatasetH srcDsH = (GDALDatasetH) aSrcDsH;
    GDALRasterizeOptions *opt = (GDALRasterizeOptions *) aOpt;
    int err = FALSE;
    GDALRasterize(dstDir, dstDsH, srcDsH, opt, &err);
    if (err == TRUE)
    {
        return UErrFalse;
    }

    return UErrTrue;
}

/***** Private B *****/
