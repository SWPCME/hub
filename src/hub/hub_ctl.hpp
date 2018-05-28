/******************************************************************************
 * $Id: hub_ctl.hpp 2017-09 $
 *
 * Project:  Hub Library.
 * Purpose:  Hub control, for all library.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016-08 ~ 2017 Weiwei Huang
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

#ifndef HUB_CTL_HPP_INCLUDED
#define HUB_CTL_HPP_INCLUDED

#include "hub_base.h"

// hub
class CHubModuleCtl;
// core
class CGdaCtl;
class COgrCtl;
// wrap
class CRstCtl;
// ctgy
class CFmdCtl;

class HUB_LIB CHubCtl
{
 public:
    static CHubCtl* Hub();

    // Initialize.
    UErrCodeT Init();

    // Register module.
    CHubModuleCtl *RegModule();
    UErrCodeT DeregModule(CHubModuleCtl *aModule);

    // Private, not to use direct.
    CHubCtl();
    ~CHubCtl();

 protected:
 private:
    static CHubCtl* mHub;
    CHubModuleCtl* mModule;
};

#endif  /* HUB_CTL_HPP_INCLUDED */
