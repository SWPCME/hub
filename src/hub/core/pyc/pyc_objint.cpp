/******************************************************************************
 * $Id: pyc_objint 2018-06 $
 *
 * Project:  PYC(PYC: Python c library).
 * Purpose:  Pyc object integer implementation..
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

#include "pyc_objint.hpp"

// PYTHON
#include <Python.h>

/**
 * \brief Constructor.
 */
CPycObjInt::CPycObjInt()
{
}

/**
 * \brief Destructor.
 */
CPycObjInt::~CPycObjInt()
{
}

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CPycObjInt::Init()
{
    return UErrFalse;
}

/**
 * \brief Set number.
 *
 * Create a new integer object from a UIntT.
 *
 * @param aDst The destination of a integer object.
 * @param aSrc The source of a UIntT number.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CPycObjInt::SetNum(PycObjIntHT *aDst, const UIntT aSrc)
{
    *aDst = (PycObjIntHT) PyLong_FromLong((UIntT) aSrc);

    return UErrFalse;
}

/**
 * \brief Get number.
 *
 * Get a number of UIntT from a float object.
 *
 * @param aDst The destination of a UIntT number.
 * @param aSrc The source of a integer object.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CPycObjInt::Num(UIntT *aDst, const PycObjIntHT *aSrc)
{
    *aDst = (UIntT) PyLong_AsLong((PyObject *) aSrc);

    return UErrFalse;
}

/***** Private A *****/

/**
 * \brief InitPointer.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CPycObjInt::InitPointer()
{
    return UErrFalse;
}

/***** Private B *****/
