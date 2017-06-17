/******************************************************************************
 * $Id: gsl_base.hpp 2017-05 $
 *
 * Project:  GSL (GSL: Gnu Science Library).
 * Purpose:  Gsl base definition.
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

#ifndef GSL_BASE_HPP_INCLUDED
#define GSL_BASE_HPP_INCLUDED

#include "hub_base.h"

#define GSL_LIB HUB_LIB

/**
 * \brief Block
 */
typedef struct
{
    UIntT size;
    UFloatT *data;
} GslBlockT;
typedef UHandleT GslBlockHT;

/**
 * \brief Vector.
 */
typedef struct
{
    UIntT size;
    UIntT stride;
    UFloatT *data;
    GslBlockT *block;
    int owner;
} GslVectorT;
typedef UHandleT GslVectorHT;

#endif  // GSL_BASE_HPP_INCLUDED
