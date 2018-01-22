/******************************************************************************
 * $Id: ust_fsfilectl.cpp 2018-01 $
 *
 * Project:  Universal structure library.
 * Purpose:  File system file controler implemention.
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

#include "ust_fsfilectl.hpp"

// base
#include "base_ctl.hpp"
// core
#include "core_ctl.hpp"
// cls
#include "cls_ctl.hpp"
#include "cls_fsctl.hpp"
#include "cls_fsaccess.hpp"
#include "cls_fsdelete.hpp"

/**
 * \brief Constructor.
 */
CUstFsFileCtl::CUstFsFileCtl()
{
    BMD_POINTER_INIT(mAccess);
    BMD_POINTER_INIT(mDelete);
}

/**
 * \brief Destructor.
 */
CUstFsFileCtl::~CUstFsFileCtl()
{
    BMD_POINTER_INIT(mAccess);
    BMD_POINTER_INIT(mDelete);
}

/**
 * \brief Initialize.
 */
UErrCodeT CUstFsFileCtl::Init()
{
    CClsCtl *cls;
    CLS_CTL(cls);
    CClsFsCtl *fs = cls->Fs();
    mAccess = fs->Access();
    mDelete = fs->Delete();

    return UErrFalse;
}

/**
 * \brief Remove.
 *
 * @param aName The name of file, it could be a regular file or a directory.
 * @param aLv If aLv == 0, all file in this directory will be deleted;
 *            If aLv >= 1, it will be only delete less than "aLv" deepth files.
 *            If aLv < 0, it will be nothing to do.
 */
UErrCodeT CUstFsFileCtl::Rm(const UStringT *aName, const UIntT aLv)
{
    if (aLv < 0)
    {
        return UErrTrue;
    }

    ClsFsFileCtnT fileCtn(UContainerList);
    if (mAccess->Dir(&fileCtn, aName) == UErrTrue)
    {
        return mDelete->File(aName);
    }
    UIntT count = fileCtn.Count();
    if ((count > 0) && (aLv == 1))
    {
        return UErrTrue;
    }

    ClsFsFileItT *it = fileCtn.Iterator();
    for (it->Head(); it->State() == UErrFalse; it->Next())
    {
        ClsFsFileT file = it->Content();
        UStringT fileName = file.Name();
        ClsFsFileTypeCodeT fileType = file.Type();
        if (fileType == ClsFsFileTypeDir)
        {
            if (aLv > 1)
            {
                Rm(&fileName, aLv - 1);
            }
            else if (aLv == 0)
            {
                Rm(&fileName, aLv);
            }
        }
        mDelete->File(&file);
    }

    mDelete->Dir(aName);

    return UErrFalse;
}
