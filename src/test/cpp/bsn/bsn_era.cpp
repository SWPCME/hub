/******************************************************************************
 * $Id: bsn_era.cpp 2017-11 $
 *
 * Project:  Business Logic library.
 * Purpose:  Test era api implementation.
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

#include "bsn_era.hpp"

// hub
#include "base_macrodefn.hpp"
// ust
#include "ust_stringtype.hpp"
// era
#include "era_ctl.hpp"
#include "era_tscctl.hpp"

/**
 * \brief Constructor.
 */
CBsnEra::CBsnEra()
{
    BMD_POINTER_INIT(mEra);
}

/**
 * \brief Destructor.
 */
CBsnEra::~CBsnEra()
{
    BMD_POINTER_INIT(mEra);
}

/**
 * \brief Initialize.
 */
UErrCodeT CBsnEra::Init()
{
    BMD_MODULE(mEra, CEraCtl, HubMEra);

    return UErrFalse;
}

/**
 * \brief Test.
 */
UErrCodeT CBsnEra::Test()
{
    CEraTscCtl *tscCtl = mEra->Tsc();
    BTimeTmT date;
    date.year = 2017;
    date.mon = 1;
    date.mday = 1;
    UFloatT jd = tscCtl->Cal2Jd(&date);
    UStringT jdStr(jd);
    jdStr.ToConsole();

    return UErrFalse;
}
