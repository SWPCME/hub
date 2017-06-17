/******************************************************************************
 * $Id: gsl_driverctl_cpp.hpp 2017-05 $
 *
 * Project:  GSL (GSL: Gnu Scientific Library).
 * Purpose:  Gsl controler definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016 ~ 2017, Weiwei Huang
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

#ifndef GSL_DRIVERCTL_CPP_HPP_INCLUDED
#define GSL_DRIVERCTL_CPP_HPP_INCLUDED

#include "gsl_driverctl.hpp"

/**
 * \brief Constructor.
 */
template <typename NumT>
CGslDriverCtl<NumT>::CGslDriverCtl()
{
    mGroup.vector = new CGslVectorCtl<NumT>;
}

/**
 * \brief Destructor.
 */
template <typename NumT>
CGslDriverCtl<NumT>::~CGslDriverCtl()
{
    delete mGroup.vector;
}

/**
 * \brief Initialize.
 */
template <typename NumT>
UErrCodeT CGslDriverCtl<NumT>::Init(BMathNumCodeT aCode)
{
    mGroup.vector->Init(aCode, &mConvert);

    return UErrFalse;
}

/**
 * \brief Group.
 */
template <typename NumT>
GslGroupT<NumT> *CGslDriverCtl<NumT>::Group()
{
    return &mGroup;
}

#endif  // GSL_DRIVERCTL_CPP_HPP_INCLUDED
