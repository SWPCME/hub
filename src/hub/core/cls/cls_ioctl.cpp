/******************************************************************************
 * $Id: cls_ioctl.hpp 2016-09 $
 *
 * Project:  C language standard library.
 * Purpose:  Input and output control implemention.
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

#include "cls_ioctl.hpp"

// C standard lib.
#include <stdio.h>

// base
#include "base_macrodefn.hpp"
// cls
#include "cls_argctl.hpp"
#include "cls_iocommonctl.hpp"
#include "cls_iostreamctl.hpp"

/**
 * \brief Constructor.
 */
CClsIoCtl::CClsIoCtl()
{
    BMD_POINTER_INIT(mCommon);
    BMD_POINTER_INIT(mStream);
}

/**
 * \brief Destructor.
 */
CClsIoCtl::~CClsIoCtl()
{
    BMD_CLASS_DEL(mCommon);
    BMD_CLASS_DEL(mStream);
}

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CClsIoCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Common Controler.
 */
CClsIoCommonCtl *CClsIoCtl::Common()
{
    BMD_CLASS_NEW(mCommon, CClsIoCommonCtl);

    return mCommon;
}

/**
 * \brief Stream Controler.
 */
CClsIoStreamCtl *CClsIoCtl::Stream()
{
    BMD_CLASS_NEW(mStream, CClsIoStreamCtl);

    return mStream;
}
