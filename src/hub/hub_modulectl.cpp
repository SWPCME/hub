/******************************************************************************
 * $Id: hub_modulectl.cpp 2017-07 $
 *
 * Project:  Hub library.
 * Purpose:  Module control.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016-08 ~ 2017, Weiwei Huang
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ****************************************************************************/

#include "hub_modulectl.hpp"

/**
 * \brief Base module.
 */
#include "base_ctl.hpp"

/**
 * \brief Core module.
 */
#include "core_ctl.hpp"
#include "cls_ctl.hpp"
#include "ccs_ctl.hpp"
#include "sys_ctl.hpp"
#include "ogr_ctl.hpp"
#include "gda_ctl.hpp"
#include "gsl_ctl.hpp"
#include "cut_ctl.hpp"

/**
 * \brief Wrap module.
 */
#include "wrap_ctl.hpp"
#include "ust_ctl.hpp"
#include "vtr_ctl.hpp"

/**
 * \brief Ctgy module.
 */
#include "ctgy_ctl.hpp"
#include "rtk_ctl.hpp"
#include "fmd_ctl.hpp"

#define HUB_REGISTER(aCode, aClass)             \
    BMD_REGISTER(aCode, aClass, mMCodeH)

#define HUB_DEREGISTER(aCode, aClass)           \
    BMD_DEREGISTER(aCode, aClass, mMCodeH)

/**
 * \brief Constructor.
 */
CHubModuleCtl::CHubModuleCtl()
{
    CBaseCtl* base = CBaseCtl::Base();
    base->Init();

    mMCodeH.Init(UContainerMap);
    mState = UStateOff;
}

/**
 * \brief Destructor.
 */
CHubModuleCtl::~CHubModuleCtl()
{
}

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CHubModuleCtl::Init(UFlagCodeT aFlag /* = UFlagOff */)
{
    return UErrFalse;
}

/**
 * \brief Register.
 *
 * @param aCode Hub code that to register.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CHubModuleCtl::Register(HubCodeT aCode)
{
    if (mMCodeH.FindByKey(aCode) == UErrFalse)
    {
        return UErrFalse;
    }

    switch (aCode)
    {
        // core
        HUB_REGISTER(HubMCls, CClsCtl);
        HUB_REGISTER(HubMCcs, CCcsCtl);
        HUB_REGISTER(HubMSys, CSysCtl);
        HUB_REGISTER(HubMOgr, COgrCtl);
        HUB_REGISTER(HubMGda, CGdaCtl);
        HUB_REGISTER(HubMGsl, CGslCtl);
        HUB_REGISTER(HubMCut, CCutCtl);
        // wrap
        HUB_REGISTER(HubMUst, CUstCtl);
        HUB_REGISTER(HubMVtr, CVtrCtl);
        // ctgy
        HUB_REGISTER(HubMRtk, CRtkCtl);
        HUB_REGISTER(HubMFmd, CFmdCtl);
    default:
        return UErrTrue;
    }

    return UErrTrue;
}

/**
 * \brief Register all module. 
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CHubModuleCtl::RegisterAll()
{
    RegisterRegion((HubCodeT) kHubCodeCoreBegin, (HubCodeT) kHubCodeCoreEnd);
    RegisterRegion((HubCodeT) kHubCodeWrapBegin, (HubCodeT) kHubCodeWrapEnd);
    RegisterRegion((HubCodeT) kHubCodeCtgyBegin, (HubCodeT) kHubCodeCtgyEnd);

    return UErrFalse;
}

/**
 * \brief Deregister.
 *
 * @param aCode Code of hub which to deregister.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CHubModuleCtl::Deregister(HubCodeT aCode)
{
    if (mMCodeH.FindByKey(aCode) == UErrTrue)
    {
        return UErrTrue;
    }

    switch (aCode)
    {
        // core
        HUB_DEREGISTER(HubMCls, CClsCtl);
        HUB_DEREGISTER(HubMCcs, CCcsCtl);
        HUB_DEREGISTER(HubMSys, CSysCtl);
        HUB_DEREGISTER(HubMOgr, COgrCtl);
        HUB_DEREGISTER(HubMGda, CGdaCtl);
        HUB_DEREGISTER(HubMGsl, CGslCtl);
        HUB_DEREGISTER(HubMCut, CCutCtl);
        // wrap
        HUB_DEREGISTER(HubMUst, CUstCtl);
        HUB_DEREGISTER(HubMVtr, CVtrCtl);
        // ctgy
        HUB_DEREGISTER(HubMRtk, CRtkCtl);
        HUB_DEREGISTER(HubMFmd, CFmdCtl);
    default:
        return UErrTrue;
    }
    mMCodeH.DelByKey(aCode);

    return UErrFalse;
}

/**
 * \brief Deregister all.
 *
 * @param aCode Code of hub which to deregister.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CHubModuleCtl::DeregisterAll()
{
    MHandleCodeItT *it = mMCodeH.Iterator();
    for (it->Head(); it->State() == UErrFalse; it->Next())
    {
        Deregister(it->Key());
    }

    return UErrFalse;
}

/**
 * \brief Get handle by hub code.
 *
 * @param aCode Hub code to select handle.
 *
 * @return Handle that you select by hub code.
 */
UHandleT CHubModuleCtl::Module(HubCodeT aCode)
{
    if (mMCodeH.FindByKey(aCode) == UErrFalse)
    {
        return (UHandleT) mMCodeH[aCode];
    }

    return NULL;
}

/***** Private A *****/

/**
 * \brief Register module with region.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CHubModuleCtl::RegisterRegion(HubCodeT aBegin, HubCodeT aEnd)
{
    for (UIntT i = aBegin; i <= aEnd; i++)
    {
        if (Register((HubCodeT) i) == UErrTrue)
        {
            break;
        }
    }

    return UErrFalse;
}

/***** Private B *****/
