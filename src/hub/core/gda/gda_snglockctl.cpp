/******************************************************************************
 * $Id: gda_snglockctl.hpp 2017-07 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Lock control implementation.
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

#include "gda_snglockctl.hpp"

// base
#include "base_macrodefn.hpp"
// gda
#include "gda_snglockdriver.hpp"

/**
 * \brief Constructor.
 */
CGdaSngLockCtl::CGdaSngLockCtl()
{
    BMD_POINTER_INIT(mDriver);
}

/**
 * \brief Destructor.
 */
CGdaSngLockCtl::~CGdaSngLockCtl()
{
    BMD_CLASS_DEL(mDriver);
}

/**
 * \brief Initialize.
 */
UErrCodeT CGdaSngLockCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Driver controler.
 */
CGdaSngLockDriver *CGdaSngLockCtl::Driver()
{
    BMD_CLASS_NEW(mDriver, CGdaSngLockDriver);

    return mDriver;
}
