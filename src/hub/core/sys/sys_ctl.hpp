/******************************************************************************
 * $Id: sys_ctl.hpp 2016-09 $
 *
 * Project:  System library.
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

#ifndef SYS_CTL_HPP_INCLUDED
#define SYS_CTL_HPP_INCLUDED

#include "sys_base.h"

// hub
class CHubModuleCtl;
// sys
class CSysFileCtl;
class CSysProcessCtl;

typedef struct
{
    CSysFileCtl* file;
    CSysProcessCtl* process;
} SysGroupT;

class SYS_LIB CSysCtl
{
  public:
    CSysCtl(CHubModuleCtl *aModule);
    ~CSysCtl();

    UErrCodeT Init();
    CHubModuleCtl *Up();

    // System group.
    CSysFileCtl* File();
    CSysProcessCtl* Process();

  protected:
  private:
    CHubModuleCtl *mModule;
    SysGroupT m_group;
};

#endif  // SYS_CTL_HPP_INCLUDED
