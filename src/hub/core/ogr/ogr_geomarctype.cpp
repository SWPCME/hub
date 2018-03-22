/******************************************************************************
 * $Id: ogr_geomarctype.cpp 2017-12 $
 *
 * Project:  Ogr(OpenGIS Simple Features Reference Implementation) library.
 * Purpose:  Ogr geometry arc type implementation.
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
 ****************************************************************************/

#include "ogr_geomarctype.hpp"

// base
#include "base_mathtype.hpp"

/**
 * \brief Constructor.
 */
OgrGeomArcT::OgrGeomArcT()
{
}

/**
 * \brief Destructor.
 */
OgrGeomArcT::~OgrGeomArcT()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT OgrGeomArcT::Init()
{
    return UErrFalse;
}

/**
 * \brief Set a circle in 2D.
 */
UErrCodeT OgrGeomArcT::SetCircle2D(const BMathCsC2dT *aCenter,
                                   const UFloatT aRadius)
{
    SetCenter2D(aCenter);
    BMathCsC2dT radius(aRadius, aRadius);
    SetRadius(&radius);

    return UErrFalse;
}

/**
 * \brief Set center with 2D point.
 */
UErrCodeT OgrGeomArcT::SetCenter2D(const BMathCsC2dT *aCenter)
{
    mCener.SetAll(aCenter->X(), aCenter->Y(), 0.0);

    return UErrFalse;
}

/**
 * \brief Set radius for ellipse.
 */
UErrCodeT OgrGeomArcT::SetRadius(const BMathCsC2dT *aRadius)
{
    mRadius = *aRadius;

    return UErrFalse;
}

/**
 * \brief Center with 3D point.
 */
BMathCsC3dT OgrGeomArcT::Center()
{
    return mCener;
}

/**
 * \brief Radius for ellipse.
 */
BMathCsC2dT OgrGeomArcT::Radius()
{
    return mRadius;
}
