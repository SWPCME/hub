/******************************************************************************
 * $Id: ust_stringtype.hpp 2018-05 $
 *
 * Project:  Common Library.
 * Purpose:  Universal string struct.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016-08 ~ 2017, Weiwei Huang
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

#ifndef UST_STRINGTYPE_HPP_INCLUDED
#define UST_STRINGTYPE_HPP_INCLUDED

#include "ust_stringbase.h"

// ust
#include "ust_containertype.hpp"

class CUstStringCtl;

class UST_LIB UStringT
{
 public:
    UStringT(void);
    UStringT(const UStringT &aStr);
    UStringT(const UStringT *aStr);
    UStringT(const char *aStr);
    UStringT(const wchar_t *aStr);
    UStringT(const UIntT aNum);
    UStringT(const UFloatT aNum);
    ~UStringT();

    // Attribute.
    UIntT Len();

    // UErrCodeT Add(UIntT aNum, ...);
    UErrCodeT Add(const UStringT *aStr);
    UErrCodeT Add(const char *aStr);
    UErrCodeT Add(const wchar_t *aStr);
    UErrCodeT Del(const char *aStr);
    UErrCodeT Del(const wchar_t *aStr);
    UErrCodeT Find(const char *aStr);
    UErrCodeT Find(const wchar_t *aStr);
    UIntT Count();
    UErrCodeT IsNull() const;
    UErrCodeT Clear();
    const UCharT *ToU();
    const char *ToA() const;
    const wchar_t *ToW();
    UIntT ToI();
    UFloatT ToF();

    // Algorithm.
    UErrCodeT Split(UContainerT<UStringT> *aStringS,
                    const UStringT *aSeparator,
                    const UStringT *aMergeTokens = NULL);

    // Operator.
    UErrCodeT operator =(const char *aStr);
    UErrCodeT operator =(const wchar_t* aStr);
    UErrCodeT operator =(const UStringT &aStr);
    UErrCodeT operator =(const UIntT &aNum);
    UErrCodeT operator =(const UFloatT &aNum);
    UErrCodeT operator ==(const UStringT &aStr);
    UErrCodeT operator ==(const char *aStr);
    UErrCodeT operator !=(const UStringT &aStr);
    UErrCodeT operator !=(const char *aStr);
    UErrCodeT operator <(const UStringT &aStr) const;
    UStringT operator +(const UStringT &aStr);
    UStringT operator +(const char *aStr);
    UStringT operator +(const UIntT aStr);
    UErrCodeT operator +=(const UStringT &aStr);
    UErrCodeT operator +=(const char *aStr);
    UErrCodeT operator +=(const UIntT aNum);

    // Console.
    UErrCodeT ToConsole();

 protected:
 private:
    UErrCodeT Init();

    UErrCodeT SplitString(UContainerT<UStringT> *aStrCtn, const char *aSrcStr,
                          const UStringT *aDelimiters);

    CUstStringCtl* mStr;

    UStateCodeT mState;
    /* Multi format. */
    char *mChar;
    wchar_t *mWchar;
    UIntT mInt;
    UFloatT mFloat;
};

#endif  /* UST_STRINGTYPE_HPP_INCLUDED */
