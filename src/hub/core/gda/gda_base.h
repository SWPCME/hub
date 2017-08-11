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
    GdaFormatNone = 0,          /* None. */
    GdaFormatAsc  = 1,          /* Arc/Info ASCII Grid. */
    GdaFormatLcp  = 2,          /* FARSITE v.4 Landscape File. */
    GdaFormatDem  = 3,          /* USGSDEM. */
    GdaFormatTif  = 4,          /* GTiff. */
    GdaFormatVrt  = 5,          /* Virtual Raster. */
} GdaFormatCodeT;

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
 * \brief Translate vector to vector option.
 */
typedef struct
{
    OgrFormatCodeT format;
} GdaTranslateV2VOptT;

/** 
 * \brief Vector to raster with attribute of vector.
 */
typedef struct
{
    UStringT layerName;         /* layer name */
    UStringT fieldName;         /* field name */
} GdaV2RVtrAttrT;
typedef UContainerT<GdaV2RVtrAttrT> GdaV2RVtrAttrCtnT;
typedef UIteratorT<GdaV2RVtrAttrT> GdaV2RVtrAttrItT;

/** 
 * \brief Vector to raster with attribute of raster.
 */
typedef struct
{
    UIntT bandId;               /* band index */
} GdaV2RRstAttrT;
typedef UContainerT<GdaV2RRstAttrT> GdaV2RRstAttrCtnT;
typedef UIteratorT<GdaV2RRstAttrT> GdaV2RRstAttrItT;

/** 
 * \brief Size of raster.
 */
typedef struct
{
    UIntT width;
    UIntT height;
} GdaRasterSizeT;

/** 
 * \brief Translate vector to raster options.
 */
class GdaTranslateV2ROptT
{
  public:
    GdaFormatCodeT format;
    UDataTCodeT type;
    GdaRasterSizeT size;      /* Output size with width and height. */
    GdaV2RVtrAttrCtnT vtrCtn; /* Vector attribute container. */
    GdaV2RRstAttrCtnT rstCtn; /* Raster attribute container. */

    GdaTranslateV2ROptT() : vtrCtn(UContainerList), rstCtn(UContainerList)
    {
        format = GdaFormatNone;
        type = UDataTNone;
        size.width = 0;
        size.height = 0;
    }

    ~GdaTranslateV2ROptT() {}
};

/** 
 * \brief Translate vector to raster options with load.
 */
class GdaV2RLoadOptT
{
  public:
    GdaV2RVtrAttrCtnT vtrCtn;   /* Vector attribute container. */
    GdaV2RRstAttrCtnT rstCtn;   /* Raster attribute container. */

    GdaV2RLoadOptT() : vtrCtn(UContainerList), rstCtn(UContainerList) {}
    ~GdaV2RLoadOptT() {}
};

/** 
 * \brief Translate vector to raster options with create.
 */
class GdaV2RCreateOptT
{
  public:
    GdaFormatCodeT format;
    UDataTCodeT type;
    GdaRasterSizeT size;      /* Output size with width and height. */
    GdaV2RVtrAttrT vtrAttr;   /* Vector attribute. */

    GdaV2RCreateOptT()
    {
        format = GdaFormatNone;
        type = UDataTNone;
        size.width = 0;
        size.height = 0;
    }

    ~GdaV2RCreateOptT() {}
};

/** 
 * \brief Landscape band.
 */
typedef struct
{
    UIntT elevation;
    UIntT slope;
    UIntT aspect;
    UIntT fuelModels;
    UIntT canopyCover;
} GdaLcpBandT;

/** 
 * \brief Landscape create options.
 */
typedef struct
{
    GdaLcpBandT band;

    /* Create operation. */
    UIntT latitude;
    GdaLinearUnitCodeT linearUnit;
} GdaR2RLcpCreateOptT;

/** 
 * \brief Translate raster to raster options.
 */
typedef struct
{
    GdaFormatCodeT format;
    UDataTCodeT type;
    union
    {
        GdaR2RLcpCreateOptT createOpt;
    };
} GdaTranslateR2ROptT;

/** 
 * \brief Translate raster.
 */
typedef struct
{
    GdaFormatCodeT format;
    UDataTCodeT outType;
    union
    {
        GdaR2RLcpCreateOptT createOpt;
    };
} GdaR2RCreateOptT;

#define GDA_TYPE_CTL(aCtl)                      \
    if (aCtl == NULL)                           \
    {                                           \
        BMD_CORE_CTL(coreCtl);                  \
        CGdaCtl *gdaCtl = coreCtl->Gda();       \
        aCtl = gdaCtl->Type();                  \
    }

#endif  /* GDA_BASE_H_INCLUDED */
