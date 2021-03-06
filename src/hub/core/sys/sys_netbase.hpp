/******************************************************************************
 * $Id: sys_netbase.hpp 2016-10 $
 *
 * Project:  System library.
 * Purpose:  Net base definition.
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

#ifndef SYS_NETBASE_HPP_INCLUDED
#define SYS_NETBASE_HPP_INCLUDED

#include "sys_base.h"

// Module.
#include "ust_stringtype.hpp"

/**
 * \brief Address families, to be used to communication.
 */
typedef enum
{
    NetAfInet = 1,
    NetAfInet6 = 2,
} NetAfCodeT;

/**
 * \brief Communication specifies.
 */
typedef enum
{
    NetSockRaw = 1,
} NetSockCodeT;

/**
 * \brief Socket address.
 */
typedef struct
{
    UUnsIntT family;
    UStringT data;
} NetSockAddrT;

/**
 * \brief Socket handle.
 */
typedef UIntT NetSockHandleT;

#endif  // SYS_NETBASE_HPP_INCLUDED
