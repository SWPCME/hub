/******************************************************************************
 * $Id: gda_utilsdem.hpp 2017-12 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Utils dem(digital elevation model) definition.
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
 *****************************************************************************/

#ifndef GDA_UTILSDEM_HPP_INCLUDED
#define GDA_UTILSDEM_HPP_INCLUDED

#include "gda_base.h"

// gda
#include "gda_demproctype.hpp"

class CGdaTypeCtl;
class CGdaCoreCtl;
class CGdaDatasetCtl;
class CGdaDemProcCtl;

class GDA_LIB CGdaUtilsDem
{
  public:
    CGdaUtilsDem();
    ~CGdaUtilsDem();

    UErrCodeT Init();
    CGdaDemProcCtl *ProcCtl();

    UErrCodeT Proc(const UStringT *aDst, const CGdaDatasetCtl *aSrc,
                   const GdaDemProcT *aProc);

  protected:
  private:
    CGdaTypeCtl *mType;
    CGdaCoreCtl *mCore;
    CGdaDemProcCtl *mProc;
};

#endif  // GDA_UTILSDEM_HPP_INCLUDED
