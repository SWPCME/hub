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

// base
#include "base_ctl.hpp"
// core
#include "core_ctl.hpp"
// gda
#include "gda_ctl.hpp"
#include "gda_bandctl.hpp"
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
#include "fmd_filectl.hpp"

/**
 * \brief Constructor.
 */
CFmdFileLoad::CFmdFileLoad()
{
}

/**
 * \brief Destructor.
 */
CFmdFileLoad::~CFmdFileLoad()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CFmdFileLoad::Init()
{
    FMD_FARSITE_H(mFarsiteH);

    CGdaUtilsCtl *utils = NULL;
    GDA_UTILS_CTL(utils);
    mTr = utils->Tr();

    OGR_CTL(mOgr);

    VTR_CTL(mVtr);

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
 * \brief Load ignition file, but get value with GeoJson.
 */
UErrCodeT CFmdFileLoad::IgnitionGjson(const UStringT *aGjson)
{
    UStringT file = mTmpDir;
    file += "ignition.shp";
    StrGjsonToShp(&file, aGjson);

    return Ignition(&file);
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

/**
 * \brief Load barrier file, but get value with GeoJson.
 */
UErrCodeT CFmdFileLoad::BarrierGjson(const UStringT *aGjson)
{
    UStringT file = mTmpDir;
    file += "ignition.shp";
    StrGjsonToShp(&file, aGjson);

    return Barrier(&file);
}

/***** Private A *****/

/**
 * \brief Initialize pointer.
 */
UErrCodeT CFmdFileLoad::InitPointer()
{
    BMD_POINTER_INIT(mTr);
    BMD_POINTER_INIT(mOgr);
    BMD_POINTER_INIT(mVtr);
    BMD_POINTER_INIT(mFarsiteH);

    return UErrFalse;
}

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

/**
 * \brief String of geojson to shp.
 */
UErrCodeT CFmdFileLoad::StrGjsonToShp(const UStringT *aDst,
                                      const UStringT *aSrc)
{
    UStringT file = mTmpDir;
    file += "strgjsontoshp.geojson";

    // String to file.
    CVtrFrmtCtl *frmtCtl = mVtr->Frmt();
    CVtrFrmtGjson *gjson = frmtCtl->Gjson();
    gjson->ToFile(&file, aSrc);

    // Open file.
    OgrFormatCodeT frmt = OgrFormatJson;
    mOgr->Register(frmt);
    COgrDriverCtl *dr = mOgr->Driver(frmt);
    COgrDatasrcCtl *ds = dr->Load(&file);
    OgrCtnDatasrcT dsCtn(UContainerList);
    dsCtn.Add(ds);

    // Translate.
    CGdaTrVtr *trVtr = mTr->Vtr();
    BCtnStringT strV2vOpt(UContainerList);
    GdaTrVtrToVtrT r2rOpt;
    r2rOpt.SetAll(frmt, &strV2vOpt);
    trVtr->ToVtr(aDst, &dsCtn, &r2rOpt);

    return UErrFalse;
}

/***** Private B *****/
