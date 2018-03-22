/******************************************************************************
 * $Id: era_tscctl.hpp 2017-11 $
 *
 * Project:  ERA (ERA: Essential Routines for Fundamental Astronomy).
 * Purpose:  Time scale and calendar controler implementation.
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

#include "era_tscctl.hpp"

// extra: erfa
#include "erfa.h"

/**
 * \brief Constructor.
 */
CEraTscCtl::CEraTscCtl()
{
}

/**
 * \brief Destructor.
 */
CEraTscCtl::~CEraTscCtl()
{
}

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CEraTscCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Calendar to julian date.
 *
 * @param aDate Set mday, mon and year.
 * @return Julian date.
 */
UFloatT CEraTscCtl::Cal2Jd(const BTimeTmT *aDate, UErrCodeT *aErr)
{
    UFloatT djm0 = 2400000.5;
    UFloatT djm = 0.0;
    UIntT state = eraCal2jd(aDate->year, aDate->mon, aDate->mday, &djm0, &djm);
    UFloatT jd = djm;

    if (aErr != NULL)
    {
        if (state == 0)
        {
            *aErr = UErrFalse;
        }
        else
        {
            *aErr = UErrTrue;
        }
    }

    return jd;
}
