/******************************************************************************
 * $Id: fmd_ctl.cpp 2017-04 $
 *
 * Project:  Fmd.
 * Purpose:  Fmd ctl.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017 Weiwei Huang
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
 *****************************************************************************/

#include "fmd_ctl.h"

// libfiremod
#include "Farsite5.h"
// Universal commad
#include "uni_ctl.h"

/**
 * \brief Construct.
 */
CFmdCtl::CFmdCtl()
{
    mFarsite = new Farsite5();
}

/**
 * \brief Destruct.
 */
CFmdCtl::~CFmdCtl()
{
    if (mFarsite)
        delete mFarsite;
    mFarsite = NULL;
}

/**
 * \brief Initilization.
 */
int CFmdCtl::Init(CUniCtl *aUni)
{
    mUni = aUni;

    return FMD_OK;
}

/**
 * \brief Launch farsite.
 */
int CFmdCtl::Launch(const FmdCfgT *aCfg)
{
    const FmdInFileCfgT *inFile = &aCfg->inFile;
    const FmdOutCfgT *out = &aCfg->out;
    LoadFile(inFile->landscape, inFile->input, inFile->ignition,
             inFile->barrier);
    LaunchFarsite();
    SetTime(out->file, out->mode);
    WriteFile(out->file, kMDefault);

    return FMD_OK;
}

/**
 * \brief Load file.
 */
int CFmdCtl::LoadFile(const char *aLandscape, const char *aInput,
                      const char *aIgnition, const char *aBarrier)
{
    LoadLandscape(aLandscape);
    LoadInput(aInput);
    LoadIgnition(aIgnition);
    LoadBarrier(aBarrier);

    return FMD_OK;
}

/**
 * \brief Load landscape file.
 *
 * \param aFile, landscape file.
 *
 * \return FMD_OK, if successful; FMD_ERR, if failed.
 */
int CFmdCtl::LoadLandscape(const char *aFile)
{
    mFarsite->LoadLandscapeFile((char*)aFile);

    return FMD_OK;
}

/**
 * \brief Load input file.
 *
 * \param aFile, input file.
 *
 * \return FMD_OK, if successful; FMD_ERR, if failed.
 */
int CFmdCtl::LoadInput(const char *aFile)
{
    mFarsite->LoadInputsFile((char*)aFile);

    return FMD_OK;
}

/**
 * \brief Load input error.
 *
 * \param aErr, error number.
 *
 * \return FMD_OK, if successful; FMD_ERR, if failed.
 */
int CFmdCtl::LoadErr(int aErr)
{
    mFarsite->LoadInputError(aErr);

    return FMD_OK;
}

/**
 * \brief Load ignition file.
 *
 * \param aFile, shape file.
 */
int CFmdCtl::LoadIgnition(const char *aFile)
{
    mFarsite->SetIgnitionFileName((char*)aFile);

    return FMD_OK;
}

/**
 * \brief Load barrier file.
 *
 * \param aFile, barrier file.
 */
int CFmdCtl::LoadBarrier(const char *aFile)
{
    mFarsite->SetBarrierFileName((char*)aFile);

    return FMD_OK;
}

/**
 * \brief Launch farsite.
 */
int CFmdCtl::LaunchFarsite()
{
    mFarsite->LaunchFarsite();

    return FMD_OK;
}

/**
 * \brief Set time.
 *
 * \param aFile, output file name.
 * \param aMode, 0 means one hour; 1 means ten hours; 
                 2 means one hundred hours; 3 means one thoundsand hours.
 */
#include <stdio.h>
int CFmdCtl::SetTime(const char *aFile, int aMode)
{
    mFarsite->LastAccess = -1;
    char mapName[256];
    double simTime;
    SimulateTime(&simTime);
    for (double maptime = 0.0; maptime <= simTime; maptime += 60.0)
    {
        if (InquireInBurnPeriod(maptime) == FMD_OK)
        {
            long mo, dy, hr, mn;
            bool mode = false;
            ConvertSimtimeToActualTime(maptime, &mo, &dy, &hr, &mn, mode);
            sprintf(mapName, "%s_%02ld-%02ld_%02ld-%02ld.asc", aFile, mo, dy,
                    hr/100, mn);
            CmMapEnvironment(aMode, maptime, mapName);
        }
    }

    return FMD_OK;
}

/**
 * \brief Simulate time for burn.
 *
 * \param O aTime, get simulate time.
 */
int CFmdCtl::SimulateTime(double *aTime)
{
    *aTime = mFarsite->burn.SIMTIME;

    return FMD_OK;
}

/**
 * \brief Inquire in burn period.
 */
int CFmdCtl::InquireInBurnPeriod(double aTime)
{
    mFarsite->InquireInBurnPeriod(aTime);

    return FMD_OK;
}

/**
 * \brief Convert simulate time to actual time,
 *
 *        Return the time in minutes of the difference between the send in
 *        date/times and the start/cond date/time.
 *
 * \param aMo, month.
 * \param aDy, day.
 * \param aHr, hour.
 * \param aMn, minute.
 * \param aFromCondit, from condition.
 *
 * \return FMD_OK.
 */
int CFmdCtl::ConvertSimtimeToActualTime(double aTime, long *aMo, long *aDy,
                                        long *aHr, long *aMn, bool aMode)
{
    mFarsite->ConvertSimtimeToActualTime(aTime, aMo, aDy, aHr, aMn, aMode);

    return FMD_OK;
}

/**
 * \brief Cm map environment.
 */
int CFmdCtl::CmMapEnvironment(int aThemeno, double aMapTime,
                              const char *aOutTime)
{
    mFarsite->CmMapEnvironment(aThemeno, aMapTime, (char *)aOutTime);

    return FMD_OK;
}

/**
 * \brief Write file
 *
 * \param aFile, output file name.
 */
int CFmdCtl::WriteFile(const char *aFile, int aMode)
{
    // Write all file.
    WriteSpecial(aFile, kMDefault);
    WriteSpecial(aFile, kMAnother);
    WriteCommon(aFile);

    return FMD_OK;
}

/**
 * \brief Write text or binary file.
 */
int CFmdCtl::WriteSpecial(const char *aFile, int aMode)
{
    WriteCrownFireGrid(aFile, aMode);
    WriteIntensityGrid(aFile, aMode);
    WriteFlameLengthGrid(aFile, aMode);
    WriteSpreadRateGrid(aFile, aMode);
    WriteSpreadDirectionGrid(aFile, aMode);
    WriteHeatPerUnitAreaGrid(aFile, aMode);
    WriteReactionIntensityGrid(aFile, aMode);
    WriteArrivalTimeGrid(aFile, aMode);

    return FMD_OK;
}

/**
 * \brief Write crown fire grid.
 */
int CFmdCtl::WriteCrownFireGrid(const char *aFile, int aMode)
{
    const char suffix[kNFile] = "_crownfiregrid";
    char file[kNFile];
    if (aMode == kMDefault)
    {
        mUni->MergeStr(file, aFile, suffix, kSAsc);
        mFarsite->WriteCrownFireGrid(file);
    }
    else
    {
        mUni->MergeStr(file, aFile, suffix, kSFbg);
        mFarsite->WriteCrownFireGridBinary(file);
    }

    return FMD_OK;
}

/**
 * \brief Write intensity grid.
 */
int CFmdCtl::WriteIntensityGrid(const char *aFile, int aMode)
{
    const char suffix[kNFile] = "_intensitygrid";
    char file[kNFile];
    if (aMode == kMDefault)
    {
        mUni->MergeStr(file, aFile, suffix, kSAsc);
        mFarsite->WriteIntensityGrid(file);
    }
    else
    {
        mUni->MergeStr(file, aFile, suffix, kSFbg);
        mFarsite->WriteIntensityGrid(file);
    }

    return FMD_OK;
}

/**
 * \brief Write flame length grid.
 */
int CFmdCtl::WriteFlameLengthGrid(const char *aFile, int aMode)
{
    const char suffix[kNFile] = "_flamelengthgird";
    char file[kNFile];
    if (aMode == kMDefault)
    {
        mUni->MergeStr(file, aFile, suffix, kSAsc);
        mFarsite->WriteFlameLengthGrid(file);
    }
    else
    {
        mUni->MergeStr(file, aFile, suffix, kSFbg);
        mFarsite->WriteFlameLengthGridBinary(file);
    }

    return FMD_OK;
}

/**
 * \brief Write spread rate grid.
 */
int CFmdCtl::WriteSpreadRateGrid(const char *aFile, int aMode)
{
    const char suffix[kNFile] = "_spreadrategrid";
    char file[kNFile];
    if (aMode == kMDefault)
    {
        mUni->MergeStr(file, aFile, suffix, kSAsc);
        mFarsite->WriteSpreadRateGrid(file);
    }
    else
    {
        mUni->MergeStr(file, aFile, suffix, kSFbg);
        mFarsite->WriteSpreadRateGridBinary(file);
    }

    return FMD_OK;
}

/**
 * \brief Write spread direction grid.
 */
int CFmdCtl::WriteSpreadDirectionGrid(const char *aFile, int aMode)
{
    const char suffix[kNFile] = "_spreaddirectiongrid";
    char file[kNFile];
    if (aMode == kMDefault)
    {
        mUni->MergeStr(file, aFile, suffix, kSAsc);
        mFarsite->WriteSpreadDirectionGrid(file);
    }
    else
    {
        mUni->MergeStr(file, aFile, suffix, kSFbg);
        mFarsite->WriteSpreadDirectionGridBinary(file);
    }

    return FMD_OK;
}

/**
 * \brief Write heat per unit area grid.
 */
int CFmdCtl::WriteHeatPerUnitAreaGrid(const char *aFile, int aMode)
{
    const char suffix[kNFile] = "_heatperunitareagrid";
    char file[kNFile];
    if (aMode == kMDefault)
    {
        mUni->MergeStr(file, aFile, suffix, kSAsc);
        mFarsite->WriteHeatPerUnitAreaGrid(file);
    }
    else
    {
        mUni->MergeStr(file, aFile, suffix, kSFbg);
        mFarsite->WriteHeatPerUnitAreaGridBinary(file);
    }

    return FMD_OK;
}

/**
 * \brief Write reaction intensity grid.
 */
int CFmdCtl::WriteReactionIntensityGrid(const char *aFile, int aMode)
{
    const char suffix[kNFile] = "_reactionintensitygrid";
    char file[kNFile];
    if (aMode == kMDefault)
    {
        mUni->MergeStr(file, aFile, suffix, kSAsc);
        mFarsite->WriteReactionIntensityGrid(file);
    }
    else
    {
        mUni->MergeStr(file, aFile, suffix, kSFbg);
        mFarsite->WriteReactionIntensityGridBinary(file);
    }

    return FMD_OK;
}

/**
 * \brief Write arrival time grid.
 */
int CFmdCtl::WriteArrivalTimeGrid(const char *aFile, int aMode)
{
    const char suffix[kNFile] = "_arrivaltimegrid";
    char file[kNFile];
    if (aMode == kMDefault)
    {
        mUni->MergeStr(file, aFile, suffix, kSAsc);
        mFarsite->WriteArrivalTimeGrid(file);
    }
    else
    {
        mUni->MergeStr(file, aFile, suffix, kSFbg);
        mFarsite->WriteArrivalTimeGridBinary(file);
    }

    return FMD_OK;
}

/**
 * \brief Write common file.
 */
int CFmdCtl::WriteCommon(const char *aFile)
{
    WriteIgnitionGrid(aFile);
    WritePerimetersShape(aFile);
    WriteSpotGrid(aFile);
    WriteSpotData(aFile);
    WriteSpotShape(aFile);
    WriteTimings(aFile);

    return FMD_OK;
}

/**
 * \brief Write ignition grid file.
 */
int CFmdCtl::WriteIgnitionGrid(const char *aFile)
{
    const char suffix[kNFile] = "_ignitiongrid";
    char file[kNFile];
    mUni->MergeStr(file, aFile, suffix, kSAsc);
    mFarsite->WriteIgnitionGrid(file);

    return FMD_OK;
}

/**
 * \brief Write perimeters shape file.
 */
int CFmdCtl::WritePerimetersShape(const char *aFile)
{
    const char suffix[kNFile] = "_perimetersshape";
    char file[kNFile];
    mUni->MergeStr(file, aFile, suffix, kSShp);
    mFarsite->WritePerimetersShapeFile(file);

    return FMD_OK;
}

/**
 * \brief Write spot grid.
 */
int CFmdCtl::WriteSpotGrid(const char *aFile)
{
    const char suffix[kNFile] = "_spotgrid";
    char file[kNFile];
    mUni->MergeStr(file, aFile, suffix, kSAsc);
    mFarsite->WriteSpotGrid(file);

    return FMD_OK;
}

/**
 * \brief Write spot data file.
 */
int CFmdCtl::WriteSpotData(const char *aFile)
{
    const char suffix[kNFile] = "_spotdata";
    char file[kNFile];
    mUni->MergeStr(file, aFile, suffix, kSCsv);
    mFarsite->WriteSpotDataFile(file);

    return FMD_OK;
}

/**
 * \brief Write spot shape file.
 */
int CFmdCtl::WriteSpotShape(const char *aFile)
{
    const char suffix[kNFile] = "_spotshape";
    char file[kNFile];
    mUni->MergeStr(file, aFile, suffix, kSShp);
    mFarsite->WriteSpotShapeFile(file);

    return FMD_OK;
}

/**
 * \brief Write timings file.
 */
int CFmdCtl::WriteTimings(const char *aFile)
{
    const char suffix[kNFile] = "_timings";
    char file[kNFile];
    mUni->MergeStr(file, aFile, suffix, kSTxt);
    mFarsite->WriteTimingsFile(file);

    return FMD_OK;
}
