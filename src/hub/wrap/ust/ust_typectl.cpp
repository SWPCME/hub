/******************************************************************************
 * $Id: ust_typectl.hpp 2018-05 $
 *
 * Project:  Common Library.
 * Purpose:  Universal type controler implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2018-05 ~ 2018 Weiwei Huang
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

#include "ust_typectl.hpp"

/**
 * \brief Constructor.
 */
CUstTypeCtl::CUstTypeCtl()
{
}

/**
 * \brief Destructor.
 */
CUstTypeCtl::~CUstTypeCtl()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CUstTypeCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Get size of "UDataTCodeT".
 */
UErrCodeT CUstTypeCtl::Size(UIntT *aSize, const UDataTCodeT aCode)
{
    switch (aCode)
    {
    case UDataTInt16:
        *aSize = 2;
        break;
    case UDataTFloat32:
        *aSize = 4;
        break;
    default:
        *aSize = 0;
        break;
    }

    return UErrFalse;
}
