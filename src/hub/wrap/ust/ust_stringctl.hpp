/******************************************************************************
 * $Id: ust_stringctl.hpp 2016-08 $
 *
 * Project:  Universal struct library.
 * Purpose:  String control.
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

#ifndef UST_STRINGCTL_HPP_INCLUDED
#define UST_STRINGCTL_HPP_INCLUDED

#include "ust_stringbase.h"

class CClsStringCtl;
class CClsMemoryCtl;

class UST_LIB CUstStringCtl
{
  public:
    CUstStringCtl();
    ~CUstStringCtl();

    // Initialize.
    UErrCodeT Init();

    /* Copy string. */
    char* Cpy(char* aDest, const char* aSrc);
    wchar_t* Cpy(wchar_t* aDest, const wchar_t* aSrc);

    /* Catch string. */
    char* Cat(char* aDest, const char* aSrc);
    wchar_t* Cat(wchar_t* aDest, const wchar_t* aSrc);

    /* Length of string */
    UIntT Len(const char* aStr);
    UIntT Len(const wchar_t* aStr);

    /* Translate */
    UErrCodeT AToW(wchar_t* aDest, const char* aSrc);
    UErrCodeT WToA(char* aDest, const wchar_t* aSrc);

    // Copy string by allocate memory.
    char* MCpy(const char* aStr);
    wchar_t* MCpy(const wchar_t* aStr);

    // Warning: the string of destination must be allocate by MCpy.
    // Catch string by allocate extra memory with destination string.
    char* MCat(char** aDest, const char* aSrc);
    wchar_t* MCat(wchar_t** aDest, const wchar_t* aSrc);

    // Translate string by allocate memory for destination string.
    wchar_t* MAToW(const char* aStr);
    char* MWToA(const wchar_t* aStr);

    // Free string by using the function of "M*".
    UErrCodeT MFree(char* aStr);
    UErrCodeT MFree(char** aStr);
    UErrCodeT MFree(wchar_t* aStr);
    UErrCodeT MFree(wchar_t** aStr);

    // Compare string.
    UErrCodeT Cmp(const char* aDest, const char* aSrc);

 protected:
  private:
    /* Size of string */
    UIntT Size(const char* aStr);
    UIntT Size(const wchar_t* aStr);

    // Allocate memory with size of string.
    char* MAlloc(const char* aStr);
    wchar_t* MAlloc(const wchar_t* aStr);

    // Reallocate memory with size of string.
    char* MRealloc(char* aStr, const char* aRef);
    wchar_t* MRealloc(wchar_t* aStr, const wchar_t* aRef);

    // Cls Library.
    CClsStringCtl* m_str;
    CClsMemoryCtl* m_mem;
};

#endif  /* CMN_STRINGCTL_HPP_INCLUDED */
