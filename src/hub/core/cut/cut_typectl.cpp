/******************************************************************************
 * $Id: cut_typectl.cpp 2017-06 $
 *
 * Project:  CUT (CUT: Client-side URL Transfer).
 * Purpose:  Type controler implementation.
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

#include "cut_typectl.hpp"

/**
 * \brief Constructor.
 */
CCutTypeCtl::CCutTypeCtl()
{
}

/**
 * \brief Destructor.
 */
CCutTypeCtl::~CCutTypeCtl()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CCutTypeCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief To error code.
 */
UErrCodeT CCutTypeCtl::ToErrCode(UErrCodeT *aDest, const CURLcode aCode)
{
    switch (aCode)
    {
    case CURLE_OK:
        *aDest = UErrFalse;
        break;
    default:
        *aDest = UErrTrue;
        break;
    }

    return UErrFalse;
}

/**
 * \brief To option.
 */
UErrCodeT CCutTypeCtl::ToOpt(CURLoption *aDest, const CutOptCodeT aOpt)
{
    switch (aOpt)
    {
        // Http.
    case CutOptUrl:
        *aDest = CURLOPT_URL;
        break;
    case CutOptHttpHeader:
        *aDest = CURLOPT_HTTPHEADER;
        break;
    case CutOptHttpGet:
        *aDest = CURLOPT_HTTPGET;
        break;
    case CutOptHttpPut:
        *aDest = CURLOPT_PUT;
        break;
    case CutOptWriteData:
        *aDest = CURLOPT_WRITEDATA;
        break;
        // Function.
    case CutOptReadFunc:
        *aDest = CURLOPT_READFUNCTION;
        break;
    case CutOptWriteFunc:
        *aDest = CURLOPT_WRITEFUNCTION;
        break;
    default:
        return UErrTrue;
    }

    return UErrFalse;
}
