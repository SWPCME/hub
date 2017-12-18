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
#include "bsn_gsl.hpp"
#include "bsn_cut.hpp"
#include "bsn_plp.hpp"
// Wrap.
#include "bsn_ust.hpp"
#include "bsn_rst.hpp"
#include "bsn_ncc.hpp"
// Ctgy.
#include "bsn_rtk.hpp"
#include "bsn_fmd.hpp"
#include "bsn_era.hpp"

CBsnCtl::CBsnCtl()
{
    mHub = CHubCtl::Hub();
    mHub->Init();
    mHub->RegisterAll();

    InitPointer();
}

CBsnCtl::~CBsnCtl()
{
    BMD_CLASS_DEL(mCls);
    BMD_CLASS_DEL(mGda);
    BMD_CLASS_DEL(mGsl);
    BMD_CLASS_DEL(mCut);
    BMD_CLASS_DEL(mPlp);

    BMD_CLASS_DEL(mUst);
    BMD_CLASS_DEL(mRst);
    BMD_CLASS_DEL(mNcc);

    BMD_CLASS_DEL(mRtk);
    BMD_CLASS_DEL(mEra);

    BMD_CLASS_DEL(mUniqueId);

    mHub->DeregisterAll();
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
    BMD_CLASS_NEW(mGsl, CBsnGsl);

    return mGsl;
}

CBsnCut *CBsnCtl::Cut()
{
    BMD_CLASS_NEW(mCut, CBsnCut);

    return mCut;
}

CBsnPlp *CBsnCtl::Plp()
{
    BMD_CLASS_NEW(mPlp, CBsnPlp);

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
    BMD_CLASS_NEW(mNcc, CBsnNcc);

    return mNcc;
}

CBsnUniqueId *CBsnCtl::UniqueId()
{
    BMD_CLASS_NEW(mUniqueId, CBsnUniqueId);

    return mUniqueId;
}

CBsnRtk *CBsnCtl::Rtk()
{
    BMD_CLASS_NEW(mRtk, CBsnRtk);

    return mRtk;
}

CBsnFmd *CBsnCtl::Fmd()
{
    BMD_CLASS_NEW(mFmd, CBsnFmd);

    return mFmd;
}

CBsnEra *CBsnCtl::Era()
{
    BMD_CLASS_NEW(mEra, CBsnEra);

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
