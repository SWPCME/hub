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

// Module
#include "ust_stringtype.hpp"
#include "ust_containertype.hpp"

// Business Logic
#include "bsn_uniqueid.hpp"
// Core.
#include "bsn_gda.hpp"
#include "bsn_rtk.hpp"
#include "bsn_gsl.hpp"
// Wrap.
#include "bsn_ncc.hpp"

CBsnCtl::CBsnCtl()
{
    mHub = CHubCtl::Hub();
    mHub->Init();
    mHub->RegisterAll();

    mGda = NULL;
    mGsl = NULL;
    mNcc = NULL;
    mRtk = NULL;
    mUniqueId = NULL;
}

CBsnCtl::~CBsnCtl()
{
    if (mGda != NULL)
    {
        delete mGda;
    }

    if (mGsl != NULL)
    {
        delete mGsl;
    }

    if (mNcc != NULL)
    {
        delete mNcc;
    }

    if (mRtk != NULL)
    {
        delete mRtk;
    }

    if (mUniqueId != NULL)
    {
        delete mUniqueId;
    }

    mHub->DeregisterAll();
}

UErrCodeT CBsnCtl::Init()
{
    return UErrFalse;
}

CBsnGda *CBsnCtl::Gda()
{
    if (mGda == NULL)
    {
        mGda = new CBsnGda;
        mGda->Init();
    }

    return mGda;
}

CBsnGsl *CBsnCtl::Gsl()
{
    if (mGsl == NULL)
    {
        mGsl = new CBsnGsl;
        mGsl->Init();
    }

    return mGsl;
}

CBsnNcc *CBsnCtl::Ncc()
{
    if (mNcc == NULL)
    {
        mNcc = new CBsnNcc;
        mNcc->Init();
    }

    return mNcc;
}

CBsnUniqueId *CBsnCtl::UniqueId()
{
    if (mUniqueId == NULL)
    {
        mUniqueId = new CBsnUniqueId;
    }

    return mUniqueId;
}

CBsnRtk *CBsnCtl::Rtk()
{
    if (mRtk == NULL)
    {
        mRtk = new CBsnRtk;
        mRtk->Init();
    }

    return mRtk;
}
