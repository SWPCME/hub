/******************************************************************************
 * $Id: gda_trvtrtovtrtype.hpp 2017-12 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Translate vector to vector type definition.
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

#ifndef GDA_TRVTRTOVTRTYPE_HPP_INCLUDED
#define GDA_TRVTRTOVTRTYPE_HPP_INCLUDED

#include "gda_base.h"

// base
#include "base_containerdefn.hpp"

// gda
class CGdaTrVtrProcCtl;
// ogr
class COgrTypeCtl;
class GdaOgrSrsT;

class GDA_LIB GdaTrVtrToVtrT
{
  public:
    GdaTrVtrToVtrT();
    ~GdaTrVtrToVtrT();

    // Set.
    UErrCodeT SetAll(const OgrFormatCodeT aFrmt, const BCtnStringT *aOpt);
    UErrCodeT SetOpt(const BCtnStringT *aOpt);
    UErrCodeT SetFrmt(const OgrFormatCodeT aFrmt);
    UErrCodeT SetSrs(const GdaOgrSrsT *aSrs);

    // Get.
    OgrFormatCodeT Frmt() const;
    GdaOgrSrsT *Srs() const;
    GdaTrVtrProcHT Handle() const;

  protected:
  private:
    UErrCodeT Init();
    UErrCodeT InitPointer();
    UErrCodeT Save();
    UErrCodeT Clear();

    CGdaTrVtrProcCtl *mProc;
    COgrTypeCtl *mOgrType;

    GdaTrVtrProcHT mProcH;
    OgrFormatCodeT mFrmt;
    GdaFrmtFlagCodeT mFrmtFlag;
    GdaOgrSrsT *mSrs;
    BCtnStringT mLOpt;

    UStateCodeT mState;
};

#endif  // GDA_TRVTRTOVTRTYPE_HPP_INCLUDED
