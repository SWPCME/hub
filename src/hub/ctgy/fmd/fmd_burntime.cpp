/******************************************************************************
 * $Id: fmd_burntime.hpp 2017-06 $
 *
 * Project:  FMD (FMD: Fire Model).
 * Purpose:  Burn time controler implementation.
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

#include "fmd_burntime.hpp"

// Firemod.
#include "Farsite5.h"

// Base.
#include "base_ctl.hpp"
// Ctgy.
#include "ctgy_ctl.hpp"
// Fmd.
#include "fmd_ctl.hpp"
#include "fmd_burnctl.hpp"

/**
 * \brief Constructor.
 */
CFmdBurnTime::CFmdBurnTime(CFmdBurnCtl *aBurn)
{
    BMD_POINTER_INIT(mBurn);
    BMD_POINTER_INIT(mFarsiteH);
    mBurn = aBurn;
}

/**
 * \brief Destructor.
 */
CFmdBurnTime::~CFmdBurnTime()
{
    BMD_POINTER_INIT(mBurn);
    BMD_POINTER_INIT(mFarsiteH);
}

/**
 * \brief Up.
 */
CFmdBurnCtl *CFmdBurnTime::Up()
{
    return mBurn;
}

/**
 * \brief Initilize.
 */
UErrCodeT CFmdBurnTime::Init()
{
    CFmdCtl *fmd = mBurn->Up();
    mFarsiteH = fmd->FarsiteH();

    return UErrFalse;
}

/**
 * \brief Simulate.
 */
UErrCodeT CFmdBurnTime::Simulate(UFloatT *aTime)
{
    *aTime = FMD_FARSITE(mFarsiteH)->burn.SIMTIME;

    return UErrFalse;
}

/**
 * \brief Inquire in burn period.
 *
 * @param aTime The time you need to check.
 *
 * @return UErrFalse, if the time is in burn period; 
 *         UErrTrue, if the time is out of burn period.
 */
UErrCodeT CFmdBurnTime::InPeriod(UFloatT aTime)
{
    if (FMD_FARSITE(mFarsiteH)->InquireInBurnPeriod(aTime) == 1)
    {
        return UErrFalse;
    }

    return UErrTrue;
}
