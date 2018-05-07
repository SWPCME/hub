/******************************************************************************
 * $Id: pyc_typeobj.cpp 2018-04 $
 *
 * Project:  PYC(PYC: Python c library).
 * Purpose:  Pyc type object implementation.
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

#include "pyc_typeobj.hpp"

// pyc
#include "pyc_objlisttype.hpp"

// PYTHON
#include "Python.h"
#include "bytesobject.h"

/**
 * \brief Constructor.
 */
CPycTypeObj::CPycTypeObj()
{
}

/**
 * \brief Destructor.
 */
CPycTypeObj::~CPycTypeObj()
{
}

/**
 * \brief Initilize.
 */
UErrCodeT CPycTypeObj::Init()
{
    return UErrFalse;
}

/**
 * \brief To list.
 */
UErrCodeT CPycTypeObj::ToList(PycObjListT *aList, PycObjHT aObjH)
{
    return aList->SetHandle(aObjH);
}

/**
 * \brief Get value as string.
 */
UErrCodeT CPycTypeObj::ValAsStr(UStringT *aVal, PycObjHT aObjH)
{
    // repr means representation
    PyObject* objRepr = PyObject_Repr((PyObject *)aObjH);
    *aVal = PyBytes_AsString(objRepr);

    return UErrFalse;
}
