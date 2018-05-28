/******************************************************************************
 * $Id: hub_modulectl.cpp 2017-09 $
 *
 * Project:  Hub library.
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

#include "hub_modulectl.hpp"

/**
 * \brief Base module.
 */
#include "base_ctl.hpp"
#include "base_tmpctl.hpp"

/**
 * \brief Core module.
 */
#ifdef NAME
#include "core_ctl.hpp"
#include "cls_ctl.hpp"
#include "ccs_ctl.hpp"
#include "sys_ctl.hpp"
#include "ogr_ctl.hpp"
#include "gda_ctl.hpp"
#endif  // NAME

#ifdef HUB_MODULE_PLP
#include "gsl_ctl.hpp"
#include "cut_ctl.hpp"
#include "plp_ctl.hpp"
#endif // HUB_MODULE_PLP

#ifdef HUB_MODULE_PYC
#include "pyc_ctl.hpp"
#endif  // HUB_MODULE_PYC

/**
 * \brief Wrap module.
 */
#include "wrap_ctl.hpp"
#include "ust_ctl.hpp"
#include "rst_ctl.hpp"
#include "vtr_ctl.hpp"
#ifdef HUB_MODULE_NCC
#include "ncc_ctl.hpp"
#endif  // HUB_MODULE_NCC

/**
 * \brief Ctgy module.
 */
#include "ctgy_ctl.hpp"
// #include "rtk_ctl.hpp"
#ifdef HUB_MODULE_FMD
#include "fmd_ctl.hpp"
#endif // HUB_MODULE_FMD
#ifdef HUB_MODULE_QMT
#include "qmt_ctl.hpp"
#endif  // HUB_MODULE_QMT
#ifdef HUB_MODULE_ERA
#include "era_ctl.hpp"
#endif  // HUB_MODULE_ERA

#define HUB_REGISTER(aCode, aClass)             \
    BMD_REGISTER(aCode, aClass, this, mMCodeH)

#define HUB_DEREGISTER(aCode, aClass)           \
    BMD_DEREGISTER(aCode, aClass, mMCodeH)

/**
 * \brief Constructor.
 */
CHubModuleCtl::CHubModuleCtl() : mMCodeH(UContainerMap)
{
    mBase = CBaseCtl::Base();

    mState = UStateOff;
}

/**
 * \brief Destructor.
 */
CHubModuleCtl::~CHubModuleCtl()
{
    DeregisterAll();
    mTmp->RmRootDir(this);
}

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CHubModuleCtl::Init(UFlagCodeT aFlag /* = UFlagOff */)
{
    mBase->Init();
    mTmp = mBase->Tmp();

    return UErrFalse;
}

/**
 * \brief Set temporary directory.
 */
UErrCodeT CHubModuleCtl::SetTmpDir(const UStringT *aDir)
{
    return mTmp->SetRootDir(aDir, this);
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
#ifdef HUB_MODULE_PLP
        HUB_REGISTER(HubMGsl, CGslCtl);
        HUB_REGISTER(HubMCut, CCutCtl);
        HUB_REGISTER(HubMPlp, CPlpCtl);
#endif  // HUB_MODULE_PLP
#ifdef HUB_MODULE_PYC
        HUB_REGISTER(HubMPyc, CPycCtl);
#endif  // HUB_MODULE_PYC

        // wrap
        HUB_REGISTER(HubMUst, CUstCtl);
        HUB_REGISTER(HubMRst, CRstCtl);
        HUB_REGISTER(HubMVtr, CVtrCtl);
        // ctgy
        // HUB_REGISTER(HubMRtk, CRtkCtl);
#ifdef HUB_MODULE_FMD
        HUB_REGISTER(HubMFmd, CFmdCtl);
#endif  // HUB_MODULE_FMD
#ifdef HUB_MODULE_QMT
        HUB_REGISTER(HubMQmt, CQmtCtl);
#endif  // HUB_MODULE_QMT

#ifdef HUB_MODULE_ERA
        HUB_REGISTER(HubMEra, CEraCtl);
#endif  // HUB_MODULE_ERA

    default:
        return UErrTrue;
    }
    mTmp->MkDir(aCode, this);

    return UErrFalse;
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
#ifdef HUB_MODULE_PLP
        HUB_DEREGISTER(HubMGsl, CGslCtl);
        HUB_DEREGISTER(HubMCut, CCutCtl);
        HUB_DEREGISTER(HubMPlp, CPlpCtl);
#endif  // HUB_MODULE_PLP
#ifdef HUB_MODULE_PYC
        HUB_DEREGISTER(HubMPyc, CPycCtl);
#endif  // HUB_MODULE_PYC
        // wrap
        HUB_DEREGISTER(HubMUst, CUstCtl);
        HUB_DEREGISTER(HubMRst, CRstCtl);
        HUB_DEREGISTER(HubMVtr, CVtrCtl);
        // ctgy
        // HUB_DEREGISTER(HubMRtk, CRtkCtl);
#ifdef HUB_MODULE_FMD
        HUB_DEREGISTER(HubMFmd, CFmdCtl);
#endif  // HUB_MODULE_FMD
#ifdef HUB_MODULE_QMT
        HUB_DEREGISTER(HubMQmt, CQmtCtl);
#endif  // HUB_MODULE_QMT

#ifdef HUB_MODULE_ERA
        HUB_DEREGISTER(HubMEra, CEraCtl);
#endif  // HUB_MODULE_ERA
    default:
        return UErrTrue;
    }
    mTmp->RmDir(aCode, this);
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

/**
 * \brief Gda handle.
 *
 * @return Handle of gda, if successful; NULL, if failed.
 */
CGdaCtl *CHubModuleCtl::Gda()
{
    return (CGdaCtl *) Module(HubMGda);
}

/**
 * \brief Ogr handle.
 *
 * @return Handle of ogr, if successful; NULL, if failed.
 */
COgrCtl *CHubModuleCtl::Ogr()
{
    return (COgrCtl *) Module(HubMOgr);
}

/**
 * \brief Rst handle.
 *
 * @return Handle of rst, if successful; NULL, if failed.
 */
CRstCtl *CHubModuleCtl::Rst()
{
    return (CRstCtl *) Module(HubMRst);
}

/**
 * \brief Fmd handle.
 *
 * @return Handle of fmd, if successful; NULL, if failed.
 */
CFmdCtl *CHubModuleCtl::Fmd()
{
    return (CFmdCtl *) Module(HubMFmd);
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
