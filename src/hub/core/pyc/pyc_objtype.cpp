/******************************************************************************
 * $Id: pyc_objtype.cpp 2018-04 $
 *
 * Project:  PYC(PYC: Python c library).
 * Purpose:  Pyc object type implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2018-04 ~ 2018, Weiwei Huang
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

#include "pyc_objtype.hpp"

// base
#include "base_ctl.hpp"
#include "base_macrodefn.hpp"
// core
#include "core_ctl.hpp"
// pyc
#include "pyc_ctl.hpp"
#include "pyc_type.hpp"
#include "pyc_typeobj.hpp"

/**
 * \brief Constructor.
 */
PycObjT::PycObjT()
{
    Init();
    PycObjHT objH = NULL;
    SetHandle(objH);
}

/**
 * \brief Constructor.
 */
PycObjT::PycObjT(PycObjHT aObjH)
{
    Init();
    SetHandle(aObjH);
}

/**
 * \brief Destructor.
 */
PycObjT::~PycObjT()
{
}

/**
 * \brief Handle.
 */
PycObjHT PycObjT::Handle()
{
    return mObjH;
}

/**
 * \brief Set handle.
 */
UErrCodeT PycObjT::SetHandle(const PycObjHT aObjH)
{
    mObjH = aObjH;

    return UErrFalse;
}

// /**
//  * \brief Set value.
//  */
// UErrCodeT PycObjT::SetVal(const UStringT *aFrmt, const BCtnStringT *aVals)
// {
//     PycObjT obj;
//     UIntT size = aVals->Size();
//     BItStringT *it = aVals->Iterator();
// // #define PYC_OBJ_SET_VAL(func, frmt, ) #func->Build(&#frmt, )
//     // mVal->Build(&obj, aFrmt);

//     return UErrFalse;
// }

/**
 * \brief To list.
 */
UErrCodeT PycObjT::ToList(PycObjListT *aList)
{
    return mObj->ToList(aList, Handle());
}

/**
 * \brief Get value as string.
 */
UErrCodeT PycObjT::ValAsStr(UStringT *aVal)
{
    return mObj->ValAsStr(aVal, Handle());
}

/***** Private A *****/

/**
 * \brief Initilize.
 */
UErrCodeT PycObjT::Init()
{
    CPycCtl *pyc = NULL;
    PYC_CTL(pyc);
    CPycType *type = pyc->Type();
    mObj = type->Obj();

    return UErrFalse;
}

/***** Private B *****/
