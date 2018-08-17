/******************************************************************************
 * $Id: TestGda.java 2018-06 $
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
        mUtils = mGda.Utils();

        // Init variable.
        mDataPath = new UStringT("../../../../data/core/gda");

        // Test core module.
        TestCore();

        // Test ogr module.
        TestOgr();

        // Test utils module.
        TestUtils();

        // Deregister module.
        hubCtl.DeregModule(module);

        return UErrCodeT.UErrFalse;
    }

    private UErrCodeT TestCore()
    {
        CoreBand();

        return UErrCodeT.UErrFalse;
    }

    private UErrCodeT DsPosToId(BMathCsC2dT aId, BMathCsC2dT aPos,
                               CGdaDatasetCtl aDs)
    {
        GdaOgrSrsT srsSrc = new GdaOgrSrsT();
        srsSrc.SetProjCs(GdaProjCsCodeT.GdaProjCsWgs1984);
        GdaOgrSrsT srsDst = new GdaOgrSrsT();
        srsDst.SetProjCs(GdaProjCsCodeT.GdaProjCsXian1980);

        GdaOgrCtrT ctr = new GdaOgrCtrT(srsSrc, srsDst);
        BMathCsC2dT pos = new BMathCsC2dT();
        ctr.Tr(pos, aPos);

        UErrCodeT err = aDs.PosToId(aId, pos);

        if (err == UErrCodeT.UErrTrue)
        {
            return err;
        }

        return err;
    }

    private UErrCodeT CoreBand()
    {
        // Load band.
        UStringT file = new UStringT(mDataPath);
        file.Add("/dem/dem_xian80.tif");
        CGdaDriverCtl dr = mDrivers.Driver(GdaFormatCodeT.GdaFormatTif);
        CGdaDatasetCtl datasetCtl = dr.Load(file, UAccessCodeT.UAccessRead);
        CGdaBandCtl bandCtl = datasetCtl.Band(1);

        // Transform the coordinate system.
        GdaOgrSrsT srsSrc = new GdaOgrSrsT();
        srsSrc.SetProjCs(GdaProjCsCodeT.GdaProjCsWgs1984);
        GdaOgrSrsT srsDst = new GdaOgrSrsT();
        srsDst.SetProjCs(GdaProjCsCodeT.GdaProjCsXian1980);
        GdaOgrCtrT ctr = new GdaOgrCtrT(srsSrc, srsDst);
        BMathCsC2dT ptSrc = new BMathCsC2dT(113.5255460, 23.4385733);
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

        // close tif
        dr.Close(file);

        return UErrCodeT.UErrFalse;
    }

    private CGdaDatasetCtl LoadDataset(UStringT aFile,
                                      UAccessCodeT aAccess,
                                      GdaFormatCodeT aFormat)
    {
        CGdaDriverCtl dr = mDrivers.Driver(aFormat);
        CGdaDatasetCtl datasetCtl = dr.Load(aFile, aAccess);

        return datasetCtl;
    }

    private UErrCodeT TestOgr()
    {
        OgrCtr();

        return UErrCodeT.UErrFalse;
    }

    private UErrCodeT OgrCtr()
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

    private UErrCodeT TestUtils()
    {
        UtilsR2R();

        return UErrCodeT.UErrFalse;
    }

    private UErrCodeT UtilsR2R()
    {
        // Prepare data of source and output file.
        UStringT trPath = new UStringT(mDataPath);
        trPath.Add("/tr");
        UStringT rstSrc = new UStringT(trPath);
        rstSrc.Add("/dem1.tif");
        UStringT rstDst = new UStringT(trPath);
        rstDst.Add("/dem1_srcwin.tif");

        // Open data of source.
        GdaFormatCodeT frmtSrc = GdaFormatCodeT.GdaFormatTif;
        CGdaCoreCtl gdaCore = mGda.Core();
        CGdaDriversCtl drs = gdaCore.Drivers();
        drs.Register(frmtSrc);
        CGdaDriverCtl drSrc = drs.Driver(frmtSrc);
        UAccessCodeT access = UAccessCodeT.UAccessRead;
        CGdaDatasetCtl dsSrc = drSrc.Load(rstSrc, access);

        // Split with subwindow.
        R2RTrSrcWin(dsSrc, rstDst);

        // Close data of source.
        drSrc.Close(rstSrc);

        return UErrCodeT.UErrFalse;
    }

    private UErrCodeT R2RTrSrcWin(CGdaDatasetCtl aDsSrc, UStringT aRstDst)
    {
        CGdaUtilsTr tr = mUtils.Tr();
        CGdaTrRst rst = tr.Rst();

        // set destination format
        GdaTrRstToRstT opt = new GdaTrRstToRstT();
        GdaFormatCodeT frmt = GdaFormatCodeT.GdaFormatTif;
        opt.SetFrmt(frmt);

        // set band number
        BCtnIntT bandNumS = new BCtnIntT(UContainerCodeT.UContainerList);
        bandNumS.Add(1);
        opt.SetBand(bandNumS);

        // ul: up left.
        BMathCsC2dT ulPos = new BMathCsC2dT(113.511129, 23.443046);
        BMathCsC2dT ulId = new BMathCsC2dT();
        DsPosToId(ulId, ulPos, aDsSrc);

        // lr: low right.
        BMathCsC2dT lrPos = new BMathCsC2dT(113.521129, 23.428046);
        BMathCsC2dT lrId = new BMathCsC2dT();
        DsPosToId(lrId, lrPos, aDsSrc);

        // set source subwindow
        BMathCsC2dT off = new BMathCsC2dT(ulId.X(), ulId.Y());
        BMathCsC2dT size = new BMathCsC2dT(lrId.X() - ulId.X(), lrId.Y() - ulId.Y());
        opt.SetSrcWin(off, size);

        rst.ToRst(aRstDst, aDsSrc, opt);

        return UErrCodeT.UErrFalse;
    }

    private CGdaCtl mGda;
    private CGdaDriversCtl mDrivers;
    private CGdaUtilsCtl mUtils;
    private UStringT mDataPath;
}
