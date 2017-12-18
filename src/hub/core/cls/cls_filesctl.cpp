/******************************************************************************
 * $Id: cls_filesctl.cpp 2017-12 $
 *
 * Project:  C language standard library.
 * Purpose:  File system controler implemention.
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

#include "cls_filesctl.hpp"

// cls
#include "cls_fileswork.hpp"
#include "cls_filescreate.hpp"

/**
 * \brief Constructor.
 */
CClsFilesCtl::CClsFilesCtl()
{
    BMD_POINTER_INIT(mWork);
    BMD_POINTER_INIT(mCreate);
}

/**
 * \brief Destructor.
 */
CClsFilesCtl::~CClsFilesCtl()
{
    BMD_CLASS_DEL(mWork);
    BMD_CLASS_DEL(mCreate);
}

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CClsFilesCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Working directory.
 */
CClsFilesWork *CClsFilesCtl::Work()
{
    BMD_CLASS_NEW(mWork, CClsFilesWork);

    return mWork;
}

/**
 * \brief Creating for file system.
 */
CClsFilesCreate *CClsFilesCtl::Create()
{
    BMD_CLASS_NEW(mCreate, CClsFilesCreate);

    return mCreate;
}
