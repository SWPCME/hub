/******************************************************************************
 * $Id: pyc_base.hpp 2018-03 $
 *
 * Project:  PYC(PYC: Python c library).
 * Purpose:  Pyc base definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2018-03 ~ 2018, Weiwei Huang
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

#ifndef PYC_BASE_HPP_INCLUDED
#define PYC_BASE_HPP_INCLUDED

#include "hub_base.h"

#define PYC_LIB HUB_LIB

typedef UHandleT PycObjHT;
typedef UHandleT PycObjTypeHT;
typedef UHandleT PycObjBytesHT;
typedef UHandleT PycObjListHT;
typedef UHandleT PycObjListItemHT;
typedef UHandleT PycObjIntHT;
typedef UHandleT PycObjFloatHT;

#define PYC_CTL(aCtl)                           \
    {                                           \
        BMD_CORE_CTL(coreCtl);                  \
        aCtl = coreCtl->Pyc();                  \
    }

#define PYC_TYPECTL(aCtl)                       \
    {                                           \
        CPycCtl *pyc;                           \
        BMD_POINTER_INIT(pyc);                  \
        PYC_CTL(pyc);                           \
        aCtl = pyc->Type();                     \
    }

#endif  // PYC_BASE_HPP_INCLUDED
