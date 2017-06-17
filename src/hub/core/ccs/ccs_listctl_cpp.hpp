/******************************************************************************
 * $Id: ccs_listctl_cpp.hpp 2016-08 $
 *
 * Project:  C with class standard library.
 * Purpose:  List control implementation.
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

#ifndef CCS_LISTCTL_CPP_HPP_INCLUDED
#define CCS_LISTCTL_CPP_HPP_INCLUDED

#include "ccs_listctl.hpp"

/**
 * \brief Constructor.
 */
template <typename ContentT>
CCcsListCtl<ContentT>::CCcsListCtl()
{
}

/**
 * \brief Constructor.
 */
template <typename ContentT>
CCcsListCtl<ContentT>::CCcsListCtl(UContainerCodeT aCode)
{
    Init(aCode);
}

/**
 * \brief Destructor.
 */
template <typename ContentT>
CCcsListCtl<ContentT>::~CCcsListCtl()
{
}

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
template <typename ContentT>
UErrCodeT CCcsListCtl<ContentT>::Init(UContainerCodeT aCode)
{
    mCode = aCode;
    Head();

    return UErrFalse;
}

/**
 * \brief Add content by default key.
 */
template <typename ContentT>
UErrCodeT CCcsListCtl<ContentT>::Add(const ContentT *aContent)
{
    mList.push_back(*aContent);

    return UErrFalse;
}

/**
 * \brief Find content with key.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
template <typename ContentT>
UErrCodeT CCcsListCtl<ContentT>::FindByKey(const UIntT *aKey)
{
    return UErrFalse;
}

/**
 * \brief Get content with key.
 */
template <typename ContentT>
ContentT* CCcsListCtl<ContentT>::Content(const UIntT *aKey)
{
    if (aKey == NULL)
    {
        return &(*mIt);
    }

    Head();
    for (UIntT i = 0; State() == UErrFalse; ++i, Next())
    {
        if (i == *aKey)
        {
            
        }
    }

    return NULL;
}

/**
 * \brief Clear all content in this list.
 */
template <typename ContentT>
UErrCodeT CCcsListCtl<ContentT>::Clear()
{
    Head();
    if (mCode == UContainerMList)
    {
        Free();
    }

    mList.clear();

    return UErrFalse;
}

/**
 * \brief Count.
 */
template <typename ContentT>
UErrCodeT CCcsListCtl<ContentT>::Count(UIntT *aNum)
{
    *aNum = mList.size();

    return UErrFalse;
}

/**
 * \brief Begin of all.
 */
template <typename ContentT>
UErrCodeT CCcsListCtl<ContentT>::Head(USequenceCodeT aCode)
{
    switch (aCode)
    {
    case USequenceOrder:
    {
        mIt = mList.begin();
        mItCode = USequenceOrder;
    }
    case USequenceReverse:
    {
        mRIt = mList.rbegin();
        mItCode = USequenceReverse;
    }
    default:
        return UErrTrue;
    }

    return UErrFalse;
}

/**
 * \brief Set the iterator to next.
 */
template <typename ContentT>
UErrCodeT CCcsListCtl<ContentT>::Next()
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
 * \brief State.
 */
template <typename ContentT>
UErrCodeT CCcsListCtl<ContentT>::State()
{
    switch (mItCode)
    {
    case USequenceOrder:
        if (mIt == mList.end())
        {
            return UErrTrue;
        }
    case USequenceReverse:
        if (mRIt == mList.rend())
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
template <typename ContentT>
ContentT* CCcsListCtl<ContentT>::Content()
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
        content = &(*mIt);
        break;
    case USequenceReverse:
        content = &(*mRIt);
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
template <typename ContentT>
UIntT* CCcsListCtl<ContentT>::Key()
{
    if (CheckIt((UHandleT) &mIt) == UErrTrue)
    {
        return NULL;
    }

    return NULL;
}

/**
 * \brief Delete a pair of content and key with current site.
 *
 * @return Content.
 */
template <typename ContentT>
UErrCodeT CCcsListCtl<ContentT>::Del()
{
    UHandleT it = It();
    if (CheckIt(it) == UErrTrue)
    {
        return UErrTrue;
    }

    switch (mItCode)
    {
    case USequenceOrder:
        mIt = mList.erase(mIt);
        break;
    case USequenceReverse:
        mRIt = mList.erase(mRIt);
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
template <typename ContentT>
UErrCodeT CCcsListCtl<ContentT>::CheckIt(UHandleT aIt)
{    
    switch (mItCode)
    {
    case USequenceOrder:
    {
        if (*((ListIteratorT *) aIt) == mList.end())
        {
            return UErrTrue;
        }
    }
    case USequenceReverse:
    {
        if (*((ListRIteratorT *) aIt) == mList.rend())
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
template <typename ContentT>
UHandleT CCcsListCtl<ContentT>::It()
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
 * \brief Free.
 */
template <typename ContentT>
UErrCodeT CCcsListCtl<ContentT>::Free()
{
    for (Head(); State() == UErrFalse;)
    {
        ContentT* content = Content();
        delete *content;
    }

    return UErrFalse;
}

/***** Private B *****/

#endif  // CCS_LISTCTL_CPP_HPP_INCLUDED
