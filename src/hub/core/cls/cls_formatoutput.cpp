/******************************************************************************
 * $Id: cls_formatoutput.cpp 2017-07 $
 *
 * Project:  C language standard library.
 * Purpose:  Format output implemention.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-07 ~ 2017 Weiwei Huang
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

#include "cls_formatoutput.hpp"

// GNU C Library
#include <stdio.h>

// cls
#include "cls_argctl.hpp"

/**
 * \brief Constructor.
 */
CClsFormatOutput::CClsFormatOutput()
{
}

/**
 * \brief Destructor.
 */
CClsFormatOutput::~CClsFormatOutput()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CClsFormatOutput::Init()
{
    return UErrFalse;
}

/**
 * \brief Print to string.
 */
UErrCodeT CClsFormatOutput::ToStr(char *aStr, const char *aFormat, ...)
{
    ClsArgListT list;
    cls_arg_start(list, aFormat);
    vsprintf(aStr, aFormat, list);
    cls_arg_end(list);

    return UErrFalse;
}

/**
 * \brief Print to console.
 */
UErrCodeT CClsFormatOutput::ToCon(const char *aFormat, ...)
{
    ClsArgListT list;
    cls_arg_start(list, aFormat);
    vprintf(aFormat, list);
    cls_arg_end(list);

    return UErrFalse;
}

/**
 * \brief Print to file.
 */
UErrCodeT CClsFormatOutput::ToFile(ClsFileHT aFile, const char *aFormat, ...)
{
    ClsArgListT list;
    cls_arg_start(list, aFormat);
    vfprintf((FILE *) aFile, aFormat, list);
    cls_arg_end(list);

    return UErrFalse;
}
