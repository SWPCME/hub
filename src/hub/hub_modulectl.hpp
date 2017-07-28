/******************************************************************************
 * $Id: hub_modulectl.hpp 2017-07 $
 *
 * Project:  Hub Library.
 * Purpose:  Module control.
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

#ifndef HUB_MODULECTL_HPP_INCLUDED
#define HUB_MODULECTL_HPP_INCLUDED

#include "hub_base.h"
// ust
#include "ust/ust_containertype.hpp"
// base
#include "base_macrodefn.hpp"

typedef UContainerT<UHandleT, HubCodeT> MHandleCodeT;
typedef UIteratorT<UHandleT, HubCodeT> MHandleCodeItT;

class HUB_LIB CHubModuleCtl
{
 public:
    CHubModuleCtl();
    ~CHubModuleCtl();

    UErrCodeT Init(UFlagCodeT aFlag = UFlagOff);
    UErrCodeT Register(HubCodeT aCode);
    UErrCodeT RegisterAll();
    UErrCodeT Deregister(HubCodeT aCode);
    UErrCodeT DeregisterAll();
    UHandleT Module(HubCodeT aCode);

 protected:
 private:
    UErrCodeT RegisterRegion(HubCodeT aBegin, HubCodeT aEnd);

    UStateCodeT mState;
    MHandleCodeT mMCodeH;     /* Register handle. */
};

#endif  /* MODULE_CTL_H_INCLUDED */
