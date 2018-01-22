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
    {                                           \
        BMD_CORE_CTL(coreCtl);                  \
        aCtl = coreCtl->Cls();                  \
    }

#define CLS_TYPE_CTL(aCtl)                      \
    {                                           \
        CClsCtl *cls = NULL;                    \
        CLS_CTL(cls);                           \
        aCtl = cls->Type();                     \
    }


/* File. */

typedef UHandleT ClsFileHT;

typedef enum
{
    ClsFileOperRt  = 1,          /* Read/Test. */
    ClsFileOperRta = 2,          /* Read/Test/append. */
    ClsFileOperRb  = 5,          /* Read/Bit. */
    ClsFileOperRba = 6,          /* Read/Bit/append. */
    ClsFileOperWt  = 21,         /* Write/Test. */
    ClsFileOperWtn = 22,         /* Write/Test/New. */
    ClsFileOperWta = 23,         /* Write/Text/Add. */
    ClsFileOperWb  = 25,         /* Write/Bit. */
    ClsFileOperWbn = 26,         /* Write/Bit/New. */
    ClsFileOperWba = 27,         /* Write/Bit/Add. */
} ClsFileOperCodeT;

typedef enum
{
    ClsFsFileTypeUnknown = 0,   /* This type is unknown. */
    ClsFsFileTypeReg     = 1,   /* A regular file. */
    ClsFsFileTypeDir     = 2,   /* A directory. */
} ClsFsFileTypeCodeT;

/* Time. */
typedef UHandleT ClsTimeHT;
typedef UHandleT ClsTmHT;
typedef UHandleT ClsTimeTHT;

#endif  /* CLS_BASE_H_INCLUDED */
