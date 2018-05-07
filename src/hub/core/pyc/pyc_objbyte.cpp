/******************************************************************************
 * $Id: pyc_objbyte.cpp 2018-04 $
 *
 * Project:  PYC(PYC: Python c library).
 * Purpose:  Pyc object byte implementation.
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

#include "pyc_objbyte.hpp"

// base
#include "base_ctl.hpp"
#include "base_macrodefn.hpp"
// core
#include "core_ctl.hpp"
// pyc
#include "pyc_ctl.hpp"
#include "pyc_obj.hpp"
#include "pyc_objcore.hpp"

// PYTHON
#include "Python.h"
#include "modsupport.h"

/**
 * \brief Constructor.
 */
CPycObjByte::CPycObjByte()
{
}

/**
 * \brief Destructor.
 */
CPycObjByte::~CPycObjByte()
{
}

/**
 * \brief Initilize.
 */
UErrCodeT CPycObjByte::Init()
{
    CPycCtl *pyc = NULL;
    PYC_CTL(pyc);
    CPycObj *obj = pyc->Obj();
    mCore = obj->Core();

    return UErrFalse;
}

/**
 * \brief Handle.
 */
PycObjByteHT CPycObjByte::Handle()
{
    return mByteH;
}

/**
 * \brief Set handle.
 */
UErrCodeT CPycObjByte::SetHandle(PycObjByteHT aByteH)
{
    mByteH = aByteH;

    return UErrFalse;
}

/**
 * \brief As string.
 */
UErrCodeT CPycObjByte::Str(UStringT *aVal)
{
    PycObjHT objReprH = NULL;
    mCore->Repr(objReprH, (PycObjHT) mByteH);
    *aVal = PyBytes_AsString((PyObject *) objReprH);

    return UErrFalse;
}
