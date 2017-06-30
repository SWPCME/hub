/******************************************************************************
 * $Id: fmd_ctl.cpp 2017-06 $
 *
 * Project:  FMD (FMD: Fire Model).
 * Purpose:  Fmd controler implementation.
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

#include "fmd_ctl.hpp"

// Firemod.
#include "Farsite5.h"

// Base.
#include "base_macrodefn.hpp"
// Fmd.
#include "fmd_typectl.hpp"
#include "fmd_filectl.hpp"
#include "fmd_burnctl.hpp"

/**
 * \brief Constructor.
 */
CFmdCtl::CFmdCtl()
{
    BMD_POINTER_INIT(mFarsiteH);
    BMD_POINTER_INIT(mType);
    BMD_POINTER_INIT(mFile);
}

/**
 * \brief Destructor.
 */
CFmdCtl::~CFmdCtl()
{
    BMD_CLASS_DELH(mFarsiteH, Farsite5);
    BMD_CLASS_DEL(mType);
    BMD_CLASS_DEL(mFile);
}

/**
 * \brief Initialize.
 */
UErrCodeT CFmdCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Farsite handle.
 */
FmdFarsiteHT CFmdCtl::FarsiteH()
{
    BMD_CLASS_ONEWH(mFarsiteH, Farsite5, FmdFarsiteHT);

    return mFarsiteH;
}

/**
 * \brief Type.
 */
CFmdTypeCtl *CFmdCtl::Type()
{
    BMD_CLASS_NEW(mType, CFmdTypeCtl);

    return mType;
}

/**
 * \brief File controler.
 */
CFmdFileCtl *CFmdCtl::File()
{
    BMD_CLASS_NEW(mFile, CFmdFileCtl);

    return mFile;
}

/**
 * \brief Burn controler.
 */
CFmdBurnCtl *CFmdCtl::Burn()
{
    BMD_CLASS_NEW(mBurn, CFmdBurnCtl);

    return mBurn;
}

/**
 * \brief Launch.
 */
UErrCodeT CFmdCtl::Launch()
{
    FMD_FARSITE(mFarsiteH)->LaunchFarsite();

    return UErrFalse;
}
