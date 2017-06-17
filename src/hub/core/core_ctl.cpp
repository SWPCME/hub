/******************************************************************************
 * $Id: core_ctl.cpp 2016-09 $
 *
 * Project:  Core library.
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

#include "core_ctl.hpp"

// Module.
#include "cls_ctl.hpp"
#include "sys_ctl.hpp"
#include "ogr_ctl.hpp"
#include "gsl_ctl.hpp"

/**
 * \brief Constructor.
 */
CCoreCtl::CCoreCtl()
{
    mCls = NULL;
    mSys = NULL;
    mOgr = NULL;
    mGsl = NULL;
}

/**
 * \brief Destructor.
 */
CCoreCtl::~CCoreCtl()
{
    if (mCls != NULL)
    {
        delete mCls;
    }

    if (mSys != NULL)
    {
        delete mSys;
    }

    if (mOgr != NULL)
    {
        delete mOgr;
    }

    if (mGsl != NULL)
    {
        delete mGsl;
    }
}

/**
 * \brief Initialize.
 */
UErrCodeT CCoreCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Cls.
 */
CClsCtl *CCoreCtl::Cls()
{
    if (mCls == NULL)
    {
        mCls = new CClsCtl;
        mCls->Init();
    }

    return mCls;
}

/**
 * \brief Sys.
 */
CSysCtl *CCoreCtl::Sys()
{
    if (mSys == NULL)
    {
        mSys = new CSysCtl;
        mSys->Init();
    }

    return mSys;
}

/**
 * \brief Ogr.
 */
COgrCtl *CCoreCtl::Ogr()
{
    if (mOgr == NULL)
    {
        mOgr = new COgrCtl;
        mOgr->Init();
    }

    return mOgr;
}

/**
 * \brief Gsl.
 */
CGslCtl *CCoreCtl::Gsl()
{
    if (mGsl == NULL)
    {
        mGsl = new CGslCtl;
        mGsl->Init();
    }

    return mGsl;
}

/***** Private A *****/

/***** Private B *****/
