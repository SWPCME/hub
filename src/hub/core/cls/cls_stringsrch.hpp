/******************************************************************************
 * $Id: cls_stringsrch.hpp 2018-07 $
 *
 * Project:  Cls (C language standard library).
 * Purpose:  String search definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2018-07 ~ 2018, Weiwei Huang
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

#ifndef CLS_STRINGSRCH_HPP_INCLUDED
#define CLS_STRINGSRCH_HPP_INCLUDED

#include "cls_base.h"

// ust
class UStringT;

/**
 * \brief Cls string search: To provide searching operations on strings.
 */
class CLS_LIB CClsStringSrch
{
  public:
    CClsStringSrch();
    ~CClsStringSrch();

    UErrCodeT Init();
    UErrCodeT Str(UStringT *aSubstr, const UStringT *aHaystack,
                  const UStringT *aNeedle);

  protected:
  private:
    UErrCodeT InitPointer();
};

#endif  // CLS_STRINGSRCH_HPP_INCLUDED
