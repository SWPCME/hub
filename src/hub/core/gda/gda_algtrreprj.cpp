/******************************************************************************
 * $Id: gda_algtrreprj.cpp 2017-12 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Alg transform reprojection implementation.
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

#include "gda_algtrreprj.hpp"

// GDAL
#include "gdal_alg.h"

/**
 * \brief Constructor.
 */
CGdaAlgTrReprj::CGdaAlgTrReprj()
{
}

/**
 * \brief Destructor.
 */
CGdaAlgTrReprj::~CGdaAlgTrReprj()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CGdaAlgTrReprj::Init()
{
    return UErrFalse;
}

/**
 * \brief Create.
 */
UErrCodeT CGdaAlgTrReprj::Create(UHandleT *aHandle, const UStringT *aDst,
                                 const UStringT *aSrc)
{
    *aHandle = GDALCreateReprojectionTransformer(aSrc->ToA(), aDst->ToA());

    return UErrFalse;
}

/**
 * \brief Destroy.
 */
UErrCodeT CGdaAlgTrReprj::Destroy(UHandleT aHandle)
{
    // GDALDestroyReprojectionTransformer(aHandle);

    return UErrFalse;
}

/**
 * \brief To geospatial.
 */
// UErrCodeT CGdaAlgTrReprj::ToGeo(UHandleT aHandle)
// {
//     int bDstToSrc;
//     int nPointCount;
//     double *x;
//     double *y;
//     double *z;
//     int *panSuccess;
//     int err = GDALReprojectionTransform(aHandle, bDstToSrc, nPointCount, x, y,
//                                         z, panSuccess);

//     return UErrFalse;
// }
