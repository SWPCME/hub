/******************************************************************************
 * $Id: cls_streamline.hpp 2017-12 $
 *
 * Project:  C language standard library.
 * Purpose:  Stream line controler definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-12 ~ 2017 Weiwei Huang
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

#ifndef CLS_STREAMLINE_HPP_INCLUDED
#define CLS_STREAMLINE_HPP_INCLUDED

#include "cls_base.h"

// ust
#include "ust/ust_stringtype.hpp"

class CClsMemoryCtl;

class CLS_LIB CClsStreamLine
{
  public:
    CClsStreamLine();
    ~CClsStreamLine();

    UErrCodeT Init();
    UErrCodeT Line(UStringT *aStr, ClsFileHT aFile);

  protected:
  private:
    UErrCodeT InitPointer();

    CClsMemoryCtl *mMem;
};

#endif  // CLS_STREAMLINE_HPP_INCLUDED
