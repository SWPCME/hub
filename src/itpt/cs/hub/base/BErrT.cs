/******************************************************************************
 * $Id: UstCtl.cs 2017-05 $
 *
 * Project:  Cs.Hub.Wrap.Ust
 * Purpose:  Universal struct.
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

namespace Cs.Hub.Base
{
    public class BErrT
    {
        /// <summary> Constructor. </summary>
        public BErrT()
        {
            Init();
        }

        /// <summary> "=" operator </summary>
        // public static UErrT operator =(UErrT aL, UErrT aR)
        // {
        //     UErrT err = new UErrT();
        //     aL. = aR;
        //     if (aL.Error() == aR.Error())
        //     {
        //         return err;
        //     }

        //     return err.SetNone();
        // }

        /// <summary> "==" operator </summary>
        public static BErrT operator ==(UErrT aL, UErrT aR)
        {
            UErrT err = new UErrT();
            if (aL.Error() == aR.Error())
            {
                return err;
            }

            return err.SetNone();
        }

        /// <summary> "!=" operator </summary>
        public static UErrT operator !=(UErrT aL, UErrT aR)
        {
            UErrT err = new UErrT();
            if (aL.Error() != aR.Error())
            {
                return err;
            }

            return err.SetNone();
        }

        /// <summary> Set Error Code. </summary>
        // public UErrT SetErrorCode(int aCode)
        // {
        //     mErr = aCode;

        //     return this;
        // }

        /// <summary> Get Error. </summary>
        public int Error()
        {
            return mErr;
        }

        /// <summary> Set Error. </summary>
        public UErrT SetError()
        {
            mErr = mError;

            return this;
        }

        /// <summary> None. </summary>
        public UErrT SetNone()
        {
            mErr = mNone;

            return this;
        }

/***** Private A *****/

        /// <summary> Destructor. </summary>
        ~UErrT()
        {
        }

        /// <summary> Initial. </summary>
        private int Init()
        {
            mErr = mNone;

            return mErr;
        }

        // Private Value.
        private int mErr;
        private static int mError = 1;
        private static int mNone = 0;

/***** Private B *****/
    }
}