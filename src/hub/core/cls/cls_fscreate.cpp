/******************************************************************************
 * $Id: cls_fscreate.cpp 2017-12 $
 *
 * Project:  C language standard library.
 * Purpose:  File system create implemention.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-12 ~ 2017, Weiwei Huang
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

#ifdef OS_WINDOWS
// This header file must be at the top.
#include <windows.h>
#endif  // OS_WINDOWS

#include "cls_fscreate.hpp"

// LIBC
#ifdef OS_UNIX
#include <sys/stat.h>
#include <unistd.h>
#endif  // OS_UNIX

// base
#include "base_ctl.hpp"
// core
#include "core_ctl.hpp"
// cls
#include "cls_ctl.hpp"
#include "cls_ioctl.hpp"
#include "cls_iostreamctl.hpp"
#include "cls_streamfile.hpp"
#include "cls_streamblock.hpp"
// ust
#include "ust_memtype.hpp"

/**
 * \brief Constructor.
 */
CClsFsCreate::CClsFsCreate()
{
    InitPointer();
}

/**
 * \brief Destructor.
 */
CClsFsCreate::~CClsFsCreate()
{
    InitPointer();
}

/**
 * \brief Initialize.
 */
UErrCodeT CClsFsCreate::Init()
{
    CClsCtl *cls;
    BMD_POINTER_INIT(cls);
    CLS_CTL(cls);
    CClsIoCtl *io = cls->Io();
    CClsIoStreamCtl *stream = io->Stream();
    mFile = stream->File();
    mBlock = stream->Block();

    return UErrFalse;
}

/**
 * \brief Create directory.
 */
UErrCodeT CClsFsCreate::Dir(const UStringT *aDir)
{
#ifdef OS_UNIX
    mode_t mode = 0777;
    mkdir(aDir->ToA(), mode);
#endif  // OS_UNIX

#ifdef OS_WINDOWS
    CreateDirectory(aDir->ToA(), NULL);
#endif  // OS_WINDOWS

    return UErrFalse;
}

/**
 * \brief Create a copy file with exist file.
 */
UErrCodeT CClsFsCreate::Copy(const UStringT *aDst, const UStringT *aSrc)
{
#ifdef DEBUG_MODE
    return CopyStdC(aDst, aSrc);
#else
    return CopySys(aDst, aSrc);
#endif  // DEBUG_MODE
}

/***** Private A *****/

/**
 * \brief Initialize pointer.
 */
UErrCodeT CClsFsCreate::InitPointer()
{
    BMD_POINTER_INIT(mFile);
    BMD_POINTER_INIT(mBlock);

    return UErrFalse;
}

/**
 * \brief Create a copy file with exist file.
 *
 * It is used with standard c.
 */
UErrCodeT CClsFsCreate::CopyStdC(const UStringT *aDst, const UStringT *aSrc)
{
    ClsFileHT srcH = NULL;
    mFile->Open(&srcH, aSrc, ClsFileOperRb);
    ClsFileHT dstH = NULL;
    mFile->Open(&dstH, aDst, ClsFileOperWb);

    UIntT size = 1;
    UIntT count = 512;
    UIntT amount = size * count;
    UMemT block(amount);
    while (mFile->Eof(srcH) == UErrTrue)
    {
        UIntT countOut = mBlock->Input(&block, size, count, srcH);
        mBlock->Output(&block, size, countOut, dstH);
    }

    mFile->Close(&srcH);
    mFile->Close(&dstH);

    return UErrFalse;
}

/**
 * \brief Create a copy file with exist file.
 *
 * It is used with system call.
 */
UErrCodeT CClsFsCreate::CopySys(const UStringT *aDst, const UStringT *aSrc)
{
    UErrCodeT err = UErrTrue;

#ifdef OS_UNIX
    UStringT cmd = "cp ";
    cmd += aSrc;
    cmd += " ";
    cmd += aDst;
    system(cmd.ToA());
    err = UErrFalse;
    // int tErr = link(aSrc->ToA(), aDst->ToA());
    // if (tErr == 0)
    // {
    //     err = UErrFalse;
    // }
#endif  // OS_UNIX

#ifdef OS_WINDOWS
    CopyFile(aSrc->ToA(), aDst->ToA(), FALSE);
    err = UErrFalse;
#endif  // OS_WINDOWS

    return err;
}

/***** Private B *****/
