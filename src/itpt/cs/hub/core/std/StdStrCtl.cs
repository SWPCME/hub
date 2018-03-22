/******************************************************************************
 * $Id: StdStrCtl.cs 2017-05 $
 *
 * Project:  Std module.
 * Purpose:  String control.
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

namespace Cs.Hub.Core.Std
{
    public class StdStrCtl
    {
        public StdStrCtl()
        {
        }

        ~StdStrCtl()
        {
        }

        /// <summary> To integer. </summary>
        /// <param name = "aStr"> String. </param>
        /// <return>
        /// BErrCodeT.None, if successful; BErrCodeT.Error, if failed.
        /// </return>
        public BErrCodeT AToI(ref Int64 aNum, string aStr)
        {
            aNum = Convert.ToInt64(aStr);
            Console.WriteLine(aNum);

            return BErrCodeT.None;
        }

        /// <summary> Compare two string. </summary>
        /// <param name = "aDest"> Destination string. </param>
        /// <param name = "aSrc"> Source string. </param>
        /// <return>
        /// BErrCodeT.None, if successful; BErrCodeT.Error, if failed.
        /// </return>
        public BErrCodeT Cmp(string aDest, string aSrc)
        {
            if (aDest == aSrc)
            {
                return BErrCodeT.None;
            }

            return BErrCodeT.Error;
        }

        /// <summary> </summary>
        public void SubString()
        {
        }

        public void IndexOf()
        {
        }
    }
}