/******************************************************************************
 * $Id: base_tmpctl.cpp 2017-12 $
 *
 * Project:  Base.
 * Purpose:  Base temporary control implemetation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-12 ~ 2017 Weiwei Huang
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

#include "base_tmpctl.hpp"

// base
#include "base_ctl.hpp"
// core
#include "core_ctl.hpp"
// cls
#include "cls_ctl.hpp"
#include "cls_filesctl.hpp"
#include "cls_fileswork.hpp"
#include "cls_filescreate.hpp"

/**
 * \brief Constructor.
 */
CBaseTmpCtl::CBaseTmpCtl()
{
}

/**
 * \brief Destructor.
 */
CBaseTmpCtl::~CBaseTmpCtl()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CBaseTmpCtl::Init()
{
    CClsCtl *cls = NULL;
    CLS_CTL(cls);
    mFs = cls->Files();

    CClsFilesWork *fsWork = mFs->Work();
    fsWork->Cur(&mDir);
    mDir += "/.tmp";

    return UErrFalse;
}

/**
 * \brief Get temporary directory.
 */
UStringT CBaseTmpCtl::Dir(HubCodeT aCode)
{
    UStringT dir = mDir;
    switch (aCode)
    {
    case HubMRst:
    {
        dir += "/rst";
        break;
    }
    case HubMVtr:
    {
        dir += "/vtr";
        break;
    }
    case HubMFmd:
    {
        dir += "/fmd";
        break;
    }
    default:
        dir = "";
        break;
    }

    return dir;
}

/**
 * \brief Crate temporary directory.
 */
UErrCodeT CBaseTmpCtl::MkDir(HubCodeT aCode)
{
    CClsFilesCreate *fsCreate =  mFs->Create();

    fsCreate->Dir(&mDir);

    UStringT dir = Dir(aCode);
    fsCreate->Dir(&dir);

    return UErrFalse;
}

/**
 * \brief Remove temporary directory.
 */
UErrCodeT CBaseTmpCtl::RmDir(HubCodeT aCode)
{
    if ((aCode != HubMRst) && (aCode != HubMVtr) && (aCode != HubMFmd))
    {
        return UErrFalse;
    }

    return UErrFalse;
}
