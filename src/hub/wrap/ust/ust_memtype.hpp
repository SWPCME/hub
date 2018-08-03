/* -*- mode: c++ -*- */
/******************************************************************************
 * $Id: ust_memtype.hpp 2018-08 $
 *
 * Project:  Ust (ust: universal struct library).
 * Purpose:  Memory type definition.
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

#ifndef UST_MEMTYPE_HPP_INCLUDED
#define UST_MEMTYPE_HPP_INCLUDED

#include "ust_base.h"

// cls
class CClsMemoryCtl;

/**
 * \brief UMemT: Universal memory type.
 */
class UST_LIB UMemT
{
  public:
    UMemT();
    UMemT(const UIntT aSize);
    ~UMemT();

    UMemHT Handle();
    UErrCodeT Set(const UIntT aSize);

  protected:
  private:
    UErrCodeT Init();
    UErrCodeT InitPointer();

    UErrCodeT Free();

    CClsMemoryCtl *mMem;
    UMemHT mMemH;
};

#endif  // UST_MEMTYPE_HPP_INCLUDED
