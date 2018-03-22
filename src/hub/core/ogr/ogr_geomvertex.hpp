/******************************************************************************
 * $Id: ogr_geomvertex.hpp 2017-11 $
 *
 * Project:  Ogr(OpenGIS Simple Features Reference Implementation) library.
 * Purpose:  Ogr geometry vertex definition.
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

#ifndef OGR_GEOMVERTEX_HPP_INCLUDED
#define OGR_GEOMVERTEX_HPP_INCLUDED

#include "ogr_base.h"

// base
#include "base_mathtype.hpp"

class OGR_LIB COgrGeomVertex
{
  public:
    COgrGeomVertex(OgrGeomHT aGeomH);
    ~COgrGeomVertex();

    UErrCodeT Init();

    // Count.
    UErrCodeT PointCount(UIntT *aCount);

    // Get point.
    UErrCodeT Point2D(BMathCsC2dT *aPt, const UIntT aId);
    UErrCodeT Point3D(BMathCsC3dT *aPt, const UIntT aId);
    UErrCodeT X(UFloatT *aVal, const UIntT aId);
    UErrCodeT Y(UFloatT *aVal, const UIntT aId);

    // Set point.
    UErrCodeT SetPoint2D(const BMathCsC2dT *aPt, const UIntT aId);
    UErrCodeT SetPoint3D(const BMathCsC3dT *aPt, const UIntT aId);

    // Add point.
    UErrCodeT AddPoint2D(const BMathCsC2dT *aPt);
    UErrCodeT AddPoint3D(const BMathCsC3dT *aPt);

  protected:
  private:
    UErrCodeT SetHandle(OgrGeomHT aGeomH);

    OgrGeomHT mGeomH;
};

#endif  // OGR_GEOMVERTEX_HPP_INCLUDED
