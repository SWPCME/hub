/******************************************************************************
 * $Id: cls_stringctl.hpp 2016-08 $
 *
 * Project:  C language standard library.
 * Purpose:  C standard string control.
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

#ifndef CLS_STRINGCTL_HPP_INCLUDED
#define CLS_STRINGCTL_HPP_INCLUDED

#include "cls_base.h"
#include "base_mathtype.hpp"

// cls
class CClsStringToken;

class CLS_LIB CClsStringCtl
{
 public:
    CClsStringCtl();
    ~CClsStringCtl();

    // Initialize.
    UErrCodeT Init();

    // Controler.
    CClsStringToken *Token();

    /* Length of string */
    UIntT Len(const char* aStr);
    UIntT Len(const wchar_t* aStr);

    /* Copy string. */
    char* Cpy(char* aDest, const char* aSrc);
    wchar_t* Cpy(wchar_t* aDest, const wchar_t* aSrc);

    /* Catch string. */
    char* Cat(char* aDest, const char* aSrc);
    wchar_t* Cat(wchar_t* aDest, const wchar_t* aSrc);

    // Compare string.
    UErrCodeT Cmp(const char* aDest, const char* aSrc);
    BMathNumSignCodeT Coll(const char *aDest, const char *aSrc);

    /* Translate */
    UErrCodeT AToW(wchar_t* aDest, const char* aSrc);
    UErrCodeT WToA(char* aDest, const wchar_t* aSrc);

 protected:
 private:
    CClsStringToken *mToken;
};

#endif  /* CLS_STRINGCTL_HPP_INCLUDED */
