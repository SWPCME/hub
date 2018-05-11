/******************************************************************************
 * $Id: gda_typeogrctr.hpp 2018-05 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Gda type ogr coordinate transform controler implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2018-05 ~ 2018, Weiwei Huang
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

#include "gda_typeogrctr.hpp"

// gda
#include "gda_ogrsrstype.hpp"

// GDAL
#include "ogr_srs_api.h"

/**
 * \brief Constructor.
 */
CGdaTypeOgrCtr::CGdaTypeOgrCtr()
{
}

/**
 * \brief Destructor.
 */
CGdaTypeOgrCtr::~CGdaTypeOgrCtr()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CGdaTypeOgrCtr::Init()
{
    return UErrFalse;
}

/**
 * \brief New.
 */
UErrCodeT CGdaTypeOgrCtr::New(GdaOgrCtrHT *aCtrH, const GdaOgrSrsT *aSrc,
                              const GdaOgrSrsT *aDst)
{
    OGRSpatialReferenceH srcH = (OGRSpatialReferenceH) aSrc->Handle();
    OGRSpatialReferenceH dstH = (OGRSpatialReferenceH) aDst->Handle();
    OGRCoordinateTransformationH ctrH = OCTNewCoordinateTransformation(srcH,
                                                                       dstH);
    *aCtrH = (GdaOgrCtrHT) ctrH;

    return UErrFalse;
}

/**
 * \brief Destroy.
 */
UErrCodeT CGdaTypeOgrCtr::Destroy(GdaOgrCtrHT aCtrH)
{
    OGRCoordinateTransformationH ctr = (OGRCoordinateTransformationH) aCtrH;
    OCTDestroyCoordinateTransformation(ctr);

    return UErrFalse;
}

/**
 * \brief Transform.
 */
UErrCodeT CGdaTypeOgrCtr::Tr(BMathCsC2dT *aDst, const BMathCsC2dT *aSrc, const GdaOgrCtrHT aCtrH)
{
    OGRCoordinateTransformationH ctrH = (OGRCoordinateTransformationH) aCtrH;
    const int kCount = 1;
    double x[kCount] = {aSrc->X()};
    double y[kCount] = {aSrc->Y()};
    double z[kCount] = {0.0};
    int success[kCount];
    int err = OCTTransformEx(ctrH, kCount, x, y, z, success);

    if (err == TRUE)
    {
        aDst->SetAll(x[0], y[0]);
        return UErrFalse;
    }

    return UErrTrue;
}
