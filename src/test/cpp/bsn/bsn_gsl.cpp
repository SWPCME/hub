/******************************************************************************
 * $Id: bsn_gsl.cpp 2017-09 $
 *
 * Project:  Business Logic library.
 * Purpose:  Test gsl control api implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-06 ~ 2017, Weiwei Huang
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
#include "hub_modulectl.hpp"
// gsl
#include "gsl_ctl.hpp"
// gsl.vector
#include "gsl_vectorctl.hpp"
#include "gsl_vectorbasectl.hpp"
#include "gsl_vectormemctl.hpp"
#include "gsl_vectoroperctl.hpp"
// gsl.sf
#include "gsl_sfctl.hpp"
#include "gsl_sflegendre.hpp"
#include "gsl_legendreassoc.hpp"
// ust
#include "ust_stringtype.hpp"

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
    if (mHub == NULL)
    {
        mHub = CHubCtl::Hub();
        mModule = mHub->RegModule();
        UStringT tmp = "~/tmp";
        mModule->SetTmpDir(&tmp);
        mModule->Register(HubMGsl);
        mGsl = (CGslCtl *) mModule->Module(HubMGsl);
    }

    return UErrFalse;
}

/**
 * \brief Test.
 */
UErrCodeT CBsnGsl::Test()
{
    TestVector();
    TestSf();

    return UErrFalse;
}

/***** Private A *****/

/**
 * \brief Test vector.
 */
UErrCodeT CBsnGsl::TestVector()
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

/**
 * \brief Test special function.
 */
UErrCodeT CBsnGsl::TestSf()
{
    CGslSfCtl *sfCtl = mGsl->Sf();
    CGslSfLegendre *legendre = sfCtl->Legendre();
    CGslLegendreAssoc *spharm = legendre->Assoc(GslSfLegendreAssocSpharm);
    UIntT lMax = 1;
    UFloatT x = 0;
    UIntT arrayN = 0;
    spharm->ArrayN(&arrayN, lMax);
    UFloatT resultArray[arrayN];
    UStringT strArrayN = arrayN;
    strArrayN.ToConsole();
    spharm->Array(resultArray, lMax, x);

    return UErrFalse;
}

/***** Private B *****/
