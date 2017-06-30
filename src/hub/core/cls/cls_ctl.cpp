/******************************************************************************
 * $Id: cls_ctl.cpp 2016-08 $
 *
 * Project:  C language standard library.
 * Purpose:  Controler implementation.
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

#include "cls_ctl.hpp"

// Module
#include "cls_typectl.hpp"
#include "cls_stringctl.hpp"
#include "cls_memoryctl.hpp"
#include "cls_ioctl.hpp"
#include "cls_unictl.hpp"
#include "cls_mathctl.hpp"

/**
 * \brief Constructor.
 */
CClsCtl::CClsCtl()
{
    mType = NULL;
    mStr = NULL;
    mMem = NULL;
    mIo = NULL;
    mUni = NULL;
    mMath = NULL;
}

/**
 * \brief Destructor.
 */
CClsCtl::~CClsCtl()
{
    if (mType != NULL)
    {
        delete mType;
    }

    if (mStr != NULL)
    {
        delete mStr;
    }

    if (mMem != NULL)
    {
        delete mMem;
    }

    if (mIo != NULL)
    {
        delete mIo;
    }

    if (mUni != NULL)
    {
        delete mUni;
    }

    if (mMath != NULL)
    {
        delete mMath;
    }
}

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CClsCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Type controler.
 */
CClsTypeCtl *CClsCtl::Type()
{
    if (mType == NULL)
    {
        mType = new CClsTypeCtl;
        mType->Init();
    }

    return mType;
}

/**
 * \brief String control.
 *
 * @return Handle of string control.
 */
CClsStringCtl *CClsCtl::Str()
{
    if (mStr == NULL)
    {
        mStr = new CClsStringCtl;
        mStr->Init();
    }

    return mStr;
}

/**
 * \brief Memory control.
 *
 * @return Handle of memory control.
 */
CClsMemoryCtl *CClsCtl::Mem()
{
    if (mMem == NULL)
    {
        mMem = new CClsMemoryCtl;
        mMem->Init();
    }

    return mMem;
}

/**
 * \brief Input and output control.
 *
 * @return Handle of io control.
 */
CClsIoCtl *CClsCtl::Io()
{
    if (mIo == NULL)
    {
        mIo = new CClsIoCtl;
        mIo->Init();
    }

    return mIo;
}

/**
 * \brief Universal control.
 *
 * @return Handle of universal control.
 */
CClsUniCtl *CClsCtl::Uni()
{
    if (mUni == NULL)
    {
        mUni = new CClsUniCtl;
        mUni->Init();
    }

    return mUni;
}

/**
 * \brief Mathematical controler.
 */
CClsMathCtl *CClsCtl::Math()
{
    if (mMath == NULL)
    {
        mMath = new CClsMathCtl;
        mMath->Init();
    }

    return mMath;
}
