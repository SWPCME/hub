/******************************************************************************
 * $Id: cls_stringctl.cpp 2017-07 $
 *
 * Project:  C language standard library.
 * Purpose:  String controler implementation.
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

#include "cls_stringctl.hpp"

// libc
#include <string.h>

// cls
// #include "cls_stringcollation.hpp"
// #include "cls_stringlength.hpp"
#include "cls_stringtoken.hpp"
#include "cls_stringsrch.hpp"
// #include "cls_stringcopy.hpp"

/**
 * \brief Constructor
 */
CClsStringCtl::CClsStringCtl()
{
    BMD_POINTER_INIT(mToken);
    BMD_POINTER_INIT(mSrch);
}

/**
 * \brief Destructor
 */
CClsStringCtl::~CClsStringCtl()
{
    BMD_CLASS_DEL(mToken);
    BMD_CLASS_DEL(mSrch);
}

/**
 * \brief Initialize
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CClsStringCtl::Init()
{
    return UErrFalse;
}


// /**
//  * \brief String length.
//  */
// CClsStringLength *CClsStringCtl::Length()
// {
//     return mLength;
// }

/**
 * \brief Finding tokens in a string.
 */
CClsStringToken *CClsStringCtl::Token()
{
    BMD_CLASS_NEW(mToken, CClsStringToken);

    return mToken;
}

/**
 * \brief Search sting on strings.
 */
CClsStringSrch *CClsStringCtl::Srch()
{
    BMD_CLASS_NEW(mSrch, CClsStringSrch);

    return mSrch;
}

/**
 * \brief Get length of string with "char" type.
 *
 * @param aStr The string that to get its length.
 *
 * @return Length of string.
 */
UIntT CClsStringCtl::Len(const char* aStr)
{
    if (aStr == NULL)
    {
        return -1;
    }

    return strlen(aStr);
}

/**
 * \brief Get length of string with "wchar_t" type.
 *
 * @param aStr The string that to get its length.
 *
 * @return Length of string.
 */
UIntT CClsStringCtl::Len(const wchar_t* aStr)
{
    return wcslen(aStr);
}

/**
 * \brief Copy string.
 *
 * Copy string, from "char" to "char".
 *
 * @param aDest The string what you want to fetch.
 * @param aSrc The string what you want to copy.
 *
 * @return String what you want to fetch.
 */
char* CClsStringCtl::Cpy(char* aDest, const char* aSrc)
{
    return strcpy(aDest, aSrc);
}

/**
 * \brief Copy string.
 *
 * Copy String, from "wchar_t" to "wchar_t".
 * 
 * @param aDest The string what you want to fetch.
 * @param aSrc The string what you want to copy.
 *
 * @return The string what you want to fetch.
 */
wchar_t* CClsStringCtl::Cpy(wchar_t* aDest, const wchar_t* aSrc)
{
    return wcscpy(aDest, aSrc);
}

/**
 * \brief To translate "char" to "wchar_t".
 *
 * @param aDest The string what you want to fetch.
 * @param aSrc The string what you want to translate.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CClsStringCtl::AToW(wchar_t* aDest, const char* aSrc)
{
    return UErrFalse;
}

/**
 * \brief Catch string.
 */
char* CClsStringCtl::Cat(char* aDest, const char* aSrc)
{
    return strcat(aDest, aSrc);
}

/**
 * \brief Catch string.
 */
wchar_t* CClsStringCtl::Cat(wchar_t* aDest, const wchar_t* aSrc)
{
    return NULL;
}

/**
 * \brief Compare string.
 */
UErrCodeT CClsStringCtl::Cmp(const char* aDest, const char* aSrc)
{
    if (strcmp(aDest, aSrc) == 0)
    {
        return UErrFalse;
    }

    return UErrTrue;
}

/**
 * \brief Compare two string using locale.
 */
BMathNumSignCodeT CClsStringCtl::Coll(const char *aDest, const char *aSrc)
{
    UIntT sign = strcoll(aDest, aSrc);
    if (sign == 0)
    {
        return BMathNumSignNull;
    }
    if (sign < 0)
    {
        return BMathNumSignNeg;
    }
    if (sign > 0)
    {
        return BMathNumSignPos;
    }

    return BMathNumSignNull;
}

/**
 * \brief To translate "wchar_t" to "char".
 *
 * @param aDest The string what you want to fetch.
 * @param aSrc The string what you want to translate.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CClsStringCtl::WToA(char* aDest, const wchar_t* aSrc)
{
    return UErrFalse;
}

/***** Private A *****/

/***** Private B *****/
