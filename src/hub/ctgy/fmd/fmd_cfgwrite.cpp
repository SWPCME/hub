/******************************************************************************
 * $Id: fmd_cfgread.hpp 2017-08 $
 *
 * Project:  FMD (FMD: Fire Model).
 * Purpose:  Config write implementation.
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

#include "fmd_cfgwrite.hpp"

// base
#include "base_stringdefn.hpp"
// ust
#include "ust_filetype.hpp"

/**
 * \brief Constructor.
 * Private.
 * Do not use this function.
 */
CFmdCfgWrite::CFmdCfgWrite() : mWeather(UContainerList),
                               mFm(UContainerList)
{
}

/**
 * \brief Constructor.
 */
CFmdCfgWrite::CFmdCfgWrite(UFileT *aFile) : mWeather(UContainerList),
                                            mFm(UContainerList)
{
    InitPointer();
    mFile = aFile;
}

/**
 * \brief Destructor.
 */
CFmdCfgWrite::~CFmdCfgWrite()
{
    InitPointer();
}

/**
 * \brief Initialize.
 */
UErrCodeT CFmdCfgWrite::Init()
{
    InitBurnTime();
    InitWeather();
    InitFuelMoisture();
    mElev = 0.0;

    return UErrFalse;
}

/**
 * \brief Set all.
 */
UErrCodeT CFmdCfgWrite::SetAll(const FmdCfgBurnTimeT *aTime,
                               const FmdCfgWeatherCtnT *aWeatherCtn,
                               const UFloatT aElev,
                               const FmdCfgFuelMoistureCtnT *aFmCtn)
{
    SetBurnTime(aTime);
    SetWeather(aWeatherCtn);
    SetElevation(aElev);
    SetFuelMoisture(aFmCtn);

    return UErrFalse;
}

/**
 * \brief Set burn time.
 */
UErrCodeT CFmdCfgWrite::SetBurnTime(const FmdCfgBurnTimeT *aTime)
{
    InitBurnTime();

    if (aTime != NULL)
    {
        mTime = *aTime;
    }

    return UErrFalse;
}

/**
 * \brief Set weather.
 */
UErrCodeT CFmdCfgWrite::SetWeather(const FmdCfgWeatherCtnT *aWeatherCtn)
{
    InitWeather();

    if (aWeatherCtn != NULL)
    {
        mWeather = *aWeatherCtn;
    }

    return UErrFalse;
}

/**
 * \brief Set elevation.
 */
UErrCodeT CFmdCfgWrite::SetElevation(UFloatT aElev)
{
    mElev = aElev;

    return UErrFalse;
}
 
/**
 * \brief Set Fuel moistures data.
 */
UErrCodeT CFmdCfgWrite::SetFuelMoisture(const FmdCfgFuelMoistureCtnT *aFmCtn)
{
    InitFuelMoisture();

    if (aFmCtn != NULL)
    {
        mFm = *aFmCtn;
    }

    return UErrFalse;
}

/**
 * \brief Save.
 */
UErrCodeT CFmdCfgWrite::Save()
{
    WriteBurnTime();
    WriteWeather();
    WriteElevation();
    WriteFuelMoisture();

    return mFile->Save();
}

/***** Private A *****/

/**
 * \brief Init pointer.
 */
UErrCodeT CFmdCfgWrite::InitPointer()
{
    BMD_POINTER_INIT(mFile);

    return UErrFalse;
}

/**
 * \brief Init burn time.
 */
UErrCodeT CFmdCfgWrite::InitBurnTime()
{
    mTime.Init();

    return UErrFalse;
}

/**
 * \brief Init weather.
 */
UErrCodeT CFmdCfgWrite::InitWeather()
{
    mWeather.Clear();
    FmdCfgWeatherT weather;
    mWeather.Add(weather);

    return UErrFalse;
}

/**
 * \brief Set Fuel moistures data.
 */
UErrCodeT CFmdCfgWrite::InitFuelMoisture()
{
    mFm.Clear();
    FmdCfgFuelMoistureT fm;
    mFm.Add(fm);

    return UErrFalse;
}

/**
 * \brief Write burn time.
 */
UErrCodeT CFmdCfgWrite::WriteBurnTime()
{
    UStringT begin;
    UFlagCodeT flag = UFlagOn;
    ToTime(&begin, mTime.Begin(), flag);
    UStringT end;
    ToTime(&end, mTime.End(), flag);
    UStringT step;
    step = mTime.Step();

    const UStringT kBegin = kFmdCfgStartTime;
    Field(&begin, &kBegin);
    const UStringT kEnd = kFmdCfgEndTime;
    Field(&end, &kEnd);
    const UStringT kStep = kFmdCfgTimeStep;
    Field(&step, &kStep);

    return UErrFalse;
}

/**
 * \brief Write weather.
 */
UErrCodeT CFmdCfgWrite::WriteWeather()
{
    const UStringT kSpace = kStrSpace;
    UStringT weather;
    FmdCfgWeatherCtnT *weatherCtn = &mWeather;
    UIntT count = weatherCtn->Count();
    weather = count;
    const UStringT kWeather = kFmdCfgRaws;
    Field(&weather, &kWeather);

    FmdCfgWeatherItT *it = weatherCtn->Iterator();
    for (it->Head(); it->State() == UErrFalse; it->Next())
    {
        FmdCfgWeatherT tWeather = it->Content();
        UStringT time;
        ToTime(&time, tWeather.Time());
        weather = time;
        weather += kSpace;
        weather += tWeather.Air()->Temperature();
        weather += kSpace;
        weather += tWeather.Air()->Humidity();
        weather += kSpace;
        weather += tWeather.Cloud()->PrecipAmount();
        weather += kSpace;
        weather += tWeather.Wind()->Speed();
        weather += kSpace;
        weather += tWeather.Wind()->Direction();
        weather += kSpace;
        weather += tWeather.Cloud()->Cover();
        Field(&weather);
    }

    return UErrFalse;
}

/**
 * \brief Write elevation.
 */
UErrCodeT CFmdCfgWrite::WriteElevation()
{
    UStringT elev = mElev;
    const UStringT kElev = kFmdCfgElevation;
    Field(&elev, &kElev);

    return UErrFalse;
}

/**
 * \brief Set Fuel moistures data.
 */
UErrCodeT CFmdCfgWrite::WriteFuelMoisture()
{
    const UStringT kSpace = kStrSpace;
    UIntT count = mFm.Count();
    UStringT fm = count;
    const UStringT kFm = kFmdCfgFuelMoisturesData;
    Field(&fm, &kFm);

    FmdCfgFuelMoistureItT *it = mFm.Iterator();
    for (it->Head(); it->State() == UErrFalse; it->Next())
    {
        FmdCfgFuelMoistureT tFm = it->Content();
        fm = tFm.Model();
        fm += kSpace;
        fm += tFm.Fm1();
        fm += kSpace;
        fm += tFm.Fm10();
        fm += kSpace;
        fm += tFm.Fm100();
        fm += kSpace;
        fm += tFm.FmLiveHerb();
        fm += kSpace;
        fm += tFm.FmLiveWoody();
        Field(&fm);
    }

    return UErrFalse;
}

/**
 * \brief Field.
 */
UErrCodeT CFmdCfgWrite::Field(const UStringT *aValue, const UStringT *aFiled)
{
    const UStringT delimeter = kFmdCfgDelimeter;
    const UStringT space = kStrSpace;

    if (aFiled != NULL)
    {
        mFile->Write(aFiled);
        mFile->Write(&delimeter);
        mFile->Write(&space);
    }

    mFile->WriteRow(aValue);

    return UErrFalse;
}

/**
 * \brief Set time.
 */
UErrCodeT CFmdCfgWrite::ToTime(UStringT *aDst, const FmdCfgTimeT *aSrc,
                               const UFlagCodeT aFlag)
{
    const UStringT kZero = "0";
    if (aFlag == UFlagOff)
    {
        *aDst = aSrc->Year();
        *aDst += kStrSpace;
    }

    if (aSrc->Mon() < 10)
    {
        *aDst += kZero;
    }
    *aDst += aSrc->Mon();

    *aDst += kStrSpace;
    if (aSrc->MDay() < 10)
    {
        *aDst += kZero;
    }
    *aDst += aSrc->MDay();

    *aDst += kStrSpace;
    if (aSrc->Hour() < 10)
    {
        *aDst += kZero;
    }
    *aDst += aSrc->Hour();
    if (aSrc->Min() < 10)
    {
        *aDst += kZero;
    }
    *aDst += aSrc->Min();

    if (aFlag == UFlagOn)
    {
        *aDst += kStrSpace;
        *aDst += aSrc->Year();
    }

    return UErrFalse;
}

/***** Private B *****/
