/******************************************************************************
 * $Id: plp_colctl.cpp 2017-12 $
 *
 * Project:  PLP (PLP: PL plot).
 * Purpose:  Plp color controler implementation.
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

#include "plp_colctl.hpp"

// PLPLOT
#include "plplot.h"

/**
 * \brief Constructor.
 */
CPlpColCtl::CPlpColCtl()
{
}

/**
 * \brief Destructor.
 */
CPlpColCtl::~CPlpColCtl()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CPlpColCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Set background color.
 *
 * @param aRed, 0 ~ 255.
 * @param aGreen, 0 ~ 255.
 * @param aBlue, 0 ~ 255.
 * @param aAlfa, 0 ~ 1.
 */
UErrCodeT CPlpColCtl::SetBg(const BGraphRgbaT *aRgba)
{
    plscolbga(aRgba->Red(), aRgba->Green(), aRgba->Blue(), aRgba->Alpha());

    return UErrFalse;
}

/**
 * \brief Set foreground color, default map 0, the useful index is set with "SetRgba".
 */
UErrCodeT CPlpColCtl::SetFg(const BGraphRgbaT *aRgba)
{
    SetRgba(aRgba, 0);
    plcol0(1);

    return UErrFalse;
}

/**
 * \brief Set rgba with color index.
 */
UErrCodeT CPlpColCtl::SetRgba(const BGraphRgbaT *aRgba, const UIntT aId)
{
    plscol0a(aId + 1, aRgba->Red(), aRgba->Green(), aRgba->Blue(), aRgba->Alpha());

    return UErrFalse;
}

/**
 * \brief Get rgba with color index.
 */
UErrCodeT CPlpColCtl::Rgba(BGraphRgbaT *aRgba, const UIntT aId)
{
    PLINT red;
    PLINT green;
    PLINT blue;
    PLFLT alpha;
    plgcol0a(aId + 1, &red, &green, &blue, &alpha);
    aRgba->SetAll(red, green, blue, alpha);

    return UErrFalse;
}

/***** Private A *****/
/***** Private B *****/
