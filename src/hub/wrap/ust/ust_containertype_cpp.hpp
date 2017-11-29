/******************************************************************************
 * $Id: ust_containertype_cpp.hpp 2016-08 $
 *
 * Project:  Universal structure library.
 * Purpose:  Container type.
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

#ifndef UST_CONTAINERTYPE_CPP_HPP_INCLUDED
#define UST_CONTAINERTYPE_CPP_HPP_INCLUDED

#include "ust_containertype.hpp"

/**
 * \brief Constructor.
 */
template <typename ContentT, typename KeyT>
UContainerT<ContentT, KeyT>::UContainerT(const UContainerCodeT aCode)
{
    mCtn = new CUstContainerCtl<ContentT, KeyT>;
    Init(aCode);
}

/**
 * \brief Destructor.
 */
template <typename ContentT, typename KeyT>
UContainerT<ContentT, KeyT>::~UContainerT()
{
    Clear();
    delete mCtn;
}

/**
 * \brief Container code.
 */
template <typename ContentT, typename KeyT>
UContainerCodeT UContainerT<ContentT, KeyT>::Code()
{
    return mCtn->Code();
}

/**
 * \brief Handle.
 */
template <typename ContentT, typename KeyT>
UstContainerHT UContainerT<ContentT, KeyT>::Handle()
{
    return mCtn->Handle();
}

/**
 * \brief Count.
 */
template <typename ContentT, typename KeyT>
UIntT UContainerT<ContentT, KeyT>::Count() const
{
    UIntT num = -1;
    mCtn->Count(&num);

    return num;
}

/**
 * \brief Add content by default key.
 */
template <typename ContentT, typename KeyT>
UErrCodeT UContainerT<ContentT, KeyT>::Add(const ContentT &aContent)
{
    return mCtn->Add(&aContent);
}

/**
 * \brief Add content and key.
 */
template <typename ContentT, typename KeyT>
UErrCodeT UContainerT<ContentT, KeyT>::Add(const ContentT *aContent, const KeyT *aKey)
{
    return mCtn->Add(aContent, aKey);
}

/**
 * \brief Add content and key.
 */
template <typename ContentT, typename KeyT>
UErrCodeT UContainerT<ContentT, KeyT>::Add(const ContentT &aContent, const KeyT &aKey)
{
    return mCtn->Add(&aContent, &aKey);
}

/**
 * \brief Delete item by content.
 */
template <typename ContentT, typename KeyT>
UErrCodeT UContainerT<ContentT, KeyT>::Del(const ContentT &aContent)
{
    return UErrFalse;
}

/**
 * \brief Delete item by key.
 */
template <typename ContentT, typename KeyT>
UErrCodeT UContainerT<ContentT, KeyT>::DelByKey(const KeyT &aKey)
{
    return UErrFalse;
}

/**
 * \brief Find item by content.
 */
template <typename ContentT, typename KeyT>
UErrCodeT UContainerT<ContentT, KeyT>::Find(const ContentT &aContent)
{
    return UErrFalse;
}

/**
 * \brief Find by key.
 */
template <typename ContentT, typename KeyT>
UErrCodeT UContainerT<ContentT, KeyT>::FindByKey(const KeyT* aKey)
{
    return mCtn->FindByKey(aKey);
}

/**
 * \brief Find by key.
 */
template <typename ContentT, typename KeyT>
UErrCodeT UContainerT<ContentT, KeyT>::FindByKey(const KeyT &aKey)
{
    return FindByKey(&aKey);
}

/**
 * \brief Iterator.
 */
template <typename ContentT, typename KeyT>
UIteratorT<ContentT,KeyT> *UContainerT<ContentT, KeyT>::Iterator() const
{
    return ((UIteratorT<ContentT,KeyT> *) mCtn->Iterator());
}

/**
 * \brief Content.
 */
template <typename ContentT, typename KeyT>
ContentT UContainerT<ContentT, KeyT>::Content(const KeyT &aKey)
{
    ContentT* content = mCtn->Content(&aKey);

    return *content;
}

/**
 * \brief Key.
 */
template <typename ContentT, typename KeyT>
const KeyT UContainerT<ContentT, KeyT>::Key(const ContentT &aContent)
{
    return NULL;
}
 
/**
 * \brief Clear.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
template <typename ContentT, typename KeyT>
UErrCodeT UContainerT<ContentT, KeyT>::Clear()
{
    return mCtn->Clear();
}

/**
 * \brief Operator [].
 */
template <typename ContentT, typename KeyT>
ContentT UContainerT<ContentT, KeyT>::operator [](const KeyT &aKey)
{
    ContentT* content = mCtn->Content(&aKey);

    return *content;
}
 
/**
 * \brief Operator =.
 */
template <typename ContentT, typename KeyT>
UErrCodeT UContainerT<ContentT, KeyT>::operator =
(const UContainerT<ContentT, KeyT> &aCtn)
{
    UContainerT<ContentT,KeyT> *ctn = (UContainerT<ContentT,KeyT> *) &aCtn;

    return mCtn->Copy(ctn->Handle());
}

/***** Private A *****/

/**
 * \brief Initialize.
 *
 * To initialize this module, if you to use the "UContainerT()";
 * Not must be to use it, if you use the "UContainerT(UContainerCodeT aCode)";
 * Others, you need to use new mode for this module.
 *
 * @param Code of container that set in this module.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
template <typename ContentT, typename KeyT>
UErrCodeT UContainerT<ContentT, KeyT>::Init(const UContainerCodeT aCode)
{
    return mCtn->Init(aCode);
}

/***** Private B *****/

#endif  // UST_CONTAINERTYPE_CPP_HPP_INCLUDED
