/* -*- mode: c++ -*- */
/******************************************************************************
 * $Id: ust_memtype.cpp 2018-08 $
 *
 * Project:  Ust (ust: universal struct library).
 * Purpose:  Memory type implemention.
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

#include "ust_memtype.hpp"

// base
#include "base_ctl.hpp"
// core
#include "core_ctl.hpp"
// cls
#include "cls_ctl.hpp"
#include "cls_memoryctl.hpp"

/**
 * \brief Constructor.
 */
UMemT::UMemT()
{
    InitPointer();
    Init();
}

/**
 * \brief Constructor.
 */
UMemT::UMemT(const UIntT aSize)
{
    InitPointer();
    Init();
    Set(aSize);
}

/**
 * \brief Destructor.
 */
UMemT::~UMemT()
{
    Free();
    InitPointer();
}

/**
 * \brief Get handle.
 */
UMemHT UMemT::Handle()
{
    return mMemH;
}

/**
 * \brief Set memory with size.
 */
UErrCodeT UMemT::Set(const UIntT aSize)
{
    Free();
    mMemH = mMem->Alloc(aSize);

    return UErrFalse;
}

/***** Private A *****/

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT UMemT::Init()
{
    CClsCtl *cls;
    BMD_POINTER_INIT(cls);
    CLS_CTL(cls);
    mMem = cls->Mem();

    return UErrFalse;
}

/**
 * \brief InitPointer.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT UMemT::InitPointer()
{
    BMD_POINTER_INIT(mMem);
    BMD_POINTER_INIT(mMemH);

    return UErrFalse;
}

/**
 * \brief Free.
 *
 * Free the memory.
 */
UErrCodeT UMemT::Free()
{
    if (mMemH != NULL)
    {
        mMem->Free(&mMemH);
    }

    return UErrFalse;
}

/***** Private B *****/
