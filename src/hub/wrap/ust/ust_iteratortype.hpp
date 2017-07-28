/******************************************************************************
 * $Id: ust_iteratortype.hpp 2017-05 $
 *
 * Project:  Universal structure library.
 * Purpose:  Iterator type definition.
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

#ifndef UST_ITERATORTYPE_HPP_INCLUDED
#define UST_ITERATORTYPE_HPP_INCLUDED

#include "ust_containerbase.h"

// Module
#include "ust_containerctl.hpp"

template <typename ContentT, typename KeyT = UIntT>
class UST_LIB UIteratorT
{
  public:
    UIteratorT();
    ~UIteratorT();

    UErrCodeT Init(CUstContainerCtl<ContentT, KeyT> *aCtn);
    UErrCodeT Head(const USequenceCodeT aCode = USequenceOrder);
    UErrCodeT Goto(const KeyT *aKey);
    UErrCodeT Goto(const KeyT &aKey);
    UErrCodeT Next();
    UErrCodeT State();
    ContentT Content();
    KeyT Key();
    UErrCodeT Add(const ContentT &aContent, const KeyT &aKey);

  protected:
  private:
    CUstContainerCtl<ContentT, KeyT> *mCtn;
};

#include "ust_iteratortype_cpp.hpp"

#endif  // UST_ITERATORTYPE_HPP_INCLUDED
