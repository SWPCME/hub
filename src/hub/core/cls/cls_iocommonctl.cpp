/******************************************************************************
 * $Id: cls_iocommonctl.hpp 2017-06 $
 *
 * Project:  C language standard library.
 * Purpose:  Common controler implemention.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016 ~ 2017 Weiwei Huang
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

#include "cls_iocommonctl.hpp"

// Glibc Module.
#include "stdio.h"

// Cls.
#include "cls_argctl.hpp"

/**
 * \brief Constructor.
 */
CClsIoCommonCtl::CClsIoCommonCtl()
{
}

/**
 * \brief Destructor.
 */
CClsIoCommonCtl::~CClsIoCommonCtl()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CClsIoCommonCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Format and print data.
 */
UErrCodeT CClsIoCommonCtl::PrintF(const char *aFormat, ...)
{
    ClsArgListT list;
    cls_arg_start(list, aFormat);
    vprintf(aFormat, list);
    cls_arg_end(list);

    return UErrFalse;
}

/**
 * \brief Format and sprint data.
 */
UErrCodeT CClsIoCommonCtl::SPrintF(char *aStr, const char *aFormat, ...)
{
    ClsArgListT list;
    cls_arg_start(list, aFormat);
    sprintf(aStr, aFormat, list);
    cls_arg_end(list);

    return UErrFalse;
}
