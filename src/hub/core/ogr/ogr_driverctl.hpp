/******************************************************************************
 * $Id: ogr_driverctl.hpp 2017-07 $
 *
 * Project:  Ogr (OpenGIS Simple Features Reference Implementation) library.
 * Purpose:  Driver controler definition.
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

#ifndef OGR_DRIVERCTL_HPP_INCLUDED
#define OGR_DRIVERCTL_HPP_INCLUDED

#include "ogr_base.h"

// ust
#include "ust/ust_stringtype.hpp"
#include "ust/ust_containertype.hpp"

class COgrDatasrcCtl;

class OGR_LIB COgrDriverCtl
{
  public:
    COgrDriverCtl(const UStringT *aName);
    ~COgrDriverCtl();

    UErrCodeT Init();
    COgrDatasrcCtl *Create(const UStringT *aFile);
    COgrDatasrcCtl *Load(const UStringT *aFile);
    UErrCodeT Close(const UStringT *aFile);
    UErrCodeT CloseAll();

  protected:
  private:
    typedef UContainerT<COgrDatasrcCtl*, UStringT> MDsT;
    typedef UIteratorT<COgrDatasrcCtl*, UStringT> MDsItT;

    UErrCodeT SetHandle(const UStringT *aName);
    COgrDatasrcCtl *DsCtl(const UStringT *aFile, UFileOperCodeT aCode);

    MDsT mMDs;
    OgrDriverHT mDriverH;
};

#endif  // OGR_DRIVERCTL_HPP_INCLUDED
