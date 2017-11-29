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

// glibc
#include "time.h"

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
    case ClsFileOperRt:
        *aDest = "rt";
        break;
    case ClsFileOperRb:
        *aDest = "rb";
        break;
    case ClsFileOperW:
        *aDest = "w";
        break;
    case ClsFileOperWt:
        *aDest = "wt";
        break;
    case ClsFileOperWta:
        *aDest = "wt+";
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

/**
 * \brief To tm.
 */
UErrCodeT CClsTypeCtl::ToTimeTm(BTimeTmT *aDest, const ClsTmHT aSrc)
{
    const UIntT yearOffset = 1900;
    const UIntT monOffset = 1;
    tm *src = (tm *) aSrc;
    aDest->sec = src->tm_sec;
    aDest->min = src->tm_min;
    aDest->hour = src->tm_hour;
    aDest->mday = src->tm_mday;
    aDest->mon = src->tm_mon + monOffset;
    aDest->year = src->tm_year + yearOffset;
    aDest->wday = src->tm_wday;
    aDest->yday = src->tm_yday;
    aDest->isdst = src->tm_isdst;
#ifdef OS_UNIX
    aDest->gmtoff = src->tm_gmtoff;
#endif
    aDest->zone = src->tm_zone;

    return UErrFalse;
}

/**
 * \brief To tm.
 */
UErrCodeT CClsTypeCtl::ToTimeTm(ClsTmHT aDst, const BTimeTmT *aSrc)
{
    const UIntT yearOffset = -1900;
    const UIntT monOffset = -1;
    tm *dst = (tm *) aDst;
    const BTimeTmT *src = aSrc;
    
    dst->tm_sec = src->sec;
    dst->tm_min = src->min;
    dst->tm_hour = src->hour;
    dst->tm_mday = src->mday;
    dst->tm_mon = src->mon + monOffset;
    dst->tm_year = src->year + yearOffset;
    dst->tm_wday = src->wday;
    dst->tm_yday = src->yday;
    dst->tm_isdst = src->isdst;
#ifdef OS_UNIX
    dst->tm_gmtoff = src->gmtoff;
#endif
    dst->tm_zone = src->zone;

    return UErrFalse;
}
