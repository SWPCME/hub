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

/***** Private B *****/