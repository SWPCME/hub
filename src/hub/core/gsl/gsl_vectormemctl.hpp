/******************************************************************************
 * $Id: gsl_vectormemctl.hpp 2017-06 $
 *
 * Project:  GSL (GSL: Gnu Scientific Library).
 * Purpose:  Vector memory controler definition.
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

#ifndef GSL_VECTORMEMCTL_HPP_INCLUDED
#define GSL_VECTORMEMCTL_HPP_INCLUDED

#include "gsl_base.hpp"

class GSL_LIB CGslVectorMemCtl
{
  public:
    CGslVectorMemCtl();
    ~CGslVectorMemCtl();

    UErrCodeT Init();
    UErrCodeT Alloc(GslVectorHT *aVector, const UIntT aSize);
    UErrCodeT Cpy(GslVectorHT *aDest, const GslVectorHT aSrc);
    UErrCodeT Free(GslVectorHT aVector);

  protected:
  private:
};

#endif  // GSL_VECTORMEMCTL_HPP_INCLUDED
