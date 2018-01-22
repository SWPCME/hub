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

// hub
#include "hub_modulectl.hpp"
// Base.
#include "base_macrodefn.hpp"
// Core.
#include "core_sngctl.hpp"
// Module.
#include "cls_ctl.hpp"
#include "sys_ctl.hpp"
#include "gda_ctl.hpp"
#include "ogr_ctl.hpp"
#ifdef HUB_MODULE_PLP
#include "gsl_ctl.hpp"
#include "cut_ctl.hpp"
#include "plp_ctl.hpp"
#endif  // HUB_MODULE_PLP

/**
 * \brief Constructor.
 */
CCoreCtl::CCoreCtl(CHubModuleCtl *aModule)
{
    InitPointer();
    mModule = aModule;
}

/**
 * \brief Destructor.
 */
CCoreCtl::~CCoreCtl()
{
    InitPointer();
}

/**
 * \brief Initialize.
 */
UErrCodeT CCoreCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Singleton.
 */
CCoreSngCtl *CCoreCtl::Sng()
{
    BMD_CLASS_NEW(mSng, CCoreSngCtl);

    return mSng;
}


/**
 * \brief Cls.
 */
CClsCtl *CCoreCtl::Cls()
{
    BMD_CLASS_NEW_A_1(mCls, CClsCtl, mModule);

    return mCls;
}

/**
 * \brief Sys.
 */
CSysCtl *CCoreCtl::Sys()
{
    BMD_CLASS_NEW_A_1(mSys, CSysCtl, mModule);

    return mSys;
}

/**
 * \brief Gda.
 */
CGdaCtl *CCoreCtl::Gda()
{
    BMD_CLASS_NEW_A_1(mGda, CGdaCtl, mModule);

    return mGda;
}

/**
 * \brief Ogr.
 */
COgrCtl *CCoreCtl::Ogr()
{
    BMD_CLASS_NEW_A_1(mOgr, COgrCtl, mModule);

    return mOgr;
}

/**
 * \brief Gsl.
 */
CGslCtl *CCoreCtl::Gsl()
{
#ifdef HUB_MODULE_GSL
    BMD_CLASS_NEW_A_1(mGsl, CGslCtl, mModule);
#endif  // HUB_MODULE_GSL

    return mGsl;
}

/**
 * \brief Cut.
 */
CCutCtl *CCoreCtl::Cut()
{
#ifdef HUB_MODULE_CUT
    BMD_CLASS_NEW_A_1(mCut, CCutCtl, mModule);
#endif  // HUB_MODULE_CUT

    return mCut;
}

/**
 * \brief Plp.
 */
CPlpCtl *CCoreCtl::Plp()
{
#ifdef HUB_MODULE_PLP
    BMD_CLASS_NEW_A_1(mPlp, CPlpCtl, mModule);
#endif  // HUB_MODULE_PLP

    return mPlp;
}

/***** Private A *****/

/**
 * \brief Init Pointer.
 */
UErrCodeT CCoreCtl::InitPointer()
{
    // core
    BMD_POINTER_INIT(mSng);
    BMD_POINTER_INIT(mCls);
    BMD_POINTER_INIT(mSys);
    BMD_POINTER_INIT(mGda);
    BMD_POINTER_INIT(mOgr);
    BMD_POINTER_INIT(mGsl);
    BMD_POINTER_INIT(mCut);
    BMD_POINTER_INIT(mPlp);

    return UErrFalse;
}

/***** Private B *****/
