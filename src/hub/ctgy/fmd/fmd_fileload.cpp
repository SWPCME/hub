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
    mFarsiteH = NULL;
}

/**
 * \brief Destructor.
 */
CFmdFileLoad::~CFmdFileLoad()
{
    mFarsiteH = NULL;
}

/**
 * \brief Initialize.
 */
UErrCodeT CFmdFileLoad::Init()
{
    CBaseCtl *baseCtl = CBaseCtl::Base();
    CCtgyCtl *ctgyCtl = baseCtl->Ctgy();
    CFmdCtl *fmdCtl = ctgyCtl->Fmd();
    mFarsiteH = fmdCtl->FarsiteH();
    
    return UErrFalse;
}

/**
 * \brief Load all file.
 */
UErrCodeT CFmdFileLoad::All(const char *aLandscape, const char *aInput,
                            const char *aIgnition, const char *aBarrier)
{
    Landscape(aLandscape);
    Input(aInput);
    Ignition(aIgnition);
    Barrier(aBarrier);

    return UErrFalse;
}

/**
 * \brief Load landscape file.
 *
 * \param aFile, landscape file.
 *
 * \return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CFmdFileLoad::Landscape(const char *aFile)
{
    ((Farsite5 *) mFarsiteH)->LoadLandscapeFile((char*)aFile);

    return UErrFalse;
}

/**
 * \brief Load input file.
 *
 * \param aFile, input file.
 *
 * \return UErrFalse, if successful; FMD_ERR, if failed.
 */
UErrCodeT CFmdFileLoad::Input(const char *aFile)
{
    ((Farsite5 *) mFarsiteH)->LoadInputsFile((char*)aFile);

    return UErrFalse;
}

/**
 * \brief Load input error.
 *
 * \param aErr, error number.
 *
 * \return UErrFalse, if successful; FMD_ERR, if failed.
 */
UErrCodeT CFmdFileLoad::InputErr(int aErr)
{
    ((Farsite5 *) mFarsiteH)->LoadInputError(aErr);

    return UErrFalse;
}

/**
 * \brief Load ignition file.
 *
 * \param aFile, shape file.
 */
UErrCodeT CFmdFileLoad::Ignition(const char *aFile)
{
    ((Farsite5 *) mFarsiteH)->SetIgnitionFileName((char*)aFile);

    return UErrFalse;
}

/**
 * \brief Load barrier file.
 *
 * \param aFile, barrier file.
 */
UErrCodeT CFmdFileLoad::Barrier(const char *aFile)
{
    ((Farsite5 *) mFarsiteH)->SetBarrierFileName((char*)aFile);

    return UErrFalse;
}
