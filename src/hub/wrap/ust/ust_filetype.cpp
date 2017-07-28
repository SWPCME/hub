/******************************************************************************
 * $Id: ust_filetype.cpp 2017-07 $
 *
 * Project:  Universal structrue library.
 * Purpose:  File type implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-07 ~ 2017, Weiwei Huang
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

#include "ust_filetype.hpp"

// base
#include "base_macrodefn.hpp"

/**
 * \brief Constructor.
 */
UFileT::UFileT()
{
    BMD_POINTER_INIT(mFileH);
}

/**
 * \brief Destructor.
 */
UFileT::~UFileT()
{
    BMD_POINTER_INIT(mFileH);
}

/**
 * \brief Open file.
 */
UErrCodeT UFileT::Open(UStringT *aFile)
{
    return UErrFalse;
}

/**
 * \brief Handle.
 */
UstFileHT UFileT::Handle()
{
    return mFileH;
}

/**
 * \brief Read.
 */
UErrCodeT UFileT::Read()
{
    return UErrFalse;
}

/**
 * \brief Write.
 */
UErrCodeT UFileT::Write()
{
    return UErrFalse;
}

/***** Private A *****/

/**
 * \brief Initialize.
 */
UErrCodeT UFileT::Init()
{
    return UErrFalse;
}

/***** Private B *****/
