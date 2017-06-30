/******************************************************************************
 * $Id: string_struct.cpp 2016-08 $
 *
 * Project:  Universal struct library.
 * Purpose:  Universal string struct.
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

#include "ust_stringtype.hpp"

// Module
#include "base_ctl.hpp"
#include "wrap_ctl.hpp"
#include "ust_ctl.hpp"
#include "ust_stringctl.hpp"

// Cls.
#include "cls_argctl.hpp"

/**
 * \brief Constructor.
 */
UStringT::UStringT()
{
    Init();
}

/**
 * \brief Constructor.
 *
 * @param aStr Initialize by "UStringT".
 */
UStringT::UStringT(const UStringT &aStr)
{
    Init();
    m_char = m_str->MCpy(aStr.ToA());
}

/**
 * \brief Constructor.
 *
 * @param aStr Initialize by "UStringT*".
 */
UStringT::UStringT(const UStringT *aStr)
{
    Init();
    m_char = m_str->MCpy(aStr->ToA());
}

/**
 * \brief Constructor.
 *
 * @param aStr Initialize by "char".
 */
UStringT::UStringT(const char *aStr)
{
    Init();
    m_char = m_str->MCpy(aStr);
}

/**
 * \brief Constructor.
 *
 * @param aStr Initialize by "wchar_t".
 */
UStringT::UStringT(const wchar_t *aStr)
{
    Init();
    m_char = m_str->MWToA(aStr);
}

/**
 * \brief Destructor.
 */
UStringT::~UStringT()
{
    Clear();
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
    m_str->MCat(&m_char, aStr);

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
//         m_str->MCat(&m_char, val);
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
    return m_char;
}

/**
 * \brief Get string with type of "wchar_t".
 *
 * @return String that storage of this object.
 */
const wchar_t* UStringT::ToW()
{
    if (m_wchar != NULL)
    {
        m_str->MFree(&m_wchar);
        m_wchar = NULL;
    }
    m_wchar = m_str->MAToW(m_char);

    return m_wchar;
}

/**
 * \brief This string is null.
 */
UErrCodeT UStringT::IsNull()
{
    if (m_str->Len(m_char) == 0)
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
    if (m_char != NULL)
    {
        m_str->MFree(m_char);
        m_char = NULL;
    }
    if (m_wchar != NULL)
    {
        m_str->MFree(m_wchar);
        m_wchar = NULL;
    }

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
    m_char = m_str->MCpy(aStr);

    return UErrFalse;
}

/**
 * \brief TODO
 */
UErrCodeT UStringT::operator !=(const char *aStr)
{
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
    m_char = m_str->MCpy(aStr.ToA());

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
    m_str->Cmp(ToA(), aStr.ToA());

    return UErrFalse;
}

/**
 * \brief Overload operator of "+".
 */
UStringT UStringT::operator +(const UStringT &aStr)
{
    m_str->MCat(&m_char, aStr.ToA());

    return m_char;
}

/**
 * \brief Overload operator of "+".
 */
UStringT UStringT::operator +(const char *aStr)
{
    m_str->MCat(&m_char, aStr);

    return m_char;
}

/**
 * \brief Overload operator of "+=".
 */
UErrCodeT UStringT::operator +=(const UStringT &aStr)
{
    m_str->MCat(&m_char, aStr.ToA());

    return UErrFalse;
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
    m_str = ustCtl->Str();

    m_state = UStateOff;
    m_char = NULL;
    m_wchar = NULL;
    m_int = 0;
    m_float = 0;
    
    return UErrFalse;
}

/***** Private B *****/
