/******************************************************************************
 * $Id: gda_ctl.hpp 2017-07 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
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

class CGdaCoreCtl;
class CGdaOgrCtl;
class CGdaAlgCtl;
class CGdaUtilsCtl;
class CGdaTypeCtl;

class GDA_LIB CGdaCtl
{
  public:
    CGdaCtl();
    ~CGdaCtl();

    // Init.
    UErrCodeT Init();

    // Controler.
    CGdaCoreCtl *Core();
    CGdaOgrCtl *Ogr();
    CGdaAlgCtl *Alg();
    CGdaUtilsCtl *Utils();

    // Private controler.
    CGdaTypeCtl *Type();

  protected:
  private:
    CGdaCoreCtl *mCore;
    CGdaOgrCtl *mOgr;
    CGdaAlgCtl *mAlg;
    CGdaUtilsCtl *mUtils;
    CGdaTypeCtl *mType;
};

#endif  // GDA_CTL_HPP_INCLUDED
