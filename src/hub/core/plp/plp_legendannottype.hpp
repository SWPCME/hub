/******************************************************************************
 * $Id: plp_legendannottype.hpp 2017-12 $
 *
 * Project:  PLP (PLP: PL plot).
 * Purpose:  Plp legend annotated type definition.
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

#ifndef PLP_LEGENDANNOTTYPE_HPP_INCLUDED
#define PLP_LEGENDANNOTTYPE_HPP_INCLUDED

#include "plp_base.hpp"

// base
#include "base_containerdefn.hpp"

class PLP_LIB PlpLegendAnnotT
{
  public:
    PlpLegendAnnotT();
    ~PlpLegendAnnotT();

    UErrCodeT Init();

    // Set value.
    // UErrCodeT SetAmount(const UIntT aAmount);
    UErrCodeT SetText(const BCtnStringT *aText);

    // Get value.
    BCtnStringT *Text() const;

  protected:
  private:
    UIntT mAmount;
    BCtnStringT mText;
};

#endif  // PLP_LEGENDANNOTTYPE_HPP_INCLUDED
