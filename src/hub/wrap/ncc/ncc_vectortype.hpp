/******************************************************************************
 * $Id: ncc_vectortype.hpp 2017-06 $
 *
 * Project:  NCC (NCC: Numerical Computing Collection).
 * Purpose:  Vector type definition.
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

#ifndef NCC_VECTORTYPE_HPP_INCLUDED
#define NCC_VECTORTYPE_HPP_INCLUDED

#include "ncc_base.hpp"

class CNccVectorCtl;

class NCC_LIB NccVectorT
{
  public:
    NccVectorT();
    ~NccVectorT();

    NccVectorHT Handle() const;
    UErrCodeT SetHandle(NccVectorHT aHandle);
    UErrCodeT DimSize(UIntT *aSize);
    UErrCodeT SetDimSize(UIntT aSize);
    UErrCodeT Value(UFloatT *aVal, UIntT aDim);
    UErrCodeT SetValue(UFloatT aVal, UIntT aDim);
    NccVectorT operator *(const NccVectorT &aVector);
    UErrCodeT operator =(const NccVectorT &aVector);

  protected:
  private:

    UErrCodeT Init();
    UErrCodeT Free();

    // GSL.
    CNccVectorCtl *mVector;
    NccVectorHT mVtrHandle;
};

#endif  // NCC_VECTORTYPE_HPP_INCLUDED
