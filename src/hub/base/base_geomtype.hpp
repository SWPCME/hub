/******************************************************************************
 * $Id: base_geomtype.hpp 2017-05 $
 *
 * Project:  Geometry.
 * Purpose:  Geometry type definition.
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

#ifndef BASE_GEOMTYPE_HPP_INCLUDED
#define BASE_GEOMTYPE_HPP_INCLUDED

// Geodetic datum (coordinate system).
typedef struct
{
    UFloatT lon;                // longitude
    UFloatT lat;                // latitude
    UFloatT h;                  // height.
} BGeomCsGdT;

// Earth-centered, earth-fixed (coordinate system).
typedef struct
{
    UFloatT x;                  // X
    UFloatT y;
    UFloatT z;
} BGeomCsEcefT;

// Earth semimajor axis (WGS84) (m)
#define BGEOM_EARTH_R 6378137.0


#endif  // BASE_GEOMTYPE_HPP_INCLUDED
