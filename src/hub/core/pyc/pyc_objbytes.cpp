/******************************************************************************
 * $Id: pyc_objbytes.cpp 2018-06 $
 *
 * Project:  PYC(PYC: Python c library).
 * Purpose:  Pyc object bytes implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2018-06 ~ 2018, Weiwei Huang
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

#include "pyc_objbytes.hpp"

// ust
#include "ust/ust_stringtype.hpp"

// PYTHON
#include <Python.h>

/**
 * \brief Constructor.
 */
CPycObjBytes::CPycObjBytes()
{
}

/**
 * \brief Destructor.
 */
CPycObjBytes::~CPycObjBytes()
{
}

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CPycObjBytes::Init()
{
    return UErrFalse;
}

/**
 * \brief Set string.
 */
UErrCodeT CPycObjBytes::SetStr(PycObjBytesHT *aBytesH, const UStringT *aStr)
{
    *aBytesH = (PyObject *) PyBytes_FromString(aStr->ToA());

    return UErrFalse;
}

/**
 * \brief Get string.
 */
UErrCodeT CPycObjBytes::Str(UStringT *aStr, const PycObjBytesHT aBytesH)
{
    *aStr = PyBytes_AsString((PyObject*) aBytesH);

    return UErrFalse;
}

/***** Private A *****/

/**
 * \brief InitPointer.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CPycObjBytes::InitPointer()
{
    return UErrFalse;
}

/***** Private B *****/
