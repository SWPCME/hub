/******************************************************************************
 * $Id: gda_ctl.hpp 2017-07 $
 *
 * Project:  Gda (GDAL: Geospatial Data Abstraction Library) library.
 * Purpose:  Gda control definition.
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
 *****************************************************************************/

#ifndef GDA_CTL_HPP_INCLUDED
#define GDA_CTL_HPP_INCLUDED

#include "gda_base.h"

// hub
class CHubModuleCtl;
// gda
class CGdaCoreCtl;
class CGdaOgrCtl;
class CGdaAlgCtl;
class CGdaWarpCtl;
class CGdaUtilsCtl;
class CGdaTypeCtl;

class GDA_LIB CGdaCtl
{
  public:
    CGdaCtl(CHubModuleCtl *aModule);
    ~CGdaCtl();

    // Init.
    UErrCodeT Init();
    CHubModuleCtl *Up();

    // Controler.
    CGdaCoreCtl *Core();
    CGdaOgrCtl *Ogr();
    CGdaAlgCtl *Alg();
    CGdaWarpCtl *Warp();
    CGdaUtilsCtl *Utils();

    // Private controler.
    CGdaTypeCtl *Type();

  protected:
  private:
    CHubModuleCtl *mModule;
    CGdaCoreCtl *mCore;
    CGdaOgrCtl *mOgr;
    CGdaAlgCtl *mAlg;
    CGdaWarpCtl *mWarp;
    CGdaUtilsCtl *mUtils;
    CGdaTypeCtl *mType;
};

#endif  // GDA_CTL_HPP_INCLUDED
