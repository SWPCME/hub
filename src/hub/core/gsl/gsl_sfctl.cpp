/******************************************************************************
 * $Id: gsl_sfctl.hpp 2017-09 $
 *
 * Project:  GSL (GSL: Gnu Scientific Library).
 * Purpose:  Special function controler implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-09 ~ 2017, Weiwei Huang
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

#include "gsl_sfctl.hpp"

// gsl
#include "gsl_sflegendre.hpp"
// GSL
#include "gsl_sf_legendre.h"

/**
 * \brief Constructor.
 */
CGslSfCtl::CGslSfCtl()
{
    BMD_POINTER_INIT(mLegendre);
}

/**
 * \brief Destructor.
 */
CGslSfCtl::~CGslSfCtl()
{
    BMD_CLASS_DEL(mLegendre);
}

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CGslSfCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Legendre.
 */
CGslSfLegendre *CGslSfCtl::Legendre()
{
    BMD_CLASS_NEW(mLegendre, CGslSfLegendre);

    return mLegendre;
}
