/******************************************************************************
 * $Id: pyc_modval.cpp 2018-04 $
 *
 * Project:  PYC(PYC: Python c library).
 * Purpose:  Pyc module implementation.
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

#include "pyc_modval.hpp"

// cls
#include "cls_argctl.hpp"
// pyc
#include "pyc_objtype.hpp"

// PYTHON
#include "Python.h"
#include "modsupport.h"

/**
 * \brief Constructor.
 */
CPycModVal::CPycModVal()
{
}

/**
 * \brief Destructor.
 */
CPycModVal::~CPycModVal()
{
}

/**
 * \brief Initilize.
 */
UErrCodeT CPycModVal::Init()
{
    return UErrFalse;
}

/**
 * \brief Build.
 */
UErrCodeT CPycModVal::Build(PycObjT *aObj, UStringT *aFrmt, ...)
{
    const char *frmt = aFrmt->ToA();
    ClsArgListT list;
    cls_arg_start(list, frmt);
    PycObjHT objH = (PycObjHT) Py_VaBuildValue(frmt, list);
    aObj->SetHandle(objH);
    cls_arg_end(list);

    return UErrFalse;
}
