/******************************************************************************
 * $Id: gda_translatevector.cpp 2017-08 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Translate vector implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-07 ~ 2017, Weiwei Huang
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

#include "gda_translatevector.hpp"

// GDAL
#include "gdal_utils.h"

// base
#include "base_ctl.hpp"
// core
#include "core_ctl.hpp"
// gda
#include "gda_ctl.hpp"
#include "gda_typectl.hpp"
#include "gda_datasetctl.hpp"
#include "gda_bandctl.hpp"
// ogr
#include "ogr_ctl.hpp"
#include "ogr_typectl.hpp"
#include "ogr_datasrcctl.hpp"
#include "ogr_layerctl.hpp"

/**
 * \brief Constructor.
 */
CGdaTranslateVector::CGdaTranslateVector()
{
    BMD_POINTER_INIT(mGdaType);
    BMD_POINTER_INIT(mOgrType);
}

/**
 * \brief Destructor.
 */
CGdaTranslateVector::~CGdaTranslateVector()
{
    BMD_POINTER_INIT(mGdaType);
    BMD_POINTER_INIT(mOgrType);
}

/**
 * \brief Initialize.
 */
UErrCodeT CGdaTranslateVector::Init()
{
    GDA_TYPE_CTL(mGdaType);
    OGR_TYPE_CTL(mOgrType);

    return UErrFalse;
}

/**
 * \brief To vector.
 */
UErrCodeT CGdaTranslateVector::ToVtr(const UStringT *aDstFile,
                                     COgrDatasrcCtl *aSrcDs,
                                     const GdaTranslateV2VOptT *aOpt)
{
    GdaDatasetHT dstDsH = NULL;
    GdaDatasetHT srcDsH = aSrcDs->Handle();
    TranslateV2V(aDstFile, dstDsH, srcDsH, aOpt);

    return UErrFalse;
}

/**
 * \brief To raster with options, complex model.
 */
UErrCodeT CGdaTranslateVector::ToRst(CGdaDatasetCtl *aDstDs,
                                     COgrDatasrcCtl *aSrcDs,
                                     const GdaV2RLoadOptT *aOpt)
{
    const UStringT dstFile;
    GdaTranslateV2ROptT opt;
    ToV2ROpt(&opt, aOpt);

    return TranslateV2R(&dstFile, aDstDs, aSrcDs, &opt);
}

/**
 * \brief To raster with options, complex model.
 */
UErrCodeT CGdaTranslateVector::ToRst(const UStringT *aDstFile,
                                     COgrDatasrcCtl *aSrcDs,
                                     const GdaV2RCreateOptT *aOpt)
{
    GdaDatasetHT dstDsH = NULL;
    GdaDatasetHT srcDsH = aSrcDs->Handle();
    GdaTranslateV2ROptT opt;
    ToV2ROpt(&opt, aOpt);

    return TranslateV2R(aDstFile, dstDsH, srcDsH, &opt);
}

/**
 * \brief To raster with only one band, easy model.
 */
UErrCodeT CGdaTranslateVector::ToRst(CGdaBandCtl *aDstBand,
                                     COgrLayerCtl *aSrcLayer,
                                     const UStringT *aSrcFieldName)
{
    UStringT dstFile;
    CGdaDatasetCtl *dstDsCtl = aDstBand->Up();
    GdaDatasetHT dstDsH = dstDsCtl->Handle();
    COgrDatasrcCtl *srcDsCtl = aSrcLayer->Up();
    GdaDatasetHT srcDsH = srcDsCtl->Handle();
    GdaTranslateV2ROptT *opt = NULL;

    return TranslateV2R(&dstFile, dstDsH, srcDsH, opt);
}

/***** Private A *****/

/**
 * \brief Translate vector to vector.
 */
UErrCodeT CGdaTranslateVector::TranslateV2V(const UStringT *aDstFile,
                                            GdaDatasetHT aDstDs,
                                            GdaDatasetHT aSrcDs,
                                            const GdaTranslateV2VOptT *aOpt)
{
    const char *dstFile = aDstFile->ToA();
    GDALDatasetH dstDsH = (GdaDatasetHT) aDstDs;
    const int kSrcCount = 1;
    GDALDatasetH srcDsH[kSrcCount] = {(GdaDatasetHT) aSrcDs};
    GDALVectorTranslateOptions *opt = NULL;
    NewV2VOpt((GdaTranslateV2VOptHT *) &opt, aOpt);
    int err;
    dstDsH = (GdaDatasetHT) GDALVectorTranslate(dstFile, dstDsH,
                                                kSrcCount, srcDsH,
                                                opt, &err);
    DelV2VOpt((GdaTranslateV2VOptHT) opt);
    if (err == CE_None)
    {
        return UErrFalse;
    }

    return UErrTrue;
}

/**
 * \brief New vector translate options.
 */
UErrCodeT CGdaTranslateVector::NewV2VOpt(GdaTranslateV2VOptHT *aDst,
                                         const GdaTranslateV2VOptT *aSrc)
{
    GdaArgvT argv = NULL;
    GDALVectorTranslateOptionsForBinary *optForBin = NULL;
    UStringT dst;
    ToV2VOpt(&dst, aSrc);
    mGdaType->NewArgv(&argv, &dst);
    *aDst = (GdaTranslateV2VOptHT) GDALVectorTranslateOptionsNew
        ((char **) argv, optForBin);
    mGdaType->DelArgv(argv);

    return UErrFalse;
}

/**
 * \brief Free vector translate options.
 */
UErrCodeT CGdaTranslateVector::DelV2VOpt(const GdaTranslateV2VOptHT aOpt)
{
    GDALVectorTranslateOptionsFree((GDALVectorTranslateOptions *) aOpt);

    return UErrFalse;
}

/**
 * \brief To "vector to vector" options.
 */
UErrCodeT CGdaTranslateVector::ToV2VOpt(UStringT *aDst,
                                        const GdaTranslateV2VOptT *aSrc)
{
    const UStringT kFormat = " -f ";
    UStringT formatValue;
    mOgrType->ToFormat(&formatValue, aSrc->format, UFlagOn);
    *aDst += kFormat;
    *aDst += formatValue;
    *aDst += " -update ";
    *aDst += " -overwrite ";

    return UErrFalse;
}

/**
 * \brief Rasterize, translate vector to raster.
 */
UErrCodeT CGdaTranslateVector::TranslateV2R(const UStringT *aDstFile,
                                            GdaDatasetHT aDstDsH,
                                            GdaDatasetHT aSrcDsH,
                                            const GdaTranslateV2ROptT *aOpt)
{
    char *dstFile = NULL;
    if (aDstFile->IsNull() == UErrTrue)
    {
        dstFile = (char *) aDstFile->ToA();
    }
    GDALDatasetH dstDsH = (GDALDatasetH) aDstDsH;
    GDALDatasetH srcDsH = (GDALDatasetH) aSrcDsH;

    GDALRasterizeOptions *opt = NULL;
    if (aOpt != NULL)
    {
        NewV2ROpt((GdaTranslateV2ROptHT *) &opt, aOpt);
    }

    int err = FALSE;
    GDALRasterize(dstFile, dstDsH, srcDsH, opt, &err);

    if (aOpt != NULL)
    {
        DelV2ROpt((GdaTranslateV2ROptHT) opt);
    }
    if (err == TRUE)
    {
        return UErrFalse;
    }

    return UErrTrue;
}

/**
 * \brief New vector to raster translate options.
 */
UErrCodeT CGdaTranslateVector::NewV2ROpt(GdaTranslateV2ROptHT *aDst,
                                         const GdaTranslateV2ROptT *aSrc)
{
    GdaArgvT argv = NULL;
    UStringT src;
    ToV2ROpt(&src, aSrc);
    mGdaType->NewArgv(&argv, &src);

    GDALRasterizeOptionsForBinary *optForBin = NULL;

    *aDst = (GDALRasterizeOptions *) GDALRasterizeOptionsNew((char **) argv,
                                                             optForBin);
    mGdaType->DelArgv(argv);

    return UErrFalse;
}

/**
 * \brief Free vector to raster translate options.
 */
UErrCodeT CGdaTranslateVector::DelV2ROpt(const GdaTranslateV2ROptHT aOpt)
{
    GDALRasterizeOptionsFree((GDALRasterizeOptions *) aOpt);

    return UErrFalse;
}

/**
 * \brief Translate vector to raster.
 */
UErrCodeT CGdaTranslateVector::ToV2ROpt(GdaTranslateV2ROptT *aDst,
                                        const GdaV2RCreateOptT *aSrc)
{
    aDst->format = aSrc->format;
    aDst->type = aSrc->type;
    aDst->size.width = aSrc->size.width;
    aDst->size.height = aSrc->size.height;
    aDst->vtrCtn.Add(aSrc->vtrAttr);

    return UErrFalse;
}

/**
 * \brief Translate vector to raster.
 */
UErrCodeT CGdaTranslateVector::ToV2ROpt(GdaTranslateV2ROptT *aDst,
                                        const GdaV2RLoadOptT *aSrc)
{
    aDst->vtrCtn = aSrc->vtrCtn;
    aDst->rstCtn = aSrc->rstCtn;

    return UErrFalse;
}

/**
 * \brief Translate vector to raster.
 */
UErrCodeT CGdaTranslateVector::ToV2ROpt(UStringT *aDst,
                                        const GdaTranslateV2ROptT *aSrc)
{
    if (aSrc->format != GdaFormatNone)
    {
        const UStringT format = " -of ";
        UStringT formatVal;
        mGdaType->ToFormat(&formatVal, aSrc->format);
        *aDst += format;
        *aDst += formatVal;
    }

    if (aSrc->type != UDataTNone)
    {
        const UStringT type = " -ot ";
        UStringT typeVal;
        mGdaType->ToDataType(&typeVal, aSrc->type);
        *aDst += type;
        *aDst += typeVal;
    }

    if ((aSrc->size.width != 0) && (aSrc->size.height != 0))
    {
        const UStringT ts = " -ts ";
        UStringT tsVal;
        tsVal += aSrc->size.width;
        tsVal += " ";
        tsVal += aSrc->size.height;
        *aDst += ts;
        *aDst += tsVal;
    }

    GdaV2RVtrAttrCtnT *vtrCtn = (GdaV2RVtrAttrCtnT *) &aSrc->vtrCtn;
    if (vtrCtn->Count() != 0)
    {
        const UStringT layer = " -l ";
        const UStringT field = " -a ";
        GdaV2RVtrAttrItT *it = vtrCtn->Iterator();
        for (it->Head(); it->State() == UErrFalse; it->Next())
        {
            *aDst += layer;
            *aDst += it->Content().layerName;

            *aDst += field;
            *aDst += it->Content().fieldName;
        }
    }

    GdaV2RRstAttrCtnT *rstCtn = (GdaV2RRstAttrCtnT *) &aSrc->rstCtn;
    if (rstCtn->Count() != 0)
    {
        const UStringT band = " -b ";
        GdaV2RRstAttrItT *it = rstCtn->Iterator();
        for (it->Head(); it->State() == UErrFalse; it->Next())
        {
            *aDst += band;
            *aDst += it->Content().bandId;
        }
    }

    // const UStringT createOpt = " -co ";
    // UStringT createOptVal;
    // mGdaType->ToGdaCreateOpt(&createOptVal, (GdaCreateOptHT) &aSrc->createOpt,
    //                       aSrc->format);
    // *aDst += createOpt;
    // *aDst += createOptVal;

    return UErrFalse;
}

/***** Private B *****/
