/******************************************************************************
 * $Id: ust_fsctl.hpp 2018-01 $
 *
 * Project:  Universal structure library.
 * Purpose:  Ust controler implemention.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016-08 ~ 2018, Weiwei Huang
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

#include "ust_ctl.hpp"

// hub
#include "hub_modulectl.hpp"
// base
#include "base_macrodefn.hpp"
// ust
#include "ust_typectl.hpp"
#include "ust_stringctl.hpp"
#include "ust_fsctl.hpp"

/**
 * \brief Constructor.
 */
CUstCtl::CUstCtl(CHubModuleCtl *aModule)
{
    BMD_POINTER_INIT(mModule);
    BMD_POINTER_INIT(mType);
    BMD_POINTER_INIT(mStr);
    BMD_POINTER_INIT(mFs);
    mModule = aModule;
}

/**
 * \brief Destructor.
 */
CUstCtl::~CUstCtl()
{
    BMD_CLASS_DEL(mType);
    BMD_CLASS_DEL(mStr);
    BMD_CLASS_DEL(mFs);
    BMD_POINTER_INIT(mModule);
}

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CUstCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Up.
 */
CHubModuleCtl *CUstCtl::Up()
{
    return mModule;
}

/**
 * \brief Get type controler.
 */
CUstTypeCtl *CUstCtl::Type()
{
    return mType;
}

/**
 * \brief Get handle of string control.
 *
 * @return Handle of string control.
 */
CUstStringCtl* CUstCtl::Str()
{
    BMD_CLASS_NEW(mStr, CUstStringCtl);

    return mStr;
}

/**
 * \brief Get handle of file system control.
 *
 * @return Hanle of file system control.
 */
CUstFsCtl* CUstCtl::Fs()
{
    BMD_CLASS_NEW(mFs, CUstFsCtl);

    return mFs;
}

/***** Private A *****/

/***** Private B *****/
