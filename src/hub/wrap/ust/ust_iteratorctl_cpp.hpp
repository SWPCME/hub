/******************************************************************************
 * $Id: ust_iteratorctl_cpp.hpp 2017-05 $
 *
 * Project:  Universal structure library.
 * Purpose:  Iterator controler implementation.
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

#ifndef UST_ITERATORCTL_CPP_HPP_INCLUDED
#define UST_ITERATORCTL_CPP_HPP_INCLUDED

/**
 * \brief Constructor.
 */
template <typename ContentT, typename KeyT>
CUstIteratorCtl<ContentT, KeyT>::CUstIteratorCtl()
{
}

/**
 * \brief Destructor.
 */
template <typename ContentT, typename KeyT>
CUstIteratorCtl<ContentT, KeyT>::~CUstIteratorCtl()
{
}

/**
 * \brief Initialize.
 */
template <typename ContentT, typename KeyT>
UErrCodeT CUstIteratorCtl<ContentT, KeyT>::Init()
{
    return UErrFalse;
}

/**
 * \brief Content.
 */
template <typename ContentT, typename KeyT>
ContentT CUstIteratorCtl<ContentT, KeyT>::Content()
{
    ContentT ctn;

    return ctn;
}

/**
 * \brief Key.
 */
template <typename ContentT, typename KeyT>
KeyT CUstIteratorCtl<ContentT, KeyT>::Key()
{
    KeyT key;

    return key;
}

/**
 * \brief Goto by key.
 */
template <typename ContentT, typename KeyT>
UErrCodeT CUstIteratorCtl<ContentT, KeyT>::GotoByKey(KeyT &aKey)
{
    return UErrFalse;
}

/**
 * \brief Goto by content.
 */
template <typename ContentT, typename KeyT>
UErrCodeT CUstIteratorCtl<ContentT, KeyT>::Goto(ContentT &aContent)
{
    return UErrFalse;
}

/**
 * \brief Goto begin.
 */
template <typename ContentT, typename KeyT>
UErrCodeT CUstIteratorCtl<ContentT, KeyT>::GotoBegin()
{
    return UErrFalse;
}

/**
 * \brief Goto end.
 */
template <typename ContentT, typename KeyT>
UErrCodeT CUstIteratorCtl<ContentT, KeyT>::GotoEnd()
{
    return UErrFalse;
}

/**
 * \brief Goto next.
 */
template <typename ContentT, typename KeyT>
UErrCodeT CUstIteratorCtl<ContentT, KeyT>::GotoNext()
{
    return UErrFalse;
}

/**
 * \brief Goto previous.
 */
template <typename ContentT, typename KeyT>
UErrCodeT CUstIteratorCtl<ContentT, KeyT>::GotoPrev()
{
    return UErrFalse;
}

/**
 * \brief Check state.
 */
template <typename ContentT, typename KeyT>
UErrCodeT CUstIteratorCtl<ContentT, KeyT>::State()
{
    return UErrFalse;
}

#endif  // UST_ITERATORCTL_CPP_HPP_INCLUDED
