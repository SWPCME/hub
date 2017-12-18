/******************************************************************************
 * $Id: gda_base.h 2017-08 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Gda base info.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016-08 ~ 2017, Weiwei Huang
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
#include "base_mathtype.hpp"
#include "base_macrodefn.hpp"
/* ust */
#include "ust/ust_stringtype.hpp"
#include "ust/ust_containertype.hpp"
/* ogr */
#include "ogr/ogr_base.h"

#define GDA_LIB HUB_LIB

/**
 * \brief Container.
 */
class CGdaDatasetCtl;
typedef UContainerT<CGdaDatasetCtl*> GdaCtnDatasetT;
typedef UIteratorT<CGdaDatasetCtl*> GdaItDatasetT;

/** 
 * \brief Handle.
 */
// core
#define GdaDriverHT UHandleT
#define GdaDatasetHT UHandleT
#define GdaBandHT UHandleT
#define GdaBandColorHT UHandleT
#define GdaCreateOptHT UHandleT
// utils
#define GdaRasterizeOptHT UHandleT
#define GdaTranslateR2ROptHT UHandleT
#define GdaTranslateV2VOptHT UHandleT
#define GdaTranslateV2ROptHT UHandleT
#define GdaArgvT UHandleT
#define GdaDemProcHT UHandleT
#define GdaTrVtrProcHT UHandleT
#define GdaTrRstProcHT UHandleT

/** 
 * Gda raster formats. 
 * "F" means format.
 */
#define GDA_F_COUNT 5
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
// VRT: Virtual Raster (.vrt)
#define GDA_F_VRT        "VRT"
#define GDA_F_VRT_SUFFIX "vrt"

typedef enum
{
    // 0 ~ 99 for raster format.
    GdaFormatNRst = 0,          /* None raster. */
    GdaFormatAsc  = 1,          /* Arc/Info ASCII Grid. */
    GdaFormatLcp  = 2,          /* FARSITE v.4 Landscape File. */
    GdaFormatDem  = 3,          /* USGSDEM. */
    GdaFormatTif  = 4,          /* GTiff. */
    GdaFormatVrt  = 5,          /* Virtual Raster. */

    // 100 ~ 199 for vector formt.
    GdaFormatNVtr   = 100,      /* None vector. */
    GdaFormatTab    = 101,
    GdaFormatShp    = 102,
    GdaFormatCsv    = 103,
    GdaFormatXls    = 104,
    GdaFormatXlsx   = 105,
    GdaFormatSqlite = 106,
    GdaFormatJson   = 107,
} GdaFormatCodeT;

typedef enum
{
    GdaFrmtFlagNone = 0,        /* None. */
    GdaFrmtFlagRst  = 1,        /* Raster format. */
    GdaFrmtFlagVtr  = 2,        /* Vector format. */
} GdaFrmtFlagCodeT;

/** 
 *  Dataset of attribute.
 */
typedef struct
{
    UIntT xSize;                /* Width of raster in pixels. */
    UIntT ySize;                /* Height of raster in pixels. */
    UIntT nBands;               /* Number of bands. */
    UDataTCodeT dataT;          /* Type of raster. */
    char **option;   /* List of driver specific control parameters. */
} GdaDatasetAttrT;

/** 
 * \brief Linear unit.
 */
typedef enum
{
    GdaLinearUnitDefault   = 1,
    GdaLinearUnitMeter     = 2,
    GdaLinearUnitFoot      = 3,
    GdaLinearUnitKilometer = 4,
} GdaLinearUnitCodeT;

/**
 * \brief Gdal utils dem processing format.
 */
typedef enum
{
    GdaDemProcFrmtSlope  = 1,
    GdaDemProcFrmtAspect = 2,
} GdaDemProcFrmtCodeT;

/** 
 * \brief Size of raster.
 */
typedef struct
{
    UIntT width;
    UIntT height;
} GdaRasterSizeT;

#define GDA_CTL(aCtl)                           \
    if (aCtl == NULL)                           \
    {                                           \
        BMD_CORE_CTL(coreCtl);                  \
        aCtl = coreCtl->Gda();                  \
    }

#define GDA_TYPE_CTL(aCtl)                       \
    if (aCtl == NULL)                            \
    {                                            \
        CGdaCtl *gdaCtl = NULL;                  \
        GDA_CTL(gdaCtl);                         \
        aCtl = gdaCtl->Type();                   \
    }

#define GDA_CORE_CTL(aCtl)                      \
    if (aCtl == NULL)                           \
    {                                           \
        CGdaCtl *gdaCtl = NULL;                 \
        GDA_CTL(gdaCtl);                        \
        aCtl = gdaCtl->Core();                  \
    }

#define GDA_UTILS_CTL(aCtl)                     \
    if (aCtl == NULL)                           \
    {                                           \
        CGdaCtl *gdaCtl = NULL;                 \
        GDA_CTL(gdaCtl);                        \
        aCtl = gdaCtl->Utils();                 \
    }

#endif  /* GDA_BASE_H_INCLUDED */
