/******************************************************************************
 * $Id: ogr_typectl.hpp 2017-07 $
 *
 * Project:  Ogr (OpenGIS Simple Features Reference Implementation) library.
 * Purpose:  Type controler definition.
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
 ****************************************************************************/

#ifndef OGR_TYPECTL_HPP_INCLUDED
#define OGR_TYPECTL_HPP_INCLUDED

#include "ogr_base.h"

// ust
#include "ust_stringtype.hpp"

class OGR_LIB COgrTypeCtl
{
  public:
    COgrTypeCtl();
    ~COgrTypeCtl();

    UErrCodeT Init();
    UErrCodeT ToFormat(UStringT *aDst, const OgrFormatCodeT aSrc,
                       UFlagCodeT aFlag = UFlagOff);
    UErrCodeT ToGeomT(OgrGeomTCodeT *aDst, const OgrGeomTHT aSrc);
    UErrCodeT ToGeomT(OgrGeomTHT aDst, const OgrGeomTCodeT aSrc);

  protected:
  private:
};

#endif  // OGR_TYPECTL_HPP_INCLUDED
