/******************************************************************************
 * $Id: string_struct.cpp 2017-07 $
 *
 * Project:  Universal struct library.
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

#include "ust_stringtype.hpp"

// base
#include "base_ctl.hpp"
#include "base_stringdefn.hpp"
// wrap
#include "wrap_ctl.hpp"
// ust
#include "ust_ctl.hpp"
#include "ust_stringctl.hpp"
// cls
#include "cls_argctl.hpp"

/**
 * \brief Constructor.
 */
UStringT::UStringT()
{
    Init();
    mChar = mStr->MCpy(kStrNull);
}

/**
 * \brief Constructor.
 *
 * @param aStr Initialize by "UStringT".
 */
UStringT::UStringT(const UStringT &aStr)
{
    Init();
    mChar = mStr->MCpy(aStr.ToA());
}

/**
 * \brief Constructor.
 *
 * @param aStr Initialize by "UStringT*".
 */
UStringT::UStringT(const UStringT *aStr)
{
    Init();
    mChar = mStr->MCpy(aStr->ToA());
}

/**
 * \brief Constructor.
 *
 * @param aStr Initialize by "char".
 */
UStringT::UStringT(const char *aStr)
{
    Init();
    mChar = mStr->MCpy(aStr);
}

/**
 * \brief Constructor.
 *
 * @param aStr Initialize by "wchar_t".
 */
UStringT::UStringT(const wchar_t *aStr)
{
    Init();
    mChar = mStr->MWToA(aStr);
}

/**
 * \brief Constructor.
 *
 * @param aNum Initialize by "UIntT".
 */
UStringT::UStringT(const UIntT aNum)
{
    Init();
    mStr->MIToA(&mChar, aNum);
}

/**
 * \brief Constructor.
 *
 * @param aNum Initialize by "UFloatT".
 */
UStringT::UStringT(const UFloatT aNum)
{
    Init();
    mStr->MFToA(&mChar, aNum);
}

/**
 * \brief Destructor.
 */
UStringT::~UStringT()
{
    Clear();
}

/**
 * \brief Length of string.
 */
UIntT UStringT::Len()
{
    return mStr->Len(mChar);
}

/**
 * \brief Add new string.
 *
 * @param aStr String that to add in original string.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT UStringT::Add(const UStringT *aStr)
{
    mStr->MCat(&mChar, aStr->ToA());

    return UErrFalse;
}

/**
 * \brief Add new string.
 *
 * @param aStr String of "char" that to add in original string.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT UStringT::Add(const char *aStr)
{
    mStr->MCat(&mChar, aStr);

    return UErrFalse;
}

/**
 * \brief Add "aNum" string.
 *
 * @param aNum Number of string.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
// UErrCodeT UStringT::Add(UIntT aNum, ...)
// {
//     ClsArgListT list;
//     cls_arg_start(list, aNum);
//     for (UIntT i = 0; i < aNum; ++i)
//     {
//         char* val = cls_arg_value(list, char*);
//         mStr->MCat(&mChar, val);
//     }
//     cls_arg_end(list);
    
//     return UErrFalse;
// }

/**
 * \brief Get string with type of "UCharT"
 *
 * @return String that storage of this object.
 */
const UCharT* UStringT::ToU()
{
#ifdef CHAR
    return (UCharT*) ToA();
#else
    return (UCharT*) ToW();
#endif
}

/**
 * \brief Get string with type of "char".
 *
 * @return String that storage of this object.
 */
const char* UStringT::ToA() const
{
    return mChar;
}

/**
 * \brief Get string with type of "wchar_t".
 *
 * @return String that storage of this object.
 */
const wchar_t* UStringT::ToW()
{
    if (mWchar != NULL)
    {
        mStr->MFree(&mWchar);
        mWchar = NULL;
    }
    mWchar = mStr->MAToW(mChar);

    return mWchar;
}

/**
 * \brief Count the string of character.
 */
// UErrCodeT UStringT::Count()
// {
//     return mStr->Len(mChar);
// }

/**
 * \brief This string is null.
 */
UErrCodeT UStringT::IsNull() const
{
    if (mStr->Len(mChar) == 0)
    {
        return UErrFalse;
    }

    return UErrTrue;
}


/**
 * \brief Clear all string in this object.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT UStringT::Clear()
{
    if (mChar != NULL)
    {
        mStr->MFree(mChar);
        mChar = NULL;
    }
    if (mWchar != NULL)
    {
        mStr->MFree(mWchar);
        mWchar = NULL;
    }

    return UErrFalse;
}

/**
 * \brief Split string.
 */
UErrCodeT UStringT::Split(UContainerT<UStringT> *aStrCtn,
                          const UStringT *aDelimiters,
                          const UStringT *aMergeTokens)
{
    SplitString(aStrCtn, mChar, aDelimiters);
    UContainerT<UStringT> strCtn(UContainerList);
    UIteratorT<UStringT> *it = aStrCtn->Iterator();

    for (it->Head(); it->State() == UErrFalse; it->Next())
    {
        UStringT str = it->Content();
        UContainerT<UStringT> tmpStrCtn(UContainerList);
        SplitString(&tmpStrCtn, str.ToA(), aMergeTokens);
        UStringT tmpStr = tmpStrCtn[0];
        if (tmpStr.Len() < str.Len())
        {
            str = tmpStr;
            while (it->Next() == UErrFalse)
            {
                UStringT str2 = it->Content();
                str += kStrSpace;

                UContainerT<UStringT> tmpStrCtn2(UContainerList);
                SplitString(&tmpStrCtn2, str2.ToA(), aMergeTokens);
                UStringT tmpStr2 = tmpStrCtn2[0];
                str += tmpStr2;
                if (tmpStr2.Len() < str2.Len())
                {
                    break;
                }
            }
        }
        strCtn.Add(&str);
    }

    *aStrCtn = strCtn;

    return UErrFalse;
}

/**
 * \brief Overload operator of "=".
 *
 * @param aStr String that need to instead of original string.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT UStringT::operator =(const char *aStr)
{
    mStr->MFree(&mChar);
    mChar = mStr->MCpy(aStr);

    return UErrFalse;
}

/**
 * \brief Overload operator of "=".
 *
 * @param aStr String that need to instead of original string.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT UStringT::operator =(const UStringT& aStr)
{
    mStr->MFree(&mChar);
    mChar = mStr->MCpy(aStr.ToA());

    return UErrFalse;
}

/**
 * \brief Overload operator of "=".
 *
 * @param aStr String that need to instead of original string.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT UStringT::operator =(const UIntT &aNum)
{
    mStr->MFree(&mChar);
    mStr->MIToA(&mChar, aNum);

    return UErrFalse;
}

/**
 * \brief Overload operator of "=".
 *
 * @param aStr String that need to instead of original string.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT UStringT::operator =(const UFloatT &aNum)
{
    mStr->MFree(&mChar);
    mStr->MFToA(&mChar, aNum);

    return UErrFalse;
}

/**
 * \brief Equal.
 */
UErrCodeT UStringT::operator ==(const UStringT &aStr)
{
    if (mStr->Cmp(mChar, aStr.ToA()) == UErrFalse)
    {
        return UErrFalse;
    }

    return UErrTrue;
}

/**
 * \brief Equal.
 */
UErrCodeT UStringT::operator ==(const char *aStr)
{
    if (mStr->Cmp(mChar, aStr) == UErrFalse)
    {
        return UErrFalse;
    }

    return UErrTrue;
}

/**
 * \brief Not Equal.
 */
UErrCodeT UStringT::operator !=(const UStringT &aStr)
{
    if (mStr->Cmp(mChar, aStr.ToA()) == UErrFalse)
    {
        return UErrTrue;
    }

    return UErrFalse;
}

/**
 * \brief Not Equal.
 */
UErrCodeT UStringT::operator !=(const char *aStr)
{
    if (mStr->Cmp(mChar, aStr) == UErrFalse)
    {
        return UErrTrue;
    }

    return UErrFalse;
}

/**
 * \brief Overload operator of "<".
 *
 * Overload operator of "<", that to be used with std::map.
 *
 * @param aStr String that compare with the original string.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT UStringT::operator <(const UStringT& aStr) const
{
    BMathNumSignCodeT code = mStr->Coll(ToA(), aStr.ToA());
    if (code == BMathNumSignNeg)
    {
        return UErrFalse;
    }

    return UErrTrue;
}

/**
 * \brief Overload operator of "+".
 */
UStringT UStringT::operator +(const UStringT &aStr)
{
    mStr->MCat(&mChar, aStr.ToA());

    return mChar;
}

/**
 * \brief Overload operator of "+".
 */
UStringT UStringT::operator +(const char *aStr)
{
    mStr->MCat(&mChar, aStr);

    return mChar;
}

/**
 * \brief Overload operator of "+"
 */
UStringT UStringT::operator +(const UIntT aNum)
{
    // mStr->MCat(&mChar, str);

    return mChar;
}

/**
 * \brief Overload operator of "+=" with string.
 */
UErrCodeT UStringT::operator +=(const UStringT &aStr)
{
    mStr->MCat(&mChar, aStr.ToA());

    return UErrFalse;
}

/**
 * \brief Overload operator of "+=" with char.
 */
UErrCodeT UStringT::operator +=(const char *aStr)
{
    mChar = mStr->MCat(&mChar, aStr);

    return UErrFalse;
}

/**
 * \brief Overload operator of "+=" with number.
 */
UErrCodeT UStringT::operator +=(const UIntT aNum)
{
    mStr->MCat(&mChar, aNum);

    return UErrFalse;
}

/**
 * \brief Output to console.
 */
UErrCodeT UStringT::ToConsole()
{
    return mStr->ToConsole(mChar);
}

/***** Private A *****/

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT UStringT::Init()
{
    CBaseCtl *baseCtl = CBaseCtl::Base();
    CWrapCtl* wrapCtl = baseCtl->Wrap();
    CUstCtl* ustCtl = wrapCtl->Ust();
    mStr = ustCtl->Str();

    mState = UStateOff;
    mChar = NULL;
    mWchar = NULL;
    mInt = 0;
    mFloat = 0;
    
    return UErrFalse;
}

UErrCodeT UStringT::SplitString(UContainerT<UStringT> *aStrCtn,
                                const char *aSrcStr,
                                const UStringT *aDelimiters)
{
    char *dst = NULL;
    char *src = mStr->MCpy(aSrcStr);
    char *delimiters = (char *) aDelimiters->ToA();

    if (mStr->Find(&dst, src, delimiters) == UErrTrue)
    {
        mStr->MFree(src);
        return UErrTrue;
    }

    src = NULL;
    do
    {
        aStrCtn->Add(dst);
    } while (mStr->Find(&dst, src, delimiters) == UErrFalse);

    mStr->MFree(src);

    return UErrFalse;
}

/***** Private B *****/
