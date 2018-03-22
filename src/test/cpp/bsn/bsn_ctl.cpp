/******************************************************************************
 * $Id: bsn_ctl.cpp 2016-08 $
 *
 * Project:  Business logic library.
 * Purpose:  Business control implementation.
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

#include "bsn_ctl.hpp"

// Hub Module.
// Base.
#include "base_macrodefn.hpp"
// Ust.
#include "ust_stringtype.hpp"
#include "ust_containertype.hpp"

// Business Logic
#include "bsn_uniqueid.hpp"
// Core.
#include "bsn_cls.hpp"
#include "bsn_gda.hpp"
#include "bsn_ogr.hpp"
#ifdef HUB_MODULE_PLP
#include "bsn_gsl.hpp"
#include "bsn_cut.hpp"
#include "bsn_plp.hpp"
#endif  // HUB_MODULE_PLP
// Wrap.
#include "bsn_ust.hpp"
#include "bsn_rst.hpp"
#ifdef HUB_MODULE_NCC
#include "bsn_ncc.hpp"
#endif  // HUB_MODULE_NCC
// Ctgy.
// #include "bsn_rtk.hpp"
#include "bsn_fmd.hpp"
#include "bsn_qmt.hpp"
#ifdef HUB_MODULE_ERA
#include "bsn_era.hpp"
#endif  // HUB_MODULE_ERA

CBsnCtl::CBsnCtl()
{
    mHub = CHubCtl::Hub();
    mHub->Init();

    InitPointer();
}

CBsnCtl::~CBsnCtl()
{
    BMD_CLASS_DEL(mCls);
    BMD_CLASS_DEL(mGda);
#ifdef HUB_MODULE_PLP
    BMD_CLASS_DEL(mGsl);
    BMD_CLASS_DEL(mCut);
    BMD_CLASS_DEL(mPlp);
#endif  // HUB_MODULE_PLP

    BMD_CLASS_DEL(mUst);
    BMD_CLASS_DEL(mRst);
#ifdef HUB_MODULE_NCC
    BMD_CLASS_DEL(mNcc);
#endif  // HUB_MODULE_NCC

    BMD_CLASS_DEL(mFmd);
    // BMD_CLASS_DEL(mRtk);
    BMD_CLASS_DEL(mQmt);
#ifdef HUB_MODULE_ERA
    BMD_CLASS_DEL(mEra);
#endif  // HUB_MODULE_ERA

    // BMD_CLASS_DEL(mUniqueId);
}

UErrCodeT CBsnCtl::Init()
{
    return UErrFalse;
}

CBsnCls *CBsnCtl::Cls()
{
    BMD_CLASS_NEW(mCls, CBsnCls);

    return mCls;
}

CBsnGda *CBsnCtl::Gda()
{
    BMD_CLASS_NEW(mGda, CBsnGda);

    return mGda;
}

CBsnOgr *CBsnCtl::Ogr()
{
    BMD_CLASS_NEW(mOgr, CBsnOgr);

    return mOgr;
}

CBsnGsl *CBsnCtl::Gsl()
{
#ifdef HUB_MODULE_GSL
    BMD_CLASS_NEW(mGsl, CBsnGsl);
#endif  // HUB_MODULE_GSL

    return mGsl;
}

CBsnCut *CBsnCtl::Cut()
{
#ifdef HUB_MODULE_CUT
    BMD_CLASS_NEW(mCut, CBsnCut);
#endif  // HUB_MODULE_CUT

    return mCut;
}

CBsnPlp *CBsnCtl::Plp()
{
#ifdef HUB_MODULE_PLP
    BMD_CLASS_NEW(mPlp, CBsnPlp);
#endif  // HUB_MODULE_PLP

    return mPlp;
}

CBsnUst *CBsnCtl::Ust()
{
    BMD_CLASS_NEW(mUst, CBsnUst);

    return mUst;
}

CBsnRst *CBsnCtl::Rst()
{
    BMD_CLASS_NEW(mRst, CBsnRst);

    return mRst;
}

CBsnNcc *CBsnCtl::Ncc()
{
#ifdef HUB_MODULE_NCC
    BMD_CLASS_NEW(mNcc, CBsnNcc);
#endif  // HUB_MODULE_NCC

    return mNcc;
}

CBsnUniqueId *CBsnCtl::UniqueId()
{
    // BMD_CLASS_NEW(mUniqueId, CBsnUniqueId);

    return mUniqueId;
}

CBsnRtk *CBsnCtl::Rtk()
{
    // BMD_CLASS_NEW(mRtk, CBsnRtk);

    return mRtk;
}

CBsnFmd *CBsnCtl::Fmd()
{
    BMD_CLASS_NEW(mFmd, CBsnFmd);

    return mFmd;
}

CBsnQmt *CBsnCtl::Qmt()
{
    BMD_CLASS_NEW(mQmt, CBsnQmt);

    return mQmt;
}

CBsnEra *CBsnCtl::Era()
{
#ifdef HUB_MODULE_ERA
    BMD_CLASS_NEW(mEra, CBsnEra);
#endif  // HUB_MODULE_ERA

    return mEra;
}

/***** Private A *****/

UErrCodeT CBsnCtl::InitPointer()
{
    BMD_POINTER_INIT(mCls);
    BMD_POINTER_INIT(mGda);
    BMD_POINTER_INIT(mOgr);
    BMD_POINTER_INIT(mGsl);
    BMD_POINTER_INIT(mCut);
    BMD_POINTER_INIT(mUst);
    BMD_POINTER_INIT(mNcc);
    BMD_POINTER_INIT(mRtk);
    BMD_POINTER_INIT(mFmd);
    BMD_POINTER_INIT(mEra);
    BMD_POINTER_INIT(mUniqueId);

    return UErrFalse;
}

/***** Private B *****/
