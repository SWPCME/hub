/******************************************************************************
 * $Id: fmd_typectl.cpp 2017-06 $
 *
 * Project:  FMD (FMD: Fire Model).
 * Purpose:  Type controler implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016 ~ 2017, Weiwei Huang
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

#include "fmd_typectl.hpp"

// Firemod.
#include "Farsite5.h"

// Base.
#include "base_ctl.hpp"
// Ctgy.
#include "ctgy_ctl.hpp"
// Fmd.
#include "fmd_ctl.hpp"

/**
 * \brief Constructor.
 */
CFmdTypeCtl::CFmdTypeCtl()
{
    BMD_POINTER_INIT(mFarsiteH);
}

/**
 * \brief Destructor.
 */
CFmdTypeCtl::~CFmdTypeCtl()
{
    BMD_POINTER_INIT(mFarsiteH);
}

/**
 * \brief Initialize.
 */
UErrCodeT CFmdTypeCtl::Init()
{
    CBaseCtl *baseCtl = CBaseCtl::Base();
    CCtgyCtl *ctgyCtl = baseCtl->Ctgy();
    CFmdCtl *fmdCtl = ctgyCtl->Fmd();
    mFarsiteH = fmdCtl->FarsiteH();

    return UErrFalse;
}

/**
 * \brief To Time.
 */
UErrCodeT CFmdTypeCtl::ToTm(BTimeTmT *aTm, const UFloatT aTime)
{
    bool mode = false;
    ((Farsite5 *) mFarsiteH)->ConvertSimtimeToActualTime
        ((double) aTime, (long *) &aTm->mon, (long *) &aTm->mday,
         (long *) &aTm->hour, (long *) &aTm->min, mode);

    return UErrFalse;
}

/**
 * \brief To Time.
 */
UErrCodeT CFmdTypeCtl::ToTm(UFloatT *aTime, const BTimeTmT *aTm)
{
    bool mode = false;
    *aTime = FMD_FARSITE(mFarsiteH)->ConvertActualTimeToSimtime
        (aTm->mon, aTm->mday, aTm->hour, aTm->min, mode);

    return UErrFalse;
}

/**
 * \brief To fmd map env interval.
 */
UErrCodeT CFmdTypeCtl::ToFmdMapEnvInterval(UIntT *aDest,
                                           FmdMapEnvIntervalCodeT aSrc)
{
    switch (aSrc)
    {
    case FmdMapEnvIntervalOneH:
        *aDest = 0;
        break;
    case FmdMapEnvIntervalTenH:
        *aDest = 1;
        break;
    case FmdMapEnvIntervalHundredH:
        *aDest = 2;
        break;
    case FmdMapEnvIntervalThousandH:
        *aDest = 3;
        break;
    default:
        return UErrTrue;
    }

    return UErrFalse;
}
