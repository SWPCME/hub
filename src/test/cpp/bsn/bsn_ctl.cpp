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
#include "bsn_gda.hpp"
#include "bsn_gsl.hpp"
#include "bsn_cut.hpp"
// Wrap.
#include "bsn_ncc.hpp"
// Ctgy.
#include "bsn_rtk.hpp"
#include "bsn_fmd.hpp"

CBsnCtl::CBsnCtl()
{
    mHub = CHubCtl::Hub();
    mHub->Init();
    mHub->RegisterAll();

    mGda = NULL;
    mGsl = NULL;
    mCut = NULL;
    mNcc = NULL;
    mRtk = NULL;
    mUniqueId = NULL;
}

CBsnCtl::~CBsnCtl()
{
    BMD_CLASS_DEL(mGda);
    BMD_CLASS_DEL(mGsl);
    BMD_CLASS_DEL(mCut);
    BMD_CLASS_DEL(mNcc);
    BMD_CLASS_DEL(mRtk);
    BMD_CLASS_DEL(mUniqueId);

    mHub->DeregisterAll();
}

UErrCodeT CBsnCtl::Init()
{
    return UErrFalse;
}

CBsnGda *CBsnCtl::Gda()
{
    BMD_CLASS_NEW(mGda, CBsnGda);

    return mGda;
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
