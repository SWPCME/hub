/******************************************************************************
 * $Id: ui_ctl.cpp 2017-07 $
 *
 * Project:  User Interface.
 * Purpose:  UI Control.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016-08 ~ 2017, Weiwei Huang
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

#include "ui_ctl.hpp"

// Business logic.
#include "bsn_ctl.hpp"
#include "bsn_cls.hpp"
#include "bsn_gda.hpp"
#include "bsn_ogr.hpp"
#include "bsn_gsl.hpp"
#include "bsn_cut.hpp"
#include "bsn_ust.hpp"
#include "bsn_ncc.hpp"
#include "bsn_rtk.hpp"
#include "bsn_fmd.hpp"
#include "bsn_uniqueid.hpp"

CUiCtl::CUiCtl()
{
    mBsn = new CBsnCtl;
}

CUiCtl::~CUiCtl()
{
    delete mBsn;
}

UErrCodeT CUiCtl::Init()
{
    mBsn->Init();

    return UErrFalse;
}

UErrCodeT CUiCtl::Main()
{
    Test();

    return UErrFalse;
}

UErrCodeT CUiCtl::Test()
{
    CBsnUniqueId *uniqueId = mBsn->UniqueId();
    BsnUniqueIdPathT uniqueIdPath;
    uniqueIdPath.in = STR_NULL;
    uniqueIdPath.out = STR_NULL;
    uniqueId->SetPath(&uniqueIdPath);
    // uniqueId->Main();

    CBsnCls *cls = mBsn->Cls();
    cls->Test();

    CBsnGda *gda = mBsn->Gda();
    gda->Test();

    CBsnOgr *ogr = mBsn->Ogr();
    // ogr->Test();

    CBsnRtk *rtk = mBsn->Rtk();
    // rtk->Test();

    CBsnGsl *gsl = mBsn->Gsl();
    gsl->Test();

    CBsnCut *cut = mBsn->Cut();
    // cut->Test();

    CBsnUst *ust = mBsn->Ust();
    ust->Test();

    CBsnNcc *ncc = mBsn->Ncc();
    ncc->Test();

    CBsnFmd *fmd = mBsn->Fmd();
    fmd->Test();

    return UErrFalse;
}
