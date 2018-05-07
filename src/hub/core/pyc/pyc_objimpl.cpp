/******************************************************************************
 * $Id: pyc_objimpl.hpp 2018-04 $
 *
 * Project:  PYC(PYC: Python c library).
 * Purpose:  Pyc object implementation implementation.
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

#include "pyc_objimpl.hpp"

// PYTHON
#include "Python.h"
#include "objimpl.h"

/**
 * \brief Constructor.
 */
CPycObjImpl::CPycObjImpl()
{
}

/**
 * \brief Destructor.
 */
CPycObjImpl::~CPycObjImpl()
{
}

/**
 * \brief Initilize.
 */
UErrCodeT CPycObjImpl::Init()
{
    return UErrFalse;
}

/**
 * \brief New.
 * It allocates memory for a new object of the given
 * type, and initializes part of it.
 */
PycObjHT CPycObjImpl::New(PycObjTypeHT aType)
{
    PyTypeObject *type = (PyTypeObject *) aType;
    PyObject *obj = _PyObject_New(aType);

    return obj;
}

/**
 * \brief Delete, garbage collection.
 * It releases the memory allocated for an object. 
 * It does not run a destructor, it only frees the memory.
 */
UErrCodeT CPycObjImpl::Del(UHandleT aObj)
{
    PyObject_Free((void *) aObj);

    return UErrFalse;
}
