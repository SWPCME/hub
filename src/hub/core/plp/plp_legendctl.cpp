/******************************************************************************
 * $Id: plp_legendctl.cpp 2017-12 $
 *
 * Project:  PLP (PLP: PL plot).
 * Purpose:  Plp legend controler implementation.
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

#include "plp_legendctl.hpp"

// plp
#include "plp_legendannottype.hpp"

// PLPLOT
#include "plplot.h"

/**
 * \brief Constructor.
 */
CPlpLegendCtl::CPlpLegendCtl()
{
}

/**
 * \brief Destructor.
 */
CPlpLegendCtl::~CPlpLegendCtl()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CPlpLegendCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Legend.
 */
UErrCodeT CPlpLegendCtl::Annot(const PlpLegendAnnotT *aAnnot)
{
    PLFLT legendWidth;
    PLFLT legendHeight;
    PLINT opt = PL_LEGEND_BACKGROUND;
    PLINT position = 0;
    PLFLT x = 0.0;
    PLFLT y = 0.0;
    PLFLT plotWidth = 0.1;
    PLINT bgColor = 15;
    PLINT bbColor = 1;
    PLINT bbStyle = 1;
    PLINT row = 0;
    PLINT column = 0;
    PLFLT textOffset = 1.0;
    PLFLT textScale = 1.0;
    PLFLT textSpacing = 2.0;
    PLFLT textJustification = 1.0;

    // aAnnot.
    BCtnStringT *sText = aAnnot->Text();
    PLINT nLegend = sText->Count();
    UStringT dText[nLegend];
    PLINT textColors[nLegend];
    PLINT optArray[nLegend];
    PLCHAR_VECTOR text[nLegend];
    PLINT lineColors[nLegend];
    PLINT lineStyles[nLegend];
    PLFLT lineWidths[nLegend];
    PLINT symbolColors[nLegend];
    PLFLT symbolScales[nLegend];
    PLINT symbolNumbers[nLegend];
    PLCHAR_VECTOR symbols[nLegend];
    for (UIntT i = 0; i < nLegend; ++i)
    {
        dText[i] = (*sText)[i];
        text[i] = dText[i].ToA();
        textColors[i] = i + 1;
        optArray[i] = PL_LEGEND_LINE;
        lineColors[i] = i + 1;
        lineStyles[i] = 1;
        lineWidths[i] = 1.0;
        symbolColors[i] = i + 1;
        symbolScales[i] = 1.0;
        symbolNumbers[i] = 4;
        symbols[i] = "";
    }

    PLINT_VECTOR boxColors = NULL;
    PLINT_VECTOR boxPatterns = NULL;
    PLFLT_VECTOR boxScales = NULL;
    PLFLT_VECTOR boxLineWidths = NULL;

    c_pllegend(&legendWidth, &legendHeight, opt, position, x, y, plotWidth,
               bgColor, bbColor, bbStyle, row, column, nLegend, optArray,
               textOffset, textScale, textSpacing, textJustification,
               textColors, text, boxColors, boxPatterns, boxScales,
               boxLineWidths, lineColors, lineStyles, lineWidths, symbolColors,
               symbolScales, symbolNumbers, symbols);

    return UErrFalse;
}
