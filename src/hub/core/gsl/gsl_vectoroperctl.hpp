/******************************************************************************
 * $Id: gsl_vectoroperctl.hpp 2017-06 $
 *
 * Project:  GSL (GSL: Gnu Scientific Library).
 * Purpose:  Vector operator controler definition.
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

#ifndef GSL_VECTOROPERCTL_HPP_INCLUDED
#define GSL_VECTOROPERCTL_HPP_INCLUDED

#include "gsl_base.hpp"

class CGslVectorMemCtl;

class GSL_LIB CGslVectorOperCtl
{
  public:
    CGslVectorOperCtl();
    ~CGslVectorOperCtl();

    UErrCodeT Init();
    UErrCodeT Mul(GslVectorHT *aC, const GslVectorHT aA,
                  const GslVectorHT aB);

  protected:
  private:
    CGslVectorMemCtl *mMem;
};

#endif  // GSL_VECTOROPERCTL_HPP_INCLUDED
