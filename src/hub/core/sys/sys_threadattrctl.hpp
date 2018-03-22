/******************************************************************************
 * $Id: sys_threadattrctl.hpp 2016-09 $
 *
 * Project:  System library.
 * Purpose:  Thread attribute control definition.
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

#ifndef SYS_THREADATTRCTL_HPP_INCLUDED
#define SYS_THREADATTRCTL_HPP_INCLUDED

#include "sys_processbase.hpp"

class SYS_LIB CSysThreadAttrCtl
{
  public:
    CSysThreadAttrCtl();
    ~CSysThreadAttrCtl();

    UErrCodeT Init();
    UErrCodeT Attach(ThreadHandleT* aHandle);
    UErrCodeT Init(ThreadAttrHT aAtrr);
    UErrCodeT Destroy(ThreadAttrHT aAtrr);

  protected:
  private:

    ThreadHandleT* m_handle;
};

#endif  // SYS_THREADATTRCTL_HPP_INCLUDED
