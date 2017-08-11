/******************************************************************************
 * $Id: ust_filebase.hpp 2017-07 $
 *
 * Project:  Universal structrue library.
 * Purpose:  File base definition.
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
 ****************************************************************************/

#ifndef UST_FILEBASE_HPP_INCLUDED
#define UST_FILEBASE_HPP_INCLUDED

#include "ust_base.h"

typedef enum
{
    UstFileOperR   = 1,          /* Read. */
    UstFileOperRt  = 2,          /* Read/Test. */
    UstFileOperRb  = 3,          /* Read/Bit. */
    UstFileOperW   = 21,         /* Write. */
    UstFileOperWt  = 22,         /* Write/Test. */
    UstFileOperWta  = 22,        /* Write/Text/Add. */
    UstFileOperWb  = 23,         /* Write/Bit. */
    UstFileOperWba = 24,         /* Write/Bit/Add. */
} UstFileOperCodeT;

#endif  // UST_FILEBASE_HPP_INCLUDED
