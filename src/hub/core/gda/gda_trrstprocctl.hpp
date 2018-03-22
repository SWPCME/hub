/******************************************************************************
 * $Id: gda_trrstprocctl.hpp 2017-12 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Translate raster processing controler definition.
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

#ifndef GDA_TRRSTPROCCTL_HPP_INCLUDED
#define GDA_TRRSTPROCCTL_HPP_INCLUDED

#include "gda_base.h"

// base
#include "base_containerdefn.hpp"

// gda
class CGdaTypeCtl;

class GDA_LIB CGdaTrRstProcCtl
{
  public:
    CGdaTrRstProcCtl();
    ~CGdaTrRstProcCtl();

    UErrCodeT Init();

    UErrCodeT New(GdaTrRstProcHT *aDst, BCtnStringT *aSrc,
                  const GdaFrmtFlagCodeT aFrmt);
    UErrCodeT Del(GdaTrRstProcHT aProcH, const GdaFrmtFlagCodeT aFrmt);
    UErrCodeT SetProg(GdaTrRstProcHT aProcH, UHandleT aFunc,
                      UHandleT aData, const GdaFrmtFlagCodeT aFrmt);

  protected:
  private:
    // Raster.
    UErrCodeT NewRst(GdaTrRstProcHT *aDst, BCtnStringT *aSrc);
    UErrCodeT DelRst(GdaTrRstProcHT aProcH);
    UErrCodeT SetProgRst(GdaTrRstProcHT aProcH, UHandleT aFunc, UHandleT aData);

    // Vector.
    UErrCodeT NewVtr(GdaTrRstProcHT *aDst, BCtnStringT *aSrc);
    UErrCodeT DelVtr(GdaTrRstProcHT aProcH);
    UErrCodeT SetProgVtr(GdaTrRstProcHT aProcH, UHandleT aFunc, UHandleT aData);

    CGdaTypeCtl *mType;
};

#endif  // GDA_TRRSTPROCCTL_HPP_INCLUDED
