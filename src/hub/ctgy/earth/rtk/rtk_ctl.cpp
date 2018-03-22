/******************************************************************************
 * $Id: rtk_ctl.cpp 2017-05 $
 *
 * Project:  Rtk (Real time kinematic).
 * Purpose:  Rtk ctl.
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

#include "rtk_ctl.hpp"

// Module.
#include "rtk_typectl.hpp"
#include "rtk_convertctl.hpp"
#include "rtk_tidectl.hpp"

/**
 * \brief Constructor.
 */
CRtkCtl::CRtkCtl()
{
    mType = NULL;
    mConvert = NULL;
    mTide = NULL;
}

/**
 * \brief Destructor.
 */
CRtkCtl::~CRtkCtl()
{
    if (mType != NULL)
    {
        delete mType;
    }

    if (mConvert != NULL)
    {
        delete mConvert;
    }

    if (mTide != NULL)
    {
        delete mTide;
    }
}

/**
 * \brief Initial.
 */
UErrCodeT CRtkCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Translate.
 */
CRtkConvertCtl *CRtkCtl::Convert()
{
    if (mConvert == NULL)
    {
        mConvert = new CRtkConvertCtl;
        mConvert->Init();
    }

    return mConvert;
}

/**
 * \brief Tide.
 */
CRtkTideCtl *CRtkCtl::Tide()
{
    if (mTide == NULL)
    {
        mTide = new CRtkTideCtl;
        mTide->Init();
    }

    return mTide;
}

/**
 * \brief Type.
 */
CRtkTypeCtl *CRtkCtl::Type()
{
    if (mType == NULL)
    {
        mType = new CRtkTypeCtl;
        mType->Init();
    }

    return mType;
}
