/******************************************************************************
 * $Id: cls_mathconst.hpp 2017-10 $
 *
 * Project:  C language standard library.
 * Purpose:  Math constants definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-10 ~ 2017 Weiwei Huang
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

#ifndef CLS_MATHCONST_HPP_INCLUDED
#define CLS_MATHCONST_HPP_INCLUDED

#include "cls_base.h"

class CLS_LIB CClsMathConst
{
  public:
    CClsMathConst();
    ~CClsMathConst();

    UErrCodeT Init();
    UFloatT Pi();

  protected:
  private:
};

#endif  // CLS_MATHCONST_HPP_INCLUDED
