/******************************************************************************
 * $Id: cls_stringsrch.cpp 2018-07 $
 *
 * Project:  Cls (C language standard library).
 * Purpose:  String search implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2018-07 ~ 2018, Weiwei Huang
 *
 * This program is free software; you can redistribute it and/or modify it 
 * under the terms of the GNU General Public License as published by the Free 
 * Software Foundation, either version 3 of the License, or (at your option) 
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT 
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for 
 * more details.
 *
 * You should have received a copy of the GNU General Public License along 
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 *****************************************************************************/

#include "cls_stringsrch.hpp"

// base
#include "base_stringdefn.hpp"
// ust
#include "ust_stringtype.hpp"

#include <string.h>

/**
 * \brief Constructor.
 */
CClsStringSrch::CClsStringSrch()
{
}

/**
 * \brief Destructor.
 */
CClsStringSrch::~CClsStringSrch()
{
}

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CClsStringSrch::Init()
{
    return UErrFalse;
}

/**
 * \brief To searche haystack for a substring needle rather than just a single 
 * byte.
 *
 * It returns a pointer into the string haystack that is the first byte of the 
 * substring, or a null pointer if no match was found. If needle is an empty
 * string, the function returns haystack.
 *
 * @param aHaystack, source string.
 * @param aNeedle, the search object.
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CClsStringSrch::Str(UStringT *aSubstr, const UStringT *aHaystack,
                              const UStringT *aNeedle)
{
    char *str = strstr(aHaystack->ToA(), aNeedle->ToA());

    if (str == NULL)
    {
        *aSubstr = kStrNull;
        return UErrTrue;
    }

    *aSubstr = str;

    return UErrFalse;
}

/***** Private A *****/

/**
 * \brief InitPointer.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CClsStringSrch::InitPointer()
{
    return UErrFalse;
}

/***** Private B *****/
