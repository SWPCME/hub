/******************************************************************************
 * $Id: ogr_geombasic.hpp 2017-11 $
 *
 * Project:  Ogr(OpenGIS Simple Features Reference Implementation) library.
 * Purpose:  Ogr geometry basic definition.
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

#ifndef OGR_GEOMBASIC_HPP_INCLUDED
#define OGR_GEOMBASIC_HPP_INCLUDED

#include "ogr_base.h"

class COgrTypeCtl;

class OGR_LIB COgrGeomBasic
{
  public:
    COgrGeomBasic(OgrGeomHT aGeomH);
    ~COgrGeomBasic();

    UErrCodeT Init();

    UErrCodeT Type(OgrGeomTCodeT *aCode);

  protected:
  private:
    UErrCodeT SetHandle(OgrGeomHT aGeomH);

    OgrGeomHT mGeomH;
    COgrTypeCtl *mType;
};

#endif  // OGR_GEOMBASIC_HPP_INCLUDED
