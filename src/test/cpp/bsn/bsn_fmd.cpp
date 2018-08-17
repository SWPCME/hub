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
// hub
#include "hub_ctl.hpp"
#include "hub_modulectl.hpp"
// ust
#include "ust_stringtype.hpp"
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
    BMD_POINTER_INIT(mHub);
    BMD_POINTER_INIT(mModule);
    BMD_POINTER_INIT(mFmd);
    mHub = CHubCtl::Hub();
    mModule = mHub->RegModule();
    UStringT tmp = "/home/swpcme/tmp";
    mModule->SetTmpDir(&tmp);
}

/**
 * \brief Destructor.
 */
CBsnFmd::~CBsnFmd()
{
    BMD_POINTER_INIT(mFmd);
    mHub->DeregModule(mModule);
    BMD_POINTER_INIT(mModule);
    BMD_POINTER_INIT(mHub);
}

/**
 * \brief Initilize.
 */
UErrCodeT CBsnFmd::Init()
{
    mModule->Register(HubMFmd);
    mFmd = (CFmdCtl *) mModule->Module(HubMFmd);
    mDataPath = "../../../../data";

    return UErrFalse;
}

/**
 * \brief Test.
 */
UErrCodeT CBsnFmd::Test()
{
    TestConfig();
    TestWrite();

    // for (int i = 0; i <= 2; ++i)
    // {
    //     mHub->DeregModule(mModule);
    //     mModule = mHub->RegModule();
    //     UStringT tmp = "/home/swpcme/tmp";
    //     mModule->SetTmpDir(&tmp);
    //     mModule->Register(HubMFmd);
    //     mFmd = (CFmdCtl *) mModule->Module(HubMFmd);
    //     TestWrite();
    // }

    return UErrFalse;
}

/**
 * \brief Test config.
 */
UErrCodeT CBsnFmd::TestConfig()
{
    CFmdFileCtl *fileCtl = mFmd->File();
    UStringT fileName = mDataPath;
    fileName += "/ctgy/fmd/3/1.input";
    // fileName += "/ctgy/fmd/baiyun_m/baiyun_m.input";
    CFmdFileCfg *cfg = fileCtl->Cfg(&fileName, FmdFileCfgCreate);
    CFmdCfgWrite *cfgWrite = cfg->Write();

    FmdCfgBurnTimeT time;
    FmdCfgTimeT begin;
    begin.SetAll(2017, 8, 1, 9, 30);
    FmdCfgTimeT end;
    end.SetAll(2017, 8, 1, 9, 50);
    time.SetAll(&begin, &end, 5);
    cfgWrite->SetBurnTime(&time);

    FmdCfgWeatherCtnT weatherCtn(UContainerList);
    FmdCfgWeatherT weather;
    FmdCfgTimeT weatherTime;
    weatherTime.SetAll(2017, 8, 1, 9, 30);
    FmdCfgWindT weatherWind;
    weatherWind.SetAll(10, 125);
    FmdCfgCloudT weatherCloud;
    weatherCloud.SetAll(0, 0);
    FmdCfgAirT weatherAir;
    weatherAir.SetAll(0, 0);
    weather.SetAll(&weatherTime, &weatherWind, &weatherCloud, &weatherAir);
    weatherCtn.Add(weather);

    weatherTime.SetAll(2017, 8, 1, 13, 30);
    weather.SetAll(&weatherTime, &weatherWind, &weatherCloud, &weatherAir);
    weatherCtn.Add(weather);

    weatherTime.SetAll(2017, 8, 1, 17, 30);
    weather.SetAll(&weatherTime, &weatherWind, &weatherCloud, &weatherAir);
    weatherCtn.Add(weather);

    weatherTime.SetAll(2017, 8, 1, 21, 30);
    weather.SetAll(&weatherTime, &weatherWind, &weatherCloud, &weatherAir);
    weatherCtn.Add(weather);

    cfgWrite->SetWeather(&weatherCtn);

    UFloatT elevation = 0.0;
    cfgWrite->SetElevation(elevation);

    FmdCfgFuelMoistureCtnT fmCtn(UContainerList);
    FmdCfgFuelMoistureT fm;
    // fm.SetAll(0, 3, 4, 6, 70, 100);
    fm.SetAll(0, 2, 2, 2, 2, 2);
    fmCtn.Add(fm);
    cfgWrite->SetFuelMoisture(&fmCtn);
    cfgWrite->Save();

    return UErrFalse;
}

/**
 * \brief Test write.
 */
UErrCodeT CBsnFmd::TestWrite()
{
    // data
    const UStringT ignitionStr1 =
      "{\"type\": \"FeatureCollection\",\"crs\": { \"type\": \"name\", \"properties\": { \"name\": \"urn:ogc:def:crs:EPSG::2383\" } },\"features\": [{ \"type\": \"Feature\", \"properties\": { \"id\": null }, \"geometry\": { \"type\": \"Polygon\", \"coordinates\": [ [ [ 450995.476157766825054, 2593188.469263007864356 ], [ 451108.449485530320089, 2593261.692716187797487 ], [ 451225.607010618434288, 2593081.772231230977923 ], [ 451052.485846314171795, 2593071.834762585349381 ], [ 450995.476157766825054, 2593188.469263007864356 ] ] ] } } ] }";
    const UStringT ignitionFile2 =
      "{\"type\": \"FeatureCollection\",\"crs\": { \"type\": \"name\", \"properties\": { \"name\": \"urn:ogc:def:crs:EPSG::4326\" } },\"features\": [{ \"type\": \"Feature\", \"properties\": { \"id\": null }, \"geometry\": { \"type\": \"Point\", \"coordinates\": [ 113.5255460, 23.4385733 ] } } ] }";

    CFmdFileCtl *fileCtl = mFmd->File();

    // Load.
    CFmdFileLoad *fileLoad = fileCtl->Load();

    UStringT cfgFile = mDataPath;
    UStringT lcpFile = mDataPath;
    UStringT ignitionFile = mDataPath;
    UStringT outFile = mDataPath;

    // cfgFile += "/ctgy/fmd/baiyun_m/baiyun_m.input";
    // ignitionFile += "/ctgy/fmd/baiyun_m/baiyun_m_i.shp";
    // lcpFile += "/ctgy/fmd/baiyun_m/baiyun_m.lcp";
    // outFile += "/ctgy/fmd/baiyun_m/baiyun_m_o";

    cfgFile += "/ctgy/fmd/3/1.input";
    lcpFile += "/ctgy/fmd/3/1.lcp";
    ignitionFile += "/ctgy/fmd/3/i1.shp";
    outFile += "/ctgy/fmd/3/o1";

    UStringT barrierFile1 = mDataPath;
    barrierFile1 += "/ctgy/fmd/3/b1.shp";

    UStringT barrierFile = "";

    // fileLoad->All(&cfgFile, &lcpFile, &ignitionFile, &barrierFile);
    fileLoad->Cfg(&cfgFile);
    fileLoad->Lcp(&lcpFile);
    fileLoad->Ignition(&ignitionFile);
    // fileLoad->IgnitionGjson(&ignitionStr1);
    // fileLoad->BarrierGjson(&barrierFile);

    // Master.
    CFmdMasterCtl *masterCtl = mFmd->Master();
    masterCtl->Launch();

    // Write.
    CFmdFileWrite *fileWrite = fileCtl->Write();
    CFmdBurnTime *burnTime = mFmd->Burn()->Time();
    CFmdTypeCtl *typeCtl = mFmd->Type();
    UFloatT sTime;
    burnTime->Simulate(&sTime);
    BTimeTmT tm;
    typeCtl->ToTm(&tm, sTime);
    // fileWrite->MapEnv(&outFile, &tm, FmdMapEnvIntervalOneH);
    fileWrite->PerimetersShape(&outFile);
    UStringT strGjson;
    fileWrite->PerimetersGjson(&strGjson);
    // fileWrite->All(&outFile);

    return UErrFalse;
}
