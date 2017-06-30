/******************************************************************************
 * $Id: ncc_vectorctl.hpp 2017-06 $
 *
 * Project:  NCC (NCC: Numerical Computing Collection).
 * Purpose:  Vector controler definition.
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

#ifndef NCC_VECTORCTL_HPP_INCLUDED
#define NCC_VECTORCTL_HPP_INCLUDED

#include "ncc_base.hpp"

class CGslVectorBaseCtl;
class CGslVectorMemCtl;
class CGslVectorOperCtl;
class CGslBlasVopCtl;

class NCC_LIB CNccVectorCtl
{
  public:
    CNccVectorCtl();
    ~CNccVectorCtl();

    UErrCodeT Init();
    UErrCodeT DimSize(UIntT *aSize, NccVectorHT aVtrH);
    UErrCodeT SetDimSize(const UIntT aSize, NccVectorHT *aVtrH);
    UErrCodeT Value(UFloatT *aVal, NccVectorHT aVector, UIntT aDim);
    UErrCodeT SetValue(UFloatT aVal, NccVectorHT aVector, UIntT aDim);
    UErrCodeT Cpy(NccVectorHT *aDest, const NccVectorHT aSrc);
    UErrCodeT Mul(NccVectorHT *aC, const NccVectorHT aA, const NccVectorHT aB);
    UErrCodeT Dot(UFloatT *aResult, const NccVectorHT aX, const NccVectorHT aY);
    UErrCodeT Free(NccVectorHT aVector);

  protected:
  private:

    CGslVectorBaseCtl *mBase;
    CGslVectorMemCtl *mMem;
    CGslVectorOperCtl *mOper;
    CGslBlasVopCtl *mVop;
};

#endif  // NCC_VECTORCTL_HPP_INCLUDED
