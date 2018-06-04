/******************************************************************************
 * $Id: pyc_obj.cpp 2018-03 $
 *
 * Project:  PYC(PYC: Python c library).
 * Purpose:  Pyc object implementation.
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

#include "pyc_obj.hpp"

// base
#include "base_macrodefn.hpp"
// pyc
#include "pyc_objcore.hpp"
#include "pyc_objimpl.hpp"
#include "pyc_objint.hpp"
#include "pyc_objfloat.hpp"
#include "pyc_objbyte.hpp"
#include "pyc_objlists.hpp"

/**
 * \brief Constructor.
 */
CPycObj::CPycObj()
{
    InitPointer();
}

/**
 * \brief Destructor.
 */
CPycObj::~CPycObj()
{
    BMD_CLASS_DEL(mCore);
    BMD_CLASS_DEL(mImpl);
    BMD_CLASS_DEL(mInt);
    BMD_CLASS_DEL(mFloat);
    BMD_CLASS_DEL(mLists);
}

/**
 * \brief Initilize.
 */
UErrCodeT CPycObj::Init()
{
    return UErrFalse;
}

/**
 * \brief Core.
 */
CPycObjCore *CPycObj::Core()
{
    BMD_CLASS_NEW(mCore, CPycObjCore);

    return mCore;
}

/**
 * \brief Implementation.
 */
CPycObjImpl *CPycObj::Impl()
{
    BMD_CLASS_NEW(mImpl, CPycObjImpl);

    return mImpl;
}

/**
 * \brief Byte.
 */
CPycObjByte *CPycObj::Byte()
{
    BMD_CLASS_NEW(mByte, CPycObjByte);

    return mByte;
}

/**
 * \brief Integer (whole number).
 */
CPycObjInt *CPycObj::Int()
{
    BMD_CLASS_NEW(mInt, CPycObjInt);

    return mInt;
}

/**
 * \brief Float point number (rational number).
 */
CPycObjFloat *CPycObj::Float()
{
    BMD_CLASS_NEW(mFloat, CPycObjFloat);

    return mFloat;
}

/**
 * \brief List set.
 */
CPycObjLists *CPycObj::Lists()
{
    BMD_CLASS_NEW(mLists, CPycObjLists);

    return mLists;
}

/***** Private A *****/

/**
 * \brief Init pointer.
 */
UErrCodeT CPycObj::InitPointer()
{
    BMD_POINTER_INIT(mCore);
    BMD_POINTER_INIT(mImpl);
    BMD_POINTER_INIT(mInt);
    BMD_POINTER_INIT(mFloat);
    BMD_POINTER_INIT(mLists);

    return UErrFalse;
}

/***** Private B *****/
