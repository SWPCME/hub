/******************************************************************************
 * $Id: HubModuleCtl.cs 2017-05 $
 *
 * Project:  Hub of cs.
 * Purpose:  Hub module control.
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

using Cs.Hub.Core;
using Cs.Hub.Core.Std;

using Cs.Hub.Wrap;

namespace Cs.Hub
{
    public class HubModuleCtl
    {
        /// <summary> Constructor. </summary>
        public HubModuleCtl()
        {
            mCore = CoreCtl.Core();
            mWrap = WrapCtl.Wrap();
        }

        /// <summary> Initial. </summary>
        public BErrCodeT Init()
        {
            return BErrCodeT.None;
        }

        public HubBase Module(BHubCodeT aCode)
        {
            HubBase handle = null;
            StdCtl std = mCore.Std();
            handle = std as HubBase;

            return handle;
        }

        /// <summary> Destructor. </summary>
        ~HubModuleCtl()
        {
        }

        // Private value.
        private CoreCtl mCore = null;
        private WrapCtl mWrap = null;
    }
}