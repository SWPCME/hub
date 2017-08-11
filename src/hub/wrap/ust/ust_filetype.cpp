/******************************************************************************
 * $Id: ust_filetype.cpp 2017-08 $
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
// ust
#include "ust_filectl.hpp"

/**
 * \brief Constructor.
 */
UFileT::UFileT()
{
    Init();
}

/**
 * \brief Constructor.
 */
UFileT::UFileT(const UStringT *aFileName, UstFileOperCodeT aOper)
{
    Init();
    InitFile(aFileName, aOper);
}

/**
 * \brief Destructor.
 */
UFileT::~UFileT()
{
    Close();
    BMD_CLASS_DEL(mFile);
    InitPointer();
}

/**
 * \brief Init file handle.
 *
 * if not ust UFileT(const UStringT *, UstFileOperCodeT), please to use this 
 * function to init this class; else this function is not need.
 */
UErrCodeT UFileT::InitFile(const UStringT *aFileName, UstFileOperCodeT aOper)
{
    Close();
    mFile->Open(&mFileH, aFileName, aOper);

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
UErrCodeT UFileT::ReadRow(UStringT *aStr)
{
    return mFile->ReadRow(aStr, mFileH);
}

/**
 * \brief Write.
 */
UErrCodeT UFileT::Write(const UStringT *aStr)
{
    return mFile->Write(aStr, mFileH);
}

/**
 * \brief Write.
 */
UErrCodeT UFileT::WriteRow(const UStringT *aStr)
{
    return mFile->WriteRow(aStr, mFileH);
}

/***** Private A *****/

/**
 * \brief Initialize.
 */
UErrCodeT UFileT::Init()
{
    InitPointer();
    BMD_CLASS_NEW(mFile, CUstFileCtl);

    return UErrFalse;
}

/**
 * \brief Init pointer.
 */
UErrCodeT UFileT::InitPointer()
{
    BMD_POINTER_INIT(mFile);
    BMD_POINTER_INIT(mFileH);

    return UErrFalse;
}

/**
 * \brief Close.
 */
UErrCodeT UFileT::Close()
{
    return mFile->Close(&mFileH);
}

/***** Private B *****/
