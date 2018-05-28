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
FmdCfgTimeT::FmdCfgTimeT(const UIntT aYear, const UIntT aMon,
                         const UIntT aMDay, const UIntT aHour,
                         const UIntT aMin)
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
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT FmdCfgTimeT::Init()
{
    SetAll(0, 0, 0, 0, 0);

    return UErrFalse;
}

/**
 * \brief Set all value.
 */
UErrCodeT FmdCfgTimeT::SetAll(const UIntT aYear, const UIntT aMon,
                              const UIntT aMDay, const UIntT aHour,
                              const UIntT aMin)
{
    SetYear(aYear);
    SetMon(aMon);
    SetMDay(aMDay);
    SetHour(aHour);
    SetMin(aMin);
        
    return UErrFalse;
}

/**
 * \brief Set year.
 *
 * @param aYear Year.
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT FmdCfgTimeT::SetYear(const UIntT aYear)
{
    mYear = aYear;

    return UErrFalse;
}

/**
 * \brief Set month.
 *
 * @param aMon Month in one year.
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT FmdCfgTimeT::SetMon(const UIntT aMon)
{
    mMon = aMon;

    return UErrFalse;
}

/**
 * \brief Set day of month.
 *
 * @param aDay Day of month.
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT FmdCfgTimeT::SetMDay(const UIntT aMDay)
{
    mMDay = aMDay;

    return UErrFalse;
}

/**
 * \brief Set hour.
 *
 * @param aHour Hour in one day.
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT FmdCfgTimeT::SetHour(const UIntT aHour)
{
    mHour = aHour;

    return UErrFalse;
}

/**
 * \brief Set minute.
 *
 * @param aMinute Minute in one hour.
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT FmdCfgTimeT::SetMin(const UIntT aMin)
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
 * @return year, if successful; kSignNeg, if failed.
 */
UIntT FmdCfgTimeT::Year() const
{
    return mYear;
}

/**
 * \brief Get month.
 *
 * @param aMon Month in one year.
 * @return month, if successful; kSignNeg, if failed.
 */
UIntT FmdCfgTimeT::Mon() const
{
    return mMon;
}

/**
 * \brief Get day in one month.
 *
 * @param aMDay Day in one month.
 * @return day, if successful; kSignNeg, if failed.
 */
UIntT FmdCfgTimeT::MDay() const
{
    return mMDay;
}

/**
 * \brief Get hour in one day.
 *
 * @param aHour Hour in one day.
 * @return hour, if successful; kSignNeg, if failed.
 */
UIntT FmdCfgTimeT::Hour() const
{
    return mHour;
}

/**
 * \brief Get minute in one hour.
 *
 * @param aMin Minute in one hour.
 * @return minute, if successful; kSignNeg, if failed.
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
                                 const UFloatT aStep)
{
    Init();
    SetAll(aBegin, aEnd, aStep);
}


/**
 * \brief Destructor.
 */
FmdCfgBurnTimeT::~FmdCfgBurnTimeT()
{
}

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT FmdCfgBurnTimeT::Init()
{
    mBegin.Init();
    mEnd.SetAll(0, 0, 0, 0, 1);
    mStep = 1;

    return UErrFalse;
}

/**
 * \brief Set all value.
 *
 * @param aBegin Time of begin.
 * @param aEnd Time of end.
 * @param aStep Time of step (min).
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT FmdCfgBurnTimeT::SetAll(const FmdCfgTimeT *aBegin,
                                  const FmdCfgTimeT *aEnd,
                                  const UFloatT aStep)
{
    SetBegin(aBegin);
    SetEnd(aEnd);
    SetStep(aStep);

    return UErrFalse;
}

/**
 * \brief Set begin time.
 */
UErrCodeT FmdCfgBurnTimeT::SetBegin(const FmdCfgTimeT *aBegin)
{
    mBegin = *aBegin;

    return UErrFalse;
}

/**
 * \brief Set end time.
 */
UErrCodeT FmdCfgBurnTimeT::SetEnd(const FmdCfgTimeT *aEnd)
{
    mEnd = *aEnd;

    return UErrFalse;
}

/**
 * \brief Set step.
 */
UErrCodeT FmdCfgBurnTimeT::SetStep(const UFloatT aStep)
{
    mStep = aStep;

    return UErrFalse;
}

/**
 * \brief Get all value.
 *
 * @param aBegin Time of begin.
 * @param aEnd Time of end.
 * @param aStep Time of step (min).
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT FmdCfgBurnTimeT::All(FmdCfgTimeT *aBegin, FmdCfgTimeT *aEnd,
                               UFloatT *aStep) const
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
 * @return Time of begin, if successful; NULL, if failed.
 */
const FmdCfgTimeT *FmdCfgBurnTimeT::Begin() const
{
    return &mBegin;
}

/**
 * \brief Get time of end.
 *
 * @param aEnd Time of end.
 * @return Time of end, if successful; NULL, if failed.
 */
const FmdCfgTimeT *FmdCfgBurnTimeT::End() const
{
    return &mEnd;
}

/**
 * \brief Get time of step.
 *
 * @param aStep Time of step (min).
 * @return Time of step, if successful; NULL, if failed.
 */
UFloatT FmdCfgBurnTimeT::Step() const
{
    return mStep;
}

/***** FmdCfgBurnTimeT Private A *****/
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
FmdCfgFuelMoistureT::FmdCfgFuelMoistureT(const UIntT aModel, const UIntT aFm1,
                                         const UIntT aFm10, const UIntT aFm100,
                                         const UIntT aFmLiveHerb,
                                         const UIntT aFmLiveWoody)
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
 * \brief Initialize.
 */
UErrCodeT FmdCfgFuelMoistureT::Init()
{
    SetAll(0, 2, 2, 2, 2, 2);

    return UErrFalse;
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
UErrCodeT FmdCfgFuelMoistureT::SetAll(const UIntT aModel, const UIntT aFm1,
                                      const UIntT aFm10, const UIntT aFm100,
                                      const UIntT aFmLiveHerb,
                                      const UIntT aFmLiveWoody)
{
    SetModel(aModel);
    SetFm1(aFm1);
    SetFm10(aFm10);
    SetFm100(aFm100);
    SetFmLiveHerb(aFmLiveHerb);
    SetFmLiveWoody(aFmLiveWoody);

    return UErrFalse;
}

/**
 * \brief Set modle.
 */
UErrCodeT FmdCfgFuelMoistureT::SetModel(const UIntT aModel)
{
    mModel = aModel;

    return UErrFalse;
}

/**
 * \brief Set fuel moistures 1.
 */
UErrCodeT FmdCfgFuelMoistureT::SetFm1(const UIntT aFm1)
{
    mFm1 = aFm1;

    return UErrFalse;
}

/**
 * \brief Set fuel moistures 10.
 */
UErrCodeT FmdCfgFuelMoistureT::SetFm10(const UIntT aFm10)
{
    mFm10 = aFm10;

    return UErrFalse;
}

/**
 * \brief Set fuel moistures 100.
 */
UErrCodeT FmdCfgFuelMoistureT::SetFm100(const UIntT aFm100)
{
    mFm100 = aFm100;

    return UErrFalse;
}

/**
 * \brief Set fuel moistures live herb.
 */
UErrCodeT FmdCfgFuelMoistureT::SetFmLiveHerb(const UIntT aFmLiveHerb)
{
    mFmLiveHerb = aFmLiveHerb;

    return UErrFalse;
}

/**
 * \brief Set fuel moistures live woody.
 */
UErrCodeT FmdCfgFuelMoistureT::SetFmLiveWoody(const UIntT aFmLiveWoody)
{
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
FmdCfgWindT::FmdCfgWindT(const UFloatT aSpeed, const UIntT aDirection)
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
 * \brief Initialize.
 */
UErrCodeT FmdCfgWindT::Init()
{
    SetAll(0, 0);

    return UErrFalse;
}       

/**
 * \brief Set all value.
 *
 * @param aSpeed Speed of wind.
 * @param aDirection Direction of wind.
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT FmdCfgWindT::SetAll(const UFloatT aSpeed, const UIntT aDirection)
{
    SetSpeed(aSpeed);
    SetDirection(aDirection);

    return UErrFalse;
}

/**
 * \brief Set speed.
 */
UErrCodeT FmdCfgWindT::SetSpeed(const UFloatT aSpeed)
{
    mSpeed = aSpeed;

    return UErrFalse;
}

/**
 * \brief Set direction.
 */
UErrCodeT FmdCfgWindT::SetDirection(const UIntT aDirection)
{
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
UErrCodeT FmdCfgWindT::All(UFloatT *aSpeed, UIntT *aDirection) const
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
UFloatT FmdCfgWindT::Speed() const
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
FmdCfgCloudT::FmdCfgCloudT(const UIntT aCover, const UFloatT aPrecipAmount)
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
 * \brief Initialize.
 */
UErrCodeT FmdCfgCloudT::Init()
{
    SetAll(0, 0);

    return UErrFalse;
}

/**
 * \brief Set all value.
 *
 * @param aCover Cover of cloud.
 * @param aPrecipAmount Precipitation amount.
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT FmdCfgCloudT::SetAll(const UIntT aCover, const UFloatT aPrecipAmount)
{
    SetCover(aCover);
    SetPrecipAmount(aPrecipAmount);

    return UErrFalse;
}

/**
 * \brief Set cover.
 */
UErrCodeT FmdCfgCloudT::SetCover(const UIntT aCover)
{
    mCover = aCover;

    return UErrFalse;
}

/**
 * \brief Set precipitation amount.
 */
UErrCodeT FmdCfgCloudT::SetPrecipAmount(const UFloatT aPrecipAmount)
{
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
FmdCfgAirT::FmdCfgAirT(const UFloatT aTemperature, const UIntT aHumidity)
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
 * \brief Initialize.
 */
UErrCodeT FmdCfgAirT::Init()
{
    SetAll(0, 0);

    return UErrFalse;
}

/**
 * \brief Set all value.
 *
 * @param aTemperature Temperature of air.
 * @param aHumidity Humidity of air.
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT FmdCfgAirT::SetAll(const UFloatT aTemperature, const UIntT aHumidity)
{
    SetTemperature(aTemperature);
    SetHumidity(aHumidity);

    return UErrFalse;
}

/**
 * \brief Set temperature.
 */
UErrCodeT FmdCfgAirT::SetTemperature(const UFloatT aTemperature)
{
    mTemperature = aTemperature;

    if (mTemperature < -40)
    {
        mTemperature = -40;
    }

    if (mTemperature > 50)
    {
        mTemperature = 50;
    }

    return UErrFalse;
}

/**
 * \brief Set humidity.
 */
UErrCodeT FmdCfgAirT::SetHumidity(const UIntT aHumidity)
{
    mHumidity = aHumidity;

    if (mHumidity < 1)
    {
        mHumidity = 1;
    }

    if (mHumidity > 100)
    {
        mHumidity = 100;
    }

    return UErrFalse;
}

/**
 * \brief Get all value.
 *
 * @param aTemperature Temperature of air.
 * @param aHumidity Humidity of air.
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT FmdCfgAirT::All(UFloatT *aTemperature, UIntT *aHumidity) const
{
    *aTemperature = mTemperature;
    *aHumidity = mHumidity;

    return UErrFalse;
}

/**
 * \brief Temperature.
 */
UFloatT FmdCfgAirT::Temperature() const
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
 * \brief Initialize.
 */
UErrCodeT FmdCfgWeatherT::Init()
{
    mTime.Init();
    mWind.Init();
    mCloud.Init();
    mAir.Init();

    return UErrFalse;
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
    SetTime(aTime);
    SetWind(aWind);
    SetCloud(aCloud);
    SetAir(aAir);

    return UErrFalse;
}

/**
 * \brief Set time.
 */
UErrCodeT FmdCfgWeatherT::SetTime(const FmdCfgTimeT *aTime)
{
    mTime.Init();

    if (aTime != NULL)
    {
        mTime = *aTime;
    }

    return UErrFalse;
}

/**
 * \brief Set wind.
 */
UErrCodeT FmdCfgWeatherT::SetWind(const FmdCfgWindT *aWind)
{
    mWind.Init();

    if (aWind != NULL)
    {
        mWind = *aWind;
    }

    return UErrFalse;
}

/**
 * \brief Set cloud.
 */
UErrCodeT FmdCfgWeatherT::SetCloud(const FmdCfgCloudT *aCloud)
{
    mCloud.Init();

    if (aCloud != NULL)
    {
        mCloud = *aCloud;
    }

    return UErrFalse;
}

/**
 * \brief Set air.
 */
UErrCodeT FmdCfgWeatherT::SetAir(const FmdCfgAirT *aAir)
{
    mAir.Init();

    if (aAir != NULL)
    {
        mAir = *aAir;
    }

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
/***** FmdCfgWeatherT Private B *****/
/***** FmdCfgWeatherT B *****/
