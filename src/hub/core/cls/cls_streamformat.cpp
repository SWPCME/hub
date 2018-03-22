/******************************************************************************
 * $Id: cls_streamformat.cpp 2017-07 $
 *
 * Project:  C language standard library.
 * Purpose:  Stream format implemention.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-07 ~ 2017 Weiwei Huang
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

#include "cls_streamformat.hpp"

// cls
#include "cls_formatinput.hpp"
#include "cls_formatoutput.hpp"

/**
 * \brief Constructor.
 */
CClsStreamFormat::CClsStreamFormat()
{
    BMD_POINTER_INIT(mInput);
    BMD_POINTER_INIT(mOutput);
}

/**
 * \brief Destructor.
 */
CClsStreamFormat::~CClsStreamFormat()
{
    BMD_CLASS_DEL(mInput);
    BMD_CLASS_DEL(mOutput);
}

/**
 * \brief Initialize.
 */
UErrCodeT CClsStreamFormat::Init()
{
    return UErrFalse;
}

/**
 * \brief Input.
 */
CClsFormatInput *CClsStreamFormat::Input()
{
    BMD_CLASS_NEW(mInput, CClsFormatInput);

    return mInput;
}

/**
 * \brief Output.
 */
CClsFormatOutput *CClsStreamFormat::Output()
{
    BMD_CLASS_NEW(mOutput, CClsFormatOutput);

    return mOutput;
}
