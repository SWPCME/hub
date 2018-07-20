/******************************************************************************
 * $Id: gda_typectl.hpp 2017-05 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Gda type control.
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
 ****************************************************************************/

#ifndef GDA_TYPECTL_HPP_INCLUDED
#define GDA_TYPECTL_HPP_INCLUDED

#include "gda_base.h"
// GDAL
#include "gdal.h"

// base
#include "base_containerdefn.hpp"
// ust
#include "ust/ust_stringtype.hpp"

// cls
class CClsStringCtl;
class CClsMemoryCtl;

// gda
class CGdaTypeOgr;
class CGdaBandDataCtl;

class GDA_LIB CGdaTypeCtl
{
  public:
    CGdaTypeCtl();
    ~CGdaTypeCtl();

    UErrCodeT Init();
    CGdaTypeOgr *Ogr();
    CGdaBandDataCtl *BandData();

    UErrCodeT ToAccess(GDALAccess *aDst, const UAccessCodeT aSrc);
    UErrCodeT ToDataType(GDALDataType *aDst, const UDataTCodeT aSrc);
    UErrCodeT ToDataType(UDataTCodeT *aDst, const GDALDataType aSrc);
    UErrCodeT ToDataType(UStringT *aDst, const UDataTCodeT aSrc);
    UErrCodeT ToDataType(UDataTCodeT *aDst, const UStringT *aSrc);
    UErrCodeT ToFormat(UStringT *aDest, const GdaFormatCodeT aSrc);
    // UErrCodeT ToGdaCreateOpt(UStringT *aDst, const GdaCreateOptHT aSrc,
    //                          const GdaFormatCodeT aFormat);
    UErrCodeT ToLinearUnit(UStringT *aDst, const GdaLinearUnitCodeT aSrc);

    // Warp
    UErrCodeT ToProjCs(UStringT *aDst, const GdaProjCsCodeT aSrc);
    UErrCodeT ToProjCs(UIntT *aDst, const GdaProjCsCodeT aSrc);
    UErrCodeT WktToProjCs(GdaProjCsCodeT *aDst, const UStringT aSrc);

    // Utils
    UErrCodeT ToDemProcFrmt(UStringT *aDst,
                            const GdaDemProcFrmtCodeT aSrc);

    // argv
    UErrCodeT NewArgv(GdaArgvT *aDst, const UStringT *aSrc);
    UErrCodeT NewArgv(GdaArgvT *aDst, const BCtnStringT *aSrc);
    UErrCodeT DelArgv(GdaArgvT aArgv);

  protected:
  private:
    UErrCodeT ProjCsToStr(UStringT *aDst, const GdaProjCsCodeT aSrc);

    UErrCodeT MergeArgv(UContainerT<UStringT> *aStrCtn,
                        const UStringT *aToken);

    CClsStringCtl *mStr;
    CClsMemoryCtl *mMem;

    // gda
    CGdaTypeOgr *mOgr;
    CGdaBandDataCtl *mBandData;
};

#endif  // GDA_TYPECTL_HPP_INCLUDED
