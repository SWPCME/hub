/******************************************************************************
 * $Id: gda_banddatatype.hpp 2017-12 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Gda band data type definition.
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

#ifndef GDA_BANDDATATYPE_HPP_INCLUDED
#define GDA_BANDDATATYPE_HPP_INCLUDED

#include "gda_base.h"
#include "ust/ust_datatype.hpp"

class CGdaBandDataCtl;

class GDA_LIB GdaBandDataT
{
  public:
    GdaBandDataT();
    GdaBandDataT(const UDataTCodeT aType, const BMathCsC2dT *aBegin,
                 const BMathCsC2dT *aEnd);
    GdaBandDataT(const UDataTCodeT aType, const BMathCsC2dT *aId);
    ~GdaBandDataT();

    UErrCodeT SetAll(const UDataTCodeT aType, const BMathCsC2dT *aBegin,
                     const BMathCsC2dT *aEnd);
    UErrCodeT SetType(const UDataTCodeT aType);
    UErrCodeT SetBegin(const BMathCsC2dT *aBegin);
    UErrCodeT SetEnd(const BMathCsC2dT *aEnd);

    UDataTCodeT Type();
    BMathCsC2dT *Begin();
    BMathCsC2dT *End();
    UDataHT Handle();

    UErrCodeT Data(UDataT *aData, const BMathCsC2dT *aId = NULL);

  protected:
  private:
    UErrCodeT Init();
    UErrCodeT SetHandle();

    CGdaBandDataCtl *mData;
    UDataTCodeT mType;
    BMathCsC2dT mBegin;
    BMathCsC2dT mEnd;
    UDataHT mDataH;
    UStateCodeT mState;
};

#endif  // GDA_BANDDATATYPE_HPP_INCLUDED
