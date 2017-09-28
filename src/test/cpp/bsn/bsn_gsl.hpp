/******************************************************************************
 * $Id: bsn_gsl.hpp 2017-09 $
 *
 * Project:  Business Logic library.
 * Purpose:  Test gsl control api definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-06 ~ 2017, Weiwei Huang
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

#ifndef BSN_GSL_HPP_INCLUDED
#define BSN_GSL_HPP_INCLUDED

#include "bsn_base.hpp"

class CGslCtl;

class BSN_LIB CBsnGsl
{
  public:
    CBsnGsl();
    ~CBsnGsl();
    UErrCodeT Init();
    UErrCodeT Test();

  protected:
  private:
    UErrCodeT TestVector();
    UErrCodeT TestSf();

    CGslCtl *mGsl;
};

#endif  // BSN_GSL_HPP_INCLUDED
