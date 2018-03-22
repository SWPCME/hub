/******************************************************************************
 * $Id: ccs_mapctl.hpp 2017-08 $
 *
 * Project:  C with class standard library.
 * Purpose:  Map control definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016-09 ~ 2017, Weiwei Huang
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

#ifndef CCS_MAPCTL_HPP_INCLUDED
#define CCS_MAPCTL_HPP_INCLUDED

#include "ccs_base.h"
#include <map>
#include <iterator>

template <typename ContentT, typename KeyT>
class CCS_LIB CCcsMapCtl
{
  public:
    CCcsMapCtl();
    CCcsMapCtl(UContainerCodeT aCode);
    ~CCcsMapCtl();

    // Attribute.
    UContainerCodeT Code();
    UstContainerHT Handle();

    UErrCodeT Init(const UContainerCodeT aCode);
    UErrCodeT Add(const ContentT *aContent, const KeyT *aKey);
    UErrCodeT Add(UstContainerHT aHandle);
    UErrCodeT Copy(UstContainerHT aHandle);
    UErrCodeT DelByKey(const KeyT *aKey);
    UErrCodeT Find(const ContentT *aContent);
    UErrCodeT FindByKey(const KeyT *aKey);
    ContentT* Content(const KeyT *aKey);
    UErrCodeT Clear();
    UErrCodeT Count(UIntT *aNum);

    // Traversal.
    UErrCodeT Head(const USequenceCodeT aCode = USequenceOrder);
    UErrCodeT Next();
    UErrCodeT Goto(const KeyT *aKey);
    UErrCodeT State();
    ContentT *Content();
    const KeyT *Key();
    UErrCodeT Del();

  protected:
  private:
    // Type
    typedef typename std::map<KeyT, ContentT>::iterator MapIteratorT;
    typedef typename std::map<KeyT, ContentT>::reverse_iterator MapRIteratorT;

    // Iterator.
    UErrCodeT CheckIt(UHandleT aIt);
    UHandleT It();
    UErrCodeT SetIt(UHandleT aIt);
    UErrCodeT SetIt(MapRIteratorT *aDest, MapRIteratorT *aSrc, UIntT aDist);

    // Distance.
    UErrCodeT Dist(UIntT *aDist, MapIteratorT *aPosA, MapIteratorT *aPosB);
    UErrCodeT DistToHead(UIntT *aDist, MapIteratorT *aPos);
    UErrCodeT DistToTail(UIntT *aDist, MapIteratorT *aPos);
    UErrCodeT Dist(UIntT *aDist, MapRIteratorT *aPosA, MapRIteratorT *aPosB);
    UErrCodeT DistToRHead(UIntT *aDist, MapIteratorT *aPos);
    UErrCodeT DistToRTail(UIntT *aDist, MapIteratorT *aPos);

    // Free
    UErrCodeT Free();
    UErrCodeT FreeContent();
    UErrCodeT FreeKey();

    // Code.
    UContainerCodeT mCode;

    // Handle
    std::map<KeyT, ContentT> mMap;
    MapIteratorT mIt;
    MapRIteratorT mRIt;
    USequenceCodeT mItCode;
};

// Map control implementation.
#include "ccs_mapctl_cpp.hpp"

#endif  // CCS_MAPCTL_HPP_INCLUDED
