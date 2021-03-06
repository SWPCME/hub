/******************************************************************************
 * $Id: base_graphtype.hpp 2017-12 $
 *
 * Project:  Base.
 * Purpose:  Base graph type definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-12 ~ 2017 Weiwei Huang
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

#ifndef BASE_GRAPHTYPE_HPP_INCLUDE
#define BASE_GRAPHTYPE_HPP_INCLUDE

#include "hub_base.h"

class HUB_LIB BGraphRgbaT
{
  public:
    BGraphRgbaT();
    ~BGraphRgbaT();

    UErrCodeT Init();

    // Set value.
    UErrCodeT SetAll(const UIntT aRed, const UIntT aGreen, const UIntT aBlue,
                     const UFloatT aAlpha);

    // Get value.
    UErrCodeT All(UIntT *aRed, UIntT *aGreen, UIntT *aBlue, UFloatT *aAlpha) const;
    UIntT Red() const;
    UIntT Green() const;
    UIntT Blue() const;
    UFloatT Alpha() const;

  protected:
  private:
    UIntT mRed;
    UIntT mGreen;
    UIntT mBlue;
    UFloatT mAlpha;
};

#endif  // BASE_GRAPHTYPE_HPP_INCLUDE
