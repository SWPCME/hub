/******************************************************************************
 * $Id: TestGda.java 2018-05 $
 *
 * Project:  Test.
 * Purpose:  Test rst.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2018.05 ~ 2018 Weiwei Huang
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

public class TestGda
{
    private CGdaCtl mGda;
    private CGdaDriversCtl mDrivers;

    public static void main(String[] aArg)
    {
        TestGda gda = new TestGda();
        gda.Test();
    }

    public UErrCodeT Test()
    {
        // Init module.
        CHubCtl hubCtl = CHubCtl.Hub();
        CHubModuleCtl module = hubCtl.RegModule();
        module.Register(HubCodeT.HubMGda);
        mGda = module.Gda();
        CGdaCoreCtl core = mGda.Core();
        mDrivers = core.Drivers();
        mDrivers.RegisterAll();

        // Test core module.
        TestCore();

        // Test ogr module.
        TestOgr();

        // Deregister module.
        hubCtl.DeregModule(module);

        return UErrCodeT.UErrFalse;
    }

    public UErrCodeT TestCore()
    {
        CoreBand();

        return UErrCodeT.UErrFalse;
    }

    public UErrCodeT CoreBand()
    {
        // Load band.
        UStringT file = new UStringT("../../../data/ctgy/fmd/baiyun_m/baiyun_m.lcp");
        CGdaDatasetCtl datasetCtl = LoadDataset(file, UAccessCodeT.UAccessRead, GdaFormatCodeT.GdaFormatLcp);
        CGdaBandCtl bandCtl = datasetCtl.Band(1);

        // Transform the coordinate system.
        GdaOgrSrsT srsSrc = new GdaOgrSrsT();
        srsSrc.SetProjCs(GdaProjCsCodeT.GdaProjCsWgs1984);
        GdaOgrSrsT srsDst = new GdaOgrSrsT();
        srsDst.SetProjCs(GdaProjCsCodeT.GdaProjCsXian1980);
        GdaOgrCtrT ctr = new GdaOgrCtrT(srsSrc, srsDst);
        BMathCsC2dT ptSrc = new BMathCsC2dT(113.451129, 23.168046);
        BMathCsC2dT ptDst = new BMathCsC2dT();
        ctr.Tr(ptDst, ptSrc);

        // Get index with position.
        BMathCsC2dT dstId = new BMathCsC2dT();
        datasetCtl.PosToId(dstId, ptDst);

        // Get value with index.
        UDataTCodeT dataT = bandCtl.DataT();
        GdaBandDataT bandData = new GdaBandDataT(dataT, dstId);
        bandCtl.Read(bandData);
        UDataT data = new UDataT();
        bandData.Data(data);
        UStringT dataStr = new UStringT();
        data.ToS(dataStr);
        dataStr.ToConsole();

        return UErrCodeT.UErrFalse;
    }

    public CGdaDatasetCtl LoadDataset(UStringT aFile,
                                      UAccessCodeT aAccess,
                                      GdaFormatCodeT aFormat)
    {
        CGdaDriverCtl dr = mDrivers.Driver(aFormat);
        CGdaDatasetCtl datasetCtl = dr.Load(aFile, aAccess);

        return datasetCtl;
    }

    public UErrCodeT TestOgr()
    {
        OgrCtr();

        return UErrCodeT.UErrFalse;
    }

    public UErrCodeT OgrCtr()
    {
        GdaOgrSrsT srsSrc = new GdaOgrSrsT();
        srsSrc.SetProjCs(GdaProjCsCodeT.GdaProjCsWgs1984);

        GdaOgrSrsT srsDst = new GdaOgrSrsT();
        srsDst.SetProjCs(GdaProjCsCodeT.GdaProjCsXian1980);

        GdaOgrCtrT ctr = new GdaOgrCtrT(srsSrc, srsDst);
        BMathCsC2dT ptSrc = new BMathCsC2dT(113.2498169, 23.3335876);
        BMathCsC2dT ptDst = new BMathCsC2dT();;
        ctr.Tr(ptDst, ptSrc);

        return UErrCodeT.UErrFalse;
    }
}
