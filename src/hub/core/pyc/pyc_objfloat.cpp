/******************************************************************************
 * $Id: pyc_objfloat 2018-06 $
 *
 * Project:  PYC(PYC: Python c library).
 * Purpose:  Pyc object float implementation.
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

#include "pyc_objfloat.hpp"

// PYTHON
#include <Python.h>

/**
 * \brief Constructor.
 */
CPycObjFloat::CPycObjFloat()
{
}

/**
 * \brief Destructor.
 */
CPycObjFloat::~CPycObjFloat()
{
}

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CPycObjFloat::Init()
{
    return UErrFalse;
}

/**
 * \brief Set number.
 *
 * Create a new float object from a UFloatT number.
 *
 * @param aDst The destination of a float object.
 * @param aSrc The source of a UFloatT number.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CPycObjFloat::SetNum(PycObjFloatHT *aDst, const UFloatT aSrc)
{
    *aDst = (PycObjFloatHT) PyFloat_FromDouble((double) aSrc);

    return UErrFalse;
}

/**
 * \brief Get number.
 *
 * Get a UFloatT number from a float object.
 *
 * @param aDst The destination of a UFloatT number.
 * @param aSrc The source of a float object.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CPycObjFloat::Num(UFloatT *aDst, const PycObjFloatHT *aSrc)
{
    *aDst = PyFloat_AsDouble((PyObject *) aSrc);

    return UErrFalse;
}

/***** Private A *****/

/**
 * \brief InitPointer.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CPycObjFloat::InitPointer()
{
    return UErrFalse;
}

/***** Private B *****/
