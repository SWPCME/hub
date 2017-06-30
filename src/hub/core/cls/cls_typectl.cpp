/******************************************************************************
 * $Id: cls_typectl.cpp 2017-06 $
 *
 * Project:  C language standard library.
 * Purpose:  Type controler implementation.
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

#include "cls_typectl.hpp"

/**
 * \brief Constructor.
 */
CClsTypeCtl::CClsTypeCtl()
{
}

/**
 * \brief Destructor.
 */
CClsTypeCtl::~CClsTypeCtl()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CClsTypeCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief To File Operator Type.
 */
UErrCodeT CClsTypeCtl::ToFileOper(UStringT *aDest, const ClsFileOperCodeT aSrc)
{
    switch (aSrc)
    {
    case ClsFileOperR:
        *aDest = "r";
        break;
    case ClsFileOperRb:
        *aDest = "rb";
        break;
    case ClsFileOperW:
        *aDest = "w";
        break;
    case ClsFileOperWb:
        *aDest = "wb";
        break;
    case ClsFileOperWba:
        *aDest = "wb+";
        break;
    default:
        return UErrTrue;
    }

    return UErrFalse;
}
