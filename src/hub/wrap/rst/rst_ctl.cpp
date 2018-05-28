/******************************************************************************
 * $Id: rst_ctl.hpp 2017-08 $
 *
 * Project:  RST (RST: Raster data process).
 * Purpose:  RST controler implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-08 ~ 2017, Weiwei Huang
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

#include "rst_ctl.hpp"

// hub
#include "hub_modulectl.hpp"
// base
#include "base_ctl.hpp"
#include "base_tmpctl.hpp"
#include "base_macrodefn.hpp"
// rst
#include "rst_utilctl.hpp"
#include "rst_frmtctl.hpp"

/**
 * \brief Constructor.
 */
CRstCtl::CRstCtl(CHubModuleCtl *aModule)
{
    InitPointer();
    mModule = aModule;
}

/**
 * \brief Destructor.
 */
CRstCtl::~CRstCtl()
{
    BMD_CLASS_DEL(mUtil);
    BMD_CLASS_DEL(mFrmt);
    InitPointer();
}

/**
 * \brief Init.
 */
UErrCodeT CRstCtl::Init()
{
    CBaseCtl *base = CBaseCtl::Base();
    CBaseTmpCtl *tmp = base->Tmp();
    tmp->MkDir(HubMRst, mModule);

    return UErrFalse;
}

/**
 * \brief Up.
 */
CHubModuleCtl *CRstCtl::Up()
{
    return mModule;
}

/**
 * \brief Util controler.
 */
CRstUtilCtl *CRstCtl::Util()
{
    BMD_CLASS_NEW(mUtil, CRstUtilCtl);

    return mUtil;
}

/**
 * \brief Format controler.
 */
CRstFrmtCtl *CRstCtl::Frmt()
{
    BMD_CLASS_NEW_A_1(mFrmt, CRstFrmtCtl, this);

    return mFrmt;
}

/***** Private A *****/

/**
 * \brief Initialize pointer.
 */
UErrCodeT CRstCtl::InitPointer()
{
    BMD_POINTER_INIT(mModule);
    BMD_POINTER_INIT(mUtil);
    BMD_POINTER_INIT(mFrmt);

    return UErrFalse;
}

/***** Private B *****/
