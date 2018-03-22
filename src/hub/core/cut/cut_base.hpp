/******************************************************************************
 * $Id: cut_ctl.hpp 2017-06 $
 *
 * Project:  CUT (CUT: Client-side URL Transfer).
 * Purpose:  Cut controler definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016 ~ 2017, Weiwei Huang
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
 ****************************************************************************/

#ifndef CUT_BASE_HPP_INCLUDED
#define CUT_BASE_HPP_INCLUDED

#include "hub_base.h"
#include "ust/ust_stringtype.hpp"
#ifdef OS_CYGWIN
#include "sys/select.h"
#endif  // OS_CYGWIN

#define CUT_LIB HUB_LIB

typedef UHandleT CutEasyHT;
typedef UHandleT CutMultiHT;
typedef UHandleT CutSlistHT;

typedef enum
{
    // Http.
    CutOptUrl        = 1,
    CutOptHttpHeader = 2,
    CutOptHttpGet    = 3,
    CutOptHttpPut    = 4,

    // Data.
    CutOptWriteData  = 11,

    // Function.
    CutOptReadFunc  = 101,
    CutOptWriteFunc = 102,
} CutOptCodeT;

// Callback Function.
typedef UErrCodeT (*cut_read_callback)(UStringT *aBuffer, UIntT aSize,
                                       UIntT aNItems, UHandleT aOutStream);
typedef UErrCodeT (*cut_write_callback)(UStringT *aBuffer, UIntT aSize,
                                        UIntT aNItems, UHandleT aOutStream);

#endif  // CUT_BASE_HPP_INCLUDED
