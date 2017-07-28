/******************************************************************************
 * $Id: gda_algrasterizer.cpp 2017-07 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Alg rasterizer implementation.
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

#include "gda_algrasterizer.hpp"

// GDAL
#include "gdal_alg.h"

// gda
#include "gda_datasetctl.hpp"
#include "gda_bandctl.hpp"
// ogr
#include "ogr_layerctl.hpp"

/**
 * \brief Constructor.
 */
CGdaAlgRasterizer::CGdaAlgRasterizer()
{
}

/**
 * \brief Destructor.
 */
CGdaAlgRasterizer::~CGdaAlgRasterizer()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CGdaAlgRasterizer::Init()
{
    return UErrFalse;
}

/**
 * \brief To band.
 *
 * @param aRstDs
 */
UErrCodeT CGdaAlgRasterizer::ToBand(CGdaBandCtl *aBand, COgrLayerCtl *aLayer)
{
    CGdaDatasetCtl *dsCtl = aBand->Up();
    GDALDatasetH hDs = (GDALDatasetH) dsCtl->Handle();

    const int nBandCount = 1;
    int bandList[nBandCount] = {1};
    int *panBandList = bandList;

    const int nLayerCount = 1;
    OGRLayerH layerHList[nBandCount] = {aLayer->Handle()};
    OGRLayerH *pahLayers = layerHList;

    GDALTransformerFunc pfnTransformer = NULL;
    void *pTransformArg = NULL;

    double *padfLayerBurnValues = NULL;
    char **papszOptions = NULL;

    GDALProgressFunc pfnProgress = NULL;
    void *pProgressArg = NULL;

    if (GDALRasterizeLayers(hDs, nBandCount, panBandList, nLayerCount,
                            pahLayers, pfnTransformer, pTransformArg,
                            padfLayerBurnValues, papszOptions,
                            pfnProgress, pProgressArg) == CE_None)
    {
        return UErrFalse;
    }

    return UErrTrue;
}
