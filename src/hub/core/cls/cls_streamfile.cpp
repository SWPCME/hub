/******************************************************************************
 * $Id: cls_streamfile.cpp 2017-08 $
 *
 * Project:  C language standard library.
 * Purpose:  Stream file implemention.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-08 ~ 2017 Weiwei Huang
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

#include "cls_streamfile.hpp"

// base
#include "base_ctl.hpp"
// core
#include "core_ctl.hpp"
// cls
#include "cls_ctl.hpp"
#include "cls_typectl.hpp"
#include "cls_filechar.hpp"
// #include "cls_filestr.hpp"
// #include "cls_fileline.hpp"
// #include "cls_fileblock.hpp"

// LIBC
#include <stdio.h>

/**
 * \brief Constructor.
 */
CClsStreamFile::CClsStreamFile()
{
}

/**
 * \brief Destructor.
 */
CClsStreamFile::~CClsStreamFile()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CClsStreamFile::Init()
{
    CLS_TYPE_CTL(mType);
    
    return UErrFalse;
}

/**
 * \brief Open file.
 */
UErrCodeT CClsStreamFile::Open(ClsFileHT *aFileH, const UStringT *aFile,
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
UErrCodeT CClsStreamFile::Close(ClsFileHT *aFileH)
{
    if (*aFileH == NULL)
    {
        return UErrTrue;
    }

    fclose((FILE *) *aFileH);
    *aFileH = NULL;

    return UErrFalse;
}

/**
 * \brief Close all file.
 */
UErrCodeT CClsStreamFile::CloseAll()
{
    fcloseall();

    return UErrFalse;
}

/**
 * \brief Charcter.
 */
CClsFileChar *CClsStreamFile::Char()
{
    return mChar;
}

// /**
//  * \brief String.
//  */
// CClsFileStr *CClsFileStr::Str()
// {
//     return mStr;
// }

// /**
//  * \brief Line-oriented.
//  */
// CClsFileLine *CClsStreamFile::Line()
// {
//     return mLine;
// }

// /**
//  * \brief Block.
//  */
// CClsFileBlock *CClsStreamFile::Block()
// {
//     return mBlock;
// }

// /**
//  * \brief Format.
//  */
// CClsFileFormat *CClsStreamFile::Format()
// {
//     return mFormat;
// }

/**
 * \brief Read chunks of generic data from STREAM.
 */
UErrCodeT CClsStreamFile::Read(UIntT *aRealCount, UDataT aData, UIntT aSize,
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
UErrCodeT CClsStreamFile::Write(const UDataT aData, UIntT aSize,
                                UIntT aCount, ClsFileHT aFileH)
{
    UIntT count = fwrite(aData, aSize, aCount, (FILE *) aFileH);

    if (count == aCount)
    {
        return UErrFalse;
    }

    return UErrTrue;
}

/***** Private A *****/

UErrCodeT CClsStreamFile::InitPointer()
{
    BMD_POINTER_INIT(mType);

    return UErrFalse;
}

/***** Private B *****/
