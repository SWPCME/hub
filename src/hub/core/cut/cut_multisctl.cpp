/******************************************************************************
 * $Id: cut_multisctl.cpp 2017-06 $
 *
 * Project:  CUT (CUT: Client-side URL Transfer).
 * Purpose:  Multi set controler implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016 ~ 2017, Weiwei Huang
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

#include "cut_multisctl.hpp"

// Cut.
#include "cut_multictl.hpp"

/**
 * \brief Constructor.
 */
CCutMultisCtl::CCutMultisCtl() : mMMultiH(UContainerMap)
{
}

/**
 * \brief Destructor.
 */
CCutMultisCtl::~CCutMultisCtl()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CCutMultisCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Open.
 */
CCutMultiCtl *CCutMultisCtl::Open(UStringT *aName)
{
    CCutMultiCtl *multiCtl = new CCutMultiCtl;
    mMMultiH.Add(multiCtl, aName->ToA());
    
    return multiCtl;
}

/**
 * \brief Close.
 */
UErrCodeT CCutMultisCtl::Close(UStringT *aName)
{
    MMultiItHT *it = mMMultiH.Iterator();

    if (it->Goto(aName->ToA()) == UErrTrue)
    {
        return UErrTrue;
    }

    CCutMultiCtl *multiCtl = it->Content();

    delete multiCtl;

    return UErrFalse;
}

/**
 * \brief Cleanup All.
 */
UErrCodeT CCutMultisCtl::CleanupAll()
{
    MMultiItHT *it = mMMultiH.Iterator();
    for (it->Head(); it->State() == UErrFalse; it->Next())
    {
        delete it->Content();
    }

    mMMultiH.Clear();

    return UErrFalse;
}
