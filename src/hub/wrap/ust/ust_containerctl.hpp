/******************************************************************************
 * $Id: ust_containerctl.hpp 2016-08 $
 *
 * Project:  Universal structure library.
 * Purpose:  Container controler definition.
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

#ifndef UST_CONTAINERCTL_HPP_INCLUDED
#define UST_CONTAINERCTL_HPP_INCLUDED

#include "ust_containerbase.h"

// Module
#include "ccs_listctl.hpp"
#include "ccs_mapctl.hpp"

template <typename ContentT, typename KeyT = UIntT>
class UST_LIB CUstContainerCtl
{
 public:
    CUstContainerCtl();
    ~CUstContainerCtl();

    // Contenter.
    UErrCodeT Init(UContainerCodeT aCode);
    UErrCodeT Add(const ContentT *aContent);
    UErrCodeT Add(const ContentT *aContent, const KeyT *aKey);
    UErrCodeT FindByKey(const KeyT *aKey);
    ContentT *Content(const KeyT *aKey);
    UErrCodeT Count(UIntT *aNum);
    UErrCodeT Clear();

    // Iterator.
    UHandleT Iterator();
    UErrCodeT Head(USequenceCodeT aCode);
    UErrCodeT Tail();
    UErrCodeT Next();
    UErrCodeT Prev();
    UErrCodeT State();
    ContentT *Content();
    const KeyT *Key();
    UErrCodeT Del();

 protected:
 private:
    UErrCodeT Lock();
    UErrCodeT Unlock();
    UContainerCodeT mCode;
    CCcsListCtl<ContentT> *mList;
    CCcsMapCtl<ContentT, KeyT> *mMap;
    ULockCodeT mRwLock;
    UHandleT mIt;
};

/* Implementation for "CCcsContainerCtl". */
#include "ust_iteratortype.hpp"
#include "ust_containerctl_cpp.hpp"

#endif  /* UST_CONTAINERCTL_HPP_INCLUDED */