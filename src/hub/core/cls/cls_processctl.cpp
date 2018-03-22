/******************************************************************************
 * $Id: cls_processctl.hpp 2017-08 $
 *
 * Project:  C language standard library.
 * Purpose:  Process controler definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-08 ~ 2017 Weiwei Huang
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

#include "cls_processctl.hpp"

/**
 * \brief Constructor.
 */
CClsProcessCtl::CClsProcessCtl()
{
}

/**
 * \brief Destructor.
 */
CClsProcessCtl::~CClsProcessCtl()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CClsProcessCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief System.
 */
UErrCodeT CClsProcessCtl::Sys(const UStringT *aCmd)
{
    system(aCmd->ToA());

    return UErrFalse;
}

/**
 * \brief Executing a file.
 */
UErrCodeT CClsProcessCtl::Exec(const UStringT *aFilename,
                               const UStringT *aArgv, ...)
{
    return UErrFalse;
}
