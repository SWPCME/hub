/******************************************************************************
 * $Id: ust_fsfiletype.cpp 2018-01 $
 *
 * Project:  Universal structure library.
 * Purpose:  File system file type implemention.
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

#include "ust_fsfiletype.hpp"

// base
#include "base_ctl.hpp"
#include "base_macrodefn.hpp"
// wrap
#include "wrap_ctl.hpp"
// ust
#include "ust_ctl.hpp"
#include "ust_fsctl.hpp"
#include "ust_fsfilectl.hpp"

/**
 * \brief Constructor.
 */
UFsFileT::UFsFileT()
{
    BMD_POINTER_INIT(mFile);
    Init();
}

/**
 * \brief Constructor.
 */
UFsFileT::UFsFileT(const UStringT *aName, const UAccessCodeT aAccess,
                   const UFsFileTypeCodeT aType)
{
    BMD_POINTER_INIT(mFile);
    Init();
    SetHandle(aName, aAccess, aType);
}

/**
 * \brief Destructor.
 */
UFsFileT::~UFsFileT()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT UFsFileT::Init()
{
    CUstCtl *ust = NULL;
    UST_CTL(ust);
    CUstFsCtl *fs = ust->Fs();
    mFile = fs->File();

    return UErrFalse;
}

/**
 * \brief Set handle.
 */
UErrCodeT UFsFileT::SetHandle(const UStringT *aName, const UAccessCodeT aAccess,
                              const UFsFileTypeCodeT aType)
{
    mName = *aName;

    return UErrFalse;
}

/**
 * \brief Get name.
 */
UStringT UFsFileT::Name()
{
    return mName;
}

/**
 * \brief Get type.
 */
UFsFileTypeCodeT UFsFileT::Type()
{
    return mType;
}

/**
 * \brief Remove file.
 *
 * @param aLv If aLv == 0, all file in this directory will be deleted;
 *            If aLv >= 1, it will be only delete less than "aLv" deepth files.
 *            If aLv < 0, it will be nothing to do.
 */
UErrCodeT UFsFileT::Rm(const UIntT aLv)
{
    return mFile->Rm(&mName, aLv);
}
