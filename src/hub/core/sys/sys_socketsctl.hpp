/******************************************************************************
 * $Id: sys_socketsctl.hpp 2016-10 $
 *
 * Project:  System library.
 * Purpose:  Sockets control definition.
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

#ifndef SYS_SOCKETSCTL_HPP_INCLUDED
#define SYS_SOCKETSCTL_HPP_INCLUDED

#include "sys_netbase.hpp"

// Module.
#include "ust_containertype.hpp"

// Class.
class CSysSocketCtl;

// Define.
typedef UContainerT<CSysSocketCtl*> SysSocketCtnT;

class SYS_LIB CSysSocketsCtl
{
  public:
    CSysSocketsCtl();
    ~CSysSocketsCtl();

    UErrCodeT Init();

    // Create
    UErrCodeT Create(NetAfCodeT aAfCode, NetSockCodeT aSockCode, 
                     UIntT aProtocol);
    UErrCodeT CreatePair();

  protected:
  private:
    SysSocketCtnT m_socketCtn;
};

#endif  // SYS_SOCKETSCTL_HPP_INCLUDED
