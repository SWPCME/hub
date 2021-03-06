/******************************************************************************
 * $Id: WrapCtl.cs 2017-05 $
 *
 * Project:  Wrap module.
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

using Cs.Hub.Core.Std;

namespace Cs.Hub.Core
{
    public class CoreCtl
    {
        /// <summary> Handle. </summary>
        public static CoreCtl Core()
        {
            if (mCore == null)
            {
                lock (mObject)
                {
                    if (mCore == null)
                    {
                        mCore = new CoreCtl();
                    }
                }
            }
            return mCore;
        }

        public StdCtl Std()
        {
            return mStd;
        }

/***** Private A *****/

        /// <summary> Constructor. </summary>
        private CoreCtl()
        {
            mStd = new StdCtl();

            Init();
        }

        /// <summary> Destructor. </summary>
        ~CoreCtl()
        {
        }

        /// <summary> Initial. </summary>
        private BErrCodeT Init()
        {
            return BErrCodeT.None;
        }

        private static volatile CoreCtl mCore;
        private static object mObject = new Object();
        private StdCtl mStd = null;

/***** Private B *****/
    }
}