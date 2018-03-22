/******************************************************************************
 * $Id: gda_trvtr.hpp 2017-08 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Translate vector definition.
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

#ifndef GDA_TRVTR_HPP_INCLUDED
#define GDA_TRVTR_HPP_INCLUDED

#include "gda_base.h"

// gda
#include "gda_trvtrtovtrtype.hpp"
#include "gda_trvtrtorsttype.hpp"
// ogr
#include "ogr/ogr_base.h"
// ust
#include "ust/ust_stringtype.hpp"

// gda
class CGdaTypeCtl;
class CGdaDatasetCtl;
class CGdaBandCtl;
class CGdaTrVtrProcCtl;
// ogr
class COgrTypeCtl;
class COgrDatasrcCtl;
class COgrLayerCtl;

class GDA_LIB CGdaTrVtr
{
  public:
    CGdaTrVtr();
    ~CGdaTrVtr();

    UErrCodeT Init();
    CGdaTrVtrProcCtl *ProcCtl();

    UErrCodeT ToRst(const UStringT *aDst, const CGdaDatasetCtl *aSrc,
                    const GdaTrVtrToRstT *aProc);
    UErrCodeT ToVtr(const UStringT *aDst, const OgrCtnDatasrcT *aSrc,
                    const GdaTrVtrToVtrT *aProc);

  protected:
  private:
    // Init pointer.
    UErrCodeT InitPointer();

    CGdaTypeCtl *mGdaType;
    COgrTypeCtl *mOgrType;
    CGdaTrVtrProcCtl *mProc;
};

#endif  // GDA_TRVTR_HPP_INCLUDED
