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

const UIntT kNInt = 11;
const UIntT kNMax = 10000;

/* Module */
const UIntT kHubCodeCoreBegin = 1;
const UIntT kHubCodeCoreEnd   = 999;
const UIntT kHubCodeWrapBegin = 1001;
const UIntT kHubCodeWrapEnd   = 1999;
const UIntT kHubCodeCtgyBegin = 2001;
const UIntT kHubCodeCtgyEnd   = 2999;

typedef enum
{
    /* Core module */
    HubMCls = 1,                /* C language standard library. */
    HubMCcs = 2,                /* C with class standard library. */
    HubMSys = 3,                /* System library. */
    HubMOgr = 4,                /* OpenGIS Simple Features Reference 
                                   Implementation. */
    HubMGda = 5,                /* Geospatial Data Absraction. */
    HubMGsl = 6,                /* Gnu Scientific Library. */
    HubMCut = 7,                /* Client-side URL Transfer. */
    HubMPlp = 8,                /* PLplot. */

    /* Wrap module */
    HubMUst = 1001,             /* Universal struct type library. */
    HubMRst = 1002,             /* Raster library. */
    HubMVtr = 1003,             /* Vector library. */

    /* Ctgy module */
    // Earth
    /* HubMRtk = 2001,             /\* Real time kinematic library. *\/ */
    // sci/physics
    HubMFmd = 2001,             /* Firemod library. */
    // sci/cesium/terrain/quantized_mesh_tile
    HubMQmt = 2002,             /* Quantized mesh tile. */
    // sci/astronomy
    HubMEra = 2003,             /* Essential routines of fundamental 
                                   astronomy */
} HubCodeT;

/* Universal error code type. */
typedef enum
{
    // Outer.
    UErrNone  = 1,
    UErrError = 0,

    // Iner.
    UErrFalse = 1,
    UErrTrue  = 0,
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
    UDataTNone     = 0,
    UDataTString   = 1,
    UDataTInt      = 2,
    UDataTInt16    = 3,
    UDataTFloat    = 4,
    UDataTFloat32  = 5,
} UDataTCodeT;

/* Universal file oper code type. */
typedef enum
{
    UFileOperCreate = 1,
    UFileOperLoad   = 2,
    UFileOperClose  = 3,
    UFileOperDelete = 4,
} UFileOperCodeT;

/* Universal obj oper code type. */
typedef enum
{
    UObjOperNew = 1,
    UObjOperDel = 2,
} UObjOperCodeT;

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
    ULockOn  = 1,
    ULockOff = 2,
} ULockCodeT;

/* Universal Sequence. */
typedef enum
{
    USequenceOrder   = 1,
    USequenceReverse = 2,
} USequenceCodeT;

#endif  /* HUB_BASE_H_INCLUDED */
