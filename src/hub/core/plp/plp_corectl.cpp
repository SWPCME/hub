/******************************************************************************
 * $Id: plp_corectl.hpp 2017-11 $
 *
 * Project:  PLP (PLP: PL plot).
 * Purpose:  Plp core controler implementation.
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

#include "plp_corectl.hpp"

// base
#include "base_ctl.hpp"
// core
#include "core_ctl.hpp"
// plp
#include "plp_ctl.hpp"
#include "plp_typectl.hpp"

// PLPLOT
#include "plplot.h"

/**
 * \brief Constructor.
 */
CPlpCoreCtl::CPlpCoreCtl()
{
}

/**
 * \brief Destructor.
 */
CPlpCoreCtl::~CPlpCoreCtl()
{
}

/**
 * \brief Intialize.
 */
UErrCodeT CPlpCoreCtl::Init()
{
    PLP_TYPE_CTL(mType);

    return UErrFalse;
}

/**
 * \brief Initialize PLplot, passing windows/page settings, and the device name.
 */
UErrCodeT CPlpCoreCtl::InitOpt(const UIntT aNX, const UIntT aNY, const PlpDevCodeT aCode)
{
    if (aCode == PlpDevNull)
    {
        plstar(aNX, aNY);

        return UErrFalse;
    }

    UStringT name;
    mType->DevCodeToName(&name, aCode);
    plstart(name.ToA(), aNX, aNY);

    return UErrFalse;
}

/**
 * \brief Set device.
 */
UErrCodeT CPlpCoreCtl::SetDev(const PlpDevCodeT aCode)
{
    UStringT name;
    mType->DevCodeToName(&name, aCode);
    plsdev(name.ToA());

    return UErrFalse;
}

/**
 * \brief Set file name.
 */
UErrCodeT CPlpCoreCtl::SetFName(const UStringT *aName)
{
    plsfnam(aName->ToA());

    return UErrFalse;
}

/**
 * \brief Set stream number.
 * If the data structure for a new stream is unallocated, we allocate it here.
 */
UErrCodeT CPlpCoreCtl::SetStrm(const UIntT aStrm)
{
    plsstrm(aStrm);

    return UErrFalse;
}

/**
 * \brief Get current stream number.
 */
UErrCodeT CPlpCoreCtl::CurStrm(UIntT *aStrm)
{
    plgstrm((PLINT *) aStrm);

    return UErrFalse;
}

/**
 * \brief Creates a new stream and makes it the default.
 */
UErrCodeT CPlpCoreCtl::MkStrm(UIntT *aStrm)
{
    plmkstrm((PLINT *) aStrm);

    return UErrFalse;
}

/**
 * \brief Copies state parameters from the reference stream to the current stream.
 */
UErrCodeT CPlpCoreCtl::CpStrm(const UIntT aStrm, const UIntT aMode)
{
    plcpstrm(aStrm, aMode);

    return UErrFalse;
}

/**
 * \brief End a plotting session for the current stream only.
 */
UErrCodeT CPlpCoreCtl::EndCurStrm()
{
    plend1();

    return UErrFalse;
}

/**
 * \brief End a plotting session for all open streams.
 */
UErrCodeT CPlpCoreCtl::EndAllStrm()
{
    plend();

    return UErrFalse;
}

/**
 * \brief Replays contents of plot buffer to current device/file.
 */
UErrCodeT CPlpCoreCtl::RePlot()
{
    plreplot();

    return UErrFalse;
}
