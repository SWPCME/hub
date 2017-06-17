/******************************************************************************
 * $Id: ust_containertype.hpp 2016-08 $
 *
 * Project:  Universal structure library.
 * Purpose:  Container type.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016, Weiwei Huang
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ****************************************************************************/

#ifndef UST_CONTAINERTYPE_HPP_INCLUDED
#define UST_CONTAINERTYPE_HPP_INCLUDED

#include "ust_containerbase.h"

// Module
#include "ust_containerctl.hpp"

template <typename ContentT, typename KeyT = UIntT>
class UST_LIB UContainerT
{
  public:
    UContainerT();
    UContainerT(UContainerCodeT aCode);
    ~UContainerT();

    UErrCodeT Init(UContainerCodeT aCode);
    UErrCodeT Add(const ContentT &aContent);
    UErrCodeT Add(const ContentT *aContent, const KeyT *aKey);
    UErrCodeT Add(const ContentT &aContent, const KeyT &aKey);
    UErrCodeT Del(ContentT &aContent);
    UErrCodeT DelByKey(KeyT &aKey);
    UErrCodeT Clear();
    UErrCodeT Find(ContentT &aContent);
    UErrCodeT FindByKey(KeyT *aKey);
    UErrCodeT FindByKey(KeyT &aKey);
    UErrCodeT Sort();
    UErrCodeT SortByKey();
    UErrCodeT Count(UIntT *aNum);

    // Iterator.
    UIteratorT<ContentT, KeyT> *Iterator();

    // Get content and key by each other.
    ContentT Content(const KeyT &aKey);
    const KeyT Key(const ContentT &aContent);

    /* Operator */
    ContentT operator [](const KeyT &aKey);
  protected:
  private:
    CUstContainerCtl<ContentT, KeyT> *mCtn;
};

#include "ust_containertype_cpp.hpp"

#endif  /* UST_CONTAINERTYPE_HPP_INCLUDED */
