/******************************************************************************
 * $Id: cut_slistctl.cpp 2017-06 $
 *
 * Project:  CUT (CUT: Client-side URL Transfer).
 * Purpose:  String to linked list controler definition.
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

#include "cut_slistctl.hpp"

// Curl Module.
#include "curl.h"

/**
 * \brief Constructor.
 */
CCutSlistCtl::CCutSlistCtl(UStringT *aName)
{
    mHandle = NULL;
    mName = aName->ToA();
}

/**
 * \brief Destructor.
 */
CCutSlistCtl::~CCutSlistCtl()
{
    FreeAll();
}

/**
 * \brief Initialize.
 */
UErrCodeT CCutSlistCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Name.
 */
UStringT CCutSlistCtl::Name()
{
    return mName;
}

/**
 * \brief Append.
 */
UErrCodeT CCutSlistCtl::Append(UStringT *aStr)
{
    curl_slist_append((curl_slist *) mHandle, aStr->ToA());

    return UErrFalse;
}

/**
 * \brief Free all.
 */
UErrCodeT CCutSlistCtl::FreeAll()
{
    curl_slist_free_all((curl_slist *) mHandle);

    return UErrFalse;
}
