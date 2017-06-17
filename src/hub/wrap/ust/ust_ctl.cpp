/******************************************************************************
 * $Id: ust_ctl.hpp 2016-08 $
 *
 * Project:  Universal structrue library.
 * Purpose:  Controler implemention.
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

#include "ust_ctl.hpp"

// Module.
// Ust control.
#include "ust_stringctl.hpp"
#include "ust_filesctl.hpp"

/**
 * \brief Constructor.
 */
CUstCtl::CUstCtl()
{
    // Group.
    m_group.str = new CUstStringCtl;
    m_group.files = new CUstFilesCtl;
}

/**
 * \brief Destructor.
 */
CUstCtl::~CUstCtl()
{
    // Group.
    delete m_group.files;
    delete m_group.str;
}

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CUstCtl::Init()
{
    m_group.str->Init();
    m_group.files->Init();

    return UErrFalse;
}

/**
 * \brief Get handle of string control.
 *
 * @return Handle of string control.
 */
CUstStringCtl* CUstCtl::Str()
{
    return m_group.str;
}

/**
 * \brief Get handle of file system control.
 *
 * @return Hanle of file system control.
 */
CUstFilesCtl* CUstCtl::Files()
{
    return m_group.files;
}

/***** Private A *****/

/***** Private B *****/
