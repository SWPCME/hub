/******************************************************************************
 * $Id: plp_argsctl.cpp 2017-11 $
 *
 * Project:  PLP (PLP: PL plot).
 * Purpose:  Plp arguments controler implementation.
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

#include "plp_argsctl.hpp"

// PLPLOT
#include "plplot.h"

/**
 * \brief Constructor.
 */
CPlpArgsCtl::CPlpArgsCtl()
{
}

/**
 * \brief Destructor.
 */
CPlpArgsCtl::~CPlpArgsCtl()
{
}

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CPlpArgsCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Parse options.
 */
UErrCodeT CPlpArgsCtl::ParseOpts(BCtnStringT *aStrCtn, const PlpParseCodeT aCode)
{
    int argc = aStrCtn->Count();
    char *argv[argc];
    BItStringT *it = aStrCtn->Iterator();
    it->Head();
    for (int i = 0; i < argc; ++i, it->Next())
    {
        UStringT content = it->Content();
        argv[i] = (char *) content.ToA();
    }

    plparseopts(&argc, argv, (PLINT) aCode);

    return UErrFalse;
}

/**
 * \brief Set option.
 */
UErrCodeT CPlpArgsCtl::SetOpt(const UStringT *aOpt, const UStringT *aArg)
{
    plsetopt(aOpt->ToA(), aArg->ToA());

    return UErrFalse;
}
