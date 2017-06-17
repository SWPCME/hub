/******************************************************************************
 * $Id: hub_ctl.cpp 2016-08 $
 *
 * Project:  Hub.
 * Purpose:  Hub ctl.
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

#include "hub_ctl.hpp"

// Module
#include "hub_modulectl.hpp"

// Global static
CHubCtl* CHubCtl::m_hub = NULL;

/******************************************************************************
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 *****************************************************************************/
UErrCodeT CHubCtl::Init()
{
    m_module->Init();

    return UErrFalse;
}

/**
 * \brief Get Hub Control.
 *
 * @return Handle of "CHubCtrl", if successful; NULL, if failed.
 */
CHubCtl* CHubCtl::Hub()
{
    if (m_hub == NULL)
    {
        m_hub = new CHubCtl;
    }

    return m_hub;
}

/**
 * \brief Register.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CHubCtl::Register(HubCodeT aCode)
{
    if ((aCode >= kHubCodeCoreEnd && aCode <= kHubCodeWrapEnd) || (aCode >= kHubCodeCtgyBegin))
    {
        return m_module->Register(aCode);
    }

    return UErrTrue;
}

/**
 * \brief Register all.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CHubCtl::RegisterAll()
{
    for (UIntT i = kHubCodeCoreEnd; i <= kHubCodeWrapEnd; ++i)
    {
        Register((HubCodeT) i);
    }
    
    return UErrFalse;
}

/**
 * \brief Deregister.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CHubCtl::Deregister(HubCodeT aCode)
{
    if ((aCode >= kHubCodeCoreEnd && aCode <= kHubCodeWrapEnd) || (aCode >= kHubCodeCtgyBegin))
    {
        return m_module->Deregister(aCode);
    }

    return UErrTrue;
}

/**
 * \brief Deregister all.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CHubCtl::DeregisterAll()
{
    for (UIntT i = kHubCodeCoreEnd; i <= kHubCodeWrapEnd; ++i)
    {
        Deregister((HubCodeT) i);
    }
    
    return UErrFalse;
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
    return m_module->Module(aCode);
}

/***** Private A *****/

/**
 * \brief Constructor.
 */
CHubCtl::CHubCtl()
{
    m_module = new CHubModuleCtl;
}

/**
 * \brief Destructor.
 */
CHubCtl::~CHubCtl()
{
    DeregisterAll();
    delete m_module;
}

/***** Private B *****/
