/******************************************************************************
 * $Id: fmd_masterctl.cpp 2017-07 $
 *
 * Project:  FMD (FMD: Fire Model).
 * Purpose:  Master controler implementation.
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

#include "fmd_masterctl.hpp"

// base
#include "base_ctl.hpp"
// ctgy
#include "ctgy_ctl.hpp"
// fmd
#include "fmd_ctl.hpp"

// Farsite module.
#include "Farsite5.h"

/**
 * \brief Constructor.
 */
CFmdMasterCtl::CFmdMasterCtl(CFmdCtl *aFmd)
{
    BMD_POINTER_INIT(mFarsiteH);
    BMD_POINTER_INIT(mFmd);
    mFmd = aFmd;
}

/**
 * \brief Destructor.
 */
CFmdMasterCtl::~CFmdMasterCtl()
{
    BMD_POINTER_INIT(mFarsiteH);
    BMD_POINTER_INIT(mFmd);
}

/**
 * \brief Initialize.
 */
UErrCodeT CFmdMasterCtl::Init()
{
    mFarsiteH = mFmd->FarsiteH();

    return UErrFalse;
}

/**
 * \brief Up.
 */
CFmdCtl *CFmdMasterCtl::Up()
{
    return mFmd;
}

/**
 * \brief Launch.
 */
UErrCodeT CFmdMasterCtl::Launch()
{
    FMD_FARSITE(mFarsiteH)->LaunchFarsite();

    return UErrFalse;
}

/**
 * \brief Cancel.
 */
UErrCodeT CFmdMasterCtl::Cancel()
{
    FMD_FARSITE(mFarsiteH)->CancelFarsite();

    return UErrFalse;
}
