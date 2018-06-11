/* -*- mode: c++ -*- */
/******************************************************************************
 * $Id: hub_ctl.cpp 2017-09 $
 *
 * Project:  Hub.
 * Purpose:  Hub ctl.
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
 *****************************************************************************/

#include "hub_ctl.hpp"

// Module
#include "hub_modulectl.hpp"

// Global static
CHubCtl* CHubCtl::mHub = NULL;

/******************************************************************************
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 *****************************************************************************/
UErrCodeT CHubCtl::Init()
{
    mModule->Init();

    return UErrFalse;
}

/**
 * \brief Get Hub Control.
 *
 * @return Handle of "CHubCtl", if successful; NULL, if failed.
 */
CHubCtl* CHubCtl::Hub()
{
    BMD_CLASS_NEW(mHub, CHubCtl);

    return mHub;
}

/**
 * \brief Register module.
 *
 * @return Handle of module, if successful; NULL, if failed.
 */
CHubModuleCtl *CHubCtl::RegModule()
{
    CHubModuleCtl *module;
    BMD_POINTER_INIT(module);
    BMD_CLASS_NEW(module, CHubModuleCtl);

    return module;
}

/**
 * \brief Deregister module.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CHubCtl::DeregModule(CHubModuleCtl *aModule)
{
    BMD_CLASS_DEL(aModule);

    return UErrFalse;
}

/***** Private A *****/

/**
 * \brief Constructor.
 */
CHubCtl::CHubCtl()
{
    mModule = new CHubModuleCtl;
}

/**
 * \brief Destructor.
 */
CHubCtl::~CHubCtl()
{
    delete mModule;
}

/***** Private B *****/
