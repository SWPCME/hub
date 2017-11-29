/******************************************************************************
 * $Id: plp_symctl.hpp 2017-11 $
 *
 * Project:  PLP (PLP: PL plot).
 * Purpose:  Plp symbol controler implementation.
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

#include "plp_symctl.hpp"

// PLPLOT
#include "plplot.h"

/**
 * \brief Constructor.
 */
CPlpSymCtl::CPlpSymCtl()
{
}

/**
 * \brief Destructor.
 */
CPlpSymCtl::~CPlpSymCtl()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CPlpSymCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Label.
 * Simple routine for labelling graphs.
 */
UErrCodeT CPlpSymCtl::Lab(const UStringT *aXLabel, const UStringT *aYLabel,
                          const UStringT *aTLabel)
{
    pllab(aXLabel->ToA(), aYLabel->ToA(), aTLabel->ToA());

    return UErrFalse;
}
