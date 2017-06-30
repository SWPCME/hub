/******************************************************************************
 * $Id: ccs_mapctl_cpp.hpp 2016-09 $
 *
 * Project:  C with class standard library.
 * Purpose:  Map control implementation.
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

#ifndef CCS_MAPCTL_CPP_HPP_INCLUDED
#define CCS_MAPCTL_CPP_HPP_INCLUDED

#include "ccs_mapctl.hpp"

/**
 * \brief Constructor.
 */
template <typename ContentT, typename KeyT>
CCcsMapCtl<ContentT, KeyT>::CCcsMapCtl()
{
    mCode = 0;
}

/**
 * \brief Constructor.
 */
template <typename ContentT, typename KeyT>
CCcsMapCtl<ContentT, KeyT>::CCcsMapCtl(const UContainerCodeT aCode)
{
    Init(aCode);
}

/**
 * \brief Destructor.
 */
template <typename ContentT, typename KeyT>
CCcsMapCtl<ContentT, KeyT>::~CCcsMapCtl()
{
    Clear();
}

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
template <typename ContentT, typename KeyT>
UErrCodeT CCcsMapCtl<ContentT, KeyT>::Init(const UContainerCodeT aCode)
{
    if (mCode == UContainerMcMap)
    {
        if (typeid(ContentT) == typeid(void*))
        {
            return UErrTrue;
        }
    }

    if (mCode != 0)
    {
        Clear();
    }

    mCode = aCode;
    Head();
        
    return UErrFalse;
}

/**
 * \brief Add a pair of content and key.
 *
 * @return UErrFalse, if successful; UErrFalse, if failed.
 */
template <typename ContentT, typename KeyT>
UErrCodeT CCcsMapCtl<ContentT, KeyT>::Add(const ContentT *aContent, const KeyT *aKey)
{
    mMap.insert(std::pair<KeyT, ContentT>(*aKey, *aContent));

    return UErrFalse;
}

/**
 * \brief Delete a pair of content and key with key.
 *
 * @return Content.
 */
template <typename ContentT, typename KeyT>
UErrCodeT CCcsMapCtl<ContentT, KeyT>::DelByKey(const KeyT *aKey)
{
    MapIteratorT it = mMap.find(*aKey);

    if (it == mMap.end())
    {
        return UErrTrue;
    }

    it = mMap.erase(it);

    return UErrFalse;
}

/**
 * \brief Find content with key.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
template <typename ContentT, typename KeyT>
UErrCodeT CCcsMapCtl<ContentT, KeyT>::FindByKey(const KeyT *aKey)
{
    MapIteratorT it = mMap.find(*aKey);
    if (it == mMap.end())
    {
        return UErrTrue;
    }

    return UErrFalse;
}

/**
 * \brief Get content with key.
 *
 * @return Content.
 */
template <typename ContentT, typename KeyT>
ContentT* CCcsMapCtl<ContentT, KeyT>::Content(const KeyT *aKey)
{
    MapIteratorT it = mMap.find(*aKey);
    if (it == mMap.end())
    {
        return NULL;
    }

    return &it->second;
}

/**
 * \brief Clear.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
template <typename ContentT, typename KeyT>
UErrCodeT CCcsMapCtl<ContentT, KeyT>::Clear()
{
    switch (mCode)
    {
    case UContainerMcMap:
        FreeContent();
        break;
    case UContainerMkMap:
        FreeKey();
        break;
    case UContainerMMap:
        Free();
        break;
    default:
        break;
    }
    mMap.clear();

    return UErrFalse;
}

/**
 * \brief Clear.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
template <typename ContentT, typename KeyT>
UErrCodeT CCcsMapCtl<ContentT, KeyT>::Count(UIntT *aNum)
{
    *aNum = mMap.size();

    return UErrFalse;
}

/**
 * \brief Set the iterator to begin.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
template <typename ContentT, typename KeyT>
UErrCodeT CCcsMapCtl<ContentT, KeyT>::Head(const USequenceCodeT aCode)
{
    switch (aCode)
    {
    case USequenceOrder:
    {
        mIt = mMap.begin();
        mItCode = USequenceOrder;
    }
    case USequenceReverse:
    {
        mRIt = mMap.rbegin();
        mItCode = USequenceReverse;
    }
    default:
        return UErrTrue;
    }

    return UErrFalse;
}

/**
 * \brief Set the iterator to next.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
template <typename ContentT, typename KeyT>
UErrCodeT CCcsMapCtl<ContentT, KeyT>::Next()
{
    UHandleT it = It();
    if (CheckIt(it) == UErrTrue)
    {
        return UErrTrue;
    }

    switch (mItCode)
    {
    case USequenceOrder:
        ++mIt;
        break;
    case USequenceReverse:
        ++mRIt;
        break;
    default:
        return UErrTrue;
    }

    return UErrFalse;
}

/**
 * \brief Goto position that you specified.
 */
template <typename ContentT, typename KeyT>
UErrCodeT CCcsMapCtl<ContentT, KeyT>::Goto(const KeyT *aKey)
{
    MapIteratorT it = mMap.find(*aKey);
    if (it == mMap.end())
    {
        return UErrTrue;
    }

    switch (mItCode)
    {
    case USequenceOrder:
        mIt = it;
        break;
    case USequenceReverse:
    {
        MapRIteratorT rIt = mMap.rbegin();
        UIntT dist;
        DistToRHead(&dist, &it);
        SetIt(&mRIt, &rIt, dist);
        break;
    }
    default:
        return UErrTrue;
    }

    return UErrFalse;
}

/**
 * \brief State.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
template <typename ContentT, typename KeyT>
UErrCodeT CCcsMapCtl<ContentT, KeyT>::State()
{
    switch (mItCode)
    {
    case USequenceOrder:
        if (mIt == mMap.end())
        {
            return UErrTrue;
        }
    case USequenceReverse:
        if (mRIt == mMap.rend())
        {
            return UErrTrue;
        }
    default:
        return UErrTrue;
    }

    return UErrFalse;
}

/**
 * \brief Get content with key.
 *
 * @return Content.
 */
template <typename ContentT, typename KeyT>
ContentT* CCcsMapCtl<ContentT, KeyT>::Content()
{
    UHandleT it = It();
    if (CheckIt(it) == UErrTrue)
    {
        return NULL;
    }

    ContentT *content = NULL;
    switch (mItCode)
    {
    case USequenceOrder:
        content = &(mIt->second);
        break;
    case USequenceReverse:
        content = &(mRIt->second);
        break;
    default:
        break;
    }

    return content;
}

/**
 * \brief Get content with key.
 *
 * @return Content.
 */
template <typename ContentT, typename KeyT>
const KeyT* CCcsMapCtl<ContentT, KeyT>::Key()
{
    UHandleT it = It();
    if (CheckIt(it) == UErrTrue)
    {
        return NULL;
    }

    switch (mItCode)
    {
    case USequenceOrder:
        return &(mIt->first);
    case USequenceReverse:
        return &(mRIt->first);
    default:
        return NULL;
    }
}

/**
 * \brief Delete a pair of content and key with current site.
 *
 * @return Content.
 */
template <typename ContentT, typename KeyT>
UErrCodeT CCcsMapCtl<ContentT, KeyT>::Del()
{
    UHandleT it = It();
    if (CheckIt(it) == UErrTrue)
    {
        return UErrTrue;
    }

    switch (mItCode)
    {
    case USequenceOrder:
        mIt = mMap.erase(mIt);
        break;
    case USequenceReverse:
        mRIt = mMap.erase(mRIt);
        break;
    default:
        return UErrTrue;
    }

    return UErrFalse;
}

/***** Private A *****/

/**
 * \brief Check iterator.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
template <typename ContentT, typename KeyT>
UErrCodeT CCcsMapCtl<ContentT, KeyT>::CheckIt(UHandleT aIt)
{
    switch (mItCode)
    {
    case USequenceOrder:
    {
        if (*((MapIteratorT *) aIt) == mMap.end())
        {
            return UErrTrue;
        }
    }
    case USequenceReverse:
    {
        if (*((MapRIteratorT *) aIt) == mMap.rend())
        {
            return UErrTrue;
        }
    }
    default:
        return UErrTrue;
    }
}

/**
 * \brief Iterator.
 */
template <typename ContentT, typename KeyT>
UHandleT CCcsMapCtl<ContentT, KeyT>::It()
{
    switch (mItCode)
    {
    case USequenceOrder:
        return ((UHandleT) &mIt);
    case USequenceReverse:
        return ((UHandleT) &mRIt);
    default:
        return NULL;
    }
}

/**
 * \brief Set iterator.
 */
template <typename ContentT, typename KeyT>
UErrCodeT CCcsMapCtl<ContentT, KeyT>::SetIt(UHandleT aIt)
{

    switch (mItCode)
    {
    case USequenceOrder:
        mIt = (MapIteratorT) (*aIt);
        break;
    case USequenceReverse:
        mRIt = (MapRIteratorT) (*aIt);
        break;
    default:
        return UErrTrue;
    }

    return UErrFalse;
}

/**
 * \brief Set reverse iterator with distance.
 */
template <typename ContentT, typename KeyT>
UErrCodeT CCcsMapCtl<ContentT, KeyT>::SetIt(MapRIteratorT *aDest,
                                            MapRIteratorT *aSrc,
                                            UIntT aDist)
{
    aDest = aSrc + aDist;

    return UErrFalse;
}

/**
 * \brief Distance with aPosA and aPosB by MapIteratorT.
 */
template <typename ContentT, typename KeyT>
UErrCodeT CCcsMapCtl<ContentT, KeyT>::Dist(UIntT *aDist, MapIteratorT *aPosA,
                                           MapIteratorT *aPosB)
{
    *aDist = std::distance(*aPosA, *aPosB);

    return UErrFalse;
}

/**
 * \brief Distance with aPosA and "Reverse Head" by MapIteratorT.
 */
template <typename ContentT, typename KeyT>
UErrCodeT CCcsMapCtl<ContentT, KeyT>::DistToRHead(UIntT *aDist, MapIteratorT *aPosA)
{
    MapIteratorT tail = mMap.end();

    return Dist(aDist, aPosA, &tail);
}

/**
 * \brief Free all content and key in this map.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
template <typename ContentT, typename KeyT>
UErrCodeT CCcsMapCtl<ContentT, KeyT>::Free()
{
    return UErrFalse;
}

/**
 * \brief Free all content in this map.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
template <typename ContentT, typename KeyT>
UErrCodeT CCcsMapCtl<ContentT, KeyT>::FreeContent()
{
    for (Head(); Next() == UErrFalse;)
    {
        delete mIt->second;
    }

    return UErrFalse;
}

/**
 * \brief Free all key in this map.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
template <typename ContentT, typename KeyT>
UErrCodeT CCcsMapCtl<ContentT, KeyT>::FreeKey()
{
    return UErrFalse;
}

/***** Private B *****/

#endif  // CCS_MAPCTL_CPP_HPP_INCLUDED
