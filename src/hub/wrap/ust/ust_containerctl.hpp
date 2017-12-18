/******************************************************************************
 * $Id: ust_containerctl.hpp 2017-07 $
 *
 * Project:  Universal structure library.
 * Purpose:  Container controler definition.
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

#ifndef UST_CONTAINERCTL_HPP_INCLUDED
#define UST_CONTAINERCTL_HPP_INCLUDED

#include "ust_containerbase.h"

// Module
#include "ccs/ccs_listctl.hpp"
#include "ccs/ccs_mapctl.hpp"

template <typename ContentT, typename KeyT = UIntT>
class UST_LIB CUstContainerCtl
{
 public:
    CUstContainerCtl();
    ~CUstContainerCtl();

    UErrCodeT Init(UContainerCodeT aCode);

    // Attribute.
    UContainerCodeT Code();
    UstContainerHT Handle();

    // Contenter.
    UErrCodeT Add(const ContentT *aContent);
    UErrCodeT Add(const ContentT *aContent, const KeyT *aKey);
    UErrCodeT Add(UstContainerHT aHandle);
    UErrCodeT FindByKey(const KeyT *aKey);
    ContentT *Content(const KeyT *aKey);
    UErrCodeT Count(UIntT *aNum);
    UErrCodeT Copy(UstContainerHT aHandle);
    UErrCodeT Clear();

    // Iterator.
    UHandleT Iterator();
    UErrCodeT Head(const USequenceCodeT aCode);
    UErrCodeT Tail();
    UErrCodeT Next();
    UErrCodeT Prev();
    UErrCodeT Goto(const KeyT *aKey);
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
