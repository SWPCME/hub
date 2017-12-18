/******************************************************************************
 * $Id: TestCtl.java 2017-09 $
 *
 * Project:  Test.
 * Purpose:  Test control.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017.09 ~ 2017 Weiwei Huang
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
 ******************************************************************************/

package TestJava;
import whub.*;

public class TestFmd
{
    private CFmdCtl mFmd;

    public static void main(String[] aArg)
    {
        TestFmd fmd = new TestFmd();
        fmd.Test();
    }

    public UErrCodeT Test()
    {
        CHubCtl hubCtl = CHubCtl.Hub();
        hubCtl.Register(HubCodeT.HubMFmd);
        mFmd = hubCtl.Fmd();
        TestConfig();

        return UErrCodeT.UErrFalse;
    }

    private UErrCodeT TestConfig()
    {
        CFmdFileCtl fileCtl = mFmd.File();
        UStringT fileName = new UStringT("../../data/geojson/tmp/forest_cfg.input");
        CFmdFileCfg cfg = fileCtl.Cfg(fileName, FmdFileCfgCodeT.FmdFileCfgCreate);
        CFmdCfgWrite cfgWrite = cfg.Write();

        FmdCfgBurnTimeT time = new FmdCfgBurnTimeT();
        FmdCfgTimeT begin = time.Begin();
        begin.SetAll(2017, 8, 1, 9, 30);
        FmdCfgTimeT end = time.End();
        end.SetAll(2017, 8, 1, 10, 45);
        time.SetAll(begin, end, 1);
        cfgWrite.BurnTime(time);

        FmdCfgWeatherCtnT weatherCtn =
            new FmdCfgWeatherCtnT(UContainerCodeT.UContainerList);
        FmdCfgWeatherT weather = new FmdCfgWeatherT();
        FmdCfgTimeT weatherTime = new FmdCfgTimeT();
        weatherTime.SetAll(2017, 8, 1, 9, 30);
        FmdCfgWindT weatherWind = new FmdCfgWindT();
        weatherWind.SetAll(100, 125);
        FmdCfgCloudT weatherCloud = new FmdCfgCloudT();
        weatherCloud.SetAll(0, 0.2);
        FmdCfgAirT weatherAir = new FmdCfgAirT();
        weatherAir.SetAll(30, 80);
        weather.SetAll(weatherTime, weatherWind, weatherCloud, weatherAir);
        weatherCtn.Add(weather);
        // cfgWrite.Weather(weatherCtn);

        double elevation = 43.4;
        cfgWrite.Elevation(elevation);

        FmdCfgFuelMoistureCtnT fmCtn =
            new FmdCfgFuelMoistureCtnT(UContainerCodeT.UContainerList);
        FmdCfgFuelMoistureT fm = new FmdCfgFuelMoistureT();
        fm.SetAll(0, 3, 4, 6, 70, 100);
        fmCtn.Add(fm);
        // cfgWrite.FuelMoisture(fmCtn);

        return UErrCodeT.UErrFalse;
    }
}
