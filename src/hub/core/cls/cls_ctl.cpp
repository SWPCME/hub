/******************************************************************************
 * $Id: cls_ctl.cpp 2017-07 $
 *
 * Project:  C language standard library.
 * Purpose:  Controler implementation.
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

#include "cls_ctl.hpp"

// base
#include "base_macrodefn.hpp"
// cls
#include "cls_typectl.hpp"
#include "cls_stringctl.hpp"
#include "cls_memoryctl.hpp"
#include "cls_ioctl.hpp"
#include "cls_filesctl.hpp"
#include "cls_mathctl.hpp"
#include "cls_timectl.hpp"

/**
 * \brief Constructor.
 */
CClsCtl::CClsCtl()
{
    BMD_POINTER_INIT(mType);
    BMD_POINTER_INIT(mStr);
    BMD_POINTER_INIT(mMem);
    BMD_POINTER_INIT(mIo);
    BMD_POINTER_INIT(mFiles);
    BMD_POINTER_INIT(mMath);
    BMD_POINTER_INIT(mTime);
}

/**
 * \brief Destructor.
 */
CClsCtl::~CClsCtl()
{
    BMD_CLASS_DEL(mType);
    BMD_CLASS_DEL(mStr);
    BMD_CLASS_DEL(mMem);
    BMD_CLASS_DEL(mIo);
    BMD_CLASS_DEL(mFiles);
    BMD_CLASS_DEL(mMath);
    BMD_CLASS_DEL(mTime);
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
    BMD_CLASS_NEW(mType, CClsTypeCtl);

    return mType;
}

/**
 * \brief String control.
 *
 * @return Handle of string control.
 */
CClsStringCtl *CClsCtl::Str()
{
    BMD_CLASS_NEW(mStr, CClsStringCtl);

    return mStr;
}

/**
 * \brief Memory control.
 *
 * @return Handle of memory control.
 */
CClsMemoryCtl *CClsCtl::Mem()
{
    BMD_CLASS_NEW(mMem, CClsMemoryCtl);

    return mMem;
}

/**
 * \brief Input and output control.
 *
 * @return Handle of io control.
 */
CClsIoCtl *CClsCtl::Io()
{
    BMD_CLASS_NEW(mIo, CClsIoCtl);

    return mIo;
}

/**
 * \brief File system control.
 *
 * @return Handle of universal control.
 */
CClsFilesCtl *CClsCtl::Files()
{
    BMD_CLASS_NEW(mFiles, CClsFilesCtl);

    return mFiles;
}

/**
 * \brief Mathematical controler.
 */
CClsMathCtl *CClsCtl::Math()
{
    BMD_CLASS_NEW(mMath, CClsMathCtl);

    return mMath;
}

/**
 * \brief Time controler.
 */
CClsTimeCtl *CClsCtl::Time()
{
    BMD_CLASS_NEW(mTime, CClsTimeCtl);

    return mTime;
}
