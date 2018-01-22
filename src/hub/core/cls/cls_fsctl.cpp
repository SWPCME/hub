/******************************************************************************
 * $Id: cls_fsctl.cpp 2018-01 $
 *
 * Project:  C language standard library.
 * Purpose:  File system controler implemention.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2018-01 ~ 2018, Weiwei Huang
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

#include "cls_fsctl.hpp"

// cls
#include "cls_fsattr.hpp"
#include "cls_fswork.hpp"
#include "cls_fsaccess.hpp"
#include "cls_fscreate.hpp"
#include "cls_fsdelete.hpp"

/**
 * \brief Constructor.
 */
CClsFsCtl::CClsFsCtl()
{
    BMD_POINTER_INIT(mAttr);
    BMD_POINTER_INIT(mWork);
    BMD_POINTER_INIT(mAccess);
    BMD_POINTER_INIT(mCreate);
    BMD_POINTER_INIT(mDelete);
}

/**
 * \brief Destructor.
 */
CClsFsCtl::~CClsFsCtl()
{
    BMD_CLASS_DEL(mAttr);
    BMD_CLASS_DEL(mWork);
    BMD_CLASS_DEL(mAccess);
    BMD_CLASS_DEL(mCreate);
    BMD_CLASS_DEL(mDelete);
}

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CClsFsCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Attribute.
 */
CClsFsAttr *CClsFsCtl::Attr()
{
    BMD_CLASS_NEW(mAttr, CClsFsAttr);

    return mAttr;
}

/**
 * \brief Working directory.
 */
CClsFsWork *CClsFsCtl::Work()
{
    BMD_CLASS_NEW(mWork, CClsFsWork);

    return mWork;
}

/**
 * \brief Accessing directory.
 */
CClsFsAccess *CClsFsCtl::Access()
{
    BMD_CLASS_NEW(mAccess, CClsFsAccess);

    return mAccess;
}

/**
 * \brief Creating for file system.
 */
CClsFsCreate *CClsFsCtl::Create()
{
    BMD_CLASS_NEW(mCreate, CClsFsCreate);

    return mCreate;
}

/**
 * \brief Delete for file system.
 */
CClsFsDelete *CClsFsCtl::Delete()
{
    BMD_CLASS_NEW(mDelete, CClsFsDelete);

    return mDelete;
}
