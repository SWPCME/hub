/******************************************************************************
 * $Id: gda_ctl.hpp 2017-05 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Gda control api.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016 ~ 2017, Weiwei Huang
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

#ifndef GDA_CTL_HPP_INCLUDED
#define GDA_CTL_HPP_INCLUDED

#include "gda_base.h"
#include "ust_stringtype.hpp"
#include "ust_containertype.hpp"

class CGdaTypeCtl;
class CGdaDriverCtl;

typedef UContainerT<GdaDriverHT, UStringT> MGdaDriverHT;
typedef UIteratorT<GdaDriverHT, UStringT> MGdaDriverHItT;
typedef UContainerT<CGdaDriverCtl*, UStringT> MGdaDriverCtlT;

class GDA_LIB CGdaCtl
{
  public:
    CGdaCtl();
    ~CGdaCtl();

    // Init.
    UErrCodeT Init();
    CGdaDriverCtl *Driver(UStringT *aName);

  protected:
  private:
    // Driver.
    UErrCodeT InitDriver();
    UErrCodeT DriverCount(UIntT *aNum);
    UErrCodeT GetDriver(GdaDriverHT *aHandle, const UStringT* aName);
    UErrCodeT GetDriver(GdaDriverHT *aHandle, UIntT aNum);

    // Register.
    UErrCodeT Register();
    UErrCodeT RegisterAll();

    // Deregister.
    UErrCodeT Deregister(UStringT *aDriver);
    UErrCodeT Deregister(GdaDriverHT aDriver);
    UErrCodeT DeregisterAll();
    UErrCodeT Destroy();

    // Cleanup all.
    UErrCodeT CleanupAll();

    // Map: driver handle with driver name.
    MGdaDriverHT mMDriverH;
    // Map: driver control with driver name.
    MGdaDriverCtlT mMDriverCtl;

    // Dataset.
    CGdaTypeCtl* mType;
};

#endif  // GDA_CTL_HPP_INCLUDED
