/******************************************************************************
 * $Id: base_ctl.hpp 2017-05 $
 *
 * Project:  Base.
 * Purpose:  Base control implemetation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016 ~ 2017 Weiwei Huang
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
 *****************************************************************************/

#include "base_ctl.hpp"

// Module.
#include "core_ctl.hpp"
#include "wrap_ctl.hpp"
#include "ctgy_ctl.hpp"

/**
 * \brief Static handle of base.
 */
CBaseCtl *CBaseCtl::mBase = NULL;

CBaseCtl *CBaseCtl::Base()
{
    if (mBase == NULL)
    {
        mBase = new CBaseCtl;
    }

    return mBase;
}

/**
 * \brief Initial.
 */
UErrCodeT CBaseCtl::Init()
{
    mCore->Init();
    mWrap->Init();
    mCtgy->Init();

    return UErrFalse;
}

/**
 * \brief Core controler.
 */
CCoreCtl *CBaseCtl::Core()
{
    return mCore;
}

/**
 * \brief Wrap controler.
 */
CWrapCtl *CBaseCtl::Wrap()
{
    return mWrap;
}

/**
 * \brief Ctgy controler.
 */
CCtgyCtl *CBaseCtl::Ctgy()
{
    return mCtgy;
}

/***** Private A ******/

/**
 * \brief Constructor.
 */
CBaseCtl::CBaseCtl()
{
    mCore = new CCoreCtl;
    mWrap = new CWrapCtl;
    mCtgy = new CCtgyCtl;
}

/**
 * \brief Destructor.
 */
CBaseCtl::~CBaseCtl()
{
    delete mCtgy;
    delete mWrap;
    delete mCore;
}

/***** Private B ******/
