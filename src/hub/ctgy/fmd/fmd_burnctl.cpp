/******************************************************************************
 * $Id: fmd_burnctl.cpp 2017-06 $
 *
 * Project:  FMD (FMD: Fire Model).
 * Purpose:  Burn controler implementation.
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

#include "fmd_burnctl.hpp"

// Fmd.
#include "fmd_burntime.hpp"

/**
 * \brief Constructor.
 */
CFmdBurnCtl::CFmdBurnCtl(CFmdCtl *aFmd)
{
    BMD_POINTER_INIT(mFmd);
    BMD_POINTER_INIT(mTime);
    mFmd = aFmd;
}

/**
 * \brief Destructor.
 */
CFmdBurnCtl::~CFmdBurnCtl()
{
    BMD_POINTER_INIT(mFmd);
    BMD_CLASS_DEL(mTime);
}

/**
 * \brief Initialize.
 */
UErrCodeT CFmdBurnCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Up.
 */
CFmdCtl *CFmdBurnCtl::Up()
{
    return mFmd;
}

/**
 * \brief Time.
 */
CFmdBurnTime *CFmdBurnCtl::Time()
{
    BMD_CLASS_NEW_A_1(mTime, CFmdBurnTime, this);

    return mTime;
}
