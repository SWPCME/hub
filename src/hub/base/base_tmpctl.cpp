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

// hub
#include "hub_modulectl.hpp"
// base
#include "base_ctl.hpp"
// core
#include "core_ctl.hpp"
// cls
#include "cls_ctl.hpp"
#include "cls_fsctl.hpp"
#include "cls_fsattr.hpp"
#include "cls_fswork.hpp"
#include "cls_fscreate.hpp"
#include "cls_timectl.hpp"
// ust
#include "ust_fsfiletype.hpp"

/**
 * \brief Constructor.
 */
CBaseTmpCtl::CBaseTmpCtl() : mMDir(UContainerMap)
{
}

/**
 * \brief Destructor.
 */
CBaseTmpCtl::~CBaseTmpCtl()
{
    DelAllDir();
}

/**
 * \brief Initialize.
 */
UErrCodeT CBaseTmpCtl::Init()
{
    CClsCtl *cls = NULL;
    CLS_CTL(cls);
    mFs = cls->Fs();
    mTime = cls->Time();

    return UErrFalse;
}

/**
 * \brief Set temporary root directory.
 */
UErrCodeT CBaseTmpCtl::SetRootDir(const UStringT *aDir, CHubModuleCtl *aModule)
{
    if (mMDir.FindByKey(aModule) == UErrFalse)
    {
        return UErrTrue;
    }

    CClsFsAttr *fsAttr = mFs->Attr();
    if (fsAttr->Access(aDir) == UErrTrue)
    {
        return UErrTrue;
    }

    UStringT dir = *aDir;
    BTimeTmT tm;
    mTime->Current(&tm);
    UStringT strTm = tm.year;
    strTm += tm.mon;
    strTm += tm.mday;
    strTm += tm.hour;
    strTm += tm.min;
    strTm += tm.sec;
    UStringT uuid = strTm;
    dir += "/";
    dir += uuid;

    UIntT num = 0;
    dir += "_";
    UStringT tmpDir = dir;
    for(tmpDir += num; fsAttr->Access(&tmpDir) == UErrFalse;)
    {
        num++;
        tmpDir = dir;
        tmpDir += num;
    }
    dir += num;
    CClsFsCreate *fsCreate = mFs->Create();
    fsCreate->Dir(&dir);
    mMDir.Add(dir, aModule);

    return UErrFalse;
}

/**
 * \brief Get temporary directory.
 */
UStringT CBaseTmpCtl::Dir(HubCodeT aCode, CHubModuleCtl *aModule)
{
    if (mMDir.FindByKey(aModule) == UErrTrue)
    {
        return UErrTrue;
    }

    UStringT dir = mMDir[aModule];
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
UErrCodeT CBaseTmpCtl::MkDir(HubCodeT aCode, CHubModuleCtl *aModule)
{
    if (mMDir.FindByKey(aModule) == UErrTrue)
    {
        SetDefaultDir(aModule);
    }

    UStringT dir = Dir(aCode, aModule);
    CClsFsCreate *fsCreate = mFs->Create();
    fsCreate->Dir(&dir);

    return UErrFalse;
}

/**
 * \brief Remove temporary directory.
 */
UErrCodeT CBaseTmpCtl::RmDir(HubCodeT aCode, CHubModuleCtl *aModule)
{
    UStringT dir = Dir(aCode, aModule);
    UFsFileT file(&dir);
    file.Rm(0);

    return UErrFalse;
}

/**
 * \brief Remove root directory.
 */
UErrCodeT CBaseTmpCtl::RmRootDir(CHubModuleCtl *aModule)
{
    UStringT dir = mMDir[aModule];
    UFsFileT file(&dir);
    file.Rm(0);
    mMDir.DelByKey(aModule);

    return UErrFalse;
}

/***** Private A *****/

/**
 * \brief Set default temporary directory.
 */
UErrCodeT CBaseTmpCtl::SetDefaultDir(CHubModuleCtl *aModule)
{
    CClsFsWork *fsWork = mFs->Work();
    UStringT dir;
    fsWork->Cur(&dir);
    dir += "/.tmp";
    CClsFsCreate *fsCreate = mFs->Create();
    fsCreate->Dir(&dir);
    mMDir.Add(dir, aModule);

    return UErrFalse;
}

/**
 * \brief Delete all directory.
 */
UErrCodeT CBaseTmpCtl::DelAllDir()
{
    MStringModuleItT *it = mMDir.Iterator();
    for (it->Head(); it->State() == UErrFalse; it->Next())
    {
        UStringT dir = it->Content();
        UFsFileT file(&dir);
        file.Rm(0);
    }

    return UErrFalse;
}

/***** Private B *****/
