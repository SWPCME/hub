/******************************************************************************
 * $Id: cls_timectl.hpp 2017-07 $
 *
 * Project:  C language standard library.
 * Purpose:  Time controler definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-07 ~ 2017 Weiwei Huang
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

#ifndef CLS_TIMECTL_HPP_INCLUDED
#define CLS_TIMECTL_HPP_INCLUDED

#include "cls_base.h"

// base
#include "base_timetype.hpp"

class CClsTypeCtl;

class CLS_LIB CClsTimeCtl
{
  public:
    CClsTimeCtl();
    ~CClsTimeCtl();

    UErrCodeT Init();
    UErrCodeT Current(BTimeTmT *aTm);
    UErrCodeT Diff(UFloatT *aElapse, const BTimeTmT *aTm1,
                   const BTimeTmT *aTm2);

 protected:
  private:
    UErrCodeT Time(ClsTimeHT aTime);
    UErrCodeT GmTime(ClsTmHT *aTm);
    UErrCodeT MkTime(UIntT *aTimeT, const ClsTmHT aTm);
    UErrCodeT TimeGm(UIntT *aTimeT, const ClsTmHT aTm);

    CClsTypeCtl *mType;
};

#endif  // CLS_TIMECTL_HPP_INCLUDED
