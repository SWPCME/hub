/******************************************************************************
 * $Id: pyc_objlists.cpp 2018-04 $
 *
 * Project:  PYC(PYC: Python c library).
 * Purpose:  Pyc object list set definition.
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

#include "pyc_objlists.hpp"

// base
#include "base_ctl.hpp"
#include "base_macrodefn.hpp"
// core
#include "core_ctl.hpp"
// pyc
#include "pyc_ctl.hpp"
#include "pyc_obj.hpp"
#include "pyc_objimpl.hpp"
#include "pyc_objlist.hpp"

/**
 * \brief Constructor.
 */
CPycObjLists::CPycObjLists() : mCtnList(UContainerList)
{
}

/**
 * \brief Destructor.
 */
CPycObjLists::~CPycObjLists()
{
}

/**
 * \brief Initilize.
 */
UErrCodeT CPycObjLists::Init()
{
    CPycCtl *pyc = NULL;
    PYC_CTL(pyc);
    CPycObj *obj = pyc->Obj();
    mImpl = obj->Impl();

    return UErrFalse;
}

/**
 * \brief New.
 */
CPycObjList *CPycObjLists::New()
{
    return List();
}

/**
 * \brief Delete.
 */
UErrCodeT CPycObjLists::Del(CPycObjList *aList)
{
    UHandleT list = (UHandleT) aList;
    mImpl->Del(list);

    return UErrFalse;
}

/***** Private A *****/

/**
 * \brief Object list.
 */
CPycObjList *CPycObjLists::List()
{
    CPycObjList *list = NULL;
    BMD_CLASS_NEW_A_1(list, CPycObjList, this);
    if (list != NULL)
    {
        mCtnList.Add(list);
    }

    return list;
}

/***** Private B *****/
