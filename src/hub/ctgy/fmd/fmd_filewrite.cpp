/******************************************************************************
 * $Id: fmd_filewrite.cpp 2017-06 $
 *
 * Project:  FMD (FMD: Fire Model).
 * Purpose:  File write implementation.
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

#include "fmd_filewrite.hpp"

// Base.
#include "base_ctl.hpp"
// Ctgy.
#include "ctgy_ctl.hpp"
// Fmd.
#include "fmd_ctl.hpp"
#include "fmd_typectl.hpp"
#include "fmd_filectl.hpp"
// Ust.
#include "ust_stringtype.hpp"

// Firemod.
#include "Farsite5.h"

// Num.
static const int kNFile = 200;
// String.
static const UStringT kSDot = ".";
static const UStringT kSAsc = "asc";
static const UStringT kSFbg = "fbg";
static const UStringT kSShp = "shp";
static const UStringT kSTxt = "txt";
static const UStringT kSCsv = "csv";

// Macro.

/**
 * \brief Constructor.
 */
CFmdFileWrite::CFmdFileWrite()
{
    BMD_POINTER_INIT(mFarsiteH);
    BMD_POINTER_INIT(mType);
}

/**
 * \brief Destructor.
 */
CFmdFileWrite::~CFmdFileWrite()
{
    BMD_POINTER_INIT(mFarsiteH);
    BMD_POINTER_INIT(mType);
}

/**
 * \brief Initialize.
 */
UErrCodeT CFmdFileWrite::Init()
{
    FMD_CTL(fmdCtl);
    mFarsiteH = fmdCtl->FarsiteH();
    mType = fmdCtl->Type();

    return UErrFalse;
}

/**
 * \brief Write file
 *
 * \param aFile, output file name.
 */
UErrCodeT CFmdFileWrite::All(const char *aFile, UFlagCodeT aFlag)
{
    // Write all file.
    Special(aFile);
    Special(aFile, UFlagOn);
    Common(aFile);

    return UErrFalse;
}

UErrCodeT CFmdFileWrite::MapEnv(UStringT *aFile, BTimeTmT *aTm,
                                FmdMapEnvIntervalCodeT aCode)
{
    UIntT code;
    mType->ToFmdMapEnvInterval(&code, aCode);
    UFloatT time;
    mType->ToTm(&time, aTm);
    FMD_FARSITE(mFarsiteH)->CmMapEnvironment(code, time,
                                             (char *) aFile->ToA());

    return UErrFalse;
}

/**
 * \brief Write text or binary file.
 */
UErrCodeT CFmdFileWrite::Special(const char *aFile, UFlagCodeT aFlag)
{
    CrownFireGrid(aFile, aFlag);
    IntensityGrid(aFile, aFlag);
    FlameLengthGrid(aFile, aFlag);
    SpreadRateGrid(aFile, aFlag);
    SpreadDirectionGrid(aFile, aFlag);
    HeatPerUnitAreaGrid(aFile, aFlag);
    ReactionIntensityGrid(aFile, aFlag);
    ArrivalTimeGrid(aFile, aFlag);

    return UErrFalse;
}

/**
 * \brief Write crown fire grid.
 */
UErrCodeT CFmdFileWrite::CrownFireGrid(const char *aFile, UFlagCodeT aFlag)
{
    const UStringT suffix = "_crownfiregrid";
    UStringT file(aFile);
    if (aFlag == UFlagOff)
    {
        file = file + suffix + kSDot + kSAsc;
        FMD_FARSITE(mFarsiteH)->WriteCrownFireGrid((char *)file.ToA());
    }
    else
    {
        file = file + suffix + kSDot + kSFbg;
        FMD_FARSITE(mFarsiteH)->WriteCrownFireGridBinary((char *)file.ToA());
    }

    return UErrFalse;
}

/**
 * \brief Write intensity grid.
 */
UErrCodeT CFmdFileWrite::IntensityGrid(const char *aFile, UFlagCodeT aFlag)
{
    const UStringT suffix = "_intensitygrid";
    UStringT file(aFile);
    if (aFlag == UFlagOff)
    {
        file = file + suffix + kSDot + kSAsc;
        FMD_FARSITE(mFarsiteH)->WriteIntensityGrid((char *) file.ToA());
    }
    else
    {
        file = file + suffix + kSDot + kSFbg;
        FMD_FARSITE(mFarsiteH)->WriteIntensityGrid((char *) file.ToA());
    }

    return UErrFalse;
}

/**
 * \brief Write flame length grid.
 */
UErrCodeT CFmdFileWrite::FlameLengthGrid(const char *aFile, UFlagCodeT aFlag)
{
    const UStringT suffix = "_flamelengthgird";
    UStringT file(aFile);
    if (aFlag == UFlagOff)
    {
        file = file + suffix + kSDot +kSAsc;
        FMD_FARSITE(mFarsiteH)->WriteFlameLengthGrid((char *) file.ToA());
    }
    else
    {
        file = file + suffix + kSDot + kSFbg;
        FMD_FARSITE(mFarsiteH)->WriteFlameLengthGridBinary((char *) file.ToA());
    }

    return UErrFalse;
}

/**
 * \brief Write spread rate grid.
 */
UErrCodeT CFmdFileWrite::SpreadRateGrid(const char *aFile, UFlagCodeT aFlag)
{
    const UStringT suffix = "_spreadrategrid";
    UStringT file(aFile);
    if (aFlag == UFlagOff)
    {
        file = file + suffix + kSDot + kSAsc;
        FMD_FARSITE(mFarsiteH)->WriteSpreadRateGrid((char *) file.ToA());
    }
    else
    {
        file = file + suffix + kSDot + kSFbg;
        FMD_FARSITE(mFarsiteH)->WriteSpreadRateGridBinary((char *) file.ToA());
    }

    return UErrFalse;
}

/**
 * \brief Write spread direction grid.
 */
UErrCodeT CFmdFileWrite::SpreadDirectionGrid(const char *aFile, UFlagCodeT aFlag)
{
    const UStringT suffix = "_spreaddirectiongrid";
    UStringT file(aFile);
    if (aFlag == UFlagOff)
    {
        file = file + suffix + kSDot + kSAsc;
        FMD_FARSITE(mFarsiteH)->WriteSpreadDirectionGrid((char *) file.ToA());
    }
    else
    {
        file = file + suffix + kSDot + kSFbg;
        FMD_FARSITE(mFarsiteH)->WriteSpreadDirectionGridBinary((char *) file.ToA());
    }

    return UErrFalse;
}

/**
 * \brief Write heat per unit area grid.
 */
UErrCodeT CFmdFileWrite::HeatPerUnitAreaGrid(const char *aFile, UFlagCodeT aFlag)
{
    const UStringT suffix = "_heatperunitareagrid";
    UStringT file(aFile);
    if (aFlag == UFlagOff)
    {
        file = file + suffix + kSDot + kSAsc;
        FMD_FARSITE(mFarsiteH)->WriteHeatPerUnitAreaGrid((char *) file.ToA());
    }
    else
    {
        file = file + suffix + kSDot + kSFbg;
        FMD_FARSITE(mFarsiteH)->WriteHeatPerUnitAreaGridBinary((char *) file.ToA());
    }

    return UErrFalse;
}

/**
 * \brief Write reaction intensity grid.
 */
UErrCodeT CFmdFileWrite::ReactionIntensityGrid(const char *aFile, UFlagCodeT aFlag)
{
    const UStringT suffix = "_reactionintensitygrid";
    UStringT file(aFile);
    if (aFlag == UFlagOff)
    {
        file = file + suffix + kSDot + kSAsc;
        FMD_FARSITE(mFarsiteH)->WriteReactionIntensityGrid((char *) file.ToA());
    }
    else
    {
        file = file + suffix + kSDot + kSFbg;
        FMD_FARSITE(mFarsiteH)->WriteReactionIntensityGridBinary((char *) file.ToA());
    }

    return UErrFalse;
}

/**
 * \brief Write arrival time grid.
 */
UErrCodeT CFmdFileWrite::ArrivalTimeGrid(const char *aFile, UFlagCodeT aFlag)
{
    const UStringT suffix = "_arrivaltimegrid";
    UStringT file(aFile);
    if (aFlag == UFlagOff)
    {
        file = file + suffix + kSDot + kSAsc;
        FMD_FARSITE(mFarsiteH)->WriteArrivalTimeGrid((char *) file.ToA());
    }
    else
    {
        file = file + suffix + kSDot + kSFbg;
        FMD_FARSITE(mFarsiteH)->WriteArrivalTimeGridBinary((char *) file.ToA());
    }

    return UErrFalse;
}

/**
 * \brief Write common file.
 */
UErrCodeT CFmdFileWrite::Common(const char *aFile)
{
    IgnitionGrid(aFile);
    PerimetersShape(aFile);
    SpotGrid(aFile);
    SpotData(aFile);
    SpotShape(aFile);
    Timings(aFile);

    return UErrFalse;
}

/**
 * \brief Write ignition grid file.
 */
UErrCodeT CFmdFileWrite::IgnitionGrid(const char *aFile)
{
    const UStringT suffix = "_ignitiongrid";
    UStringT file(aFile);
    file = file + suffix + kSDot + kSAsc;
    FMD_FARSITE(mFarsiteH)->WriteIgnitionGrid((char *) file.ToA());

    return UErrFalse;
}

/**
 * \brief Write perimeters shape file.
 */
UErrCodeT CFmdFileWrite::PerimetersShape(const char *aFile)
{
    const UStringT suffix = "_perimetersshape";
    UStringT file(aFile);
    file = file + suffix + kSDot + kSShp;
    FMD_FARSITE(mFarsiteH)->WritePerimetersShapeFile((char *) file.ToA());

    return UErrFalse;
}

/**
 * \brief Write spot grid.
 */
UErrCodeT CFmdFileWrite::SpotGrid(const char *aFile)
{
    const UStringT suffix = "_spotgrid";
    UStringT file(aFile);
    file = file + suffix + kSDot + kSAsc;
    FMD_FARSITE(mFarsiteH)->WriteSpotGrid((char *) file.ToA());

    return UErrFalse;
}

/**
 * \brief Write spot data file.
 */
UErrCodeT CFmdFileWrite::SpotData(const char *aFile)
{
    const UStringT suffix = "_spotdata";
    UStringT file(aFile);
    file = file + suffix + kSDot + kSCsv;
    FMD_FARSITE(mFarsiteH)->WriteSpotDataFile((char *) file.ToA());

    return UErrFalse;
}

/**
 * \brief Write spot shape file.
 */
UErrCodeT CFmdFileWrite::SpotShape(const char *aFile)
{
    const UStringT suffix = "_spotshape";
    UStringT file(aFile);
    file = file + suffix + kSDot + kSShp;
    FMD_FARSITE(mFarsiteH)->WriteSpotShapeFile((char *) file.ToA());

    return UErrFalse;
}

/**
 * \brief Write timings file.
 */
UErrCodeT CFmdFileWrite::Timings(const char *aFile)
{
    const UStringT suffix = "_timings";
    UStringT file(aFile);
    file = file + suffix + kSDot + kSTxt;
    FMD_FARSITE(mFarsiteH)->WriteTimingsFile((char *) file.ToA());

    return UErrFalse;
}
