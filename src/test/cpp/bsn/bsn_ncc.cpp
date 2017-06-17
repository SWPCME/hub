/******************************************************************************
 * $Id: bsn_ncc.cpp 2017-06 $
 *
 * Project:  Business Logic library.
 * Purpose:  Test ncc control api definition.
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
 *****************************************************************************/

#include "bsn_ncc.hpp"

// Ncc.
#include "ncc_vectortype.hpp"

/**
 * \brief Constructor.
 */
CBsnNcc::CBsnNcc()
{
}

/**
 * \brief Destructor.
 */
CBsnNcc::~CBsnNcc()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CBsnNcc::Init()
{
    return UErrFalse;
}

/**
 * \brief Test.
 */
UErrCodeT CBsnNcc::Test()
{
    UIntT dimSize = 2;
    NccVectorT a;
    a.SetDimSize(dimSize);
    a.SetValue(2,0);
    a.SetValue(1,1);

    NccVectorT b;
    b.SetDimSize(dimSize);
    b.SetValue(1,0);
    b.SetValue(2,1);

    NccVectorT c;
    c = (a * b);
    UFloatT val1;
    c.Value(&val1, 0);
    UFloatT val2;
    c.Value(&val2, 1);

    return UErrFalse;
}
