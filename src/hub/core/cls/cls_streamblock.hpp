/* -*- mode: c++ -*- */
/******************************************************************************
 * $Id: cls_streamblock.hpp 2018-08 $
 *
 * Project:  Cls (C language standard library).
 * Purpose:  Stream block definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2018-08 ~ 2018, Weiwei Huang
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

#ifndef CLS_STREAMBLOCK_HPP_INCLUDED
#define CLS_STREAMBLOCK_HPP_INCLUDED

#include "cls_base.h"

// cls
class CClsMemoryCtl;
// ust
class UMemT;

/**
 * \brief Cls stream block: Input and output operations on blocks of data.
 */
class CLS_LIB CClsStreamBlock
{
  public:
    CClsStreamBlock();
    ~CClsStreamBlock();

    UErrCodeT Init();

    UIntT Input(UMemT *aBlock, UIntT aSize, UIntT aCount,
                ClsFileHT aFileH);
    UErrCodeT Output(UMemT *aBlock, UIntT aSize, UIntT aCount,
                     ClsFileHT aFileH);

  protected:
  private:
    UErrCodeT InitPointer();

    CClsMemoryCtl *mMem;
};

#endif  // CLS_STREAMBLOCK_HPP_INCLUDED
