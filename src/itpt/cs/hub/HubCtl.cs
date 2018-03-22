/******************************************************************************
 * $Id: HubCtl.cs 2017-05 $
 *
 * Project:  Hub of cs.
 * Purpose:  Hub control.
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

namespace Cs.Hub
{
    public sealed class HubCtl
    {
        /// <summary> Hub. </summary>
        public static HubCtl Hub()
        {
            if (mHub == null)
            {
                lock (mObject)
                {
                    if (mHub == null)
                    {
                        mHub = new HubCtl();
                    }
                }
            }
            return mHub;
        }

        /// <summary> Initial. </summary>
        public BErrCodeT Init()
        {
            mModule.Init();

            return BErrCodeT.None;
        }

        /// <summary> Module. </summary>
        public HubBase Module(BHubCodeT aCode)
        {
            return mModule.Module(aCode);
        }

        /***** Private A *****/
        /// <summary> Constructor. </summary>
        /// <param name=""> void </param>
        /// <return> NULL </return>
        private HubCtl()
        {
            mModule = new HubModuleCtl();
        }

        /// <summary> Destructor. </summary>
        ~HubCtl()
        {
        }

        private static volatile HubCtl mHub = null;
        private static object mObject = new Object();
        private HubModuleCtl mModule = null;
        /***** Private B *****/
    }
}