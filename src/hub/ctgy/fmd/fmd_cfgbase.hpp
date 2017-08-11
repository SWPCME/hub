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

typedef struct
{
    UIntT year;
    UIntT mon;
    UIntT mday;
    UIntT hour;
    UIntT min;
} FmdCfgTimeT;

typedef struct
{
    FmdCfgTimeT begin;
    FmdCfgTimeT end;
    UIntT step;
} FmdCfgBurnTimeT;

typedef struct
{
    UIntT model;
    UIntT fm1;
    UIntT fm10;
    UIntT fm100;
    UIntT fmLiveHerb;
    UIntT fmLiveWoody;
} FmdCfgFuelMoisturesT;
typedef UContainerT<FmdCfgFuelMoisturesT> FmdCfgFuelMoisturesCtnT;
typedef UIteratorT<FmdCfgFuelMoisturesT> FmdCfgFuelMoisturesItT;

typedef struct
{
    UIntT speed;
    UIntT direction;
} FmdCfgWindT;

typedef struct
{
    UIntT cover;
    UIntT precipAmount;
} FmdCfgCloudT;

typedef struct
{
    UIntT temperature;
    UIntT humidity;
} FmdCfgAirT;

typedef struct
{
    FmdCfgTimeT time;
    FmdCfgWindT wind;
    FmdCfgCloudT cloud;
    FmdCfgAirT air;
} FmdCfgWeatherT;
typedef UContainerT<FmdCfgWeatherT> FmdCfgWeatherCtnT;
typedef UIteratorT<FmdCfgWeatherT> FmdCfgWeatherItT;

#endif  // FMD_CFGBASE_HPP_INCLUDED
