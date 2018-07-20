/******************************************************************************
 * $Id: ust_stringctl.hpp 2018-07 $
 *
 * Project:  Universal struct library.
 * Purpose:  String control.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016-08 ~ 2018, Weiwei Huang
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
#include "base_mathtype.hpp"

// cls
class CClsStringCtl;
class CClsStringToken;
class CClsStringSrch;
class CClsMemoryCtl;
class CClsIoCommonCtl;
class CClsFormatOutput;
// ust
class UStringT;

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
    char* Cat(char* aDest, const UIntT aSrc);
    wchar_t* Cat(wchar_t* aDest, const wchar_t* aSrc);

    /* Length of string */
    UIntT Len(const char* aStr);
    UIntT Len(const wchar_t* aStr);

    /* Translate */
    UErrCodeT AToW(wchar_t* aDest, const char* aSrc);
    UErrCodeT WToA(char* aDest, const wchar_t* aSrc);
    UErrCodeT IToA(char *aDest, const UIntT aSrc);
    UErrCodeT FToA(char *aDest, const UFloatT aSrc);

    // Copy string by allocate memory.
    char* MCpy(const char* aStr);
    wchar_t* MCpy(const wchar_t* aStr);

    // Warning: the string of destination must be allocate by MCpy.
    // Catch string by allocate extra memory with destination string.
    char* MCat(char** aDest, const char* aSrc);
    char* MCat(char** aDest, const UIntT aSrc);
    wchar_t* MCat(wchar_t** aDest, const wchar_t* aSrc);

    // Translate string by allocate memory for destination string.
    wchar_t* MAToW(const char* aStr);
    char* MWToA(const wchar_t* aStr);
    UErrCodeT MIToA(char **aStr, const UIntT aNum);
    UErrCodeT MFToA(char **aStr, const UFloatT aNum);

    // Free string by using the function of "M*".
    UErrCodeT MFree(char* aStr);
    UErrCodeT MFree(char** aStr);
    UErrCodeT MFree(wchar_t* aStr);
    UErrCodeT MFree(wchar_t** aStr);

    // Compare string.
    UErrCodeT Cmp(const char* aDest, const char* aSrc);
    BMathNumSignCodeT Coll(const char *aDest, const char *aSrc);

    // Finding token.
    UErrCodeT Find(char **aDst, char *aSrc, const char *aDelimiters);
    // Check substring needle.
    UErrCodeT Check(const UStringT *aHaystack, const UStringT *aNeedle);

    // Console.
    UErrCodeT ToConsole(const char *aStr);

  protected:
  private:
    /* Size of string */
    UIntT Size(const char* aStr);
    UIntT Size(const wchar_t* aStr);

    // Allocate memory with size of string.
    char* MAlloc(const UDataTCodeT aCode);
    char* MAlloc(const UIntT aNum);
    char* MAlloc(const char* aStr);
    wchar_t* MAlloc(const wchar_t* aStr);

    // Reallocate memory with size of string.
    char *MRealloc(char *aStr, const UIntT aNum);
    char* MRealloc(char* aStr, const char* aRef);
    wchar_t* MRealloc(wchar_t* aStr, const wchar_t* aRef);

    // Cls Library.
    CClsStringCtl* mStr;
    CClsStringToken *mToken;
    CClsStringSrch *mSrch;
    CClsMemoryCtl *mMem;
    CClsIoCommonCtl *mIoCmn;
    CClsFormatOutput *mFmtOut;
};

#endif  /* CMN_STRINGCTL_HPP_INCLUDED */
