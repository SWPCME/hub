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
        CHubModuleCtl module = hubCtl.RegModule();
        module.Register(HubCodeT.HubMFmd);
        mFmd = module.Fmd();
        TestConfig();
        TestConfigSimple();
        TestWrite();
        hubCtl.DeregModule(module);

        return UErrCodeT.UErrFalse;
    }

    private UErrCodeT TestConfig()
    {
        CFmdFileCtl fileCtl = mFmd.File();
        UStringT fileName = new UStringT("../../../data/ctgy/fmd/1/1.input");
        CFmdFileCfg cfg = fileCtl.Cfg(fileName, FmdFileCfgCodeT.FmdFileCfgCreate);
        CFmdCfgWrite cfgWrite = cfg.Write();

        FmdCfgBurnTimeT time = new FmdCfgBurnTimeT();
        FmdCfgTimeT begin = time.Begin();
        begin.SetAll(2017, 8, 1, 9, 30);
        FmdCfgTimeT end = time.End();
        end.SetAll(2017, 8, 1, 10, 45);
        time.SetAll(begin, end, 1);
        cfgWrite.SetBurnTime(time);

        FmdCfgWeatherCtnT weatherCtn =
            new FmdCfgWeatherCtnT(UContainerCodeT.UContainerList);
        FmdCfgWeatherT weather = new FmdCfgWeatherT();
        FmdCfgTimeT weatherTime = new FmdCfgTimeT();
        weatherTime.SetAll(2017, 8, 1, 9, 30);
        FmdCfgWindT weatherWind = new FmdCfgWindT();
        weatherWind.SetAll(2, 180);
        FmdCfgCloudT weatherCloud = new FmdCfgCloudT();
        weatherCloud.SetAll(0, 0.2);
        FmdCfgAirT weatherAir = new FmdCfgAirT();
        weatherAir.SetAll(30, 80);
        weather.SetAll(weatherTime, weatherWind, weatherCloud, weatherAir);
        weatherCtn.Add(weather);
        cfgWrite.SetWeather(weatherCtn);

        double elevation = 43.4;
        cfgWrite.SetElevation(elevation);

        FmdCfgFuelMoistureCtnT fmCtn =
            new FmdCfgFuelMoistureCtnT(UContainerCodeT.UContainerList);
        FmdCfgFuelMoistureT fm = new FmdCfgFuelMoistureT();
        fm.SetAll(0, 2, 2, 2, 2, 2);
        fmCtn.Add(fm);
        cfgWrite.SetFuelMoisture(fmCtn);

        cfgWrite.Save();

        return UErrCodeT.UErrFalse;
    }

    private UErrCodeT TestConfigSimple()
    {
        CFmdFileCtl fileCtl = mFmd.File();
        UStringT fileName = new UStringT("../../../data/ctgy/fmd/1/s1.input");
        CFmdFileCfg cfg = fileCtl.Cfg(fileName, FmdFileCfgCodeT.FmdFileCfgCreate);
        CFmdCfgWrite cfgWrite = cfg.Write();

        FmdCfgBurnTimeT time = new FmdCfgBurnTimeT();
        FmdCfgTimeT begin = time.Begin();
        begin.SetAll(2017, 1, 1, 0, 0);
        FmdCfgTimeT end = time.End();
        end.SetAll(2017, 1, 1, 1, 0);
        time.SetAll(begin, end, 1);
        cfgWrite.SetBurnTime(time);

        FmdCfgWeatherCtnT weatherCtn =
            new FmdCfgWeatherCtnT(UContainerCodeT.UContainerList);
        FmdCfgWeatherT weather = new FmdCfgWeatherT();
        FmdCfgTimeT weatherTime = new FmdCfgTimeT();
        weatherTime.SetAll(2017, 1, 1, 0, 0);
        weather.SetTime(weatherTime);
        FmdCfgWindT weatherWind = new FmdCfgWindT();
        weatherWind.SetAll(2, 180);
        weather.SetWind(weatherWind);
        weatherCtn.Add(weather);
        cfgWrite.SetWeather(weatherCtn);

        cfgWrite.Save();

        return UErrCodeT.UErrFalse;
    }

    private UErrCodeT TestWrite()
    {
        CFmdFileCtl fileCtl = mFmd.File();

        // Load.
        CFmdFileLoad fileLoad = fileCtl.Load();
        UStringT cfgFile = new UStringT("../../../data/ctgy/fmd/1/1.input");

        UStringT lcpFile = new UStringT("../../../data/ctgy/fmd/3/1.lcp");
        UStringT ignitionFile =
            new UStringT("{\"type\": \"FeatureCollection\",\"features\": [{ \"type\": \"Feature\", \"properties\": { \"id\": null }, \"geometry\": { \"type\": \"Point\", \"coordinates\": [ 113.5255460, 23.4385733 ] } } ] }");
        UStringT barrierFile = new UStringT("");

        fileLoad.Cfg(cfgFile);
        fileLoad.Lcp(lcpFile);
        fileLoad.IgnitionGjson(ignitionFile);
        fileLoad.BarrierGjson(barrierFile);

        // Master.
        CFmdMasterCtl masterCtl = mFmd.Master();
        masterCtl.Launch();

        // Write.
        CFmdFileWrite fileWrite = fileCtl.Write();
        UStringT strGjson = new UStringT("");
        fileWrite.PerimetersGjson(strGjson);
        strGjson.ToConsole();

        return UErrCodeT.UErrFalse;
    }
}
