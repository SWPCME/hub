/******************************************************************************
 * $Id: cut_ctl.hpp 2017-06 $
 *
 * Project:  CUT (CUT: Client-side URL Transfer).
 * Purpose:  Cut controler implementation.
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

#include "cut_ctl.hpp"

// cURL Module.
#include "curl.h"

// Cut.
#include "cut_typectl.hpp"
#include "cut_easysctl.hpp"
#include "cut_multisctl.hpp"
#include "cut_slistsctl.hpp"

/**
 * \brief Constructor.
 */
CCutCtl::CCutCtl()
{
    mEasys = NULL;
    mMultis = NULL;
    mSlists = NULL;
}

/**
 * \brief Destructor.
 */
CCutCtl::~CCutCtl()
{
    if (mEasys != NULL)
    {
        delete mEasys;
    }

    if (mMultis != NULL)
    {
        delete mMultis;
    }

    if (mSlists != NULL)
    {
        delete mSlists;
    }
}

/**
 * \brief Initialize.
 */
UErrCodeT CCutCtl::Init()
{
    GInit();

    return UErrFalse;
}

/**
 * \brief Type Constructor.
 */
CCutTypeCtl *CCutCtl::Type()
{
    if (mType == NULL)
    {
        mType = new CCutTypeCtl;
        mType->Init();
    }

    return mType;
}

/**
 * \brief Easy Set Controler.
 */
CCutEasysCtl *CCutCtl::Easys()
{
    if (mEasys == NULL)
    {
        mEasys = new CCutEasysCtl;
        mEasys->Init();
    }

    return mEasys;
}

/**
 * \brief Multi Set Controler.
 */
CCutMultisCtl *CCutCtl::Multis()
{
    if (mMultis == NULL)
    {
        mMultis = new CCutMultisCtl;
        mMultis->Init();
    }

    return mMultis;
}

/**
 * \brief String to linked list set.
 */
CCutSlistsCtl *CCutCtl::Slists()
{
    if (mSlists == NULL)
    {
        mSlists = new CCutSlistsCtl;
        mSlists->Init();
    }

    return mSlists;
}

/***** Private A *****/

/**
 * \brief Global Initialize.
 */
UErrCodeT CCutCtl::GInit()
{
    curl_global_init(CURL_GLOBAL_ALL);

    return UErrFalse;
}

/**
 * \brief Global Cleanup.
 */
UErrCodeT CCutCtl::GCleanup()
{
    curl_global_cleanup();

    return UErrFalse;
}

/***** Private B *****/
