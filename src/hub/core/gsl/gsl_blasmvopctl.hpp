/******************************************************************************
 * $Id: gsl_blasmvopctl.hpp 2017-06 $
 *
 * Project:  GSL (GSL: Gnu Scientific Library).
 * Purpose:  Blas (Blas: Basic Linear Algebra Subprograms) matrix-vector 
 *           operations controler definition.
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

#ifndef GSL_BLASMVOPCTL_HPP_INCLUDED
#define GSL_BLASMVOPCTL_HPP_INCLUDED

#include "gsl_base.hpp"

class GSL_LIB CGslBlasMvopCtl
{
  public:
    CGslBlasMvopCtl();
    ~CGslBlasMvopCtl();

    UErrCodeT Init();

  protected:
  private:
};

#endif  // GSL_BLASMVOPCTL_HPP_INCLUDED
