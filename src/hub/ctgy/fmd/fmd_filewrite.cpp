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

// base
#include "base_ctl.hpp"
#include "base_tmpctl.hpp"
// core
#include "core_ctl.hpp"
// gda
#include "gda_ctl.hpp"
#include "gda_bandctl.hpp"
#include "gda_ogrsrstype.hpp"
#include "gda_utilsctl.hpp"
#include "gda_utilstr.hpp"
#include "gda_trvtr.hpp"
#include "gda_trvtrtovtrtype.hpp"
// ogr
#include "ogr_ctl.hpp"
#include "ogr_driverctl.hpp"
#include "ogr_datasrcctl.hpp"
// wrap
#include "wrap_ctl.hpp"
// vtr
#include "vtr_ctl.hpp"
#include "vtr_frmtctl.hpp"
#include "vtr_frmtgjson.hpp"
// ctgy
#include "ctgy_ctl.hpp"
// fmd
#include "fmd_ctl.hpp"
#include "fmd_typectl.hpp"
#include "fmd_filectl.hpp"

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
    InitPointer();
}

/**
 * \brief Destructor.
 */
CFmdFileWrite::~CFmdFileWrite()
{
    InitPointer();
}

/**
 * \brief Initialize.
 */
UErrCodeT CFmdFileWrite::Init()
{
    CBaseCtl *base = CBaseCtl::Base();
    CBaseTmpCtl *tmp = base->Tmp();
    mTmpDir = tmp->Dir(HubMFmd);

    CGdaUtilsCtl *utils = NULL;
    GDA_UTILS_CTL(utils);
    mTr = utils->Tr();

    OGR_CTL(mOgr);

    VTR_CTL(mVtr);

    FMD_FARSITE_H(mFarsiteH);
    FMD_TYPE_CTL(mType);

    return UErrFalse;
}

/**
 * \brief Write file
 *
 * \param aFile, output file name.
 */
UErrCodeT CFmdFileWrite::All(const UStringT *aFile, UFlagCodeT aFlag)
{
    // Write all file.
    Special(aFile);
    Special(aFile, UFlagOn);
    Common(aFile);

    return UErrFalse;
}

UErrCodeT CFmdFileWrite::MapEnv(const UStringT *aFile, BTimeTmT *aTm,
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
UErrCodeT CFmdFileWrite::Special(const UStringT *aFile, UFlagCodeT aFlag)
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
UErrCodeT CFmdFileWrite::CrownFireGrid(const UStringT *aFile, UFlagCodeT aFlag)
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
UErrCodeT CFmdFileWrite::IntensityGrid(const UStringT *aFile, UFlagCodeT aFlag)
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
UErrCodeT CFmdFileWrite::FlameLengthGrid(const UStringT *aFile, UFlagCodeT aFlag)
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
UErrCodeT CFmdFileWrite::SpreadRateGrid(const UStringT *aFile, UFlagCodeT aFlag)
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
UErrCodeT CFmdFileWrite::SpreadDirectionGrid(const UStringT *aFile, UFlagCodeT aFlag)
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
UErrCodeT CFmdFileWrite::HeatPerUnitAreaGrid(const UStringT *aFile, UFlagCodeT aFlag)
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
UErrCodeT CFmdFileWrite::ReactionIntensityGrid(const UStringT *aFile, UFlagCodeT aFlag)
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
UErrCodeT CFmdFileWrite::ArrivalTimeGrid(const UStringT *aFile, UFlagCodeT aFlag)
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
UErrCodeT CFmdFileWrite::Common(const UStringT *aFile)
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
UErrCodeT CFmdFileWrite::IgnitionGrid(const UStringT *aFile)
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
UErrCodeT CFmdFileWrite::PerimetersShape(const UStringT *aFile, const UFlagCodeT aFlag)
{
    UStringT file(aFile);
    if (aFlag == UFlagOff)
    {
        const UStringT suffix = "_perimetersshape";
        file = file + suffix + kSDot + kSShp;
    }
    FMD_FARSITE(mFarsiteH)->WritePerimetersShapeFile((char *) file.ToA());

    return UErrFalse;
}

/**
 * \brief Write perimeters with geojson format string.
 */
UErrCodeT CFmdFileWrite::PerimetersGjson(UStringT *aStr)
{
    UStringT src = mTmpDir;
    src += "/tmp_perimetersgjson.shp";
    PerimetersShape(&src, UFlagOn);
    UStringT dst = mTmpDir;
    dst += "/tmp_perimetersgjson.geojson";

    // Open file.
    OgrFormatCodeT frmt = OgrFormatShp;
    mOgr->Register(frmt);
    COgrDriverCtl *dr = mOgr->Driver(frmt);
    COgrDatasrcCtl *ds = dr->Load(&src);
    OgrCtnDatasrcT dsCtn(UContainerList);
    dsCtn.Add(ds);

    // Translate.
    frmt = OgrFormatJson;
    CGdaTrVtr *trVtr = mTr->Vtr();
    BCtnStringT strV2vOpt(UContainerList);
    strV2vOpt.Add("-s_srs");
    strV2vOpt.Add("EPSG:2383");
    GdaTrVtrToVtrT r2rOpt;
    r2rOpt.SetFrmt(frmt);
    r2rOpt.SetOpt(&strV2vOpt);
    GdaOgrSrsT srs;
    GdaProjCsCodeT projCs = GdaProjCsWgs1984;
    srs.SetProjCs(projCs);
    r2rOpt.SetSrs(&srs);
    trVtr->ToVtr(&dst, &dsCtn, &r2rOpt);

    // String to file.
    CVtrFrmtCtl *frmtCtl = mVtr->Frmt();
    CVtrFrmtGjson *gjson = frmtCtl->Gjson();
    gjson->ToStr(aStr, &dst);

    return UErrFalse;
}

/**
 * \brief Write spot grid.
 */
UErrCodeT CFmdFileWrite::SpotGrid(const UStringT *aFile)
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
UErrCodeT CFmdFileWrite::SpotData(const UStringT *aFile)
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
UErrCodeT CFmdFileWrite::SpotShape(const UStringT *aFile)
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
UErrCodeT CFmdFileWrite::Timings(const UStringT *aFile)
{
    const UStringT suffix = "_timings";
    UStringT file(aFile);
    file = file + suffix + kSDot + kSTxt;
    FMD_FARSITE(mFarsiteH)->WriteTimingsFile((char *) file.ToA());

    return UErrFalse;
}

/***** Private A *****/

/**
 * \brief Initialize pointer.
 */
UErrCodeT CFmdFileWrite::InitPointer()
{
    BMD_POINTER_INIT(mTr);
    BMD_POINTER_INIT(mOgr);
    BMD_POINTER_INIT(mVtr);
    BMD_POINTER_INIT(mFarsiteH);
    BMD_POINTER_INIT(mType);

    return UErrFalse;
}

/***** Private B *****/
