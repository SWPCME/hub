/******************************************************************************
 * $Id: ust_stringctl.cpp 2017-08 $
 *
 * Project:  Universal struct library.
 * Purpose:  String control.
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

#include "ust_stringctl.hpp"

// C Standard Library
#include <string.h>

// cls
#include "base_macrodefn.hpp"
#include "base_ctl.hpp"
// core
#include "core_ctl.hpp"
// cls
#include "cls_ctl.hpp"
#include "cls_stringctl.hpp"
#include "cls_stringtoken.hpp"
#include "cls_memoryctl.hpp"
#include "cls_ioctl.hpp"
#include "cls_iocommonctl.hpp"
#include "cls_iostreamctl.hpp"
#include "cls_streamformat.hpp"
#include "cls_formatoutput.hpp"

/**
 * \brief Constructor.
 */
CUstStringCtl::CUstStringCtl()
{
    BMD_POINTER_INIT(mStr);
    BMD_POINTER_INIT(mToken);
    BMD_POINTER_INIT(mMem);
    BMD_POINTER_INIT(mIoCmn);
    BMD_POINTER_INIT(mFmtOut);
}

/**
 * \brief Destructor.
 */
CUstStringCtl::~CUstStringCtl()
{
    BMD_POINTER_INIT(mStr);
    BMD_POINTER_INIT(mToken);
    BMD_POINTER_INIT(mMem);
    BMD_POINTER_INIT(mIoCmn);
    BMD_POINTER_INIT(mFmtOut);
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
    mStr = clsCtl->Str();
    mToken = mStr->Token();
    mMem = clsCtl->Mem();
    CClsIoCtl *ioCtl = clsCtl->Io();
    mIoCmn = ioCtl->Common();
    CClsIoStreamCtl *stream = ioCtl->Stream();
    CClsStreamFormat *format = stream->Format();
    mFmtOut = format->Output();

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
    UIntT len = mStr->Len(aStr);

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
    return mStr->Len(aStr);
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
    return mStr->Cpy(aDest, aSrc);
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
    return mStr->Cpy(aDest, aSrc);
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
    return mStr->Cat(aDest, aSrc);
}

/**
 * \brief Catch number to string.
 *
 * Catch number to string, that the type of string is "char".
 *
 * @param aDest String of destination.
 * @param aSrc Number of source.
 *
 * @return String of destination, if successful; NULL, if failed.
 */
char* CUstStringCtl::Cat(char* aDest, const UIntT aSrc)
{
    char *src;
    MIToA(&src, aSrc);
    aDest = Cat(aDest, src);
    MFree(src);

    return aDest;
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
    return mStr->Cat(aDest, aSrc);
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
    return mStr->AToW(aDest, aSrc);
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
    return mStr->WToA(aDest, aSrc);
}

/**
 * \brief Translate string.
 *
 * Translate string from "UIntT" to "char".
 *
 * @param aDest String of destination.
 * @param aSrc String of source.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CUstStringCtl::IToA(char *aDest, const UIntT aSrc)
{
    return mFmtOut->ToStr(aDest, "%ld", aSrc);
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

/**
 * \brief Catch number to string.
 *
 * Catch number to string, that the type of string is "char".
 *
 * @param aDest String of destination.
 * @param aSrc Number of source.
 *
 * @return String of destination, if successful; NULL, if failed.
 */
char *CUstStringCtl::MCat(char **aDst, const UIntT aSrc)
{
    char *src;
    MIToA(&src, aSrc);
    *aDst = MRealloc(*aDst, sizeof(char) * Len(src));
    *aDst = mStr->Cat(*aDst, src);
    MFree(src);

    return *aDst;
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

/**
 * \brief Integer to char with allocate memory.
 */
UErrCodeT CUstStringCtl::MIToA(char **aStr, const UIntT aNum)
{
    *aStr = MAlloc(kNInt);

    return IToA(*aStr, aNum);
}

UErrCodeT CUstStringCtl::MFree(char* aStr)
{
    return mMem->Free((UHandleT) aStr);
}

UErrCodeT CUstStringCtl::MFree(wchar_t* aStr)
{
    return mMem->Free((UHandleT) aStr);
}

UErrCodeT CUstStringCtl::MFree(char** aStr)
{
    return mMem->Free((UHandleT*) aStr);
}

UErrCodeT CUstStringCtl::MFree(wchar_t** aStr)
{
    return mMem->Free((UHandleT*) aStr);
}

UErrCodeT CUstStringCtl::Cmp(const char* aDest, const char* aSrc)
{
    return mStr->Cmp(aDest, aSrc);
}

BMathNumSignCodeT CUstStringCtl::Coll(const char *aDest, const char *aSrc)
{
    return mStr->Coll(aDest, aSrc);
}

/**
 * \brief Finding tokens.
 */
UErrCodeT CUstStringCtl::Find(char **aDst, char *aSrc, const char *aDelimiters)
{
    return mToken->Find(aDst, aSrc, aDelimiters);
}

UErrCodeT CUstStringCtl::ToConsole(const char *aStr)
{
    return mIoCmn->PrintF("%s\n", aStr);
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

char* CUstStringCtl::MAlloc(const UIntT aNum)
{
    return (char*) mMem->Alloc(aNum);
}

char* CUstStringCtl::MAlloc(const char* aStr)
{
    return (char*) mMem->Alloc(Size(aStr));
}

wchar_t* CUstStringCtl::MAlloc(const wchar_t* aStr)
{
    return (wchar_t*) mMem->Alloc(Size(aStr));
}

/**
 * \brief Reallocate memeory by aNum for aStr.
 */
char *CUstStringCtl::MRealloc(char *aStr, const UIntT aNum)
{
    return (char *) mMem->Realloc((UHandleT) aStr, Size(aStr) + aNum);
}

char* CUstStringCtl::MRealloc(char* aStr, const char* aRef)
{
    return (char*) mMem->Realloc((UHandleT) aStr, Size(aStr) + Size(aRef) - 1);
}

wchar_t* CUstStringCtl::MRealloc(wchar_t* aStr, const wchar_t* aRef)
{
    return (wchar_t*) mMem->Realloc((UHandleT) aStr, Size(aStr) + Size(aRef) - 1);
}

/***** Private B *****/
