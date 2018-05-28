/******************************************************************************
 * $Id: fmd_ctl.hpp 2017-06 $
 *
 * Project:  FMD (FMD: Fire Model).
 * Purpose:  Fmd base definition.
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

#ifndef FMD_BASE_HPP_INCLUDED
#define FMD_BASE_HPP_INCLUDED

#include "hub_base.h"
// Base.
#include "base_macrodefn.hpp"

#define FMD_LIB HUB_LIB

typedef UHandleT FmdFarsiteHT;
typedef enum
{
    FmdFileCfgCreate = 1,
    FmdFileCfgLoad   = 2,
} FmdFileCfgCodeT;

typedef enum
{
    FmdMapEnvIntervalOneH      = 1,
    FmdMapEnvIntervalTenH      = 2,
    FmdMapEnvIntervalHundredH  = 3,
    FmdMapEnvIntervalThousandH = 4,
} FmdMapEnvIntervalCodeT;

#define FMD_FARSITE(aCtl) BMD_CLASS_H(aCtl, Farsite5)

#define FMD_CTL(aCtl)                               \
    BMD_CTGY_CTL(ctgyCtl);                          \
    CFmdCtl *aCtl = ctgyCtl->Fmd()

#define FMD_TYPE_CTL(aCtl)                      \
    {                                           \
        FMD_CTL(fmdCtl);                        \
        aCtl = fmdCtl->Type();                  \
    }

#endif  // FMD_BASE_HPP_INCLUDED
