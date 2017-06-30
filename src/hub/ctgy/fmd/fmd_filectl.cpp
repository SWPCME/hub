/******************************************************************************
 * $Id: fmd_filectl.cpp 2017-06 $
 *
 * Project:  FMD (FMD: Fire Model).
 * Purpose:  File controler implementation.
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

#include "fmd_filectl.hpp"

// Firemod.
#include "Farsite5.h"

// Fmd.
#include "fmd_fileload.hpp"
#include "fmd_filewrite.hpp"
// #include "fmd_filecfg.hpp"

/**
 * \brief Constructor.
 */
CFmdFileCtl::CFmdFileCtl()
{
    BMD_POINTER_INIT(mLoad);
    BMD_POINTER_INIT(mWrite);
    // BMD_POINTER_INIT(mCfg);
}

/**
 * \brief Destructor.
 */
CFmdFileCtl::~CFmdFileCtl()
{
    BMD_CLASS_DEL(mLoad);
    BMD_CLASS_DEL(mWrite);
    // BMD_CLASS_DEL(mCfg);
}

/**
 * \brief Initialize.
 */
UErrCodeT CFmdFileCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Load.
 */
CFmdFileLoad *CFmdFileCtl::Load()
{
    BMD_CLASS_NEW(mLoad, CFmdFileLoad);

    return mLoad;
}

/**
 * \brief Write.
 */
CFmdFileWrite *CFmdFileCtl::Write()
{
    BMD_CLASS_NEW(mWrite, CFmdFileWrite);

    return mWrite;
}

/**
 * \brief Config.
 */
// CFmdFileCfg *CFmdFileCtl::Cfg()
// {
//     BMD_CLASS_NEW(mCfg, CFmdFileCfg);

//     return mCfg;
// }
