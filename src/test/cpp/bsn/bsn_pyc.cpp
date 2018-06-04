/******************************************************************************
 * $Id: bsn_pyc.cpp 2018-03 $
 *
 * Project:  Business Logic library.
 * Purpose:  Test pyc api implementation.
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
 *****************************************************************************/

#include "bsn_pyc.hpp"

// hub
#include "hub_ctl.hpp"
#include "hub_modulectl.hpp"
// ust
#include "ust_stringtype.hpp"

// pyc
#include "pyc_ctl.hpp"
#include "pyc_objtype.hpp"
#include "pyc_mod.hpp"
#include "pyc_modval.hpp"
#include "pyc_obj.hpp"
#include "pyc_objlist.hpp"

/**
 * \brief Constructor.
 */
CBsnPyc::CBsnPyc()
{
    InitPointer();
}

/**
 * \brief Destructor.
 */
CBsnPyc::~CBsnPyc()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CBsnPyc::Init()
{
    if (mHub == NULL)
    {
        mHub = CHubCtl::Hub();
        mModule = mHub->RegModule();
        UStringT tmp = "~/tmp";
        mModule->SetTmpDir(&tmp);
        mModule->Register(HubMPyc);
        mPyc = (CPycCtl *) mModule->Module(HubMPyc);
    }

    return UErrFalse;
}

/**
 * \brief Test.
 */
UErrCodeT CBsnPyc::Test()
{
    Mod();

    return UErrFalse;
}

/***** Private A *****/

/**
 * \brief Initialize pointer.
 */
UErrCodeT CBsnPyc::InitPointer()
{
    BMD_POINTER_INIT(mHub);
    BMD_POINTER_INIT(mModule);
    BMD_POINTER_INIT(mPyc);

    return UErrFalse;
}

/**
 * \brief Module.
 */
UErrCodeT CBsnPyc::Mod()
{
    CPycMod *mod = mPyc->Mod();
    CPycModVal *val = mod->Val();
    // UStringT frmt = "[i, i]";
    UStringT frmt = "i";
    PycObjT obj;
    // val->Build(&obj, &frmt, 1, 2);
    val->Build(&obj, &frmt, 1);
    UStringT valStr;
    obj.ValAsStr(&valStr);
    valStr.ToConsole();

    return UErrFalse;
}

/**
 * \brief Object.
 */
UErrCodeT CBsnPyc::Obj()
{
    return UErrFalse;
}

/**
 * \brief Object list.
 */
UErrCodeT CBsnPyc::ObjList()
{
    return UErrFalse;
}

/***** Private B *****/
