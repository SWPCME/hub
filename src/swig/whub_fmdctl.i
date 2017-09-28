/******************************************************************************
 * $Id: whub_fmdctl.i 2017-09 $
 *
 * Project:  whub (Wrap hub).
 * Purpose:  Api for fmd.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-09 ~ 2017, Weiwei Huang
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

%module "WHubFmd"
%{
// fmd
#include "fmd/fmd_ctl.hpp"
#include "fmd/fmd_masterctl.hpp"
#include "fmd/fmd_filectl.hpp"
#include "fmd/fmd_filecfg.hpp"
#include "fmd/fmd_cfgread.hpp"
#include "fmd/fmd_cfgwrite.hpp"
#include "fmd/fmd_fileload.hpp"
#include "fmd/fmd_filewrite.hpp"
#include "fmd/fmd_burnctl.hpp"
// ust
#include "ust/ust_containertype.hpp"
%}

%include "whub_ctl.i"
%include "whub_ustctl.i"

typedef enum
{
    FmdFileCfgCreate = 1,
    FmdFileCfgLoad   = 2,
} FmdFileCfgCodeT;

/**
 * \brief Fmd config for time type.
 */
class FmdCfgTimeT
{
  public:
    FmdCfgTimeT();
    FmdCfgTimeT(UIntT aYear, UIntT aMon, UIntT aMDay, UIntT aHour,
                UIntT aMin);
    ~FmdCfgTimeT();

    // Set.
    UErrCodeT SetAll(UIntT aYear, UIntT aMon, UIntT aMDay, UIntT aHour,
                     UIntT aMin);
    UErrCodeT SetYear(UIntT aYear);
    UErrCodeT SetMon(UIntT aMon);
    UErrCodeT SetMDay(UIntT aMDay);
    UErrCodeT SetHour(UIntT aHour);
    UErrCodeT SetMin(UIntT aMin);

    // Get.
    UErrCodeT All(UIntT *aYear, UIntT *aMon, UIntT *aMDay, UIntT *aHour,
                  UIntT *aMin) const;
    UIntT Year() const;
    UIntT Mon() const;
    UIntT MDay() const;
    UIntT Hour() const;
    UIntT Min() const;
};

/**
 * \brief Fmd config for burn time type.
 */
class FmdCfgBurnTimeT
{
  public:
    FmdCfgBurnTimeT();
    FmdCfgBurnTimeT(const FmdCfgTimeT *aBegin, const FmdCfgTimeT *aEnd,
                    UIntT aStep);
    ~FmdCfgBurnTimeT();

    // Set.
    UErrCodeT SetAll(const FmdCfgTimeT *aBegin, const FmdCfgTimeT *aEnd, UIntT aStep);
    // Get.
    UErrCodeT All(FmdCfgTimeT *aBegin, FmdCfgTimeT *aEnd, UIntT *aStep) const;
    const FmdCfgTimeT *Begin() const;
    const FmdCfgTimeT *End() const;
    UIntT Step() const;
};

/**
 * \brief Fmd config for fuel moisture.
 */
class FmdCfgFuelMoistureT
{
  public:
    FmdCfgFuelMoistureT();
    FmdCfgFuelMoistureT(UIntT aModel, UIntT aFm1, UIntT aFm10, UIntT aFm100,
                        UIntT aFmLiveHerb, UIntT aFmLiveWoody);
    ~FmdCfgFuelMoistureT();

    // Set.
    UErrCodeT SetAll(UIntT aModel, UIntT aFm1, UIntT aFm10, UIntT aFm100,
                     UIntT aFmLiveHerb, UIntT aFmLiveWoody);
    // Get.
    UErrCodeT All(UIntT *aModel, UIntT *aFm1, UIntT *aFm10, UIntT *aFm100,
                  UIntT *aFmLiveHerb, UIntT *aFmLiveWoody) const;
    UIntT Model() const;
    UIntT Fm1() const;
    UIntT Fm10() const;
    UIntT Fm100() const;
    UIntT FmLiveHerb() const;
    UIntT FmLiveWoody() const;
};
typedef UContainerT<FmdCfgFuelMoistureT> FmdCfgFuelMoistureCtnT;
typedef UIteratorT<FmdCfgFuelMoistureT> FmdCfgFuelMoistureItT;

class FmdCfgWindT
{
  public:
    FmdCfgWindT();
    FmdCfgWindT(UIntT aSpeed, UIntT aDirection);
    ~FmdCfgWindT();

    // Set.
    UErrCodeT SetAll(UIntT aSpeed, UIntT aDirection);

    // Get.
    UErrCodeT All(UIntT *aSpeed, UIntT *aDirection) const;
    UIntT Speed() const;
    UIntT Direction() const;
};

class FmdCfgCloudT
{
  public:
    FmdCfgCloudT();
    FmdCfgCloudT(UIntT aCover, UFloatT aPrecipAmount);
    ~FmdCfgCloudT();

    // Set value.
    UErrCodeT SetAll(UIntT aCover, UFloatT aPrecipAmount);

    // Get value.
    UErrCodeT All(UIntT *aCover, UFloatT *aPrecipAmount) const;
    UIntT Cover() const;
    UIntT PrecipAmount() const;
};

class FmdCfgAirT
{
  public:
    FmdCfgAirT();
    FmdCfgAirT(UIntT aTemperature, UIntT aHumidity);
    ~FmdCfgAirT();

    // Set value.
    UErrCodeT SetAll(UIntT aTemperature, UIntT aHumidity);

    // Get value.
    UErrCodeT All(UIntT *aTemperature, UIntT *aHumidity) const;
    UIntT Temperature() const;
    UIntT Humidity() const;
};

/**
 * \brief Fmd config for weather.
 */
class FmdCfgWeatherT
{
  public:
    FmdCfgWeatherT();
    FmdCfgWeatherT(const FmdCfgTimeT *aTime, const FmdCfgWindT *aWind,
                   const FmdCfgCloudT *aCloud, const FmdCfgAirT *aAir);
    ~FmdCfgWeatherT();

    // Set value.
    UErrCodeT SetAll(const FmdCfgTimeT *aTime, const FmdCfgWindT *aWind,
                     const FmdCfgCloudT *aCloud, const FmdCfgAirT *aAir);

    // Get value.
    UErrCodeT All(FmdCfgTimeT *aTime, FmdCfgWindT *aWind,
                  FmdCfgCloudT *aCloud, FmdCfgAirT *aAir) const;
    const FmdCfgTimeT *Time() const;
    const FmdCfgWindT *Wind() const;
    const FmdCfgCloudT *Cloud() const;
    const FmdCfgAirT *Air() const;
};
typedef UContainerT<FmdCfgWeatherT> FmdCfgWeatherCtnT;
typedef UIteratorT<FmdCfgWeatherT> FmdCfgWeatherItT;

class CFmdCtl
{
  public:
    UErrCodeT Init();
    // Controler.
    CFmdMasterCtl *Master();
    CFmdFileCtl *File();
    CFmdBurnCtl *Burn();
};

class CFmdMasterCtl
{
  public:
    UErrCodeT Init();
    UErrCodeT Launch();
    UErrCodeT Cancel();
};

class CFmdFileCtl
{
  public:
    UErrCodeT Init();
    CFmdFileCfg *Cfg(const UStringT *aFileName,
                     const FmdFileCfgCodeT aCfg);
    CFmdFileLoad *Load();
    CFmdFileWrite *Write();
};

class CFmdFileCfg
{
  public:
    UErrCodeT Init();
    CFmdCfgRead *Read();
    CFmdCfgWrite *Write();
};

class CFmdCfgRead
{
  public:
    UErrCodeT Init();
};

class CFmdCfgWrite
{
  public:
    UErrCodeT Init();
    UErrCodeT BurnTime(const FmdCfgBurnTimeT *aTime);
    UErrCodeT Weather(const FmdCfgWeatherCtnT *aWeatherCtn);
    UErrCodeT Elevation(UFloatT aElev);
    UErrCodeT FuelMoisture(const FmdCfgFuelMoistureCtnT *aFm);
    UErrCodeT Save();
};

class CFmdFileLoad
{
  public:
    UErrCodeT Init();
    // Load All file.
    UErrCodeT All(const UStringT *aCfg, const UStringT *aLcp,
                  const UStringT *aIgnition, const UStringT *aBarrier);
    // Load configuration file.
    UErrCodeT Cfg(const UStringT *aFile);
    // Load landscape file.
    UErrCodeT Lcp(const UStringT *aFile);
    // Set ignition file.
    UErrCodeT Ignition(const UStringT *aFile);
    // Set barrier file.
    UErrCodeT Barrier(const UStringT *aFile);
};

class CFmdFileWrite
{
  public:
    UErrCodeT Init();
    UErrCodeT All(const UStringT *aFile, UFlagCodeT aFlag = UFlagOff);
    // Map Environment.
    UErrCodeT MapEnv(const UStringT *aFile, BTimeTmT *aTm,
                     FmdMapEnvIntervalCodeT aCode);
    // Special.
    UErrCodeT Special(const UStringT *aFile, UFlagCodeT aFlag = UFlagOff);
    UErrCodeT CrownFireGrid(const UStringT *aFile, UFlagCodeT aFlag = UFlagOff);
    UErrCodeT IntensityGrid(const UStringT *aFile, UFlagCodeT aFlag = UFlagOff);
    UErrCodeT FlameLengthGrid(const UStringT *aFile, UFlagCodeT aFlag = UFlagOff);
    UErrCodeT SpreadRateGrid(const UStringT *aFile, UFlagCodeT aFlag = UFlagOff);
    UErrCodeT SpreadDirectionGrid(const UStringT *aFile,
                                  UFlagCodeT aFlag = UFlagOff);
    UErrCodeT HeatPerUnitAreaGrid(const UStringT *aFile,
                                  UFlagCodeT aFlag = UFlagOff);
    UErrCodeT ReactionIntensityGrid(const UStringT *aFile,
                                    UFlagCodeT aFlag = UFlagOff);
    UErrCodeT ArrivalTimeGrid(const UStringT *aFile, UFlagCodeT aFlag = UFlagOff);
    // Common.
    UErrCodeT Common(const UStringT *aFile);
    UErrCodeT IgnitionGrid(const UStringT *aFile);
    UErrCodeT PerimetersShape(const UStringT *aFile);
    UErrCodeT SpotGrid(const UStringT *aFile);
    UErrCodeT SpotData(const UStringT *aFile);
    UErrCodeT SpotShape(const UStringT *aFile);
    UErrCodeT Timings(const UStringT *aFile);
};

class CFmdBurnCtl
{
  public:
    UErrCodeT Init();
    CFmdBurnTime *Time();
};
