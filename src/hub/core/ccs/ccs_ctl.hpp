/******************************************************************************
 * $Id: ccs_ctl.hpp 2016-09 $
 *
 * Project:  C with class standard library.
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

#ifndef CCS_CTL_HPP_INCLUDED
#define CCS_CTL_HPP_INCLUDED

#include "ccs_base.h"

// hub
class CHubModuleCtl;
// ccs
class CCcsTypeCtl;

class CCS_LIB CCcsCtl
{
  public:
    CCcsCtl(CHubModuleCtl *aModule);
    ~CCcsCtl();

    UErrCodeT Init();
    CHubModuleCtl *Up();

    CCcsTypeCtl* Type();

  protected:
  private:
    CHubModuleCtl *mModule;
    CCcsTypeCtl *mType;
};

#endif  // CCS_CTL_HPP_INCLUDED
