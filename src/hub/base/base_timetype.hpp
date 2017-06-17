/******************************************************************************
 * $Id: base_time.hpp 2016-08 $
 *
 * Project:  Base.
 * Purpose:  Base time struct.
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
 *****************************************************************************/

#ifndef BASE_TIMETYPE_HPP_INCLUDED
#define BASE_TIMETYPE_HPP_INCLUDED

#include "hub_base.h"

/**
 * \brief BTimeDateT.
 */
typedef struct
{
    UIntT sec;                  // Seconds. [0, 60]
    UIntT min;                  // Minutes. [0, 59]
    UIntT hour;                 // Hours.   [0, 23]
    UIntT mday;                 // Day.     [1, 31]
    UIntT mon;                  // Month.   [0, 11]
    UIntT year;                 // Year.    [-9999, 9999]

    UIntT wday;                 // Day of week. [0, 6]
    UIntT yday;                 // Days of year. [0, 365]

    UIntT isdst;                // DST. [-1, 1]

    UIntT gmtoff;               // Seconds east of UTC.
    UIntT zone;                 // Timezone abbreviation.
} BTimeTmT;

#endif  // BASE_TIMETYPE_HPP_INCLUDED
