/******************************************************************************
 * $Id: bsn_fmd.hpp 2017-06 $
 *
 * Project:  Business Logic library.
 * Purpose:  Test fmd control api implementation.
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
    CFmdFileCtl *fileCtl = mFmd->File();
    const UStringT fileName = "../../data/geojson/tmp/forest_cfg.input";
    CFmdFileCfg *cfg = fileCtl->Cfg(&fileName, FmdFileCfgCreate);
    CFmdCfgWrite *cfgWrite = cfg->Write();

    FmdCfgBurnTimeT time;
    FmdCfgTimeT *begin = &(time.begin);
    begin->year = 2017;
    begin->mon = 8;
    begin->mday = 1;
    begin->hour = 9;
    begin->min = 30;
    FmdCfgTimeT *end = &(time.end);
    end->year = 2017;
    end->mon = 8;
    end->mday = 1;
    end->hour = 9;
    end->min = 50;
    time.step = 5;
    cfgWrite->BurnTime(&time);

    FmdCfgWeatherCtnT weatherCtn(UContainerList);
    FmdCfgWeatherT weather;
    weather.time.year = 2017;
    weather.time.mon = 8;
    weather.time.mday = 1;
    weather.time.hour = 9;
    weather.time.min = 30;
    weather.air.temperature = 30;
    weather.air.humidity = 80;
    weather.cloud.precipAmount = 0;
    weather.cloud.cover = 0.2;
    weather.wind.speed = 100;
    weather.wind.direction = 125;
    weatherCtn.Add(weather);
    cfgWrite->Weather(&weatherCtn);

    UIntT elevation = 43.4;
    cfgWrite->Elevation(elevation);

    FmdCfgFuelMoisturesCtnT fmCtn(UContainerList);
    FmdCfgFuelMoisturesT fm;
    fm.model = 0;
    fm.fm1 = 3;
    fm.fm10 = 4;
    fm.fm100 = 6;
    fm.fmLiveHerb = 70;
    fm.fmLiveWoody = 100;
    fmCtn.Add(fm);
    cfgWrite->FuelMoistures(&fmCtn);

    // CFmdFileLoad *fileLoad = fileCtl->Load();
    // CFmdFileWrite *fileWrite = fileCtl->Write();
    // CFmdBurnCtl *burnCtl = mFmd->Burn();
    // CFmdBurnTime *burnTime = burnCtl->Time();

    // fileLoad->All();
    // fileWrite->All();

    return UErrFalse;
}
