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
#include "base_macrodefn.hpp"
// core
#include "core_ctl.hpp"
// cls
#include "cls_ctl.hpp"
#include "cls_ioctl.hpp"
#include "cls_iostreamctl.hpp"
#include "cls_streamfile.hpp"
#include "cls_streamline.hpp"
#include "cls_streamformat.hpp"
#include "cls_formatoutput.hpp"
#include "cls_formatinput.hpp"

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
    mLine = streamCtl->Line();

    CClsStreamFormat *format = streamCtl->Format();
    mFrmtOut = format->Output();
    mFrmtIn = format->Input();

    return UErrFalse;
}

/**
 * \brief Create file.
 */
UErrCodeT CUstFileCtl::Open(UstFileHT *aFileH, const UStringT *aFileName,
                            const UstFileOperCodeT aOper)
{
    ClsFileOperCodeT oper;
    ToFileOper(&oper, aOper);

    return mFile->Open(aFileH, aFileName, oper);
}

/**
 * \brief Close file.
 */
UErrCodeT CUstFileCtl::Close(UstFileHT *aFileH)
{
    return mFile->Close(aFileH);
}

/**
 * \brief Save file.
 */
UErrCodeT CUstFileCtl::Save(UstFileHT *aFileH, const UStringT *aFileName,
                            const UstFileOperCodeT aOper)
{
    UstFileOperCodeT oper = UstFileOperWta;
    if (aOper < UstFileOperWt)
    {
        return UErrTrue;
    }
    else if (aOper >= UstFileOperWb)
    {
        oper = UstFileOperWba;
    }

    Close(aFileH);

    return Open(aFileH, aFileName, oper);
}

/**
 * \brief Read next row.
 */
UErrCodeT CUstFileCtl::ReadRow(UStringT *aStr, UstFileHT aFileH)
{
    // char str[kNMax];
    // mFrmtIn->FromFile(aFileH, "%[^\n]", str);
    // *aStr = str;

    return mLine->Line(aStr, (ClsFileHT) aFileH);
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

/**
 * \brief End of file.
 */
UErrCodeT CUstFileCtl::Eof(UstFileHT aFileH)
{
    return mFile->Eof(aFileH);
}

/***** Private A *****/

/**
 * \brief Init pointer.
 */
UErrCodeT CUstFileCtl::InitPointer()
{
    BMD_POINTER_INIT(mFile);
    BMD_POINTER_INIT(mLine);
    BMD_POINTER_INIT(mFrmtIn);
    BMD_POINTER_INIT(mFrmtOut);

    return UErrFalse;
}

/**
 * \brief To file operation.
 */
UErrCodeT CUstFileCtl::ToFileOper(ClsFileOperCodeT *aDst,
                                  const UstFileOperCodeT aSrc)
{
    *aDst = (ClsFileOperCodeT) aSrc;

    return UErrFalse;
}

/**
 * \brief Check file operation of write.
 */
UErrCodeT CUstFileCtl::CheckWrite()
{
    // UstFileOperCodeT oper;
    // if ((oper == UstFileOperW) || (oper == UstFileOperWt)
    //     || (oper == UstFileOperWta) || (oper == UstFileOperWb)
    //     || (oper == UstFileOperWba))
    // {
    //     return UErrFalse;
    // }

    return UErrTrue;
}

/**
 * \brief Reopen file.
 */
UErrCodeT CUstFileCtl::Reopen()
{
    BMD_CHECK_ERR(CheckWrite());

    return UErrFalse;
}

/***** Private B *****/
