/******************************************************************************
 * $Id: cls_iostreamctl.hpp 2017-05 $
 *
 * Project:  C language standard library.
 * Purpose:  Stream controler implemention.
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

#include "cls_iostreamctl.hpp"

// cls
#include "cls_streamformat.hpp"
#include "cls_streamfile.hpp"

/**
 * \brief Constructor.
 */
CClsIoStreamCtl::CClsIoStreamCtl()
{
}

/**
 * \brief Destructor.
 */
CClsIoStreamCtl::~CClsIoStreamCtl()
{
    BMD_CLASS_DEL(mFormat);
}

/**
 * \brief Initialize.
 */
UErrCodeT CClsIoStreamCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief File.
 */
CClsStreamFile *CClsIoStreamCtl::File()
{
    BMD_CLASS_NEW(mFile, CClsStreamFile);

    return mFile;
}

/**
 * \brief Format.
 */
CClsStreamFormat *CClsIoStreamCtl::Format()
{
    BMD_CLASS_NEW(mFormat, CClsStreamFormat);

    return mFormat;
}

/***** Private A *****/

UErrCodeT CClsIoStreamCtl::InitPointer()
{
    BMD_POINTER_INIT(mFormat);

    return UErrFalse;
}

/***** Private B *****/
