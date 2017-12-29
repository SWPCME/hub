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
    private CRstCtl mRst;

    public static void main(String[] aArg)
    {
        TestRst rst = new TestRst();
        rst.Test();
    }

    public UErrCodeT Test()
    {
        CHubCtl hubCtl = CHubCtl.Hub();
        hubCtl.Register(HubCodeT.HubMRst);
        mRst = hubCtl.Rst();
        TestFrmt();

        return UErrCodeT.UErrFalse;
    }

    public UErrCodeT TestFrmt()
    {
        CRstFrmtCtl frmtCtl = mRst.Frmt();
        CRstFrmtLcp frmtLcp = frmtCtl.Lcp();
        UStringT lcp = new UStringT("../../data/core/gda/dem/test.lcp");
        UStringT elev = new UStringT("../../data/core/gda/dem/dem1.tif");
        frmtLcp.Create(lcp, elev, null, null);

        return UErrCodeT.UErrFalse;
    }
}
