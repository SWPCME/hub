/******************************************************************************
 * $Id: bsn_ctl.hpp 2017-07 $
 *
 * Project:  Business logic library.
 * Purpose:  Business control definition.
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

#ifndef BSN_CTL_HPP_INCLUDED
#define BSN_CTL_HPP_INCLUDED

#include "bsn_base.hpp"

class CBsnCls;
class CBsnGda;
class CBsnOgr;
class CBsnGsl;
class CBsnCut;
class CBsnPlp;

class CBsnUst;
class CBsnRst;
class CBsnNcc;

class CBsnRtk;
class CBsnFmd;
class CBsnQmt;
class CBsnEra;

class CBsnUniqueId;

class BSN_LIB CBsnCtl
{
 public:
    CBsnCtl();
    ~CBsnCtl();

    UErrCodeT Init();

    CBsnCls *Cls();
    CBsnGda *Gda();
    CBsnOgr *Ogr();
    CBsnGsl *Gsl();
    CBsnCut *Cut();
    CBsnPlp *Plp();

    CBsnUst *Ust();
    CBsnRst *Rst();
    CBsnNcc *Ncc();

    CBsnRtk *Rtk();
    CBsnFmd *Fmd();
    CBsnQmt *Qmt();
    CBsnEra *Era();

    CBsnUniqueId *UniqueId();

 protected:
 private:
    UErrCodeT InitPointer();

    CHubCtl *mHub;

    CBsnCls *mCls;
    CBsnGda *mGda;
    CBsnOgr *mOgr;
    CBsnGsl *mGsl;
    CBsnCut *mCut;
    CBsnPlp *mPlp;

    CBsnUst *mUst;
    CBsnRst *mRst;
    CBsnNcc *mNcc;

    CBsnRtk *mRtk;
    CBsnFmd *mFmd;
    CBsnQmt *mQmt;
    CBsnEra *mEra;

    CBsnUniqueId *mUniqueId;
};

#endif  /* BSN_CTL_HPP_INCLUDED */
