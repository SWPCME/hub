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

// Base.
#include "base_macrodefn.hpp"
// Module.
#include "cls_ctl.hpp"
#include "sys_ctl.hpp"
#include "ogr_ctl.hpp"
#include "gsl_ctl.hpp"
#include "cut_ctl.hpp"

/**
 * \brief Constructor.
 */
CCoreCtl::CCoreCtl()
{
    BMD_POINTER_INIT(mCls);
    BMD_POINTER_INIT(mSys);
    BMD_POINTER_INIT(mOgr);
    BMD_POINTER_INIT(mGsl);
    BMD_POINTER_INIT(mCut);
}

/**
 * \brief Destructor.
 */
CCoreCtl::~CCoreCtl()
{
    BMD_CLASS_DEL(mCls);
    BMD_CLASS_DEL(mSys);
    BMD_CLASS_DEL(mOgr);
    BMD_CLASS_DEL(mGsl);
    BMD_CLASS_DEL(mCut);
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
    BMD_CLASS_NEW(mCls, CClsCtl);

    return mCls;
}

/**
 * \brief Sys.
 */
CSysCtl *CCoreCtl::Sys()
{
    BMD_CLASS_NEW(mSys, CSysCtl);

    return mSys;
}

/**
 * \brief Ogr.
 */
COgrCtl *CCoreCtl::Ogr()
{
    BMD_CLASS_NEW(mOgr, COgrCtl);

    return mOgr;
}

/**
 * \brief Gsl.
 */
CGslCtl *CCoreCtl::Gsl()
{
    BMD_CLASS_NEW(mGsl, CGslCtl);

    return mGsl;
}

/**
 * \brief Cut.
 */
CCutCtl *CCoreCtl::Cut()
{
    BMD_CLASS_NEW(mCut, CCutCtl);

    return mCut;
}

/***** Private A *****/

/***** Private B *****/
