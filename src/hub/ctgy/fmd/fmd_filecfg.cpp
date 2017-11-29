/******************************************************************************
 * $Id: fmd_filecfg.hpp 2017-08 $
 *
 * Project:  FMD (FMD: Fire Model).
 * Purpose:  File config implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-06 ~ 2017, Weiwei Huang
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

#include "fmd_filecfg.hpp"

// fmd
#include "fmd_cfgread.hpp"
#include "fmd_cfgwrite.hpp"


/**
 * \brief Constructor.
 * Private.
 * Do not use this function.
 */
CFmdFileCfg::CFmdFileCfg()
{
}

/**
 * \brief Constructor.
 */
CFmdFileCfg::CFmdFileCfg(const UStringT *aFileName, const FmdFileCfgCodeT aCfg)
{
    InitPointer();
    InitCfg(aFileName, aCfg);
}

/**
 * \brief Destructor.
 */
CFmdFileCfg::~CFmdFileCfg()
{
    BMD_CLASS_DEL(mRead);
    BMD_CLASS_DEL(mWrite);
}

/**
 * \brief Initialize.
 */
UErrCodeT CFmdFileCfg::Init()
{
    return UErrFalse;
}

/**
 * \brief Read.
 *
 * @return Handle of read, if successful; NULL, if failed.
 */
CFmdCfgRead *CFmdFileCfg::Read()
{
    BMD_CLASS_NEW_A_1(mRead, CFmdCfgRead, &mFile);

    return mRead;
}

/**
 * \brief Write.
 *
 * @return Handle of write, if successful; NULL, if failed.
 */
CFmdCfgWrite *CFmdFileCfg::Write()
{
    BMD_CLASS_NEW_A_1(mWrite, CFmdCfgWrite, &mFile);

    return mWrite;
}

/***** Private A *****/

/**
 * \brief Init pointer.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CFmdFileCfg::InitPointer()
{
    BMD_POINTER_INIT(mRead);
    BMD_POINTER_INIT(mWrite);

    return UErrFalse;
}

/**
 * \brief Init config.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CFmdFileCfg::InitCfg(const UStringT *aFileName,
                               const FmdFileCfgCodeT aCfg)
{
    switch(aCfg)
    {
    case FmdFileCfgCreate:
        Create(aFileName);
        break;
    case FmdFileCfgLoad:
        Load(aFileName);
        break;
    default:
        return UErrTrue;
    }

    return UErrFalse;
}

/**
 * \brief Create.
 */
UErrCodeT CFmdFileCfg::Create(const UStringT *aFileName)
{
    mFile.InitFile(aFileName, UstFileOperWta);

    return UErrFalse;
}

/**
 * \brief Load.
 */
UErrCodeT CFmdFileCfg::Load(const UStringT *aFileName)
{
    mFile.InitFile(aFileName, UstFileOperWta);

    return UErrFalse;
}

/***** Private B *****/
