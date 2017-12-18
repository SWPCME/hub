/******************************************************************************
 * $Id: plp_base.hpp 2017-11 $
 *
 * Project:  PLP (PLP: PL plot).
 * Purpose:  Plp base definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-11 ~ 2017, Weiwei Huang
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

#ifndef PLP_BASE_HPP_INCLUDED
#define PLP_BASE_HPP_INCLUDED

// hub
#include "hub_base.h"

// base
#include "base_macrodefn.hpp"

#define PLP_LIB HUB_LIB

typedef enum
{
    PlpParsePartial   = 0x0000,
    PlpParseFull      = 0x0001,
    PlpParseQuiet     = 0x0002,
    PlpParseNodelete  = 0x0004,
    PlpParseShowall   = 0x0008,
    PlpParseOverride  = 0x0010,
    PlpParseNoprogram = 0x0020,
    PlpParseNodash    = 0x0040,
    PlpParseSkip      = 0x0080,
} PlpParseCodeT;

typedef enum
{
    PlpDevNull = 0,

    // libgd
    PlpDevPng  = 1,
    PlpDevJpeg = 2,
    PlpDevGif  = 3,
} PlpDevCodeT;

#define PLP_TYPE_CTL(aCtl)                      \
    if (aCtl == NULL)                           \
    {                                           \
        BMD_CORE_CTL(coreCtl);                  \
        CPlpCtl *plpCtl = coreCtl->Plp();       \
        aCtl = plpCtl->Type();                  \
    }

#endif  // PLP_BASE_HPP_INCLUDED
