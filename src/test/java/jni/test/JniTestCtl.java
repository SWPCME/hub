/******************************************************************************
 * $Id: TestJavaCtl.java 2017-09 $
 *
 * Project:  Test of java.
 * Purpose:  Test java control.
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

import jnitest.*;

public class JniTestCtl
{
    public static void main(String[] aArgs)
    {
        System.out.println(System.getProperty("java.library.path"));
        CJniTest test = new CJniTest();
        test.Test();
    }
}
