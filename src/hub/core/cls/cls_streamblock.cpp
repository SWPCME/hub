/* -*- mode: c++ -*- */
/******************************************************************************
 * $Id: cls_streamblock.cpp 2018-08 $
 *
 * Project:  Cls (C language standard library).
 * Purpose:  Stream block implemention.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2018-08 ~ 2018, Weiwei Huang
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

#include "cls_streamblock.hpp"

// base
#include "base_ctl.hpp"
// core
#include "core_ctl.hpp"
// cls
#include "cls_ctl.hpp"
#include "cls_memoryctl.hpp"
// ust
#include "ust_memtype.hpp"

#include <stdio.h>

/**
 * \brief Constructor.
 */
CClsStreamBlock::CClsStreamBlock()
{
    InitPointer();
}

/**
 * \brief Destructor.
 */
CClsStreamBlock::~CClsStreamBlock()
{
    InitPointer();
}

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CClsStreamBlock::Init()
{
    CClsCtl *cls = NULL;
    CLS_CTL(cls);
    mMem = cls->Mem();

    return UErrFalse;
}

/**
 * \brief Input block from stream.
 */
UIntT CClsStreamBlock::Input(UMemT *aBlock, UIntT aSize, UIntT aCount,
                             ClsFileHT aFileH)
{
    void *block = (void *) aBlock->Handle();
    UIntT amount = fread(block, (size_t) aSize, (size_t) aCount, (FILE *) aFileH);

    return amount;
}

/**
 * \brief Output block to stream.
 */
UErrCodeT CClsStreamBlock::Output(UMemT *aBlock, UIntT aSize, UIntT aCount,
                                  ClsFileHT aFileH)
{
    void *block = (void *) aBlock->Handle();
    fwrite(block, (size_t) aSize, (size_t) aCount, (FILE *) aFileH);

    return UErrFalse;
}

/***** Private A *****/

/**
 * \brief InitPointer.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CClsStreamBlock::InitPointer()
{
    BMD_POINTER_INIT(mMem);

    return UErrFalse;
}

/***** Private B *****/
