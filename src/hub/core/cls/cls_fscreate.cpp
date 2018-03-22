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

/**
 * \brief Constructor.
 */
CClsFsCreate::CClsFsCreate()
{
}

/**
 * \brief Destructor.
 */
CClsFsCreate::~CClsFsCreate()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CClsFsCreate::Init()
{
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
#ifdef OS_UNIX
    link(aSrc->ToA(), aDst->ToA());
#endif  // OS_UNIX

#ifdef OS_WINDOWS
    CopyFile(aSrc->ToA(), aDst->ToA(), FALSE);
#endif  // OS_WINDOWS

    return UErrFalse;
}
