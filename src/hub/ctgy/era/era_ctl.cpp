/******************************************************************************
 * $Id: era_ctl.hpp 2017-11 $
 *
 * Project:  ERA (ERA: Essential Routines for Fundamental Astronomy).
 * Purpose:  Era controler implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-11 ~ 2017, Weiwei Huang
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

#include "era_ctl.hpp"

#include "era_tscctl.hpp"

// base
#include "base_macrodefn.hpp"

/**
 * \brief Constructor.
 */
CEraCtl::CEraCtl()
{
    BMD_POINTER_INIT(mTsc);
}

/**
 * \brief Destructor.
 */
CEraCtl::~CEraCtl()
{
    BMD_CLASS_DEL(mTsc);
}

/**
 * \brief Initialize.
 */
UErrCodeT CEraCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Time scale and calendar tools.
 */
CEraTscCtl *CEraCtl::Tsc()
{
    BMD_CLASS_NEW(mTsc, CEraTscCtl);

    return mTsc;
}
