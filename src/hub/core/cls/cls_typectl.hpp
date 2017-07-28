/******************************************************************************
 * $Id: cls_typectl.hpp 2017-06 $
 *
 * Project:  C language standard library.
 * Purpose:  Type controler definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016 ~ 2017 Weiwei Huang
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

#ifndef CLS_TYPECTL_HPP_INCLUDED
#define CLS_TYPECTL_HPP_INCLUDED

#include "cls_base.h"

// base
#include "base_timetype.hpp"
// ust
#include "ust/ust_stringtype.hpp"

class CLS_LIB CClsTypeCtl
{
  public:
    CClsTypeCtl();
    ~CClsTypeCtl();

    UErrCodeT Init();
    UErrCodeT ToFileOper(UStringT *aDest, const ClsFileOperCodeT aSrc);
    UErrCodeT ToTimeTm(BTimeTmT *aDest, const ClsTmHT aSrc);

  protected:
  private:
};

#endif  // CLS_TYPECTL_HPP_INCLUDED
