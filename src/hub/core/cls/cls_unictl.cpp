/******************************************************************************
 * $Id: cls_unictl.cpp 2016-08 $
 *
 * Project:  C language standard library.
 * Purpose:  Universal controler implemention.
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

#include "cls_unictl.hpp"

// C Standard Library
#include <unistd.h>

/**
 * \brief Constructor.
 */
CClsUniCtl::CClsUniCtl()
{
}

/**
 * \brief Destructor.
 */
CClsUniCtl::~CClsUniCtl()
{
}

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CClsUniCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Get current work directory.
 *
 * @return Const string which is current work directory.
 */
UErrCodeT CClsUniCtl::Cwd(UStringT* aStr)
{
    char path[kNMax];
    getcwd(path, kNMax);
    *aStr = path;

    return UErrFalse;
}

/**
 * \brief Sleep.
 *
 * @param aInterval Interval.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CClsUniCtl::Sleep(UIntT aInterval)
{
    sleep(aInterval);

    return UErrFalse;
}
