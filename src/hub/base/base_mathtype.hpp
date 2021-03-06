/******************************************************************************
 * $Id: base_mathtype.hpp 2017-11 $
 *
 * Project:  Base.
 * Purpose:  Base math type.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016-08 ~ 2017 Weiwei Huang
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

// hub
#include "hub_base.h"

const UIntT kSignNeg = -1;

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
class HUB_LIB BMathCsC2dT
{
  public:
    BMathCsC2dT();
    BMathCsC2dT(const UFloatT aX, const UFloatT aY);
    ~BMathCsC2dT();

    UErrCodeT SetAll(const UFloatT aX, const UFloatT aY);
    UErrCodeT SetX(const UFloatT aX);
    UErrCodeT SetY(const UFloatT aY);

    UErrCodeT All(UFloatT *aX, UFloatT *aY) const;
    UFloatT X() const;
    UFloatT Y() const;

  protected:
  private:
    UErrCodeT Init();

    UFloatT mX;
    UFloatT mY;
};

/**
 * \brief Coordinate system with space.
 */
class HUB_LIB BMathCsC3dT
{
  public:
    BMathCsC3dT();
    BMathCsC3dT(const UFloatT aX, const UFloatT aY, const UFloatT aZ);
    ~BMathCsC3dT();

    UErrCodeT SetAll(const UFloatT aX, const UFloatT aY, const UFloatT aZ);
    UErrCodeT SetX(const UFloatT aX);
    UErrCodeT SetY(const UFloatT aY);
    UErrCodeT SetZ(const UFloatT aZ);

    UErrCodeT All(UFloatT *aX, UFloatT *aY, UFloatT *aZ) const;
    UFloatT X() const;
    UFloatT Y() const;
    UFloatT Z() const;

  protected:
  private:
    UErrCodeT Init();

    UFloatT mX;
    UFloatT mY;
    UFloatT mZ;
};

/**
 * \brief Set region for 2d.
 */
// class HUB_LIB BMathRegion2dT
// {
//   public:
//     BMathRegion2dT();
//     ~BMathRegion2dT();

//     UErrCodeT SetAll(const BMathCsC2dT *aBegin, const BMathCsC2dT *aEnd);

//     UErrCodeT All(BMathCsC2dT *aBegin, BMathCsC2dT *aEnd);

//   protected:
//   private:
// }

/**
 * \brief Spherical coordinate system.
 */
typedef struct
{
    UFloatT r;  // radial distance
    UFloatT p;  // polar angle
    UFloatT a;  // azimuthal angle
} BMathCsST;

#endif  // BASE_MATHTYPE_HPP_INCLUDED
