/******************************************************************************
 * $Id: pyc_ctl.cpp 2018-03 $
 *
 * Project:  PYC(PYC: Python c library).
 * Purpose:  Pyc base implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2018-03 ~ 2018, Weiwei Huang
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

#include "pyc_ctl.hpp"

// base
#include "base_macrodefn.hpp"
// pyc
#include "pyc_mod.hpp"
#include "pyc_obj.hpp"
#include "pyc_type.hpp"

/**
 * \brief Constructor.
 */
CPycCtl::CPycCtl(CHubModuleCtl *aModule)
{
    InitPointer();
    mModule = aModule;
}

/**
 * \brief Destructor.
 */
CPycCtl::~CPycCtl()
{
    BMD_CLASS_DEL(mMod);
    BMD_CLASS_DEL(mObj);
    BMD_CLASS_DEL(mType);
}

/**
 * \brief Initilize.
 */
UErrCodeT CPycCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Module.
 */
CPycMod *CPycCtl::Mod()
{
    BMD_CLASS_NEW(mMod, CPycMod);

    return mMod;
}

/**
 * \brief Object.
 */
CPycObj *CPycCtl::Obj()
{
    BMD_CLASS_NEW(mObj, CPycObj);

    return mObj;
}

/**
 * \brief Type.
 */
CPycType *CPycCtl::Type()
{
    BMD_CLASS_NEW(mType, CPycType);

    return mType;
}

/***** Private A *****/

/**
 * \brief Init pointer.
 */
UErrCodeT CPycCtl::InitPointer()
{
    BMD_POINTER_INIT(mMod);
    BMD_POINTER_INIT(mObj);
    BMD_POINTER_INIT(mType);

    return UErrFalse;
}

/***** Private B *****/
