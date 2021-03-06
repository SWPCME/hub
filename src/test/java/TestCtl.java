/******************************************************************************
 * $Id: TestCtl.java 2017-09 $
 *
 * Project:  Test.
 * Purpose:  Test control.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017.08 ~ 2017 Weiwei Huang
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
import TestJava.*;

public class TestCtl
{
    public static void main(String[] aArgs)
    {
        System.out.println(System.getProperty("java.library.path"));
        TestOgr ogr = new TestOgr();
        ogr.Test();

        TestGda gda = new TestGda();
        gda.Test();

        TestRst rst = new TestRst();
        rst.Test();

        TestFmd fmd = new TestFmd();
        fmd.Test();
    }
}
