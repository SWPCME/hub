/******************************************************************************
 * $Id: cls_fscreate.hpp 2017-12 $
 *
 * Project:  C language standard library.
 * Purpose:  File system create definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-12 ~ 2017, Weiwei Huang
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

#ifndef CLS_FSCREATE_HPP_INCLUDED
#define CLS_FSCREATE_HPP_INCLUDED

#include "cls_base.h"

// ust
#include "ust/ust_stringtype.hpp"

// cls
class CClsStreamFile;
class CClsStreamBlock;

class CLS_LIB CClsFsCreate
{
  public:
    CClsFsCreate();
    ~CClsFsCreate();

    UErrCodeT Init();

    UErrCodeT Dir(const UStringT *aDir);
    UErrCodeT Copy(const UStringT *aDst, const UStringT *aSrc);

  protected:
  private:
    UErrCodeT InitPointer();
    UErrCodeT CopyStdC(const UStringT *aDst, const UStringT *aSrc);
    UErrCodeT CopySys(const UStringT *aDst, const UStringT *aSrc);

    CClsStreamFile *mFile;
    CClsStreamBlock *mBlock;
};

#endif  // CLS_FSCREATE_HPP_INCLUDED
