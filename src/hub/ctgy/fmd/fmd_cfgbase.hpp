/******************************************************************************
 * $Id: fmd_cfgbase.hpp 2017-08 $
 *
 * Project:  FMD (FMD: Fire Model).
 * Purpose:  Config base definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-08 ~ 2017, Weiwei Huang
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

#ifndef FMD_CFGBASE_HPP_INCLUDED
#define FMD_CFGBASE_HPP_INCLUDED

#include "fmd_base.hpp"
#include "ust/ust_containertype.hpp"

const UIntT kNFmdCfg = 50;
const char kFmdCfgDelimeter[kNFmdCfg] = ":";
const char kFmdCfgVersion[kNFmdCfg] = "FARSITE INPUTS FILE VERSION 1.0";
const char kFmdCfgStartTime[kNFmdCfg] = "FARSITE_START_TIME";
const char kFmdCfgEndTime[kNFmdCfg] = "FARSITE_END_TIME";
const char kFmdCfgTimeStep[kNFmdCfg] = "FARSITE_TIMESTEP";
const char kFmdCfgDistanceRes[kNFmdCfg] = "FARSITE_DISTANCE_RES";
const char kFmdCfgPerimeterRes[kNFmdCfg] = "FARSITE_PERIMETER_RES";
const char kFmdCfgMinIgnitionVertexDistance[kNFmdCfg] =
  "FARSITE_MIN_IGNITION_VERTEX_DISTANCE";
const char kFmdCfgSpotGridResolution[kNFmdCfg] =
  "FARSITE_SPOT_GRID_RESOLUTION";
const char kFmdCfgSpotProbability[kNFmdCfg] = "FARSITE_SPOT_PROBABILITY";
const char kFmdCfgSpotIgnitionDelay[kNFmdCfg] = "FARSITE_SPOT_IGNITION_DELAY";
const char kFmdCfgMinimumSpotDistance[kNFmdCfg] =
  "FARSITE_MINIMUM_SPOT_DISTANCE";
const char kFmdCfgAccelerationOn[kNFmdCfg] = "FARSITE_ACCELERATION_ON";
const char kFmdCfgFillBarriers[kNFmdCfg] = "FARSITE_FILL_BARRIERS";
const char kFmdCfgSpottingSeed[kNFmdCfg] = "SPOTTING_SEED";
const char kFmdCfgBurnPeriods[kNFmdCfg] = "FARSITE_BURN_PERIODS"; // Array.
const char kFmdCfgFuelMoisturesData[kNFmdCfg] = "FUEL_MOISTURES_DATA"; // Array.
const char kFmdCfgElevation[kNFmdCfg] = "RAWS_ELEVATION";
const char kFmdCfgRawsUnits[kNFmdCfg] = "RAWS_UNITS";
const char kFmdCfgRaws[kNFmdCfg] = "RAWS"; // Array.
const char kFmdCfgFoliarMoistureContent[kNFmdCfg] = "FOLIAR_MOISTURE_CONTENT";
const char kFmdCfgCrownFireMethod[kNFmdCfg] = "CROWN_FIRE_METHOD";
const char kFmdCfgNumberProcessors[kNFmdCfg] = "NUMBER_PROCESSORS";
const char kFmdCfgFlameLength[kNFmdCfg] = "FLAMELENGTH";
const char kFmdCfgSpreadRate[kNFmdCfg] = "SPREADRATE";
const char kFmdCfgIntensity[kNFmdCfg] = "INTENSITY";
const char kFmdCfgCrownState[kNFmdCfg] = "CROWNSTATE";

/**
 * \brief Fmd config for time type.
 */
class FMD_LIB FmdCfgTimeT
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

    // Operator.
    UErrCodeT operator =(const FmdCfgTimeT &aTime);

  protected:
  private:
    UErrCodeT Init();

    UIntT mYear;
    UIntT mMon;
    UIntT mMDay;
    UIntT mHour;
    UIntT mMin;
};

/**
 * \brief Fmd config for burn time type.
 */
class FMD_LIB FmdCfgBurnTimeT
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

  protected:
  private:
    UErrCodeT Init();

    FmdCfgTimeT mBegin;
    FmdCfgTimeT mEnd;
    UIntT mStep;
};

/**
 * \brief Fmd config for fuel moisture.
 */
class FMD_LIB FmdCfgFuelMoistureT
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

  protected:
  private:
    UErrCodeT Init();

    UIntT mModel;
    UIntT mFm1;
    UIntT mFm10;
    UIntT mFm100;
    UIntT mFmLiveHerb;
    UIntT mFmLiveWoody;
};
typedef UContainerT<FmdCfgFuelMoistureT> FmdCfgFuelMoistureCtnT;
typedef UIteratorT<FmdCfgFuelMoistureT> FmdCfgFuelMoistureItT;

class FMD_LIB FmdCfgWindT
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

  protected:
  private:
    UErrCodeT Init();

    UIntT mSpeed;
    UIntT mDirection;
};

class FMD_LIB FmdCfgCloudT
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
    UFloatT PrecipAmount() const;

  protected:
  private:
    UErrCodeT Init();

    UIntT mCover;
    UFloatT mPrecipAmount;
};

class FMD_LIB FmdCfgAirT
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

  protected:
  private:
    UErrCodeT Init();

    UIntT mTemperature;
    UIntT mHumidity;
};

/**
 * \brief Fmd config for weather.
 */
class FMD_LIB FmdCfgWeatherT
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

  protected:
  private:
    UErrCodeT Init();

    FmdCfgTimeT mTime;
    FmdCfgWindT mWind;
    FmdCfgCloudT mCloud;
    FmdCfgAirT mAir;
};
typedef UContainerT<FmdCfgWeatherT> FmdCfgWeatherCtnT;
typedef UIteratorT<FmdCfgWeatherT> FmdCfgWeatherItT;

#endif  // FMD_CFGBASE_HPP_INCLUDED
