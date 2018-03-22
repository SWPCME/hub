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
#include "fmd_filecfg.hpp"
#include "fmd_fileload.hpp"
#include "fmd_filewrite.hpp"

/**
 * \brief Constructor.
 */
CFmdFileCtl::CFmdFileCtl(CFmdCtl *aFmd)
{
    BMD_POINTER_INIT(mFmd);
    BMD_POINTER_INIT(mCfg);
    BMD_POINTER_INIT(mLoad);
    BMD_POINTER_INIT(mWrite);
    mFmd = aFmd;
}

/**
 * \brief Destructor.
 */
CFmdFileCtl::~CFmdFileCtl()
{
    BMD_CLASS_DEL(mCfg);
    BMD_CLASS_DEL(mLoad);
    BMD_CLASS_DEL(mWrite);
    BMD_POINTER_INIT(mFmd);
}

/**
 * \brief Initialize.
 */
UErrCodeT CFmdFileCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Up.
 */
CFmdCtl *CFmdFileCtl::Up()
{
    return mFmd;
}

/**
 * \brief Config file.
 */
CFmdFileCfg *CFmdFileCtl::Cfg(const UStringT *aFileName,
                              const FmdFileCfgCodeT aCfg)
{
    BMD_CLASS_NEW_A_2(mCfg, CFmdFileCfg, aFileName, aCfg);

    return mCfg;
}

/**
 * \brief Load.
 */
CFmdFileLoad *CFmdFileCtl::Load()
{
    BMD_CLASS_NEW_A_1(mLoad, CFmdFileLoad, this);

    return mLoad;
}

/**
 * \brief Write.
 */
CFmdFileWrite *CFmdFileCtl::Write()
{
    BMD_CLASS_NEW_A_1(mWrite, CFmdFileWrite, this);

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
