/******************************************************************************
 * $Id: core_ctl.hpp 2016-09 $
 *
 * Project:  Core library.
 * Purpose:  Control definition.
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

#ifndef CORE_CTL_HPP_INCLUDED
#define CORE_CTL_HPP_INCLUDED

#include "core_base.h"

// hub
class CHubModuleCtl;
// core
class CCoreSngCtl;
// module
class CClsCtl;
class CSysCtl;
class CGdaCtl;
class COgrCtl;
class CGslCtl;
class CCutCtl;
class CPlpCtl;
class CPycCtl;

class CORE_LIB CCoreCtl
{
  public:
    CCoreCtl(CHubModuleCtl *aModule);
    ~CCoreCtl();

    UErrCodeT Init();
    // core
    CCoreSngCtl *Sng();
    // module
    CClsCtl *Cls();
    CSysCtl *Sys();
    CGdaCtl *Gda();
    COgrCtl *Ogr();
    CGslCtl *Gsl();
    CCutCtl *Cut();
    CPlpCtl *Plp();
    CPycCtl *Pyc();

  protected:
  private:

    UErrCodeT InitPointer();

    // hub
    CHubModuleCtl *mModule;
    // core
    CCoreSngCtl *mSng;
    CClsCtl *mCls;
    CSysCtl *mSys;
    CGdaCtl *mGda;
    COgrCtl *mOgr;
    CGslCtl *mGsl;
    CCutCtl *mCut;
    CPlpCtl *mPlp;
    CPycCtl *mPyc;
};

#endif  // CORE_CTL_HPP_INCLUDED
