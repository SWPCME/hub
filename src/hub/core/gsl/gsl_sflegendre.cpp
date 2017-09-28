/******************************************************************************
 * $Id: gsl_sflegendre.cpp 2017-09 $
 *
 * Project:  GSL (GSL: Gnu Scientific Library).
 * Purpose:  Legendre controler implementation.
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

#include "gsl_sflegendre.hpp"

// gsl
#include "gsl_legendreassoc.hpp"

/**
 * \brief Constructor.
 */
CGslSfLegendre::CGslSfLegendre()
{
    BMD_POINTER_INIT(mAssoc);
}

/**
 * \brief Destructor.
 */
CGslSfLegendre::~CGslSfLegendre()
{
    BMD_CLASS_DEL(mAssoc);
}

/**
 * \brief Initialize.
 */
UErrCodeT CGslSfLegendre::Init()
{
    return UErrFalse;
}

/**
 * \brief Associated legendre polynomials.
 */
CGslLegendreAssoc *CGslSfLegendre::Assoc(GslSfLegendreAssocCodeT aCode)
{
    BMD_CLASS_NEW_A_1(mAssoc, CGslLegendreAssoc, aCode);

    return mAssoc;
}
