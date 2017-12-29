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

    return mModule;
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

/**
 * \brief Register.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CHubCtl::Register(HubCodeT aCode)
{
    return mModule->Register(aCode);
}

/**
 * \brief Register all.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CHubCtl::RegisterAll()
{
    return mModule->RegisterAll();
}

/**
 * \brief Deregister.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CHubCtl::Deregister(HubCodeT aCode)
{
    return mModule->Deregister(aCode);
}

/**
 * \brief Deregister all.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CHubCtl::DeregisterAll()
{
    return mModule->DeregisterAll();
}

/**
 * \brief Get module.
 *
 * @param aCode Hub code.
 *
 * @return Handle that you select by aCode.
 */
UHandleT CHubCtl::Module(HubCodeT aCode)
{
    return mModule->Module(aCode);
}

/**
 * \brief Gda handle.
 *
 * @return Handle of gda, if successful; NULL, if failed.
 */
CGdaCtl *CHubCtl::Gda()
{
    return (CGdaCtl *) Module(HubMGda);
}

/**
 * \brief Ogr handle.
 *
 * @return Handle of ogr, if successful; NULL, if failed.
 */
COgrCtl *CHubCtl::Ogr()
{
    return (COgrCtl *) Module(HubMOgr);
}

/**
 * \brief Rst handle.
 *
 * @return Handle of rst, if successful; NULL, if failed.
 */
CRstCtl *CHubCtl::Rst()
{
    return (CRstCtl *) Module(HubMRst);
}

/**
 * \brief Fmd handle.
 *
 * @return Handle of fmd, if successful; NULL, if failed.
 */
CFmdCtl *CHubCtl::Fmd()
{
    return (CFmdCtl *) Module(HubMFmd);
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
    DeregisterAll();
    delete mModule;
}

/***** Private B *****/
