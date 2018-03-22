/******************************************************************************
 * $Id: gda_trrst.hpp 2017-07 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Translate raster definition.
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

#ifndef GDA_TRRST_HPP_INCLUDED
#define GDA_TRRST_HPP_INCLUDED

#include "gda_base.h"

// ust
#include "ust/ust_stringtype.hpp"
// gda
#include "gda_trrsttorsttype.hpp"

// gda
class CGdaTypeCtl;
class CGdaDatasetCtl;
class CGdaTrRstProcCtl;

class GDA_LIB CGdaTrRst
{
  public:
    CGdaTrRst();
    ~CGdaTrRst();

    UErrCodeT Init();
    CGdaTrRstProcCtl *ProcCtl();

    UErrCodeT ToRst(const UStringT *aDst, CGdaDatasetCtl *aSrc,
                    const GdaTrRstToRstT *aOpt);

 protected:
  private:
    CGdaTypeCtl *mType;
    CGdaTrRstProcCtl *mProc;
};

#endif  // GDA_TRRST_HPP_INCLUDED
