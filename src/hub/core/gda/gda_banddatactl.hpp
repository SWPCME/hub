/******************************************************************************
 * $Id: gda_banddatactl.hpp 2017-12 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Gda band data controler definition.
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
 ****************************************************************************/

#ifndef GDA_BANDDATACTL_HPP_INCLUDED
#define GDA_BANDDATACTL_HPP_INCLUDED

#include "gda_base.h"
#include "ust/ust_base.h"

// cls
class CClsMemoryCtl;
// ust
class CUstTypeCtl;

class GDA_LIB CGdaBandDataCtl
{
  public:
    CGdaBandDataCtl();
    ~CGdaBandDataCtl();

    UErrCodeT Init();

    UErrCodeT New(UDataHT *aDataH, const UDataTCodeT aType,
                  const BMathCsC2dT *aBegin, const BMathCsC2dT *aEnd);
    UErrCodeT Del(UDataHT *aDataH);

    UErrCodeT Size(UIntT *aSize, const BMathCsC2dT *aBegin,
                   const BMathCsC2dT *aEnd);
    UErrCodeT Id(UIntT *aId, const BMathCsC2dT *aPt,
                 const BMathCsC2dT *aBegin, const BMathCsC2dT *aEnd);

  protected:
  private:
    UErrCodeT InitPointer();
    UErrCodeT CheckPt(const BMathCsC2dT *aPt, const BMathCsC2dT *aBegin,
                      const BMathCsC2dT *aEnd);

    CClsMemoryCtl *mMem;
    CUstTypeCtl *mUstType;
};

#endif  // GDA_BANDDATACTL_HPP_INCLUDED
