/******************************************************************************
 * $Id: plp_legendannottype.cpp 2017-12 $
 *
 * Project:  PLP (PLP: PL plot).
 * Purpose:  Plp legend annotated type implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-12 ~ 2017, Weiwei Huang
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

#include "plp_legendannottype.hpp"

/**
 * \brief Constructor.
 */
PlpLegendAnnotT::PlpLegendAnnotT() : mText(UContainerList)
{
}

/**
 * \brief Destructor.
 */
PlpLegendAnnotT::~PlpLegendAnnotT()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT PlpLegendAnnotT::Init()
{
    return UErrFalse;
}

/**
 * \brief Set amount of legend entries.
 */
// UErrCodeT PlpLegendAnnotT::SetAmount(const UIntT aAmount)
// {
//     mAmount = aAmount;

//     return UErrFalse;
// }

/**
 * \brief Set text.
 */
UErrCodeT PlpLegendAnnotT::SetText(const BCtnStringT *aText)
{
    mText.Clear();
    mText = *aText;

    return UErrFalse;
}

/**
 * \brief Text.
 */
BCtnStringT *PlpLegendAnnotT::Text() const
{
    return &mText;
}

/***** Private A *****/
/***** Private B *****/
