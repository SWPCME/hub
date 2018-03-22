/******************************************************************************
 * $Id: ust_iteratorctl.hpp 2017-05 $
 *
 * Project:  Universal structure library.
 * Purpose:  Iterator controler definition.
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

#ifndef UST_ITERATORCTL_HPP_INCLUDED
#define UST_ITERATORCTL_HPP_INCLUDED

template<typename ContentT, typename KeyT = UIntT>
class UST_LIB CUstIteratorCtl
{
  public:
    CUstIteratorCtl();
    ~CUstIteratorCtl();

    UErrCodeT Init(USequenceCodeT aCode);
    ContentT Content();
    KeyT Key();
    UErrCodeT GotoByKey(KeyT &aKey);
    UErrCodeT Goto(ContentT &aContent);
    UErrCodeT GotoBegin();
    UErrCodeT GotoEnd();
    UErrCodeT GotoNext();
    UErrCodeT GotoPrev();
    UErrCodeT State();

  protected:
  private:
};

#include "ust_iteratorctl_cpp.hpp"

#endif  // UST_ITERATORCTL_HPP_INCLUDED
