/******************************************************************************
 * $Id: TestCtl.java 2017-01 $
 *
 * Project:  Test of java.
 * Purpose:  Test control.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016 ~ 2017 Weiwei Huang
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

import hub.HubCtl;
import hub.HubBase;

public class TestCtl
{
    public void TestCtl()
    {
    }

    public static void main(String[] aArgs)
    {
        HubCtl hubCtl = new HubCtl();
        if (hubCtl.init() == HubBase.err.t())
        {
        }
    }
}
