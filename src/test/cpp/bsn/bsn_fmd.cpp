/******************************************************************************
 * $Id: bsn_fmd.hpp 2017-08 $
 *
 * Project:  Business Logic library.
 * Purpose:  Test fmd control api implementation.
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
 *****************************************************************************/

#include "bsn_fmd.hpp"

// base
#include "base_macrodefn.hpp"
// fmd
#include "fmd_ctl.hpp"
#include "fmd_filectl.hpp"
#include "fmd_filecfg.hpp"
#include "fmd_cfgwrite.hpp"
#include "fmd_fileload.hpp"
#include "fmd_filewrite.hpp"
#include "fmd_burnctl.hpp"
#include "fmd_burntime.hpp"
#include "fmd_masterctl.hpp"
#include "fmd_typectl.hpp"

/**
 * \brief Constructor.
 */
CBsnFmd::CBsnFmd()
{
    BMD_POINTER_INIT(mFmd);
}

/**
 * \brief Destructor.
 */
CBsnFmd::~CBsnFmd()
{
    BMD_POINTER_INIT(mFmd);
}

/**
 * \brief Initilize.
 */
UErrCodeT CBsnFmd::Init()
{
    BMD_MODULE(mFmd, CFmdCtl, HubMFmd);

    return UErrFalse;
}

/**
 * \brief Test.
 */
UErrCodeT CBsnFmd::Test()
{
    // TestConfig();
    TestWrite();

    return UErrFalse;
}

/**
 * \brief Test config.
 */
UErrCodeT CBsnFmd::TestConfig()
{
    CFmdFileCtl *fileCtl = mFmd->File();
    const UStringT fileName = "../../data/geojson/tmp/forest_cfg.input";
    CFmdFileCfg *cfg = fileCtl->Cfg(&fileName, FmdFileCfgCreate);
    CFmdCfgWrite *cfgWrite = cfg->Write();

    FmdCfgBurnTimeT time;
    FmdCfgTimeT begin;
    begin.SetAll(2017, 8, 1, 9, 30);
    FmdCfgTimeT end;
    end.SetAll(2017, 8, 1, 10, 50);
    time.SetAll(&begin, &end, 1);
    cfgWrite->BurnTime(&time);

    FmdCfgWeatherCtnT weatherCtn(UContainerList);
    FmdCfgWeatherT weather;
    FmdCfgTimeT weatherTime;
    weatherTime.SetAll(2017, 8, 1, 9, 30);
    FmdCfgWindT weatherWind;
    weatherWind.SetAll(100, 125);
    FmdCfgCloudT weatherCloud;
    weatherCloud.SetAll(0, 0.2);
    FmdCfgAirT weatherAir;
    weatherAir.SetAll(30, 80);
    weather.SetAll(&weatherTime, &weatherWind, &weatherCloud, &weatherAir);
    weatherCtn.Add(weather);
    cfgWrite->Weather(&weatherCtn);

    UIntT elevation = 43.4;
    cfgWrite->Elevation(elevation);

    FmdCfgFuelMoistureCtnT fmCtn(UContainerList);
    FmdCfgFuelMoistureT fm;
    fm.SetAll(0, 3, 4, 6, 70, 100);
    fmCtn.Add(fm);
    cfgWrite->FuelMoisture(&fmCtn);

    return UErrFalse;
}

/**
 * \brief Test write.
 */
UErrCodeT CBsnFmd::TestWrite()
{
    CFmdFileCtl *fileCtl = mFmd->File();

    // Load.
    CFmdFileLoad *fileLoad = fileCtl->Load();
    const UStringT cfgFile = "../../data/geojson/tmp/forest_cfg.input";

    // const UStringT lcpFile = "../../data/geojson/tmp/forest.lcp";
    // const UStringT ignitionFile = "../../data/geojson/tmp/forest_ignition.shp";
    // const UStringT barrierFile = "../../data/geojson/tmp/forest_barrier.shp";

    const UStringT lcpFile = "../../data/geojson/tmp/fmd_test/fmd_test_2.lcp";
    const UStringT ignitionFile = "../../data/geojson/tmp/fmd_test/fmd_testignition_2.shp";
    const UStringT barrierFile = "../../data/geojson/tmp/fmd_test/fmd_testbarrier.shp";

    fileLoad->All(&cfgFile, &lcpFile, &ignitionFile, &barrierFile);

    // Master.
    CFmdMasterCtl *masterCtl = mFmd->Master();
    masterCtl->Launch();

    // Write.
    CFmdFileWrite *fileWrite = fileCtl->Write();
    CFmdBurnTime *burnTime = mFmd->Burn()->Time();
    CFmdTypeCtl *typeCtl = mFmd->Type();
    const UStringT outFile = "../../data/geojson/tmp/forest/test";
    UFloatT sTime;
    burnTime->Simulate(&sTime);
    BTimeTmT tm;
    typeCtl->ToTm(&tm, sTime);
    // fileWrite->MapEnv(&outFile, &tm, FmdMapEnvIntervalOneH);
    fileWrite->PerimetersShape(&outFile);
    // fileWrite->All(&outFile);

    return UErrFalse;
}
