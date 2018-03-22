/******************************************************************************
 * $Id: cls_fsaccess.cpp 2018-01 $
 *
 * Project:  C language standard library.
 * Purpose:  File system accessing directories implemention.
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
#endif  // OS_WINDOWS

#include "cls_fsaccess.hpp"

// LIBC
#ifdef OS_UNIX
#include <dirent.h>
#endif  // OS_UNIX

/**
 * \brief Constructor.
 */
CClsFsAccess::CClsFsAccess()
{
}

/**
 * \brief Destructor.
 */
CClsFsAccess::~CClsFsAccess()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CClsFsAccess::Init()
{
    return UErrFalse;
}

/**
 * \brief Get directory.
 */
UErrCodeT CClsFsAccess::Dir(ClsFsFileCtnT *aFileCtn, const UStringT *aDir)
{
    if ((*aDir == "/") || (*aDir == ""))
    {
        return UErrTrue;
    }

    aFileCtn->Clear();
    ClsFsFileT file;
    UStringT fileName;
    ClsFsFileTypeCodeT fileType;

#ifdef OS_UNIX
    DIR *dp = NULL;
    struct dirent *ep = NULL;

    dp = opendir(aDir->ToA());
    if (dp == NULL)
    {
        return UErrTrue;
    }

    for (ep = readdir(dp); ep != NULL; ep = readdir(dp))
    {
        UStringT baseName = ep->d_name;
        if (baseName == "." || baseName == "..")
        {
            continue;
        }
        fileName = *aDir;
        fileName += "/";
        fileName += baseName;

        if (ep->d_type == DT_DIR)
        {
            fileType = ClsFsFileTypeDir;
        }
        else if (ep->d_type == DT_REG)
        {
            fileType = ClsFsFileTypeReg;
        }
        else
        {
            fileType = ClsFsFileTypeUnknown;
        }

        file.SetAll(&fileName, fileType);
        aFileCtn->Add(file);
    }

    closedir(dp);
#endif  // OS_UNIX

#ifdef OS_WINDOWS
    WIN32_FIND_DATA ffd;
    HANDLE hFind = INVALID_HANDLE_VALUE;
    UStringT szDir = *aDir;
    szDir += "/*";

    hFind = FindFirstFile(szDir.ToA(), &ffd);
    if (INVALID_HANDLE_VALUE == hFind)
    {
        return UErrTrue;
    }

    do
    {
        UStringT baseName = ffd.cFileName;
        if (baseName == "." || baseName == "..")
        {
            continue;
        }
        fileName = *aDir;
        fileName += "/";
        fileName += baseName;

        if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        {
            fileType = ClsFsFileTypeDir;
        }
        else
        {
            fileType = ClsFsFileTypeReg;
        }

        file.SetAll(&fileName, fileType);
        aFileCtn->Add(file);
    } while(FindNextFile(hFind, &ffd) != 0);
    FindClose(hFind);
#endif  // OS_WINDOWS

    return UErrFalse;
}
