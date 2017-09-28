/******************************************************************************
 * $Id: fmd_cfgbase.cpp 2017-09 $
 *
 * Project:  FMD (FMD: Fire Model).
 * Purpose:  Config base implementation.
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

#include "fmd_cfgbase.hpp"

// base
#include "base_mathtype.hpp"

/***** FmdCfgTimeT A *****/

/**
 * \brief Constructor.
 */
FmdCfgTimeT::FmdCfgTimeT()
{
    Init();
}

/**
 * \brief Constructor.
 */
FmdCfgTimeT::FmdCfgTimeT(UIntT aYear, UIntT aMon, UIntT aMDay, UIntT aHour,
                         UIntT aMin)
{
    Init();
    SetAll(aYear, aMon, aMDay, aHour, aMin);
}

/**
 * \brief Destructor.
 */
FmdCfgTimeT::~FmdCfgTimeT()
{
}

/**
 * \brief Set all value.
 */
UErrCodeT FmdCfgTimeT::SetAll(UIntT aYear, UIntT aMon, UIntT aMDay, UIntT aHour,
                              UIntT aMin)
{
    mYear = aYear;
    mMon = aMon;
    mMDay = aMDay;
    mHour = aHour;
    mMin = aMin;
        
    return UErrFalse;
}

/**
 * \brief Set year.
 *
 * @param aYear Year.
 * @retrun UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT FmdCfgTimeT::SetYear(UIntT aYear)
{
    mYear = aYear;

    return UErrFalse;
}

/**
 * \brief Set month.
 *
 * @param aMon Month in one year.
 * @retrun UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT FmdCfgTimeT::SetMon(UIntT aMon)
{
    mMon = aMon;

    return UErrFalse;
}

/**
 * \brief Set day of month.
 *
 * @param aDay Day of month.
 * @retrun UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT FmdCfgTimeT::SetMDay(UIntT aMDay)
{
    mMDay = aMDay;

    return UErrFalse;
}

/**
 * \brief Set hour.
 *
 * @param aHour Hour in one day.
 * @retrun UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT FmdCfgTimeT::SetHour(UIntT aHour)
{
    mHour = aHour;

    return UErrFalse;
}

/**
 * \brief Set minute.
 *
 * @param aMinute Minute in one hour.
 * @retrun UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT FmdCfgTimeT::SetMin(UIntT aMin)
{
    mMin = aMin;

    return UErrFalse;
}

/**
 * \brief Get all value.
 */
UErrCodeT FmdCfgTimeT::All(UIntT *aYear, UIntT *aMon, UIntT *aMDay,
                           UIntT *aHour, UIntT *aMin) const
{
    *aYear = mYear;
    *aMon = mMon;
    *aMDay = mMDay;
    *aHour = mHour;
    *aMin = mMin;

    return UErrFalse;
}

/**
 * \brief Get year.
 *
 * @param aYear Year.
 * @retrun year, if successful; kSignNeg, if failed.
 */
UIntT FmdCfgTimeT::Year() const
{
    return mYear;
}

/**
 * \brief Get month.
 *
 * @param aMon Month in one year.
 * @retrun month, if successful; kSignNeg, if failed.
 */
UIntT FmdCfgTimeT::Mon() const
{
    return mMon;
}

/**
 * \brief Get day in one month.
 *
 * @param aMDay Day in one month.
 * @retrun day, if successful; kSignNeg, if failed.
 */
UIntT FmdCfgTimeT::MDay() const
{
    return mMDay;
}

/**
 * \brief Get hour in one day.
 *
 * @param aHour Hour in one day.
 * @retrun hour, if successful; kSignNeg, if failed.
 */
UIntT FmdCfgTimeT::Hour() const
{
    return mHour;
}

/**
 * \brief Get minute in one hour.
 *
 * @param aMin Minute in one hour.
 * @retrun minute, if successful; kSignNeg, if failed.
 */
UIntT FmdCfgTimeT::Min() const
{
    return mMin;
}

/**
 * \brief Overload operator of "=".
 *
 * @param FmdCfgTimeT itself.
 * @return UErrFalse, if successful; UErrTrue, failed.
 */
UErrCodeT FmdCfgTimeT::operator =(const FmdCfgTimeT &aTime)
{
    SetAll(aTime.Year(), aTime.Mon(), aTime.MDay(), aTime.Hour(), aTime.Min());

    return UErrFalse;
}

/***** FmdCfgTimeT Private A *****/

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT FmdCfgTimeT::Init()
{
    SetAll(kSignNeg, kSignNeg, kSignNeg, kSignNeg, kSignNeg);

    return UErrFalse;
}

/***** FmdCfgTimeT Private B *****/
/***** FmdCfgTimeT B *****/

/***** FmdCfgBurnTimeT A *****/

/**
 * \brief Constructor.
 */
FmdCfgBurnTimeT::FmdCfgBurnTimeT()
{
    Init();
}

/**
 * \brief Constructor.
 */
FmdCfgBurnTimeT::FmdCfgBurnTimeT(const FmdCfgTimeT *aBegin,
                                 const FmdCfgTimeT *aEnd,
                                 UIntT aStep)
{
    Init();
}


/**
 * \brief Destructor.
 */
FmdCfgBurnTimeT::~FmdCfgBurnTimeT()
{
}

/**
 * \brief Set all value.
 *
 * @param aBegin Time of begin.
 * @param aEnd Time of end.
 * @param aStep Time of step.
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT FmdCfgBurnTimeT::SetAll(const FmdCfgTimeT *aBegin,
                                  const FmdCfgTimeT *aEnd,
                                  UIntT aStep)
{
    mBegin = *aBegin;
    mEnd = *aEnd;
    mStep = aStep;

    return UErrFalse;
}

/**
 * \brief Get all value.
 *
 * @param aBegin Time of begin.
 * @param aEnd Time of end.
 * @param aStep Time of step.
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT FmdCfgBurnTimeT::All(FmdCfgTimeT *aBegin, FmdCfgTimeT *aEnd,
                               UIntT *aStep) const
{
    *aBegin = mBegin;
    *aEnd = mEnd;
    *aStep = mStep;

    return UErrFalse;
}

/**
 * \brief Get time of begin.
 *
 * @param aBegin Time of begin.
 * @retrun Time of begin, if successful; NULL, if failed.
 */
const FmdCfgTimeT *FmdCfgBurnTimeT::Begin() const
{
    return &mBegin;
}

/**
 * \brief Get time of end.
 *
 * @param aEnd Time of end.
 * @retrun Time of end, if successful; NULL, if failed.
 */
const FmdCfgTimeT *FmdCfgBurnTimeT::End() const
{
    return &mEnd;
}

/**
 * \brief Get time of step.
 *
 * @param aStep Time of step.
 * @return Time of step, if successful; NULL, if failed.
 */
UIntT FmdCfgBurnTimeT::Step() const
{
    return mStep;
}

/***** FmdCfgBurnTimeT Private A *****/

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT FmdCfgBurnTimeT::Init()
{
    return UErrFalse;
}

/***** FmdCfgBurnTimeT Private B *****/
/***** FmdCfgBurnTimeT B *****/

/***** FmdCfgFuelMoistureT A *****/

/**
 * \brief Constructor.
 */
FmdCfgFuelMoistureT::FmdCfgFuelMoistureT()
{
    Init();
}

/**
 * \brief Constructor.
 */
FmdCfgFuelMoistureT::FmdCfgFuelMoistureT(UIntT aModel, UIntT aFm1,
                                         UIntT aFm10, UIntT aFm100,
                                         UIntT aFmLiveHerb, UIntT aFmLiveWoody)
{
    Init();
    SetAll(aModel, aFm1, aFm10, aFm100, aFmLiveHerb, aFmLiveWoody);
}

/**
 * \brief Fmd config fuel moistures.
 */
FmdCfgFuelMoistureT::~FmdCfgFuelMoistureT()
{
}

/**
 * \brief Set all value.
 *
 * @param aModel Model.
 * @param aFm1 Fuel moistures 1.
 * @param aFm10 Fuel moistures 10.
 * @param aFm100 Fuel moistures 100.
 * @param aFmLiveHerb Live herb.
 * @param aFmLiveWoody Live woody.
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT FmdCfgFuelMoistureT::SetAll(UIntT aModel, UIntT aFm1, UIntT aFm10,
                                       UIntT aFm100, UIntT aFmLiveHerb,
                                       UIntT aFmLiveWoody)
{
    mModel = aModel;
    mFm1 = aFm1;
    mFm10 = aFm10;
    mFm100 = aFm100;
    mFmLiveHerb = aFmLiveHerb;
    mFmLiveWoody = aFmLiveWoody;

    return UErrFalse;
}

/**
 * \brief Get all value.
 *
 * @param aModel Model.
 * @param aFm1 Fuel moistures 1.
 * @param aFm10 Fuel moistures 10.
 * @param aFm100 Fuel moistures 100.
 * @param aFmLiveHerb Live herb.
 * @param aFmLiveWoody Live woody.
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT FmdCfgFuelMoistureT::All(UIntT *aModel, UIntT *aFm1, UIntT *aFm10,
                                    UIntT *aFm100, UIntT *aFmLiveHerb,
                                    UIntT *aFmLiveWoody) const
{
    *aModel = mModel;
    *aFm1 = mFm1;
    *aFm10 = mFm10;
    *aFm100 = mFm100;
    *aFmLiveHerb = mFmLiveHerb;
    *aFmLiveWoody = mFmLiveWoody;
    
    return UErrFalse;
}

/**
 * \brief Model value.
 *
 * @return Model value, if successful; kSignNeg, if failed.
 */
UIntT FmdCfgFuelMoistureT::Model() const
{
    return mModel;
}

/**
 * \brief Fuel moisture 1 value.
 *
 * @return Fuel moisture 1 value, if successful; kSignNeg, if failed.
 */
UIntT FmdCfgFuelMoistureT::Fm1() const
{
    return mFm1;
}

/**
 * \brief Fuel moisture 10 value.
 *
 * @return Fuel moisture 10 value, if successful; kSignNeg, if failed.
 */
UIntT FmdCfgFuelMoistureT::Fm10() const
{
    return mFm10;
}

/**
 * \brief Fuel moisture 100 value.
 *
 * @return Fuel moisture 100 value, if successful; kSignNeg, if failed.
 */
UIntT FmdCfgFuelMoistureT::Fm100() const
{
    return mFm100;
}

/**
 * \brief Fuel moisture of live herb.
 *
 * @return Fuel moisture of live herb, if successful; kSignNeg, if failed.
 */
UIntT FmdCfgFuelMoistureT::FmLiveHerb() const
{
    return mFmLiveHerb;
}

/**
 * \brief Fuel moisture of live woody.
 *
 * @return Fuel moisture of live woody, if successful; kSignNeg, if failed.
 */
UIntT FmdCfgFuelMoistureT::FmLiveWoody() const
{
    return mFmLiveWoody;
}

/***** FmdCfgFuelMoistureT Private A *****/

UErrCodeT FmdCfgFuelMoistureT::Init()
{
    return UErrFalse;
}

/***** FmdCfgFuelMoistureT Private B *****/
/***** FmdCfgFuelMoistureT B *****/

/***** FmdCfgWindT A *****/

/**
 * \brief Constructor.
 */
FmdCfgWindT::FmdCfgWindT()
{
    Init();
}

/**
 * \brief Constructor.
 */
FmdCfgWindT::FmdCfgWindT(UIntT aSpeed, UIntT aDirection)
{
    Init();
    SetAll(aSpeed, aDirection);
}

/**
 * \brief Destructor.
 */
FmdCfgWindT::~FmdCfgWindT()
{
}

/**
 * \brief Set all value.
 *
 * @param aSpeed Speed of wind.
 * @param aDirection Direction of wind.
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT FmdCfgWindT::SetAll(UIntT aSpeed, UIntT aDirection)
{
    mSpeed = aSpeed;
    mDirection = aDirection;

    return UErrFalse;
}

/**
 * \brief Get all value.
 *
 * @param aSpeed Speed of wind.
 * @param aDirection Direction of wind.
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT FmdCfgWindT::All(UIntT *aSpeed, UIntT *aDirection) const
{
    *aSpeed = mSpeed;
    *aDirection = mDirection;

    return UErrFalse;
}

/**
 * \brief Speed of wind.
 *
 * @return Speed of wind, if successful; kSignNeg, if failed.
 */
UIntT FmdCfgWindT::Speed() const
{
    return mSpeed;
}

/**
 * \brief Direction of wind.
 *
 * @return Direction of wind, if successful; kSignNeg, if failed.
 */
UIntT FmdCfgWindT::Direction() const
{
    return mDirection;
}

/***** FmdCfgWindT Private A *****/

UErrCodeT FmdCfgWindT::Init()
{
    return UErrFalse;
}       

/***** FmdCfgWindT Private B *****/
/***** FmdCfgWindT B *****/

/***** FmdCfgCloudT A *****/

/**
 * \brief Constructor.
 */
FmdCfgCloudT::FmdCfgCloudT()
{
    Init();
}

/**
 * \brief Constructor.
 */
FmdCfgCloudT::FmdCfgCloudT(UIntT aCover, UFloatT aPrecipAmount)
{
    Init();
    SetAll(aCover, aPrecipAmount);
}

/**
 * \brief Destructor.
 */
FmdCfgCloudT::~FmdCfgCloudT()
{
}

/**
 * \brief Set all value.
 *
 * @param aCover Cover of cloud.
 * @param aPrecipAmount Precipitation amount.
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT FmdCfgCloudT::SetAll(UIntT aCover, UFloatT aPrecipAmount)
{
    mCover = aCover;
    mPrecipAmount = aPrecipAmount;

    return UErrFalse;
}

/**
 * \brief Get all value.
 */
UErrCodeT FmdCfgCloudT::All(UIntT *aCover, UFloatT *aPrecipAmount) const
{
    *aCover = mCover;
    *aPrecipAmount = mPrecipAmount;

    return UErrFalse;
}

/**
 * \brief Cover of cloud.
 *
 * @return Cover of cloud, if successful; kSignNeg, if failed.
 */
UIntT FmdCfgCloudT::Cover() const
{
    return mCover;
}

/**
 * \brief Precipitation amount.
 *
 * @return Precipitation amount, if successful; kSignNeg, if failed.
 */
UFloatT FmdCfgCloudT::PrecipAmount() const
{
    return mPrecipAmount;
}

/***** FmdCfgCloudT Private A *****/

UErrCodeT FmdCfgCloudT::Init()
{
    return UErrFalse;
}

/***** FmdCfgCloudT Private B *****/
/***** FmdCfgCloudT B *****/

/***** FmdCfgAirT A *****/
/**
 * \brief Constructor.
 */
FmdCfgAirT::FmdCfgAirT()
{
    Init();
}

/**
 * \brief Constructor.
 */
FmdCfgAirT::FmdCfgAirT(UIntT aTemperature, UIntT aHumidity)
{
    Init();
    SetAll(aTemperature, aHumidity);
}

/**
 * \brief Destructor.
 */
FmdCfgAirT::~FmdCfgAirT()
{
}

/**
 * \brief Set all value.
 *
 * @param aTemperature Temperature of air.
 * @param aHumidity Humidity of air.
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT FmdCfgAirT::SetAll(UIntT aTemperature, UIntT aHumidity)
{
    mTemperature = aTemperature;
    mHumidity = aHumidity;

    return UErrFalse;
}

/**
 * \brief Get all value.
 *
 * @param aTemperature Temperature of air.
 * @param aHumidity Humidity of air.
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT FmdCfgAirT::All(UIntT *aTemperature, UIntT *aHumidity) const
{
    *aTemperature = mTemperature;
    *aHumidity = mHumidity;

    return UErrFalse;
}

/**
 * \brief Temperature.
 */
UIntT FmdCfgAirT::Temperature() const
{
    return mTemperature;
}

/**
 * \brief Humidity.
 */
UIntT FmdCfgAirT::Humidity() const
{
    return mHumidity;
}

/***** FmdCfgAirT Private A *****/

/**
 * \brief Initialize.
 */
UErrCodeT FmdCfgAirT::Init()
{
    return UErrFalse;
}

/***** FmdCfgAirT Private B *****/
/***** FmdCfgAirT B *****/

/***** FmdCfgWeatherT A *****/

/**
 * \brief Constructor.
 */
FmdCfgWeatherT::FmdCfgWeatherT()
{
    Init();
}

/**
 * \brief Constructor.
 */
FmdCfgWeatherT::FmdCfgWeatherT(const FmdCfgTimeT *aTime,
                               const FmdCfgWindT *aWind,
                               const FmdCfgCloudT *aCloud,
                               const FmdCfgAirT *aAir)
{
}

/**
 * \brief Destructor.
 */
FmdCfgWeatherT::~FmdCfgWeatherT()
{
}

/**
 * \brief Set all value.
 *
 * @param aTime Time of weather.
 * @param aWind Wind.
 * @param aCloud Cloud.
 * @param aAir Air.
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT FmdCfgWeatherT::SetAll(const FmdCfgTimeT *aTime,
                                 const FmdCfgWindT *aWind,
                                 const FmdCfgCloudT *aCloud,
                                 const FmdCfgAirT *aAir)
{
    mTime = *aTime;
    mWind = *aWind;
    mCloud = *aCloud;
    mAir = *aAir;

    return UErrFalse;
}

/**
 * \brief Get all value.
 *
 * @param aTime Time of weather.
 * @param aWind Wind.
 * @param aCloud Cloud.
 * @param aAir Air.
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT FmdCfgWeatherT::All(FmdCfgTimeT *aTime, FmdCfgWindT *aWind,
                              FmdCfgCloudT *aCloud, FmdCfgAirT *aAir) const
{
    *aTime = mTime;
    *aWind = mWind;
    *aCloud = mCloud;
    *aAir = mAir;

    return UErrFalse;
}

/**
 * \brief Time.
 *
 * @return Time, if successful; NULL, if failed.
 */
const FmdCfgTimeT *FmdCfgWeatherT::Time() const
{
    return &mTime;
}

/**
 * \brief Wind.
 *
 * @return Wind, if successful; NULL, if failed.
 */
const FmdCfgWindT *FmdCfgWeatherT::Wind() const
{
    return &mWind;
}

/**
 * \brief Cloud.
 *
 * @return Cloud, if successful; NULL, if failed.
 */
const FmdCfgCloudT *FmdCfgWeatherT::Cloud() const
{
    return &mCloud;
}

/**
 * \brief Air.
 *
 * @return Air, if successful; NULL, if failed.
 */
const FmdCfgAirT *FmdCfgWeatherT::Air() const
{
    return &mAir;
}

/***** FmdCfgWeatherT Private A *****/

/**
 * \brief Initialize.
 */
UErrCodeT FmdCfgWeatherT::Init()
{
    return UErrFalse;
}

/***** FmdCfgWeatherT Private B *****/
/***** FmdCfgWeatherT B *****/
