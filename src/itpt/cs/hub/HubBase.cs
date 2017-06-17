/******************************************************************************
 * $Id: hub_base.cpp 2017-05 $
 *
 * Project:  Hub of java.
 * Purpose:  Hub base.
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

namespace Cs.Hub
{
    public class HubBase
    {
        public HubBase() {}
        ~HubBase() {}
    }

    public enum BHubCodeT
    {
        Std = 0x00,
    }

    public enum BErrCodeT
    {
        None = 0x00,
        Error = 0x01,
    }
}