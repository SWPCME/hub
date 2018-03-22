/******************************************************************************
 * $Id: cls_fsdelete.hpp 2018-01 $
 *
 * Project:  C language standard library.
 * Purpose:  File system delete implemention.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2018-01 ~ 2018, Weiwei Huang
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
#include <direct.h>
#endif  // OS_WINDOWS

#include "cls_fsdelete.hpp"

// LIBC
#ifdef OS_UNIX
#include <sys/stat.h>
#include <unistd.h>
#endif  // OS_UNIX

/**
 * \brief Constructor.
 */
CClsFsDelete::CClsFsDelete()
{
}

/**
 * \brief Destructor.
 */
CClsFsDelete::~CClsFsDelete()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CClsFsDelete::Init()
{
    return UErrFalse;
}

/**
 * \brief Remove file.
 */
UErrCodeT CClsFsDelete::File(const ClsFsFileT *aFile)
{
    UStringT name = aFile->Name();
    if (aFile->Type() == ClsFsFileTypeDir)
    {
        Dir(&name);
    }
    else
    {
        File(&name);
    }

    return UErrFalse;
}

/**
 * \brief Remove file.
 */
UErrCodeT CClsFsDelete::File(const UStringT *aFile)
{
#ifdef OS_UNIX
    int err = -1;
    if (unlink(aFile->ToA()) == -1)
    {
        return UErrTrue;
    }
#endif  // OS_UNIX

#ifdef OS_WINDOWS
    if (DeleteFile(aFile->ToA()) == 0)
    {
        return UErrTrue;
    }
#endif  // OS_WINDOWS

    return UErrFalse;
}

/**
 * \brief Remove directory.
 */
UErrCodeT CClsFsDelete::Dir(const UStringT *aFile)
{
#ifdef OS_UNIX
    if (rmdir(aFile->ToA()) == -1)
    {
        return UErrTrue;
    }
#endif  // OS_UNIX

#ifdef OS_WINDOWS
    // RemoveDirectory(aFile->ToA());
    if (_rmdir(aFile->ToA()) == -1)
    {
        return UErrTrue;
    }
#endif  // OS_WINDOWS

    return UErrFalse;
}
