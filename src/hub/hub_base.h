/******************************************************************************
 * $Id: hub_base.h 2016-08 $
 *
 * Project:  Hub.
 * Purpose:  Hub Base.
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

#ifndef HUB_BASE_H_INCLUDED
#define HUB_BASE_H_INCLUDED

/* OS */
/* To use unix as a standard os. */
#if defined(unix) && !defined(UNIX)
#    undef UNIX
#endif

#ifdef UNIX
#    undef WINDOWS
#endif

#if defined(_WIN32) && !defined(WINDOWS)
#    define WINDOWS
#endif

#if defined(_WINDOWS) && !defined(WINDOWS)
#    define WINDOWS
#endif

#ifdef WINDOWS
#    undef UNIX
#endif

/* Compile */
#ifdef GCC
#    undef MSVC
#endif

#if defined(_MSC_VER) && !defined(MSVC)
#    define MSVC
#endif

#ifdef MSVC
#    undef GCC
#endif

/* -------------------------------------------------------------------------- */
/* The following apparently allow you to use functions that judged "unsafe"   */
/* by MSVC                                                                    */
/* -------------------------------------------------------------------------- */
#ifdef MSVC
#    ifndef _CRT_SECURE_NO_DEPRECATE
#        define _CRT_SECURE_NO_DEPRECATE
#    endif
#    ifndef _CRT_NONSTDC_NO_DEPRECATE
#        define _CRT_NONSTDC_NO_DEPRECATE
#    endif
#endif

#ifndef HUB_LIB
#    if defined(GCC)
#        define HUB_LIB __attribute__((visibility("default")))
#    else
#        if defined(MSVC)
#            define HUB_LIB __declspec(dllexport)
#        else
#            define HUB_LIB
#        endif
#    endif
#endif

/* Character */
#ifndef CHARACTER_SET
#define CHAR
#else
#define WCHAR
#endif

// Base module.
/* C standard library. */
#include <wchar.h>
#include <stdint.h>
/* C++ standard library. */
#include <typeinfo>

// Base definition.
#define HUB_CBF                 /* Hub callback function. */
#define CHAR_SIZE sizeof(char)
#define WCHAR_SIZE sizeof(wchar_t)

/* Base type */
/* Character. */
#ifdef CHAR
typedef char UCharT;
#else
typedef wchar_t UCharT;
#endif
/* Integer. */
typedef int64_t UIntT;
typedef uint64_t UUnsIntT;
/* Float. */
typedef double UFloatT;
/* Handle. */
typedef void* UHandleT;
/* Data */
typedef void* UDataT;

const UIntT kNMax = 10000;

const UIntT kHubCodeCoreBegin = -1;
const UIntT kHubCodeCoreEnd   = -7;
const UIntT kHubCodeWrapBegin = 1;
const UIntT kHubCodeWrapEnd   = 1;
const UIntT kHubCodeCtgyBegin = 1000;

typedef enum
{
    /* Core module */
    HubMCls = -1,               /* C language standard library. */
    HubMCcs = -2,               /* C with class standard library. */
    HubMUst = -3,               /* Universal struct type library. */
    HubMSys = -4,               /* System library. */
    HubMOgr = -5,               /* Ogr library. */
    HubMGda = -6,               /* Gda library. */
    HubMGsl = -7,               /* Gsl library. */

    /* Wrap module */
    HubMVtr = 1,                /* Vector library. */

    /* Ctgy module */
    // Earth
    HubMRtk = 1000,             /* Rtk library. */
} HubCodeT;

/* Universal error code type. */
typedef enum
{
    // Outer.
    UErrNone  = 0,
    UErrError = 1,

    // Iner.
    UErrFalse = 0,
    UErrTrue  = 1,
} UErrCodeT;

/* Universal flag code type. */
typedef enum
{
    UFlagOff = 0,
    UFlagOn  = 1,
} UFlagCodeT;

/* Universal state code type. */
typedef enum
{
    UStateOff = 0,
    UStateOn  = 1,
} UStateCodeT;

/* Universal data type code type. */
typedef enum
{
    UDataTNone   = 0,
    UDataTString = 1,
    UDataTInt    = 2,
    UDataTFloat  = 3,
} UDataTCodeT;

/* Universal access code type. */
typedef enum
{
    UAccessRead = 0,
    UAccessWrite = 1,
} UAccessCodeT;

/* Universal geometry type code type. */
typedef enum
{
    UGeometryTNone       = 0,
    UGeometryTPoint      = 1,
    UGeometryTLineString = 2,
    UGeometryTRegion     = 3,
} UGeometryTCodeT;

/* Universal lock code. */
typedef enum
{
    ULockTrue  = 1,
    ULockFalse = 2,
} ULockCodeT;

/* Universal Sequence. */
typedef enum
{
    USequenceOrder   = 1,
    USequenceReverse = 2,
} USequenceCodeT;

#endif  /* HUB_BASE_H_INCLUDED */
