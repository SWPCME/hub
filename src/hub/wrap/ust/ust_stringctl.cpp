/******************************************************************************
 * $Id: ust_stringctl.cpp 2016-08 $
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

#include "ust_stringctl.hpp"

// C Standard Library
#include <string.h>

// Module
#include "base_ctl.hpp"
#include "core_ctl.hpp"
#include "cls_ctl.hpp"
#include "cls_stringctl.hpp"
#include "cls_memoryctl.hpp"

/**
 * \brief Constructor.
 */
CUstStringCtl::CUstStringCtl()
{
}

/**
 * \brief Destructor.
 */
CUstStringCtl::~CUstStringCtl()
{
}

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CUstStringCtl::Init()
{
    CBaseCtl *baseCtl = CBaseCtl::Base();
    CCoreCtl* coreCtl = baseCtl->Core();
    CClsCtl* clsCtl = coreCtl->Cls();
    m_str = clsCtl->Str();
    m_mem = clsCtl->Mem();

    return UErrFalse;
}

/**
 * \brief Get length of string.
 *
 * Get length of string, that the type of string is "char".
 *
 * @param aStr String that process.
 *
 * @return Length of string, if successful; -1, if failed.
 */
UIntT CUstStringCtl::Len(const char* aStr)
{
    UIntT len = m_str->Len(aStr);

    return len;
}

/**
 * \brief Get length of string.
 *
 * Get length of string, that the type of string is "wchar_t".
 *
 * @param aStr String that process.
 *
 * @return Length of string, if successful; -1, if failed.
 */
UIntT CUstStringCtl::Len(const wchar_t* aStr)
{
    return m_str->Len(aStr);
}

/**
 * \brief Copy one string to other.
 *
 * Copy one string to other, that the type of string is "char".
 *
 * @param aDest String of destination.
 * @param aSrc String of source.
 *
 * @return String of destination, if successful; NULL, if failed.
 */
char* CUstStringCtl::Cpy(char* aDest, const char* aSrc)
{
    return m_str->Cpy(aDest, aSrc);
}

/**
 * \brief Copy one string to other.
 *
 * Copy one string to other, that the type of string is "wchar_t".
 *
 * @param aDest String of destination.
 * @param aSrc String of source.
 *
 * @return String of destination, if successful; NULL, if failed.
 */
wchar_t* CUstStringCtl::Cpy(wchar_t* aDest, const wchar_t* aSrc)
{
    return m_str->Cpy(aDest, aSrc);
}

/**
 * \brief Catch one string to other.
 *
 * Catch one string to other, that the type of string is "char".
 *
 * @param aDest String of destination.
 * @param aSrc String of source.
 *
 * @return String of destination, if successful; NULL, if failed.
 */
char* CUstStringCtl::Cat(char* aDest, const char* aSrc)
{
    return m_str->Cat(aDest, aSrc);
}

/**
 * \brief Catch one string to other.
 *
 * Catch one string to other, that the type of string is "wchar_t".
 *
 * @param aDest String of destination.
 * @param aSrc String of source.
 *
 * @return String of destination, if successful; NULL, if failed.
 */
wchar_t* CUstStringCtl::Cat(wchar_t* aDest, const wchar_t* aSrc)
{
    return m_str->Cat(aDest, aSrc);
}

/**
 * \brief Translate string.
 *
 * Translate string from "char" to "wchar_t".
 *
 * @param aDest String of destination.
 * @param aSrc String of source.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CUstStringCtl::AToW(wchar_t* aDest, const char* aSrc)
{
    return m_str->AToW(aDest, aSrc);
}

/**
 * \brief Translate string.
 *
 * Translate string from "wchar_t" to "char".
 *
 * @param aDest String of destination.
 * @param aSrc String of source.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CUstStringCtl::WToA(char* aDest, const wchar_t* aSrc)
{
    return m_str->WToA(aDest, aSrc);
}

char* CUstStringCtl::MCpy(const char* aStr)
{
    char* dest = MAlloc(aStr);

    return Cpy(dest, aStr);
}

wchar_t* CUstStringCtl::MCpy(const wchar_t* aStr)
{
    wchar_t* dest = MAlloc(aStr);

    return Cpy(dest, aStr);
}

char* CUstStringCtl::MCat(char** aDest, const char* aSrc)
{
    *aDest = MRealloc(*aDest, aSrc);

    return Cat(*aDest, aSrc);
}

wchar_t* CUstStringCtl::MCat(wchar_t** aDest, const wchar_t* aSrc)
{
    *aDest = MRealloc(*aDest, aSrc);

    return Cat(*aDest, aSrc);
}

wchar_t* CUstStringCtl::MAToW(const char* aStr)
{
    return NULL;
}

char* CUstStringCtl::MWToA(const wchar_t* aStr)
{
    return NULL;
}

UErrCodeT CUstStringCtl::MFree(char* aStr)
{
    return m_mem->Free((UHandleT) aStr);
}

UErrCodeT CUstStringCtl::MFree(wchar_t* aStr)
{
    return m_mem->Free((UHandleT) aStr);
}

UErrCodeT CUstStringCtl::MFree(char** aStr)
{
    return m_mem->Free((UHandleT*) aStr);
}

UErrCodeT CUstStringCtl::MFree(wchar_t** aStr)
{
    return m_mem->Free((UHandleT*) aStr);
}

UErrCodeT CUstStringCtl::Cmp(const char* aDest, const char* aSrc)
{
    return m_str->Cmp(aDest, aSrc);
}

/***** Private A *****/

UIntT CUstStringCtl::Size(const char* aStr)
{
    UIntT len = (Len(aStr) + 1) * CHAR_SIZE;

    return len;
}

UIntT CUstStringCtl::Size(const wchar_t* aStr)
{
    UIntT len = (Len(aStr) + 1) * WCHAR_SIZE;

    return len;
}

char* CUstStringCtl::MAlloc(const char* aStr)
{
    return (char*) m_mem->Alloc(Size(aStr));
}

wchar_t* CUstStringCtl::MAlloc(const wchar_t* aStr)
{
    return (wchar_t*) m_mem->Alloc(Size(aStr));
}

char* CUstStringCtl::MRealloc(char* aStr, const char* aRef)
{
    return (char*) m_mem->Realloc((UHandleT) aStr, Size(aRef));
}

wchar_t* CUstStringCtl::MRealloc(wchar_t* aStr, const wchar_t* aRef)
{
    return (wchar_t*) m_mem->Realloc((UHandleT) aStr, Size(aRef));
}

/***** Private B *****/
