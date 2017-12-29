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
/* // ust */
#include "ust/ust_containertype.hpp"
%}

typedef UContainerT<FmdCfgWeatherT> FmdCfgWeatherCtnT;
typedef UIteratorT<FmdCfgWeatherT> FmdCfgWeatherItT;
typedef UContainerT<FmdCfgFuelMoistureT> FmdCfgFuelMoistureCtnT;
typedef UIteratorT<FmdCfgFuelMoistureT> FmdCfgFuelMoistureItT;

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
    FmdCfgTimeT(const UIntT aYear, const UIntT aMon, const UIntT aMDay,
                const UIntT aHour, const UIntT aMin);
    ~FmdCfgTimeT();

    UErrCodeT Init();

    // Set.
    UErrCodeT SetAll(const UIntT aYear, const UIntT aMon, const UIntT aMDay,
                     const UIntT aHour, const UIntT aMin);
    UErrCodeT SetYear(const UIntT aYear);
    UErrCodeT SetMon(const UIntT aMon);
    UErrCodeT SetMDay(const UIntT aMDay);
    UErrCodeT SetHour(const UIntT aHour);
    UErrCodeT SetMin(const UIntT aMin);

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
                    const UFloatT aStep);
    ~FmdCfgBurnTimeT();

    UErrCodeT Init();

    // Set.
    UErrCodeT SetAll(const FmdCfgTimeT *aBegin, const FmdCfgTimeT *aEnd,
                     const UFloatT aStep);
    UErrCodeT SetBegin(const FmdCfgTimeT *aBegin);
    UErrCodeT SetEnd(const FmdCfgTimeT *aEnd);
    UErrCodeT SetStep(const UFloatT aStep);

    // Get.
    UErrCodeT All(FmdCfgTimeT *aBegin, FmdCfgTimeT *aEnd, UFloatT *aStep) const;
    const FmdCfgTimeT *Begin() const;
    const FmdCfgTimeT *End() const;
    UFloatT Step() const;
};

/**
 * \brief Fmd config for fuel moisture.
 */
class FmdCfgFuelMoistureT
{
  public:
    FmdCfgFuelMoistureT();
    FmdCfgFuelMoistureT(const UIntT aModel, const UIntT aFm1,
                        const UIntT aFm10, const UIntT aFm100,
                        const UIntT aFmLiveHerb, const UIntT aFmLiveWoody);
    ~FmdCfgFuelMoistureT();

    UErrCodeT Init();

    // Set.
    UErrCodeT SetAll(const UIntT aModel, const UIntT aFm1, const UIntT aFm10,
                     const UIntT aFm100, const UIntT aFmLiveHerb,
                     const UIntT aFmLiveWoody);
    UErrCodeT SetModel(const UIntT aModel);
    UErrCodeT SetFm1(const UIntT aFm1);
    UErrCodeT SetFm10(const UIntT aFm10);
    UErrCodeT SetFm100(const UIntT aFm100);
    UErrCodeT SetFmLiveHerb(const UIntT aFmLiveHerb);
    UErrCodeT SetFmLiveWoody(const UIntT aFmLiveWoody);

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

class FmdCfgWindT
{
  public:
    FmdCfgWindT();
    FmdCfgWindT(const UFloatT aSpeed, const UIntT aDirection);
    ~FmdCfgWindT();

    UErrCodeT Init();

    // Set.
    UErrCodeT SetAll(const UFloatT aSpeed, const UIntT aDirection);
    UErrCodeT SetSpeed(const UFloatT aSpeed);
    UErrCodeT SetDirection(const UIntT aDirection);

    // Get.
    UErrCodeT All(UFloatT *aSpeed, UIntT *aDirection) const;
    UFloatT Speed() const;
    UIntT Direction() const;
};

class FmdCfgCloudT
{
  public:
    FmdCfgCloudT();
    FmdCfgCloudT(const UIntT aCover, const UFloatT aPrecipAmount);
    ~FmdCfgCloudT();

    UErrCodeT Init();

    // Set value.
    UErrCodeT SetAll(const UIntT aCover, const UFloatT aPrecipAmount);
    UErrCodeT SetCover(const UIntT aCover);
    UErrCodeT SetPrecipAmount(const UFloatT aPrecipAmount);

    // Get value.
    UErrCodeT All(UIntT *aCover, UFloatT *aPrecipAmount) const;
    UIntT Cover() const;
    UFloatT PrecipAmount() const;
};

class FmdCfgAirT
{
  public:
    FmdCfgAirT();
    FmdCfgAirT(const UFloatT aTemperature, const UIntT aHumidity);
    ~FmdCfgAirT();

    UErrCodeT Init();

    // Set value.
    UErrCodeT SetAll(const UFloatT aTemperature, const UIntT aHumidity);
    UErrCodeT SetTemperature(const UFloatT aTemperature);
    UErrCodeT SetHumidity(const UIntT aHumidity);

    // Get value.
    UErrCodeT All(UFloatT *aTemperature, UIntT *aHumidity) const;
    UFloatT Temperature() const;
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

    UErrCodeT Init();

    // Set value.
    UErrCodeT SetAll(const FmdCfgTimeT *aTime, const FmdCfgWindT *aWind,
                     const FmdCfgCloudT *aCloud, const FmdCfgAirT *aAir);
    UErrCodeT SetTime(const FmdCfgTimeT *aTime);
    UErrCodeT SetWind(const FmdCfgWindT *aWind);
    UErrCodeT SetCloud(const FmdCfgCloudT *aCloud);
    UErrCodeT SetAir(const FmdCfgAirT *aAir);

    // Get value.
    UErrCodeT All(FmdCfgTimeT *aTime, FmdCfgWindT *aWind,
                  FmdCfgCloudT *aCloud, FmdCfgAirT *aAir) const;
    const FmdCfgTimeT *Time() const;
    const FmdCfgWindT *Wind() const;
    const FmdCfgCloudT *Cloud() const;
    const FmdCfgAirT *Air() const;
};

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
    CFmdCfgWrite(UFileT *aFile);
    ~CFmdCfgWrite();

    UErrCodeT Init();

    UErrCodeT SetAll(const FmdCfgBurnTimeT *aTime,
                     const FmdCfgWeatherCtnT *aWeatherCtn, const UFloatT aElev,
                     const FmdCfgFuelMoistureCtnT *aFmCtn);

    UErrCodeT SetBurnTime(const FmdCfgBurnTimeT *aTime);
    UErrCodeT SetWeather(const FmdCfgWeatherCtnT *aWeatherCtn);
    UErrCodeT SetElevation(const UFloatT aElev);
    UErrCodeT SetFuelMoisture(const FmdCfgFuelMoistureCtnT *aFmCtn);

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
    UErrCodeT IgnitionGjson(const UStringT *aGjson);
    // Set barrier file.
    UErrCodeT BarrierGjson(const UStringT *aGjson);
};

class CFmdFileWrite
{
  public:
    UErrCodeT Init();
    // Special.
    UErrCodeT PerimetersGjson(UStringT *aStr);
};

class CFmdBurnCtl
{
  public:
    UErrCodeT Init();
    CFmdBurnTime *Time();
};
