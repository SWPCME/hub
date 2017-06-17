/******************************************************************************
 * $Id: ui_ctl.cpp 2016-08 $
 *
 * Project:  User Interface.
 * Purpose:  UI Control.
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

#include "ui_ctl.hpp"

// Business logic.
#include "bsn_ctl.hpp"
#include "bsn_gda.hpp"
#include "bsn_gsl.hpp"
#include "bsn_ncc.hpp"
#include "bsn_rtk.hpp"
#include "bsn_uniqueid.hpp"

CUiCtl::CUiCtl()
{
    m_bsn = new CBsnCtl;
}

CUiCtl::~CUiCtl()
{
    delete m_bsn;
}

UErrCodeT CUiCtl::Init()
{
    m_bsn->Init();

    return UErrFalse;
}

UErrCodeT CUiCtl::Main()
{
    Test();

    return UErrFalse;
}

UErrCodeT CUiCtl::Test()
{
    CBsnUniqueId *uniqueId = m_bsn->UniqueId();
    BsnUniqueIdPathT uniqueIdPath;
    uniqueIdPath.in = STR_NULL;
    uniqueIdPath.out = STR_NULL;
    uniqueId->SetPath(&uniqueIdPath);
    // uniqueId->Main();

    CBsnGda *gda = m_bsn->Gda();
    gda->Test();

    CBsnRtk *rtk = m_bsn->Rtk();
    rtk->Test();

    CBsnGsl *gsl = m_bsn->Gsl();
    gsl->Test();

    CBsnNcc *ncc = m_bsn->Ncc();
    ncc->Test();

    return UErrFalse;
}
