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

#include "pyc_objlisttype.hpp"

// pyc
#include "pyc_typeobjlist.hpp"
#include "pyc_objtype.hpp"

/**
 * \brief Constructor.
 */
PycObjListT::PycObjListT(PycObjT *aObj)
{
    aObj->ToList(this);
}

/**
 * \brief Destructor.
 */
PycObjListT::~PycObjListT()
{
}

/**
 * \brief Initilize.
 */
UErrCodeT PycObjListT::Init()
{
    return UErrFalse;
}

/**
 * \brief Handle.
 */
PycObjListHT PycObjListT::Handle()
{
    return mListH;
}

/**
 * \brief Set handle.
 */
UErrCodeT PycObjListT::SetHandle(PycObjListHT aListH)
{
    mListH = aListH;

    return UErrFalse;
}

/**
 * \brief Get item.
 */
UErrCodeT PycObjListT::Item(UStringT *aVal, UIntT aId)
{
    return mList->Item(aVal, aId, mListH);
}

// /**
//  * \brief Add item.
//  */
// UErrCodeT PycObjListT::Add()
// {
//     return UErrFalse;
// }

/***** Private A *****/
/***** Private B *****/
