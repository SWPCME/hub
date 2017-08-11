/******************************************************************************
 * $Id: cut_easysctl.hpp 2017-06 $
 *
 * Project:  CUT (CUT: Client-side URL Transfer).
 * Purpose:  Easy set controler implementation.
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

#include "cut_easysctl.hpp"

// Cut.
#include "cut_easyctl.hpp"

/**
 * \brief Constructor.
 */
CCutEasysCtl::CCutEasysCtl() : mMEasyH(UContainerMap)
{
}

/**
 * \brief Destructor.
 */
CCutEasysCtl::~CCutEasysCtl()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CCutEasysCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Open.
 */
CCutEasyCtl *CCutEasysCtl::Open(UStringT *aName)
{
    CCutEasyCtl *easyCtl = NULL;
    EasyHItT *it = mMEasyH.Iterator();
    
    if (it->Goto(aName->ToA()) == UErrFalse)
    {
        easyCtl = it->Content();
    }
    else
    {
        easyCtl = new CCutEasyCtl(aName);
        easyCtl->Init();
        mMEasyH.Add(easyCtl, aName->ToA());
    }

    return easyCtl;
}

/**
 * \brief Close.
 */
UErrCodeT CCutEasysCtl::Close(UStringT *aName)
{
    EasyHItT *it = mMEasyH.Iterator();

    if (it->Goto(aName->ToA()) == UErrTrue)
    {
        return UErrTrue;
    }

    CCutEasyCtl *easyCtl = it->Content();

    delete easyCtl;

    return UErrFalse;
}

/**
 * \brief CleanupAll.
 */
UErrCodeT CCutEasysCtl::CleanupAll()
{
    EasyHItT *it = mMEasyH.Iterator();
    for (it->Head(); it->State() == UErrFalse; it->Next())
    {
        delete it->Content();
    }

    mMEasyH.Clear();

    return UErrFalse;
}
