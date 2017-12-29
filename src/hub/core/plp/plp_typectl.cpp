/******************************************************************************
 * $Id: plp_typectl.hpp 2017-11 $
 *
 * Project:  PLP (PLP: PL plot).
 * Purpose:  Plp type controler implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-11 ~ 2017, Weiwei Huang
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

#include "plp_typectl.hpp"

/**
 * \brief Constructor.
 */
CPlpTypeCtl::CPlpTypeCtl()
{
}

/**
 * \brief Destructor.
 */
CPlpTypeCtl::~CPlpTypeCtl()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CPlpTypeCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Option code to name.
 */
UErrCodeT CPlpTypeCtl::ToOpt(UStringT *aName, const PlpOptCodeT aCode)
{
    switch (aCode)
    {
    case PlpOptDev:
        *aName = "dev";
        break;
    case PlpOptFile:
        *aName = "o";
        break;
    case PlpOptBg:
        *aName = "bg";
        break;
    default:
        return UErrTrue;
    }

    return UErrFalse;
}

/**
 * \brief Device code.
 */
UErrCodeT CPlpTypeCtl::DevCodeToName(UStringT *aName, const PlpDevCodeT aCode)
{
    switch (aCode)
    {
    case PlpDevPng:
        *aName = "png";
        break;
    case PlpDevJpeg:
        *aName = "jpeg";
        break;
    case PlpDevGif:
        *aName = "gif";
        break;
    default:
        return UErrTrue;
    }

    return UErrFalse;
}
