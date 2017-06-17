/******************************************************************************
 * $Id: ust_containerctl_cpp.hpp 2016-08 $
 *
 * Project:  Universal structure library.
 * Purpose:  Container controler implementation.
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

#ifndef UST_CONTAINERCTL_CPP_HPP_INCLUDED
#define UST_CONTAINERCTL_CPP_HPP_INCLUDED

#include "ust_containerctl.hpp"

/**
 * \brief Constructor.
 */
template <typename ContentT, typename KeyT>
CUstContainerCtl<ContentT, KeyT>::CUstContainerCtl()
{
    mIt = NULL;
    mList = NULL;
    mMap = NULL;
}

/**
 * \brief Destructor.
 */
template <typename ContentT, typename KeyT>
CUstContainerCtl<ContentT, KeyT>::~CUstContainerCtl()
{
    if (mIt != NULL)
    {
        delete (UIteratorT<ContentT, KeyT> *) mIt;
    }
    if (mList != NULL)
    {
        delete mList;
    }
    if (mMap != NULL)
    {
        delete mMap;
    }
}

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
template <typename ContentT, typename KeyT>
UErrCodeT CUstContainerCtl<ContentT, KeyT>::Init(UContainerCodeT aCode)
{
    switch (aCode)
    {
    case UContainerMList:
    case UContainerList:
    {
        mCode = UContainerList;
        mList = new CCcsListCtl<ContentT>(aCode);
        break;
    }
    case UContainerMcMap:
    case UContainerMkMap:
    case UContainerMMap:
    case UContainerMap:
    {
        mCode = UContainerMap;
        mMap = new CCcsMapCtl<ContentT, KeyT>(aCode);
        break;
    }
    default:
        break;
    }

    return UErrFalse;
}

/**
 * \brief Add a pair of content by default key.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
template <typename ContentT, typename KeyT>
UErrCodeT CUstContainerCtl<ContentT, KeyT>::Add(const ContentT *aContent)
{
    switch (mCode)
    {
    case UContainerList:
        mList->Add(aContent);
        break;
    default:
        break;
    }

    return UErrFalse;
}

/**
 * \brief Add a pair of content and key.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
template <typename ContentT, typename KeyT>
UErrCodeT CUstContainerCtl<ContentT, KeyT>::Add(const ContentT *aContent, const KeyT *aKey)
{
    switch (mCode)
    {
    case UContainerList:
        return mList->Add(aContent);
    case UContainerMap:
        return mMap->Add(aContent, aKey);
    default:
        return UErrTrue;
    }
}

/**
 * \brief Find by key.
 */
template <typename ContentT, typename KeyT>
UErrCodeT CUstContainerCtl<ContentT, KeyT>::FindByKey(const KeyT *aKey)
{
    switch (mCode)
    {
    case UContainerList:
        return mList->FindByKey((UIntT*) aKey);
    case UContainerMap:
        return mMap->FindByKey(aKey);
    default:
        return UErrTrue;
    }
}

/**
 * \brief Get content with key.
 */
template <typename ContentT, typename KeyT>
ContentT* CUstContainerCtl<ContentT, KeyT>::Content(const KeyT *aKey)
{
  switch (mCode)
  {
    case UContainerList:
        return mList->Content((UIntT*) aKey);
    case UContainerMap:
        return mMap->Content(aKey);
    default:
        return NULL;
    }
}

/**
 * \brief Count.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
template <typename ContentT, typename KeyT>
UErrCodeT CUstContainerCtl<ContentT, KeyT>::Count(UIntT *aNum)
{
    switch (mCode)
    {
    case UContainerList:
        return mList->Count(aNum);
    case UContainerMap:
        return mMap->Count(aNum);
    default:
        return UErrTrue;
    }

    return UErrFalse;
}

/**
 * \brief Clear.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
template <typename ContentT, typename KeyT>
UErrCodeT CUstContainerCtl<ContentT, KeyT>::Clear()
{
    switch (mCode)
    {
    case UContainerList:
        return mList->Clear();
    case UContainerMap:
        return mMap->Clear();
    default:
        return UErrTrue;
    }

    return UErrFalse;
}

/**
 * \brief Iterator.
 */
template <typename ContentT, typename KeyT>
UHandleT CUstContainerCtl<ContentT, KeyT>::Iterator()
{
    if (mIt == NULL)
    {
        mIt = (UHandleT) new UIteratorT<ContentT, KeyT>;
    }

    return mIt;
}

/**
 * \brief Set current site to begin.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
template <typename ContentT, typename KeyT>
UErrCodeT CUstContainerCtl<ContentT, KeyT>::Head(USequenceCodeT aCode)
{
    if (Lock() == UErrTrue)
    {
        return UErrTrue;
    }

    switch (mCode)
    {
    case UContainerList:
        return mList->Head(aCode);
    case UContainerMap:
        return mMap->Head(aCode);
    default:
        return UErrTrue;
    }
}

/**
 * \brief Set current site to end.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
template <typename ContentT, typename KeyT>
UErrCodeT CUstContainerCtl<ContentT, KeyT>::Tail()
{
    if (Unlock() == UErrTrue)
    {
        return UErrTrue;
    }

    switch (mCode)
    {
    case UContainerList:
        return mList->Tail();
    case UContainerMap:
        return mMap->Tail();
    default:
        return UErrTrue;
    }
}

/**
 * \brief Set current site to next.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
template <typename ContentT, typename KeyT>
UErrCodeT CUstContainerCtl<ContentT, KeyT>::Next()
{
    switch (mCode)
    {
    case UContainerList:
        return mList->Next();
    case UContainerMap:
        return mMap->Next();
    default:
        return UErrTrue;
    }
}

/**
 * \brief Set current site to previous.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
template <typename ContentT, typename KeyT>
UErrCodeT CUstContainerCtl<ContentT, KeyT>::Prev()
{
    return UErrFalse;
}

/**
 * \brief State.
 */
template <typename ContentT, typename KeyT>
UErrCodeT CUstContainerCtl<ContentT, KeyT>::State()
{
    switch (mCode)
    {
    case UContainerList:
        return mList->State();
    case UContainerMap:
        return mMap->State();
    default:
        return UErrTrue;
    }

    return UErrFalse;
}

/**
 * \brief Content.
 */
template <typename ContentT, typename KeyT>
ContentT *CUstContainerCtl<ContentT, KeyT>::Content()
{
    switch (mCode)
    {
    case UContainerList:
        return mList->Content();
    case UContainerMap:
        return mMap->Content();
    default:
        return NULL;
    }
}

/**
 * \brief Key.
 */
template <typename ContentT, typename KeyT>
const KeyT *CUstContainerCtl<ContentT, KeyT>::Key()
{
    switch (mCode)
    {
    case UContainerList:
        return NULL;
        // return mList->Key();
    case UContainerMap:
        return mMap->Key();
    default:
        return NULL;
    }
}

/***** Private A *****/

/**
 * \brief Read and write lock.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
template <typename ContentT, typename KeyT>
UErrCodeT CUstContainerCtl<ContentT, KeyT>::Lock()
{
    if (mRwLock == ULockFalse)
    {
        mRwLock = ULockTrue;
        return UErrFalse;
    }

    return UErrTrue;
}

/**
 * \brief Read and write unlock.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
template <typename ContentT, typename KeyT>
UErrCodeT CUstContainerCtl<ContentT, KeyT>::Unlock()
{
    if (mRwLock == ULockTrue)
    {
        mRwLock = ULockFalse;
        return UErrFalse;
    }

    return UErrTrue;
}

/***** Private B *****/

#endif  // UST_CONTAINERCTL_CPP_HPP_INCLUDED
