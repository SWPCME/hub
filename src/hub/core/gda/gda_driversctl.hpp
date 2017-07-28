/******************************************************************************
 * $Id: gda_driversctl.hpp 2017-07 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Core drivers controler definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-05 ~ 2017, Weiwei Huang
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

#ifndef GDA_DRIVERSCTL_HPP_INCLUDED
#define GDA_DRIVERSCTL_HPP_INCLUDED

#include "gda_base.h"
#include "ust/ust_stringtype.hpp"
#include "ust/ust_containertype.hpp"

class CGdaTypeCtl;
class CGdaLockCtl;
class CGdaDriverCtl;

class GDA_LIB CGdaDriversCtl
{
  public:
    CGdaDriversCtl();
    ~CGdaDriversCtl();

    // Init.
    UErrCodeT Init();

    // Controler.
    CGdaTypeCtl *Type();

    // Register and deregister.
    UErrCodeT Register(const UStringT *aName);
    UErrCodeT Register(const GdaFormatCodeT aFormat);
    UErrCodeT RegisterAll();
    UErrCodeT Deregister(const UStringT *aName);
    UErrCodeT Deregister(const GdaFormatCodeT aFormat);
    UErrCodeT DeregisterAll();

    // Driver.
    CGdaDriverCtl *Driver(const UStringT *aName);
    CGdaDriverCtl *Driver(const GdaFormatCodeT aFormat);

  protected:
  private:
    typedef UContainerT<CGdaDriverCtl*, UStringT> MDriverT;
    typedef UIteratorT<CGdaDriverCtl*, UStringT> MDriverItT;

    UErrCodeT GdaRegisterAll();
    UErrCodeT DestroyDriverManager();
    UErrCodeT Destroy();
    UErrCodeT CleanupAll();

    // Map: driver control with driver name.
    MDriverT mMDriver;

    // Dataset.
    CGdaTypeCtl* mType;
};

#endif  // GDA_DRIVERSCTL_HPP_INCLUDED
