/******************************************************************************
 * $Id: hub_modulectl.hpp 2017-09 $
 *
 * Project:  Hub Library.
 * Purpose:  Module control.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016-08 ~ 2017, Weiwei Huang
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

#ifndef HUB_MODULECTL_HPP_INCLUDED
#define HUB_MODULECTL_HPP_INCLUDED

#include "hub_base.h"
// ust
#include "ust/ust_containertype.hpp"
// base
#include "base_macrodefn.hpp"

// base
class CBaseCtl;

class HUB_LIB CHubModuleCtl
{
 public:
    CHubModuleCtl();
    ~CHubModuleCtl();

    UErrCodeT Init(UFlagCodeT aFlag = UFlagOff);
    UErrCodeT Register(HubCodeT aCode);
    UErrCodeT RegisterAll();
    UErrCodeT Deregister(HubCodeT aCode);
    UErrCodeT DeregisterAll();
    UHandleT Module(HubCodeT aCode);

 protected:
 private:
    typedef UContainerT<UHandleT, HubCodeT> MHandleCodeT;
    typedef UIteratorT<UHandleT, HubCodeT> MHandleCodeItT;

    UErrCodeT RegisterRegion(HubCodeT aBegin, HubCodeT aEnd);

    UStateCodeT mState;
    MHandleCodeT mMCodeH;     /* Register handle. */

    CBaseCtl *mBase;
};

#endif  /* MODULE_CTL_H_INCLUDED */
