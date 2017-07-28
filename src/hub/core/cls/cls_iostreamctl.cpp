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

// Glibc Module.
#include "stdio.h"

// base
#include "base_ctl.hpp"
// core
#include "core_ctl.hpp"
// cls
#include "cls_ctl.hpp"
#include "cls_typectl.hpp"
#include "cls_streamformat.hpp"

/**
 * \brief Constructor.
 */
CClsIoStreamCtl::CClsIoStreamCtl()
{
    BMD_POINTER_INIT(mType);
    BMD_POINTER_INIT(mFormat);
}

/**
 * \brief Destructor.
 */
CClsIoStreamCtl::~CClsIoStreamCtl()
{
    BMD_POINTER_INIT(mType);
    BMD_CLASS_DEL(mFormat);
}

/**
 * \brief Initialize.
 */
UErrCodeT CClsIoStreamCtl::Init()
{
    CLS_TYPE_CTL(mType);
    
    return UErrFalse;
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
 * \brief Open file.
 */
UErrCodeT CClsIoStreamCtl::Open(ClsFileHT *aFileH, const UStringT *aFile,
                                const ClsFileOperCodeT aOper)
{
    UStringT oper;
    mType->ToFileOper(&oper, aOper);
    *aFileH = (ClsFileHT) fopen(aFile->ToA(), oper.ToA());

    return UErrFalse;
}

/**
 * \brief Close file.
 */
UErrCodeT CClsIoStreamCtl::Close(ClsFileHT *aFileH)
{
    fclose((FILE *) *aFileH);
    *aFileH = NULL;

    return UErrFalse;
}

/**
 * \brief Read chunks of generic data from STREAM.
 */
UErrCodeT CClsIoStreamCtl::Read(UIntT *aRealCount, UDataT aData, UIntT aSize,
                                UIntT aCount, ClsFileHT aFileH)
{
    *aRealCount = fread(aData, aSize, aCount, (FILE *) aFileH);

    if (*aRealCount == aCount)
    {
        return UErrFalse;
    }

    return UErrTrue;
}

/**
 * \brief Write chunks of generic data to STREAM.
 */
UErrCodeT CClsIoStreamCtl::Write(const UDataT aData, UIntT aSize, UIntT aCount,
                                 ClsFileHT aFileH)
{
    UIntT count = fwrite(aData, aSize, aCount, (FILE *) aFileH);

    if (count == aCount)
    {
        return UErrFalse;
    }

    return UErrTrue;
}
