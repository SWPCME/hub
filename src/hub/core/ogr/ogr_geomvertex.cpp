/******************************************************************************
 * $Id: ogr_geomvertex.cpp 2017-11 $
 *
 * Project:  Ogr(OpenGIS Simple Features Reference Implementation) library.
 * Purpose:  Ogr geometry vertex implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-11 ~ 2017, Weiwei Huang
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

#include "ogr_geomvertex.hpp"

// base
#include "base_macrodefn.hpp"

// GDAL/OGR
#include "ogr_api.h"

/**
 * \brief Constructor.
 */
COgrGeomVertex::COgrGeomVertex(OgrGeomHT aGeomH)
{
    BMD_POINTER_INIT(mGeomH);
    SetHandle(aGeomH);
}

/**
 * \brief Destructor.
 */
COgrGeomVertex::~COgrGeomVertex()
{
    BMD_POINTER_INIT(mGeomH);
}

/**
 * \brief Initialize.
 */
UErrCodeT COgrGeomVertex::Init()
{
    return UErrFalse;
}

/**
 * \brief Get point count.
 */
UErrCodeT COgrGeomVertex::PointCount(UIntT *aCount)
{
    *aCount = OGR_G_GetPointCount((OGRGeometryH) mGeomH);

    return UErrFalse;
}

/**
 * \brief Get 2D point.
 */
UErrCodeT COgrGeomVertex::Point2D(BMathCsC2dT *aPt, const UIntT aId)
{
    UFloatT x = 0.0;
    UFloatT y = 0.0;
    UFloatT z = 0.0;
    OGR_G_GetPoint((OGRGeometryH) mGeomH, aId, &x, &y, &z);
    aPt->SetAll(x, y);

    return UErrFalse;
}

/**
 * \brief Get x with id.
 */
UErrCodeT COgrGeomVertex::X(UFloatT *aVal, const UIntT aId)
{
    *aVal = OGR_G_GetX((OGRGeometryH) mGeomH, aId);

    return UErrFalse;
}

/**
 * \brief Get y with id.
 */
UErrCodeT COgrGeomVertex::Y(UFloatT *aVal, const UIntT aId)
{
    *aVal = OGR_G_GetY((OGRGeometryH) mGeomH, aId);

    return UErrFalse;
}

/**
 * \brief Get 3D point.
 */
UErrCodeT COgrGeomVertex::Point3D(BMathCsC3dT *aPt, const UIntT aId)
{
    UFloatT x = 0.0;
    UFloatT y = 0.0;
    UFloatT z = 0.0;
    OGR_G_GetPoint((OGRGeometryH) mGeomH, aId, &x, &y, &z);
    aPt->SetAll(x, y, z);

    return UErrFalse;
}

/**
 * \brief Set 2D point.
 */
UErrCodeT COgrGeomVertex::SetPoint2D(const BMathCsC2dT *aPt, const UIntT aId)
{
    OGR_G_SetPoint_2D((OGRGeometryH) mGeomH, aId, aPt->X(), aPt->Y());

    return UErrFalse;
}

/**
 * \brief Set 3D point.
 */
UErrCodeT COgrGeomVertex::SetPoint3D(const BMathCsC3dT *aPt, const UIntT aId)
{
    OGR_G_SetPoint((OGRGeometryH) mGeomH, aId, aPt->X(), aPt->Y(), aPt->Z());

    return UErrFalse;
}

/**
 * \brief Add 2D point.
 */
UErrCodeT COgrGeomVertex::AddPoint2D(const BMathCsC2dT *aPt)
{
    OGR_G_AddPoint_2D((OGRGeometryH) mGeomH, aPt->X(), aPt->Y());

    return UErrFalse;
}

/**
 * \brief Add 3D point.
 */
UErrCodeT COgrGeomVertex::AddPoint3D(const BMathCsC3dT *aPt)
{
    OGR_G_AddPoint((OGRGeometryH) mGeomH, aPt->X(), aPt->Y(), aPt->Z());

    return UErrFalse;
}

/***** Private A *****/

/**
 * \brief Set handle.
 */
UErrCodeT COgrGeomVertex::SetHandle(OgrGeomHT aGeomH)
{
    mGeomH = aGeomH;

    return UErrFalse;
}

/***** Private B *****/
