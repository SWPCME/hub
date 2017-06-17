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

// Module.
#include "ust_ctl.hpp"
#include "vtr_ctl.hpp"
#include "ncc_ctl.hpp"

/**
 * \brief Constructor.
 */
CWrapCtl::CWrapCtl()
{
    mUst = NULL;
    mVtr = NULL;
    mNcc = NULL;
}

/**
 * \brief Destructor.
 */
CWrapCtl::~CWrapCtl()
{
    if (mUst != NULL)
    {
        delete mUst;
    }

    if (mVtr != NULL)
    {
        delete mVtr;
    }

    if (mNcc != NULL)
    {
        delete mNcc;
    }
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
    if (mUst == NULL)
    {
        mUst = new CUstCtl;
        mUst->Init();
    }

    return mUst;
}

/**
 * \brief Vtr controler.
 */
CVtrCtl *CWrapCtl::Vtr()
{
    if (mVtr == NULL)
    {
        mVtr = new CVtrCtl;
        mVtr->Init();
    }

    return mVtr;
}

/**
 * \brief Ncc controler.
 */
CNccCtl *CWrapCtl::Ncc()
{
    if (mNcc == NULL)
    {
        mNcc = new CNccCtl;
        mNcc->Init();
    }

    return mNcc;
}

/***** Private A *****/

/***** Private B *****/
