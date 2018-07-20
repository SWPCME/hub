/******************************************************************************
 * $Id: TestRst.java 2017-12 $
 *
 * Project:  Test.
 * Purpose:  Test rst.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017.12 ~ 2017 Weiwei Huang
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

public class TestRst
{
    public static void main(String[] aArg)
    {
        TestRst rst = new TestRst();
        rst.Test();
    }

    public UErrCodeT Test()
    {
        CHubCtl hubCtl = CHubCtl.Hub();
        CHubModuleCtl module = hubCtl.RegModule();
        module.Register(HubCodeT.HubMRst);
        mRst = module.Rst();

        // Init variable.
        mDataPath = new UStringT("../../../../data/core/gda");

        TestFrmt();

        hubCtl.DeregModule(module);

        return UErrCodeT.UErrFalse;
    }

    private UErrCodeT TestFrmt()
    {
        CRstFrmtCtl frmtCtl = mRst.Frmt();
        CRstFrmtLcp frmtLcp = frmtCtl.Lcp();
        UStringT lcp = new UStringT(mDataPath);
        lcp.Add("/tr/dem1_srcwin.lcp");
        UStringT elev = new UStringT(mDataPath);
        elev.Add("/tr/dem1_srcwin.tif");
        frmtLcp.Create(lcp, elev, null, null, GdaProjCsCodeT.GdaProjCsXian1980);

        return UErrCodeT.UErrFalse;
    }

    private CRstCtl mRst;
    private UStringT mDataPath;
}
