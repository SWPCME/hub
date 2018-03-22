/******************************************************************************
 * $Id: gda_utilsctl.hpp 2017-07 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Utils control definition.
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

#ifndef GDA_UTILSCTL_CTL_HPP
#define GDA_UTILSCTL_CTL_HPP

#include "gda_base.h"

class CGdaUtilsInfo;
class CGdaUtilsTr;
class CGdaUtilsDem;

class GDA_LIB CGdaUtilsCtl
{
  public:
    CGdaUtilsCtl();
    ~CGdaUtilsCtl();

    UErrCodeT Init();
    CGdaUtilsInfo *Info();
    CGdaUtilsTr *Tr();
    CGdaUtilsDem *Dem();

  protected:
  private:
    CGdaUtilsInfo *mInfo;
    CGdaUtilsTr *mTr;
    CGdaUtilsDem *mDem;
};

#endif  // GDA_UTILSCTL_CTL_HPP
