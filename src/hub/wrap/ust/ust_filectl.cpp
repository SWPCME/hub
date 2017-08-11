/******************************************************************************
 * $Id: ust_filetype.hpp 2017-08 $
 *
 * Project:  Universal structrue library.
 * Purpose:  File controler implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-08 ~ 2017, Weiwei Huang
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

#include "ust_filectl.hpp"

// base
#include "base_ctl.hpp"
// core
#include "core_ctl.hpp"
// cls
#include "cls_ctl.hpp"
#include "cls_ioctl.hpp"
#include "cls_iostreamctl.hpp"
#include "cls_streamfile.hpp"
#include "cls_streamformat.hpp"
#include "cls_formatoutput.hpp"

/**
 * \brief Constructor.
 */
CUstFileCtl::CUstFileCtl()
{
    InitPointer();
}

/**
 * \brief Destructor.
 */
CUstFileCtl::~CUstFileCtl()
{
    InitPointer();
}

/**
 * \brief Initialize.
 */
UErrCodeT CUstFileCtl::Init()
{
    CBaseCtl *baseCtl = CBaseCtl::Base();
    CCoreCtl *coreCtl = baseCtl->Core();
    CClsCtl *clsCtl = coreCtl->Cls();
    CClsIoCtl *ioCtl = clsCtl->Io();
    CClsIoStreamCtl *streamCtl = ioCtl->Stream();
    mFile = streamCtl->File();
    CClsStreamFormat *format = streamCtl->Format();
    mFrmtOut = format->Output();

    return UErrFalse;
}

/**
 * \brief Create.
 */
UErrCodeT CUstFileCtl::Open(UstFileHT *aFileH, const UStringT *aFileName,
                            UstFileOperCodeT aOper)
{
    ClsFileOperCodeT oper;
    ToFileOper(&oper, aOper);

    return mFile->Open(aFileH, aFileName, oper);
}

/**
 * \brief Close.
 */
UErrCodeT CUstFileCtl::Close(UstFileHT *aFileH)
{
    return mFile->Close(aFileH);
}

/**
 * \brief Read next row.
 */
UErrCodeT CUstFileCtl::ReadRow(UStringT *aStr, UstFileHT aFileH)
{
    return UErrFalse;
}

/**
 * \brief Write.
 */
UErrCodeT CUstFileCtl::Write(const UStringT *aStr, UstFileHT aFileH)
{
    return mFrmtOut->ToFile(aFileH, "%s", aStr->ToA());
}

/**
 * \brief Write next row.
 */
UErrCodeT CUstFileCtl::WriteRow(const UStringT *aStr, UstFileHT aFileH)
{
    return mFrmtOut->ToFile(aFileH, "%s\n", aStr->ToA());
}

/***** Private A *****/

/**
 * \brief Init pointer.
 */
UErrCodeT CUstFileCtl::InitPointer()
{
    BMD_POINTER_INIT(mFile);
    BMD_POINTER_INIT(mFrmtOut);

    return UErrFalse;
}

/**
 * \brief 
 */
UErrCodeT CUstFileCtl::ToFileOper(ClsFileOperCodeT *aDst,
                                  const UstFileOperCodeT aSrc)
{
    *aDst = (ClsFileOperCodeT) aSrc;

    return UErrFalse;
}

/***** Private B *****/
