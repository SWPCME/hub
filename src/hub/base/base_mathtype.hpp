/******************************************************************************
 * $Id: base_mathtype.hpp 2016-08 $
 *
 * Project:  Base.
 * Purpose:  Base math type.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016 ~ 2017 Weiwei Huang
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

#ifndef BASE_MATHTYPE_HPP_INCLUDED
#define BASE_MATHTYPE_HPP_INCLUDED

/**
 * \brief Numeric type.
 */
typedef enum
{
    BMathNumInt   = 1,          // Int.
    BMathNumFloat = 2,          // Float.
} BMathNumCodeT;

/**
 * \brief Number.
 */
typedef enum
{
    BMathNumSignNeg  = -1,
    BMathNumSignNull = 0,
    BMathNumSignPos  = 1,
} BMathNumSignCodeT;

/**
 * \brief Block
 */
typedef struct
{
    UIntT size;
    UFloatT *data;
} BMathBlockT;

/**
 * \brief Vector.
 */
typedef struct
{
    UIntT size;
    UIntT stride;
    UFloatT *data;
    BMathBlockT block;
    int owner;
} BMathVectorT;

/**
 * \brief Coordinate system with surface.
 */
typedef struct
{
    UFloatT x;
    UFloatT y;
} BMathCsC2dT;

/**
 * \brief Coordinate system with space.
 */
typedef struct
{
    UFloatT x;
    UFloatT y;
    UFloatT z;
} BMathCsC3dT;

#endif  // BASE_MATHTYPE_HPP_INCLUDED
