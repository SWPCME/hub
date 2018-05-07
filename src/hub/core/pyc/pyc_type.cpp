/******************************************************************************
 * $Id: pyc_type.cpp 2018-04 $
 *
 * Project:  PYC(PYC: Python c library).
 * Purpose:  Pyc type implementation.
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

#include "pyc_type.hpp"

// base
#include "base_macrodefn.hpp"
// pyc
#include "pyc_typeobj.hpp"

/**
 * \brief Constructor.
 */
CPycType::CPycType()
{
}

/**
 * \brief Destructor.
 */
CPycType::~CPycType()
{
}

/**
 * \brief Initilize.
 */
UErrCodeT CPycType::Init()
{
    return UErrFalse;
}

/**
 * \brief Object.
 */
CPycTypeObj *CPycType::Obj()
{
    BMD_CLASS_NEW(mObj, CPycTypeObj);

    return mObj;
}
