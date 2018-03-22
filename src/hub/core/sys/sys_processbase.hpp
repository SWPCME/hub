/******************************************************************************
 * $Id: sys_processbase.hpp 2016-09 $
 *
 * Project:  System library.
 * Purpose:  Process base definition.
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

#ifndef SYS_PROCESSBASE_HPP_INCLUDED
#define SYS_PROCESSBASE_HPP_INCLUDED

#include "sys_base.h"
#include "ust_stringtype.hpp"

/**
 * \brief Thread identifier.
 */
typedef UUnsIntT ThreadIdT;

/**
 * \brief Thread attributes.
 */
typedef UHandleT ThreadAttrHT;

/**
 * \brief Posix thread attributes handle.
 */
typedef UHandleT PThreadAttrHT;

/**
 * \brief Thread function handle.
 */
typedef void* (*ThreadFuncHT) (void*);

/**
 * \brief Thread function argument.
 */
typedef void* ThreadFuncAT;

/*
 * \brief Thread function type.
 */
typedef struct
{
    ThreadFuncHT handle;
    ThreadFuncAT arg;
} ThreadFuncT;

/**
 * \brief Thread handle type.
 */
typedef struct
{
    ThreadIdT id;
    ThreadAttrHT attr;
    ThreadFuncT func;
} ThreadHandleT;

#endif  /* SYS_PROCESSBASE_HPP_INCLUDED */
