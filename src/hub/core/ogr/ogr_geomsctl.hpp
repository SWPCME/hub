/******************************************************************************
 * $Id: ogr_geomsctl.hpp 2017-11 $
 *
 * Project:  Ogr(OpenGIS Simple Features Reference Implementation) library.
 * Purpose:  Ogr geometry set definition.
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

#ifndef OGR_GEOMSCTL_HPP_INCLUDED
#define OGR_GEOMSCTL_HPP_INCLUDED

#include "ogr_base.h"

// ust
#include "ust/ust_stringtype.hpp"
#include "ust/ust_containertype.hpp"

class COgrGeomCtl;
class OgrGeomArcT;

class OGR_LIB COgrGeomsCtl
{
  public:
    COgrGeomsCtl(OgrFeaturesHT aFeatureH);
    ~COgrGeomsCtl();

    UErrCodeT Init();

    // Create.
    COgrGeomCtl *Create(const OgrGeomTCodeT aCode);
    COgrGeomCtl *CreateArc(const OgrGeomArcT *aArc);

    UErrCodeT Set(COgrGeomCtl *aGeom);
    COgrGeomCtl *Load();
    UErrCodeT Close(COgrGeomCtl *aGeom);
    UErrCodeT CloseAll();

  protected:
  private:
    typedef UContainerT<COgrGeomCtl*> LGeomT;
    typedef UIteratorT<COgrGeomCtl*> LGeomItT;

    UErrCodeT SetHandle(OgrFeatureHT aFeatureH);
    COgrGeomCtl *GeomCtl(const UFileOperCodeT aOper,
                         const OgrGeomTCodeT aGeomT = OgrGeomTUnknown);
    COgrGeomCtl *GeomCtl(const OgrGeomArcT *aArc);

    LGeomT mLGeom;
    OgrGeomsHT mGeomsH;
};

#endif  // OGR_GEOMSCTL_HPP_INCLUDED
