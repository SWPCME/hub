/******************************************************************************
 * $Id: ust_filesctl.cpp 2016-08 $
 *
 * Project:  Universal structrue library.
 * Purpose:  File system controler implemention.
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

#include "ust_filesctl.hpp"

// Module.
// Base.
#include "base_ctl.hpp"
// Core control.
#include "core_ctl.hpp"
// Cls control.
#include "cls_ctl.hpp"
#include "cls_unictl.hpp"
// Sys control.
#include "sys_ctl.hpp"
#include "sys_filectl.hpp"
#include "sys_filetwctl.hpp"

/**
 * \brief Constructor.
 */
CUstFilesCtl::CUstFilesCtl()
{
}

/**
 * \brief Destructor.
 */
CUstFilesCtl::~CUstFilesCtl()
{
}

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CUstFilesCtl::Init()
{
    CBaseCtl *baseCtl = CBaseCtl::Base();
    CCoreCtl* coreCtl = baseCtl->Core();

    // Cls control.
    CClsCtl* clsCtl = coreCtl->Cls();
    m_uni = clsCtl->Uni();

    // System control.
    CSysCtl* sysCtl = coreCtl->Sys();
    CSysFileCtl* fileCtl = sysCtl->File();
    m_ftw = fileCtl->Ftw();

    return UErrFalse;
}

/**
 * \brief File tree walk.
 */
UErrCodeT CUstFilesCtl::Ftw(UStringT* aPath)
{
    return m_ftw->Traversal(aPath);
}

/**
 * \brief Get current work directory.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CUstFilesCtl::Cwd(UStringT* aPath)
{
    return m_uni->Cwd(aPath);
}
