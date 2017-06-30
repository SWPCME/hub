/******************************************************************************
 * $Id: hub_modulectl.cpp 2016-08 $
 *
 * Project:  Hub library.
 * Purpose:  Module control.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016, Weiwei Huang
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
    case HubMCls:
    {
        CClsCtl *clsCtl = new CClsCtl;
        clsCtl->Init();
        mMCodeH.Add((UHandleT) clsCtl, aCode);
        return UErrFalse;
    }
    case HubMSys:
    {
        CSysCtl *sysCtl = new CSysCtl;
        sysCtl->Init();
        mMCodeH.Add((UHandleT) sysCtl, aCode);
        return UErrFalse;
    }
    case HubMOgr:
    {
        COgrCtl *ogrCtl = new COgrCtl;
        ogrCtl->Init();
        mMCodeH.Add((UHandleT) ogrCtl, aCode);
        return UErrFalse;
    }
    case HubMGda:
    {
        CGdaCtl *gdaCtl = new CGdaCtl;
        gdaCtl->Init();
        mMCodeH.Add((UHandleT) gdaCtl, aCode);
        return UErrFalse;
    }
    case HubMGsl:
    {
        CGslCtl *gslCtl = new CGslCtl;
        gslCtl->Init();
        mMCodeH.Add((UHandleT) gslCtl, aCode);
        return UErrFalse;
    }
    case HubMCut:
    {
        CCutCtl *cutCtl = new CCutCtl;
        cutCtl->Init();
        mMCodeH.Add((UHandleT) cutCtl, aCode);
    }
    case HubMVtr:
    {
        CVtrCtl *vtrCtl = new CVtrCtl;
        vtrCtl->Init();
        mMCodeH.Add((UHandleT) vtrCtl, aCode);
        return UErrFalse;
    }
    case HubMRtk:
    {
        CRtkCtl *rtkCtl = new CRtkCtl;
        rtkCtl->Init();
        mMCodeH.Add((UHandleT) rtkCtl, aCode);
        return UErrFalse;
    }
    default:
        return UErrTrue;
    }
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
    case HubMCls:
        delete (CClsCtl*) mMCodeH[aCode];
        break;
    case HubMSys:
        delete (CSysCtl*) mMCodeH[aCode];
        break;
    case HubMOgr:
        delete (COgrCtl*) mMCodeH[aCode];
        break;
    case HubMGda:
        delete (CGdaCtl*) mMCodeH[aCode];
        break;
    case HubMGsl:
        delete (CGslCtl*) mMCodeH[aCode];
        break;
    case HubMVtr:
        delete (CVtrCtl*) mMCodeH[aCode];
        break;
    case HubMRtk:
        delete (CRtkCtl*) mMCodeH[aCode];
        break;
    default:
        break;
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

/***** Private B *****/
