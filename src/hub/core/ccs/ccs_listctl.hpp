/******************************************************************************
 * $Id: ccs_listctl.hpp 2017-07 $
 *
 * Project:  C with class standard library.
 * Purpose:  List control.
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

#ifndef CCS_LISTCTL_HPP_INCLUDED
#define CCS_LISTCTL_HPP_INCLUDED

#include "ccs_base.h"

// C++ standard library.
#include <list>

template <typename ContentT>
class CCS_LIB CCcsListCtl
{
 public:
    CCcsListCtl();
    CCcsListCtl(UContainerCodeT aCode);
    ~CCcsListCtl();

    UErrCodeT Init(UContainerCodeT aCode);

    // Attribute
    UContainerCodeT Code();
    UstContainerHT Handle();

    UErrCodeT Add(const ContentT* aContent);
    UErrCodeT Add(UstContainerHT aHandle);
    UErrCodeT Del(const ContentT *aContent);
    UErrCodeT DelByKey(const UIntT *aKey);
    UErrCodeT Copy(UstContainerHT aHandle);
    UErrCodeT Find(const ContentT* aContent);
    UErrCodeT FindByKey(const UIntT* aKey);
    ContentT* Content(const UIntT* aKey);
    UErrCodeT Count(UIntT *aNum);
    UErrCodeT Clear();

    // Traversal.
    UErrCodeT Head(USequenceCodeT aCode = USequenceOrder);
    UErrCodeT Next();
    UErrCodeT State();
    ContentT *Content();
    UIntT *Key();
    UErrCodeT Del();

 protected:
 private:
    // Type.
    typedef typename std::list<ContentT>::iterator ListIteratorT;
    typedef typename std::list<ContentT>::reverse_iterator ListRIteratorT;

    // Check
    UErrCodeT CheckIt(UHandleT aIt);
    UHandleT It();

    // Free.
    UErrCodeT Free();

    // Code.
    UContainerCodeT mCode;
    // Handle.
    std::list<ContentT> mList;
    ListIteratorT mIt;
    ListRIteratorT mRIt;
    USequenceCodeT mItCode;
};

// C with class standard list control implementation.
#include "ccs_listctl_cpp.hpp"

#endif  // CCS_LISTCTL_HPP_INCLUDED
