/******************************************************************************
 * $Id: vtr_formatctl.cpp 2017-08 $
 *
 * Project:  Vector Info Process
 * Purpose:  Format controler implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-07 ~ 2017, Weiwei Huang
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

#include "vtr_frmtctl.hpp"

// vtr
#include "vtr_frmtgjson.hpp"

// base
#include "base_macrodefn.hpp"

/**
 * \brief Constructor.
 */
CVtrFrmtCtl::CVtrFrmtCtl()
{
}

/**
 * \brief Destructor.
 */
CVtrFrmtCtl::~CVtrFrmtCtl()
{
}

/**
 * \brief Initialization.
 */
UErrCodeT CVtrFrmtCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief GeoJSON.
 */
CVtrFrmtGjson *CVtrFrmtCtl::Gjson()
{
    BMD_CLASS_NEW(mGjson, CVtrFrmtGjson);

    return mGjson;
}
