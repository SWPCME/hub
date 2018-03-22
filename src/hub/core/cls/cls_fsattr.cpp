/******************************************************************************
 * $Id: cls_fsattr.cpp 2018-01 $
 *
 * Project:  C language standard library.
 * Purpose:  File system file attribute definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2018-01 ~ 2018, Weiwei Huang
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
 ****************************************************************************/

#include "cls_fsattr.hpp"

// GLIBC
#include <unistd.h>

/**
 * \brief Constructor.
 */
CClsFsAttr::CClsFsAttr()
{
}

/**
 * \brief Destructor.
 */
CClsFsAttr::~CClsFsAttr()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CClsFsAttr::Init()
{
    return UErrFalse;
}

/**
 * \brief Testing permission to access a file.
 */
UErrCodeT CClsFsAttr::Access(const UStringT *aFile)
{
    if (access(aFile->ToA(), F_OK) == 0)
    {
        return UErrFalse;
    }

    return UErrTrue;
}
