/******************************************************************************
 * $Id: sys_socketsctl.hpp 2016-10 $
 *
 * Project:  System library.
 * Purpose:  Sockets control implemention.
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

#include "sys_socketsctl.hpp"

// GNU C Library, libc.
#include <sys/socket.h>

// Module.
#include "sys_socketctl.hpp"

/**
 * \brief Constructor.
 */
CSysSocketsCtl::CSysSocketsCtl()
{
    m_socketCtn.Init(UContainerList);
}

/**
 * \brief Destructor.
 */
CSysSocketsCtl::~CSysSocketsCtl()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CSysSocketsCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Create a new socket.
 *
 * \param aAfCode Address families.
 * \param aSockCode Communication specifies.
 * \param aProtocol protocol, between 0 and 65555.
 *
 * \return UErrCodeT.
 */
UErrCodeT CSysSocketsCtl::Create(NetAfCodeT aAfCode, NetSockCodeT aSockCode, 
                                 UIntT aProtocol)
{
    int domain = AF_INET;
    int type = SOCK_RAW;
    int protocol = 80;
    int handle = socket(domain, type, protocol);
    CSysSocketCtl* socketCtl = new CSysSocketCtl(handle);
    m_socketCtn.Add(socketCtl);

    return UErrFalse;
}

/**
 * \brief Add a socket.
 */
// UErrCodeT CSysSocketsCtl::Add()
// {
//     return UErrFalse;
// }

/**
 * \brief Del a socket.
 */
// UErrCodeT CSysSocketsCtl::Del()
// {
//     return UErrFalse;
// }
