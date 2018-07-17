/******************************************************************************
 * $Id: pyc_typeobjlist.hpp 2018-04 $
 *
 * Project:  PYC(PYC: Python c library).
 * Purpose:  Pyc type object list implementation.
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

#include "pyc_typeobjlist.hpp"

// base
#include "base_ctl.hpp"
#include "base_macrodefn.hpp"
// core
#include "core_ctl.hpp"
// pyc
#include "pyc_ctl.hpp"
#include "pyc_obj.hpp"
#include "pyc_objtype.hpp"
#include "pyc_objlists.hpp"
#include "pyc_objlist.hpp"

// PYTHON
#include "Python.h"

/**
 * \brief Constructor.
 */
CPycTypeObjList::CPycTypeObjList()
{
    InitPointer();
}

/**
 * \brief Destructor.
 */
CPycTypeObjList::~CPycTypeObjList()
{
    mLists->Del(mList);
    InitPointer();
}

/**
 * \brief Initilize.
 */
UErrCodeT CPycTypeObjList::Init()
{
    if (mLists == NULL)
    {
        CPycCtl *pyc;
        BMD_POINTER_INIT(pyc);
        PYC_CTL(pyc);
        CPycObj *obj = pyc->Obj();
        mLists = obj->Lists();
    }

    if (mList == NULL)
    {
        mList = mLists->New();
    }

    return UErrFalse;
}

/**
 * \brief Get item.
 */
UErrCodeT CPycTypeObjList::Item(UStringT *aVal, UIntT aId)
{
    return mList->Item(aVal, aId);
}

/**
 * \brief Set item.
 */
UErrCodeT CPycTypeObjList::Add(UStringT *aVal)
{
    return mList->AppendItem(aVal);
}

/***** Private A *****/

/**
 * \brief Initilize pointer.
 */
UErrCodeT CPycTypeObjList::InitPointer()
{
    BMD_POINTER_INIT(mLists);
    BMD_POINTER_INIT(mList);

    return UErrFalse;
}

/***** Private B *****/
