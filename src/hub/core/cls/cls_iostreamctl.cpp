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
#include "cls_streamfile.hpp"
#include "cls_streamline.hpp"
#include "cls_streamformat.hpp"
#include "cls_streamblock.hpp"

/**
 * \brief Constructor.
 */
CClsIoStreamCtl::CClsIoStreamCtl()
{
    InitPointer();
}

/**
 * \brief Destructor.
 */
CClsIoStreamCtl::~CClsIoStreamCtl()
{
    BMD_CLASS_DEL(mFile);
    BMD_CLASS_DEL(mLine);
    BMD_CLASS_DEL(mFormat);
    BMD_CLASS_DEL(mBlock);
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
 * \brief Line-Oriented.
 */
CClsStreamLine *CClsIoStreamCtl::Line()
{
    BMD_CLASS_NEW(mLine, CClsStreamLine);

    return mLine;
}

/**
 * \brief Format.
 */
CClsStreamFormat *CClsIoStreamCtl::Format()
{
    BMD_CLASS_NEW(mFormat, CClsStreamFormat);

    return mFormat;
}

/**
 * \brief Block.
 */
CClsStreamBlock *CClsIoStreamCtl::Block()
{
    BMD_CLASS_NEW(mBlock, CClsStreamBlock);

    return mBlock;
}

/***** Private A *****/

UErrCodeT CClsIoStreamCtl::InitPointer()
{
    BMD_POINTER_INIT(mFile);
    BMD_POINTER_INIT(mLine);
    BMD_POINTER_INIT(mFormat);
    BMD_POINTER_INIT(mBlock);

    return UErrFalse;
}

/***** Private B *****/
