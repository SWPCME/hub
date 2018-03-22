/******************************************************************************
 * $Id: gda_utilsctl.hpp 2017-07 $
 *
 * Project:  C language standard library.
 * Purpose:  String token implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-07 ~ 2017, Weiwei Huang
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

#include "cls_stringtoken.hpp"

// GNU C Library
#include <string.h>

/**
 * \brief Constructor.
 */
CClsStringToken::CClsStringToken()
{
}

/**
 * \brief Destructor.
 */
CClsStringToken::~CClsStringToken()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CClsStringToken::Init()
{
    return UErrFalse;
}

/**
 * \brief Find.
 * MT-Unsafe.
 * @param aDst Fetch the target string.
 * @param aSrc The string that select to find, and next will be "NULL" to 
 * continue.
 * @param aDelimiters The delimiter that must be specified.
 *
 * @return UErrFalse, if successful or must be continue; UErrTrue, if failed 
 * or must be stop.
 */
UErrCodeT CClsStringToken::Find(char **aDst, char *aSrc,
                                const char *aDelimiters)
{
    *aDst = strtok(aSrc, aDelimiters);

    if (*aDst == NULL)
    {
        return UErrTrue;
    }

    return UErrFalse;
}
