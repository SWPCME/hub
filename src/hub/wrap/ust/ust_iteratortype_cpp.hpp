/******************************************************************************
 * $Id: ust_iteratortype_cpp.hpp 2017-05 $
 *
 * Project:  Universal structure library.
 * Purpose:  Iterator type definition.
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

#ifndef UST_ITERATORTYPE_CPP_HPP_INCLUDED
#define UST_ITERATORTYPE_CPP_HPP_INCLUDED

#include "ust_iteratortype.hpp"

/**
 * \brief Constructor.
 */
template <typename ContentT, typename KeyT>
UIteratorT<ContentT, KeyT>::UIteratorT()
{
}

/**
 * \brief Destructor.
 */
template <typename ContentT, typename KeyT>
UIteratorT<ContentT, KeyT>::~UIteratorT()
{
}

/**
 * \brief Initialize.
 */
template <typename ContentT, typename KeyT>
UErrCodeT UIteratorT<ContentT, KeyT>::Init(CUstContainerCtl<ContentT, KeyT> *aCtn)
{
    mCtn = aCtn;

    return UErrFalse;
}

/**
 * \brief Goto begin.
 */
template <typename ContentT, typename KeyT>
UErrCodeT UIteratorT<ContentT, KeyT>::Head(const USequenceCodeT aCode)
{
    return mCtn->Head(aCode);
}

/**
 * \brief Goto position that specified.
 */
template <typename ContentT, typename KeyT>
UErrCodeT UIteratorT<ContentT, KeyT>::Goto(const KeyT &aKey)
{
    return mCtn->Goto(&aKey);
}

/**
 * \brief Goto next.
 */
template <typename ContentT, typename KeyT>
UErrCodeT UIteratorT<ContentT, KeyT>::Next()
{
    return mCtn->Next();
}

/**
 * \brief State.
 */
template <typename ContentT, typename KeyT>
UErrCodeT UIteratorT<ContentT, KeyT>::State()
{
    return mCtn->State();
}

/**
 * \brief Content.
 */
template <typename ContentT, typename KeyT>
const ContentT UIteratorT<ContentT, KeyT>::Content()
{
    return *mCtn->Content();
}

/**
 * \brief Key.
 */
template <typename ContentT, typename KeyT>
const KeyT UIteratorT<ContentT, KeyT>::Key()
{
    return *mCtn->Key();
}

/**
 * \brief Add.
 */
template <typename ContentT, typename KeyT>
UErrCodeT UIteratorT<ContentT, KeyT>::Add(const ContentT &aContent, const KeyT &aKey)
{
    return mCtn->Add(&aContent, &aKey);
}

#endif  // UST_ITERATORTYPE_CPP_HPP_INCLUDED
