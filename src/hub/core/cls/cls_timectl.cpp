/******************************************************************************
 * $Id: cls_timectl.cpp 2017-07 $
 *
 * Project:  C language standard library.
 * Purpose:  Time controler implementation.
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

#include "cls_timectl.hpp"

// glibc
#include "time.h"
// base
#include "base_ctl.hpp"
// core
#include "core_ctl.hpp"
// cls
#include "cls_ctl.hpp"
#include "cls_typectl.hpp"

/**
 * \brief Constructor.
 */
CClsTimeCtl::CClsTimeCtl()
{
    BMD_POINTER_INIT(mType);
}

/**
 * \brief Destructor.
 */
CClsTimeCtl::~CClsTimeCtl()
{
    BMD_POINTER_INIT(mType);
}

/**
 * \brief Initialize.
 */
UErrCodeT CClsTimeCtl::Init()
{
    CLS_TYPE_CTL(mType);

    return UErrFalse;
}

/**
 * \brief Current time.
 */
UErrCodeT CClsTimeCtl::Current(BTimeTmT *aTm)
{
    tm *tms = NULL;
    GmTime((ClsTmHT *) &tms);
    mType->ToTimeTm(aTm, (ClsTmHT) tms);

    return UErrFalse;
}

/**
 * \brief Diff time.
 */
UErrCodeT CClsTimeCtl::Diff(UFloatT *aElapse, const BTimeTmT *aBegin, const BTimeTmT *aEnd)
{
    time_t begin = 0;
    time_t end = 0;
    tm beginTm;
    tm endTm;
    mType->ToTimeTm((ClsTmHT) &beginTm, aBegin);
    mType->ToTimeTm((ClsTmHT) &endTm, aEnd);
    TimeGm((UIntT *) &begin, (ClsTmHT) &beginTm);
    TimeGm((UIntT *) &end, (ClsTmHT) &endTm);
    *aElapse = difftime(end, begin);

    return UErrFalse;
}

/***** Private A *****/

/**
 * \brief Current time with second from 1970.1.1 00:00:00 (UTC).
 */
UErrCodeT CClsTimeCtl::Time(ClsTimeHT aTime)
{
    time((time_t *) aTime);

    return UErrFalse;
}

/**
 * \brief Current time with struct of tm.
 */
UErrCodeT CClsTimeCtl::GmTime(ClsTmHT *aTm)
{
    time_t time_s;
    Time((ClsTimeHT) &time_s);
    *aTm = (ClsTmHT) gmtime(&time_s);

    return UErrFalse;
}

/**
 * \brief Convert tm to time_t.
 */
UErrCodeT CClsTimeCtl::MkTime(UIntT *aTime, const ClsTmHT aTm)
{
    *aTime = mktime((tm *) aTm);

    return UErrFalse;
}

/**
 * \brief Convert tm to time_t, for UTC.
 */
UErrCodeT CClsTimeCtl::TimeGm(UIntT *aTime, const ClsTmHT aTm)
{
#ifdef OS_UNIX
    *aTime = timegm((tm *) aTm);
#endif  // OS_UNIX

#ifdef OS_WINDOWS
    *aTime = _mkgmtime((tm *) aTm);
#endif  // OS_WINDOWS

    return UErrFalse;
}

/***** Private B *****/
