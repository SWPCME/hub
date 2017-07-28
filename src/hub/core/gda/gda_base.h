/******************************************************************************
 * $Id: gda_base.h 2017-05 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Gda base info.
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

#ifndef GDA_BASE_H_INCLUDED
#define GDA_BASE_H_INCLUDED

#include "hub_base.h"
/* base */
#include "base_macrodefn.hpp"
/* ust */
#include "ust/ust_stringtype.hpp"

#define GDA_LIB HUB_LIB

/**
 * Gda raster formats. 
 * "F" means format.
 */
#define GDA_F_COUNT 4
// AAIGrid: Arc/Info ASCII Grid (.asc).
#define GDA_F_ASC        "AAIGrid"
#define GDA_F_ASC_SUFFIX "asc"
// LCP: FARSITE v.4 Landscape File (.lcp).
#define GDA_F_LCP        "LCP"
#define GDA_F_LCP_SUFFIX "lcp"
// USGSDEM: USGS Optional ASCII DEM (and CDED) (.dem)
#define GDA_F_DEM        "USGSDEM"
#define GDA_F_DEM_SUFFIX "dem"
// GTiff: GeoTIFF (.tif)
#define GDA_F_TIF        "GTiff"
#define GDA_F_TIF_SUFFIX "tif"

typedef enum
{
    GdaFormatAsc = 1,           /* Arc/Info ASCII Grid. */
    GdaFormatLcp = 2,           /* FARSITE v.4 Landscape File. */
    GdaFormatDem = 3,           /* USGSDEM. */
    GdaFormatTif = 4,           /* GTiff. */
} GdaFormatCodeT;

typedef struct
{
    UIntT xSize;                /* Width of raster in pixels. */
    UIntT ySize;                /* Height of raster in pixels. */
    UIntT nBands;               /* Number of bands. */
    UDataTCodeT dataT;          /* Type of raster. */
    char **option;   /* List of driver specific control parameters. */
} GdaDatasetAttrT;

/**
 * \brief Translate options.
 */
typedef struct
{
    GdaFormatCodeT format;
    UDataTCodeT outType;
    UIntT bandCount;
    UIntT *bandList;
} GdaTranslateRstOptT;

/**
 * \brief Handle.
 */
// core
#define GdaDriverHT UHandleT
#define GdaDatasetHT UHandleT
#define GdaRasterBandHT UHandleT
// utils
#define GdaRasterizeOptHT UHandleT
#define GdaTranslateRstOptHT UHandleT
#define GdaTranslateVtrOptHT UHandleT
#define GdaArgvT UHandleT

#define GDA_TYPECTL(aType)                      \
    if (mType == NULL)                          \
    {                                           \
        BMD_CORE_CTL(coreCtl);                  \
        CGdaCtl *gdaCtl = coreCtl->Gda();       \
        aType = gdaCtl->Type();                 \
    }

#endif  /* GDA_BASE_H_INCLUDED */
