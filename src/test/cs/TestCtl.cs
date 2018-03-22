/******************************************************************************
 * $Id: TestCtl.cs 2017-05 $
 *
 * Project:  Test of cs.
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

using System;
using Cs.Hub;
using Cs.Hub.Core.Std;

namespace Cs.Test
{
    public class TestCtl
    {
        public TestCtl()
        {
        }

        ~TestCtl()
        {
        }

        public static void Main(String[] aArgs)
        {
            HubCtl hubCtl = HubCtl.Hub();
            hubCtl.Init();
            StdCtl stdCtl = hubCtl.Module(BHubCodeT.Std) as StdCtl;
            stdCtl.Init();
            StdStrCtl str = stdCtl.Str();
            Int64 num = new Int64();
            string x = "123";
            str.AToI(ref num, x);
            Console.WriteLine(x);
            Console.WriteLine(num);
        }
    }
}