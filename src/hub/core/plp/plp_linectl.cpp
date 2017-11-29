/******************************************************************************
 * $Id: plp_linectl.cpp 2017-11 $
 *
 * Project:  PLP (PLP: PL plot).
 * Purpose:  Plp line controler implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-11 ~ 2017, Weiwei Huang
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

#include "plp_linectl.hpp"

// PLPLOT
#include "plplot.h"

/**
 * \brief Constructor.
 */
CPlpLineCtl::CPlpLineCtl()
{
}

/**
 * \brief Destructor.
 */
CPlpLineCtl::~CPlpLineCtl()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CPlpLineCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Line.
 * Draws line segments connecting a series of points.
 */
UErrCodeT CPlpLineCtl::Line(const BCtnMathCsC2dT *aPtrs)
{
    UIntT n = aPtrs->Count();
    UFloatT x[n];
    UFloatT y[n];
    BItMathCsC2dT *it = aPtrs->Iterator();
    it->Head();
    for (UIntT i = 0; i < n; ++i, it->Next())
    {
        x[i] = it->Content().x;
        y[i] = it->Content().y;
    }
    plline(n, x, y);

    return UErrFalse;
}
