/******************************************************************************
 * $Id: base_typectl.cpp 2017-05 $
 *
 * Project:  Category.
 * Purpose:  Category control implemetation.
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

#include "ctgy_ctl.hpp"

// Module.
// #include "earth_ctl.hpp"
#include "fmd_ctl.hpp"

/**
 * \brief Constructor.
 */
CCtgyCtl::CCtgyCtl()
{
    mEarth = NULL;
    mFmd = NULL;
}

/**
 * \brief Destructor.
 */
CCtgyCtl::~CCtgyCtl()
{
    if (mEarth != NULL)
    {
        delete mEarth;
    }

    if (mFmd != NULL)
    {
        delete mFmd;
    }
}

/**
 * \brief Initial.
 */
UErrCodeT CCtgyCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Earth.
 */
CEarthCtl *CCtgyCtl::Earth()
{
    // if (mEarth == NULL)
    // {
    //     mEarth = new CEarthCtl;
    //     mEarth->Init();
    // }

    return mEarth;
}

/**
 * \brief Fmd Controler.
 */
CFmdCtl *CCtgyCtl::Fmd()
{
    if (mFmd == NULL)
    {
        mFmd = new CFmdCtl;
        mFmd->Init();
    }

    return mFmd;
}
