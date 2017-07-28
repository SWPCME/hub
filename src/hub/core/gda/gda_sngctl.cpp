/******************************************************************************
 * $Id: gda_sngctl.cpp 2017-07 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Singleton controler definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-05 ~ 2017, Weiwei Huang
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

#include "gda_sngctl.hpp"

// base
#include "base_macrodefn.hpp"
// gda
#include "gda_snglockctl.hpp"

/**
 * \brief Constructor.
 */
CGdaSngCtl::CGdaSngCtl()
{
    BMD_POINTER_INIT(mLock);
}

/**
 * \brief Destructor.
 */
CGdaSngCtl::~CGdaSngCtl()
{
    BMD_CLASS_DEL(mLock);
}

/**
 * \brief Initialize.
 */
UErrCodeT CGdaSngCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Lock controler.
 */
CGdaSngLockCtl *CGdaSngCtl::Lock()
{
    BMD_CLASS_NEW(mLock, CGdaSngLockCtl);

    return mLock;
}
