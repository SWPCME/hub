/******************************************************************************
 * $Id: ogr_geomarctype.hpp 2017-12 $
 *
 * Project:  Ogr(OpenGIS Simple Features Reference Implementation) library.
 * Purpose:  Ogr geometry arc type definition.
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

#ifndef OGR_GEOMARCTYPE_HPP_INCLUDED
#define OGR_GEOMARCTYPE_HPP_INCLUDED

#include "ogr_base.h"

class OGR_LIB OgrGeomArcT
{
  public:
    OgrGeomArcT();
    ~OgrGeomArcT();

    UErrCodeT Init();

    // Set.
    // For setting all values.
    UErrCodeT SetCircle2D(const BMathCsC2dT *aCenter,
                          const UFloatT aRadius);
    // For setting part values.
    UErrCodeT SetCenter2D(const BMathCsC2dT *aCenter);
    UErrCodeT SetRadius(const BMathCsC2dT *aRadius);

    // Get.
    BMathCsC3dT Center();
    BMathCsC2dT Radius();

  protected:
  private:
    BMathCsC3dT mCener;
    BMathCsC2dT mRadius;
};

#endif  // OGR_GEOMARCTYPE_HPP_INCLUDED
