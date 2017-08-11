/******************************************************************************
 * $Id: cls_base.h 2016-08 $
 *
 * Project:  C language standard library.
 * Purpose:  Base definition.
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

#ifndef CLS_BASE_H_INCLUDED
#define CLS_BASE_H_INCLUDED

#include "hub_base.h"
/* base. */
#include "base_macrodefn.hpp"

#define CLS_LIB HUB_LIB

/* Macro. */

#define CLS_CTL(aCtl)                           \
    BMD_CORE_CTL(coreCtl);                      \
    CClsCtl *aCtl = coreCtl->Cls();

#define CLS_TYPE_CTL(aCtl)                      \
    {                                           \
        CLS_CTL(clsCtl);                        \
        aCtl = clsCtl->Type();                  \
    }


/* File. */

typedef UHandleT ClsFileHT;

typedef enum
{
    ClsFileOperR   = 1,          /* Read. */
    ClsFileOperRt  = 2,          /* Read/Test. */
    ClsFileOperRb  = 3,          /* Read/Bit. */
    ClsFileOperW   = 21,         /* Write. */
    ClsFileOperWt  = 22,         /* Write/Test. */
    ClsFileOperWta = 23,        /* Write/Text/Add. */
    ClsFileOperWb  = 25,         /* Write/Bit. */
    ClsFileOperWba = 26,         /* Write/Bit/Add. */
} ClsFileOperCodeT;

/* Time. */
typedef UHandleT ClsTimeHT;
typedef UHandleT ClsTmHT;

#endif  /* CLS_BASE_H_INCLUDED */
