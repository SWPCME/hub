/******************************************************************************
 * $Id: cut_slistsctl.cpp 2017-06 $
 *
 * Project:  CUT (CUT: Client-side URL Transfer).
 * Purpose:  String to linked list set controler implementation.
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

#include "cut_slistsctl.hpp"

// Cut.
#include "cut_slistctl.hpp"

/**
 * \brief Constructor.
 */
CCutSlistsCtl::CCutSlistsCtl() : mMSlistH(UContainerMap)
{
}

/**
 * \brief Destructor.
 */
CCutSlistsCtl::~CCutSlistsCtl()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CCutSlistsCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Open.
 */
CCutSlistCtl *CCutSlistsCtl::Open(UStringT *aName)
{
    CCutSlistCtl *slistCtl = NULL;
    SlistHItT *it = mMSlistH.Iterator();

    if (it->Goto(aName->ToA()) == UErrFalse)
    {
        slistCtl = it->Content();
    }
    else
    {
        slistCtl = new CCutSlistCtl(aName);
        slistCtl->Init();
        mMSlistH.Add(slistCtl, aName->ToA());
    }

    return slistCtl;
}

/**
 * \brief Close.
 */
UErrCodeT CCutSlistsCtl::Close(UStringT *aName)
{
    SlistHItT *it = mMSlistH.Iterator();

    if (it->Goto(aName->ToA()) == UErrTrue)
    {
        return UErrTrue;
    }

    CCutSlistCtl *slistCtl = it->Content();

    delete slistCtl;

    return UErrFalse;
}

/**
 * \brief Cleanup All.
 */
UErrCodeT CCutSlistsCtl::CleanupAll()
{
    SlistHItT *it = mMSlistH.Iterator();
    for (it->Head(); it->State() == UErrFalse; it->Next())
    {
        delete it->Content();
    }

    mMSlistH.Clear();

    return UErrFalse;
}
