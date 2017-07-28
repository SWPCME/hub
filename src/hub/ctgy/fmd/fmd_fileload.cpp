/******************************************************************************
 * $Id: fmd_readctl.cpp 2017-06 $
 *
 * Project:  FMD (FMD: Fire Model).
 * Purpose:  Read controler implementation.
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

#include "fmd_fileload.hpp"

// Firemod.
#include "Farsite5.h"

// Base.
#include "base_ctl.hpp"
// Ctgy.
#include "ctgy_ctl.hpp"
// Fmd.
#include "fmd_ctl.hpp"
#include "fmd_filectl.hpp"

/**
 * \brief Constructor.
 */
CFmdFileLoad::CFmdFileLoad()
{
    BMD_POINTER_INIT(mFarsiteH);
}

/**
 * \brief Destructor.
 */
CFmdFileLoad::~CFmdFileLoad()
{
    BMD_POINTER_INIT(mFarsiteH);
}

/**
 * \brief Initialize.
 */
UErrCodeT CFmdFileLoad::Init()
{
    FMD_FARSITE_H(mFarsiteH);
    
    return UErrFalse;
}

/**
 * \brief Load all file.
 */
UErrCodeT CFmdFileLoad::All(const UStringT *aCfg, const UStringT *aLcp,
                            const UStringT *aIgnition, const UStringT *aBarrier)
{
    Cfg(aCfg);
    Lcp(aLcp);
    Ignition(aIgnition);
    Barrier(aBarrier);

    return UErrFalse;
}

/**
 * \brief Load configuration file.
 *
 * \param aFile, configuration file.
 *
 * \return UErrFalse, if successful; FMD_ERR, if failed.
 */
UErrCodeT CFmdFileLoad::Cfg(const UStringT *aFile)
{
    FMD_FARSITE(mFarsiteH)->LoadInputsFile((char *) aFile->ToA());

    return UErrFalse;
}

/**
 * \brief Load landscape file.
 *
 * \param aFile, landscape file.
 *
 * \return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CFmdFileLoad::Lcp(const UStringT *aFile)
{
    FMD_FARSITE(mFarsiteH)->LoadLandscapeFile((char *) aFile->ToA());

    return UErrFalse;
}

/**
 * \brief Load ignition file.
 *
 * \param aFile, shape file.
 */
UErrCodeT CFmdFileLoad::Ignition(const UStringT *aFile)
{
    FMD_FARSITE(mFarsiteH)->SetIgnitionFileName((char *) aFile->ToA());

    return UErrFalse;
}

/**
 * \brief Load barrier file.
 *
 * \param aFile, barrier file.
 */
UErrCodeT CFmdFileLoad::Barrier(const UStringT *aFile)
{
    FMD_FARSITE(mFarsiteH)->SetBarrierFileName((char *) aFile->ToA());

    return UErrFalse;
}

/***** Private A *****/

/**
 * \brief Load input error.
 *
 * \param aErr, error number.
 *
 * \return UErrFalse, if successful; FMD_ERR, if failed.
 */
UErrCodeT CFmdFileLoad::InputErr(UIntT aErr)
{
    FMD_FARSITE(mFarsiteH)->LoadInputError(aErr);

    return UErrFalse;
}

/***** Private B *****/
