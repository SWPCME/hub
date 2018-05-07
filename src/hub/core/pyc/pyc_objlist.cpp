/******************************************************************************
 * $Id: pyc_objlist.cpp 2018-03 $
 *
 * Project:  PYC(PYC: Python c library).
 * Purpose:  Pyc object list implementation.
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

#include "pyc_objlist.hpp"

// PYTHON
#include "Python.h"
#include "listobject.h"

/**
 * \brief Constructor.
 */
CPycObjList::CPycObjList(CPycObjLists *aLists)
{
    mLists = aLists;
}

/**
 * \brief Destructor.
 */
CPycObjList::~CPycObjList()
{
}

/**
 * \brief Initilize.
 */
UErrCodeT CPycObjList::Init()
{
    return UErrFalse;
}

/**
 * \brief Get size.
 */
UIntT CPycObjList::Size()
{
    Py_ssize_t size = PyList_Size((PyObject *) mListH);
    UIntT rSize = size;

    return rSize;
}

/**
 * \brief Get item.
 */
PycObjListItemHT CPycObjList::Item()
{
    // PycObjListItemHT item = (PycObjListItemHT) PyList_GetItem((PyObject *) mListH);
    PycObjListItemHT item = NULL;

    return item;
}

// /**
//  * \brief Set item.
//  */
// UErrCodeT CPycObjList::SetItem()
// {
//     return UErrFalse;
// }

// /**
//  * \brief Insert item.
//  */
// UErrCodeT CPycObjList::InsertItem()
// {
//     return UErrFalse;
// }

// /**
//  * \brief Append item.
//  */
// UErrCodeT CPycObjList::AppendItem()
// {
//     return UErrFalse;
// }
