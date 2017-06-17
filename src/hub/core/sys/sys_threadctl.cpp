/******************************************************************************
 * $Id: sys_threadctl.cpp 2016-09 $
 *
 * Project:  System library.
 * Purpose:  Thread control implemention.
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

#include "sys_threadctl.hpp"

// Module.
#include "sys_threadattrctl.hpp"

/**
 * \brief Constructor.
 */
CSysThreadCtl::CSysThreadCtl(ThreadHandleT* aHandle)
{
    m_attr = new CSysThreadAttrCtl;
    Init(aHandle);
}

/**
 * \brief Destructor.
 */
CSysThreadCtl::~CSysThreadCtl()
{
    delete m_attr;
}

/**
 * \brief Attribute.
 */
CSysThreadAttrCtl* CSysThreadCtl::Attr()
{
    return m_attr;
}

/***** Private A *****/

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CSysThreadCtl::Init(ThreadHandleT* aHandle)
{
    m_handle = aHandle;

    return UErrFalse;
}

/**
 * \brief Join thread.
 */
// UErrCodeT CSysThreadCtl::Join()
// {
//     return UErrFalse;
// }

/***** Private B *****/
