/******************************************************************************
 * $Id: cls_fsfiletype.hpp 2018-01 $
 *
 * Project:  C language standard library.
 * Purpose:  File system file type definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2018-01 ~ 2018, Weiwei Huang
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

#ifndef CLS_FSFILETYPE_HPP_INCLUDED
#define CLS_FSFILETYPE_HPP_INCLUDED

#include "cls_base.h"

// base
#include "base_containerdefn.hpp"

class CLS_LIB ClsFsFileT
{
  public:
    ClsFsFileT();
    ~ClsFsFileT();

    UErrCodeT Init();

    // Set value.
    UErrCodeT SetAll(const UStringT *aName, const ClsFsFileTypeCodeT aType);
    UErrCodeT SetName(const UStringT *aName);
    UErrCodeT SetType(const ClsFsFileTypeCodeT aType);

    // Get value.
    UErrCodeT All(UStringT *aName, ClsFsFileTypeCodeT *aType) const;
    UStringT Name() const;
    ClsFsFileTypeCodeT Type() const;

  protected:
  private:

    UStringT mName;
    ClsFsFileTypeCodeT mType;
};

typedef UContainerT<ClsFsFileT> ClsFsFileCtnT;
typedef UIteratorT<ClsFsFileT> ClsFsFileItT;

#endif  // CLS_FSFILETYPE_HPP_INCLUDED
