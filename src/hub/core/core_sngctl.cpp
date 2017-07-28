/******************************************************************************
 * $Id: core_sngctl.cpp 2017-07 $
 *
 * Project:  Core library.
 * Purpose:  Singleton controler implemention.
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

#include "core_sngctl.hpp"

// base
#include "base_macrodefn.hpp"
// module
#include "gda_sngctl.hpp"

/**
 * \brief Constructor.
 */
CCoreSngCtl::CCoreSngCtl()
{
    BMD_POINTER_INIT(mGda);
}

/**
 * \brief Destructor.
 */
CCoreSngCtl::~CCoreSngCtl()
{
    BMD_CLASS_DEL(mGda);
}

/**
 * \brief Initialize.
 */
UErrCodeT CCoreSngCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Gda.
 */
CGdaSngCtl *CCoreSngCtl::Gda()
{
    BMD_CLASS_NEW(mGda, CGdaSngCtl);

    return mGda;
}
