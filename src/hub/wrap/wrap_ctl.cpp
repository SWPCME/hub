/******************************************************************************
 * $Id: core_ctl.cpp 2016-09 $
 *
 * Project:  Wrap library.
 * Purpose:  Control implemention.
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

#include "wrap_ctl.hpp"

// base
#include "base_macrodefn.hpp"
// wrap
#include "ust_ctl.hpp"
#include "rst_ctl.hpp"
#include "vtr_ctl.hpp"
#include "ncc_ctl.hpp"

/**
 * \brief Constructor.
 */
CWrapCtl::CWrapCtl()
{
    BMD_POINTER_INIT(mUst);
    BMD_POINTER_INIT(mRst);
    BMD_POINTER_INIT(mVtr);
    BMD_POINTER_INIT(mNcc);
}

/**
 * \brief Destructor.
 */
CWrapCtl::~CWrapCtl()
{
    BMD_CLASS_DEL(mUst);
    BMD_CLASS_DEL(mRst);
    BMD_CLASS_DEL(mVtr);
    BMD_CLASS_DEL(mNcc);
}

/**
 * \brief Initialize.
 */
UErrCodeT CWrapCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Ust controler.
 */
CUstCtl *CWrapCtl::Ust()
{
    BMD_CLASS_NEW(mUst, CUstCtl);

    return mUst;
}

/**
 * \brief Rst controler.
 */
CRstCtl *CWrapCtl::Rst()
{
    BMD_CLASS_NEW(mRst, CRstCtl);

    return mRst;
}

/**
 * \brief Vtr controler.
 */
CVtrCtl *CWrapCtl::Vtr()
{
    BMD_CLASS_NEW(mVtr, CVtrCtl);

    return mVtr;
}

/**
 * \brief Ncc controler.
 */
CNccCtl *CWrapCtl::Ncc()
{
    BMD_CLASS_NEW(mNcc, CNccCtl);

    return mNcc;
}

/***** Private A *****/

/***** Private B *****/
