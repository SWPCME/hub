/******************************************************************************
 * $Id: bsn_gsl.cpp 2017-06 $
 *
 * Project:  Business Logic library.
 * Purpose:  Test gsl control api implementation.
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

#include "bsn_gsl.hpp"

// Hub.
#include "hub_ctl.hpp"
// Gsl.
#include "gsl_ctl.hpp"
#include "gsl_vectorctl.hpp"
#include "gsl_vectorbasectl.hpp"
#include "gsl_vectormemctl.hpp"
#include "gsl_vectoroperctl.hpp"

/**
 * \brief Constructor.
 */
CBsnGsl::CBsnGsl()
{
}

/**
 * \brief Destructor.
 */
CBsnGsl::~CBsnGsl()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CBsnGsl::Init()
{
    CHubCtl *hubCtl = CHubCtl::Hub();
    hubCtl->Register(HubMGsl);
    mGsl = (CGslCtl*) hubCtl->Module(HubMGsl);

    return UErrFalse;
}

/**
 * \brief Test.
 */
UErrCodeT CBsnGsl::Test()
{
    CGslVectorCtl *vectorCtl = mGsl->Vector();
    CGslVectorMemCtl *memCtl = vectorCtl->Mem();
    CGslVectorBaseCtl *baseCtl = vectorCtl->Base();
    CGslVectorOperCtl *operCtl = vectorCtl->Oper();

    GslVectorHT vtr1;
    GslVectorHT vtr2;
    UIntT size = 2;
    memCtl->Alloc(&vtr1, size);
    memCtl->Alloc(&vtr2, size);
    baseCtl->SetValue(1, vtr1, 0);
    baseCtl->SetValue(2, vtr1, 1);
    baseCtl->SetValue(2, vtr2, 0);
    baseCtl->SetValue(1, vtr2, 1);
    GslVectorHT vtr3;
    operCtl->Mul(&vtr3, vtr1, vtr2);
    UFloatT val1;
    UFloatT val2;
    baseCtl->Value(&val1, vtr3, 0);
    baseCtl->Value(&val2, vtr3, 1);
    memCtl->Free(vtr1);
    memCtl->Free(vtr2);
    memCtl->Free(vtr3);

    return UErrFalse;
}
