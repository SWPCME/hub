/******************************************************************************
 * $Id: ust_fsctl.hpp 2018-01 $
 *
 * Project:  Universal structure library.
 * Purpose:  File system controler implemention.
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

#include "ust_fsctl.hpp"

// base
#include "base_macrodefn.hpp"
// ust
#include "ust_fsfilectl.hpp"

/**
 * \brief Constructor.
 */
CUstFsCtl::CUstFsCtl()
{
    BMD_POINTER_INIT(mFile);
}

/**
 * \brief Destructor.
 */
CUstFsCtl::~CUstFsCtl()
{
    BMD_CLASS_DEL(mFile);
}

/**
 * \brief Initialize.
 */
UErrCodeT CUstFsCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief File controler.
 */
CUstFsFileCtl *CUstFsCtl::File()
{
    BMD_CLASS_NEW(mFile, CUstFsFileCtl);

    return mFile;
}
