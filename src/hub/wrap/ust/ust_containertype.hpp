/******************************************************************************
 * $Id: ust_containertype.hpp 2017 $
 *
 * Project:  Universal structure library.
 * Purpose:  Container type.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016-08 ~ 2017, Weiwei Huang
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
    UContainerT(const UContainerCodeT aCode);
    ~UContainerT();

    // Attribute
    UContainerCodeT Code();
    UstContainerHT Handle();
    UIntT Count() const;

    UErrCodeT Add(const ContentT &aContent);
    UErrCodeT Add(const ContentT *aContent, const KeyT *aKey);
    UErrCodeT Add(const ContentT &aContent, const KeyT &aKey);
    UErrCodeT Del(const ContentT &aContent);
    UErrCodeT DelByKey(const KeyT &aKey);
    UErrCodeT Clear();
    UErrCodeT Find(const ContentT &aContent);
    UErrCodeT FindByKey(const KeyT *aKey);
    UErrCodeT FindByKey(const KeyT &aKey);
    UErrCodeT Sort();
    UErrCodeT SortByKey();

    // Iterator.
    UIteratorT<ContentT, KeyT> *Iterator() const;

    // Get content and key by each other.
    ContentT Content(const KeyT &aKey);
    const KeyT Key(const ContentT &aContent);

    /* Operator */
    ContentT operator [](const KeyT &aKey);
    UErrCodeT operator =(const UContainerT<ContentT, KeyT> &aCtn);

  protected:
  private:
    UErrCodeT Init(const UContainerCodeT aCode);

    CUstContainerCtl<ContentT, KeyT> *mCtn;
};

#include "ust_containertype_cpp.hpp"

#endif  /* UST_CONTAINERTYPE_HPP_INCLUDED */
