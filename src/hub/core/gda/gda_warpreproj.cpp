/******************************************************************************
 * $Id: gda_warpreprj.cpp 2017-12 $
 *
 * Project:  Gda (GDAL: Geospatial Data Abstraction Library) library.
 * Purpose:  Gda warp control implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-12 ~ 2017, Weiwei Huang
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

#include "gda_warpreproj.hpp"

// base
#include "base_ctl.hpp"
// core
#include "core_ctl.hpp"
// gda
#include "gda_ctl.hpp"
#include "gda_typectl.hpp"
#include "gda_driverctl.hpp"
#include "gda_datasetctl.hpp"

// GDAL
#include "gdalwarper.h"

/**
 * \brief Constructor.
 */
CGdaWarpReproj::CGdaWarpReproj()
{
    BMD_POINTER_INIT(mType);
}

/**
 * \brief Destructor.
 */
CGdaWarpReproj::~CGdaWarpReproj()
{
    BMD_POINTER_INIT(mType);
}

/**
 * \brief Initialize.
 */
UErrCodeT CGdaWarpReproj::Init()
{
    GDA_TYPE_CTL(mType);

    return UErrFalse;
}

/**
 * \brief Create image.
 */
UErrCodeT CGdaWarpReproj::ToImage(CGdaDatasetCtl *aDst, CGdaDatasetCtl *aSrc,
                                  const GdaWarpReprojImageT *aReproj)
{
    GDALDatasetH src = (GDALDatasetH) aSrc->Handle();
    GDALDatasetH dst = (GDALDatasetH) aDst->Handle();    

    UStringT srcProj;
    GdaOgrSrsT *srcSrs = aReproj->SrcSrs();
    srcSrs->ExportToWkt(&srcProj);
    UStringT dstProj;
    GdaOgrSrsT *dstSrs = aReproj->DstSrs();
    dstSrs->ExportToWkt(&dstProj);

    GDALResampleAlg resampleAlg = GRA_NearestNeighbour;
    double warpMemLimit = 0;
    double maxErr = 0.0;
    GDALProgressFunc progFunc = NULL;
    void *progArg = NULL;
    GDALWarpOptions *opts = NULL;
    CPLErr err = GDALReprojectImage(src, srcProj.ToA(), dst, dstProj.ToA(),
                                    resampleAlg, warpMemLimit, maxErr,
                                    progFunc, progArg, opts);

    if (err == CE_None)
    {
        return UErrFalse;
    }

    return UErrTrue;
}

/**
 * \brief Create image with create file.
 */
UErrCodeT CGdaWarpReproj::ToImage(const UStringT *aDst, CGdaDatasetCtl *aSrc,
                                  const GdaWarpReprojImageT *aReproj)
{
    GDALDatasetH src = (GDALDatasetH) aSrc->Handle();
    const char *dst = aDst->ToA();

    UStringT srcProj;
    GdaOgrSrsT *srcSrs = aReproj->SrcSrs();
    srcSrs->ExportToWkt(&srcProj);
    UStringT dstProj;
    GdaOgrSrsT *dstSrs = aReproj->DstSrs();
    dstSrs->ExportToWkt(&dstProj);

    const CGdaDriverCtl *dstDr = aReproj->DstDr();
    GDALDriverH dstDrH = (GDALDriverH) dstDr->Handle();
    char **createOpt = NULL;
    GDALResampleAlg resampleAlg = GRA_NearestNeighbour;
    double warpMemLimit = 0;
    double maxErr = 0.0;
    GDALProgressFunc progFunc = NULL;
    void *progArg = NULL;
    GDALWarpOptions *opts = NULL;
    CPLErr err = GDALCreateAndReprojectImage(src, srcProj.ToA(), dst,
                                             dstProj.ToA(), dstDrH,
                                             createOpt, resampleAlg,
                                             warpMemLimit, maxErr, progFunc,
                                             progArg, opts);

    if (err == CE_None)
    {
        return UErrFalse;
    }

    return UErrTrue;
}
