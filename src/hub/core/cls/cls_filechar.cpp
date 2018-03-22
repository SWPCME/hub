/******************************************************************************
 * $Id: cls_filechar.cpp 2017-08 $
 *
 * Project:  C language standard library.
 * Purpose:  File character implemention.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-08 ~ 2017 Weiwei Huang
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

#include "cls_filechar.hpp"

// GLibc
#include <stdio.h>

/**
 * \brief Constructor.
 */
CClsFileChar::CClsFileChar()
{
}

/**
 * \brief Destructor.
 */
CClsFileChar::~CClsFileChar()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CClsFileChar::Init()
{
    return UErrFalse;
}

/**
 * \brief Get character.
 */
UErrCodeT CClsFileChar::Get(UIntT *aC, ClsFileHT aFileH)
{
    *aC = fgetc((FILE *) aFileH);

    if (*aC == EOF)
    {
        return UErrTrue;
    }

    return UErrFalse;
}

/**
 * \brief Put character.
 */
UErrCodeT CClsFileChar::Put(UIntT aC, ClsFileHT aFileH)
{
    UIntT c = fputc(aC, (FILE *) aFileH);

    if (c == EOF)
    {
        return UErrTrue;
    }

    return UErrFalse;
}
