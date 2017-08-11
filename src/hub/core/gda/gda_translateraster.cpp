/******************************************************************************
 * $Id: gda_translateraster.hpp 2017-08 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Translate raster implementation.
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

#include "gda_translateraster.hpp"

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

/**
 * \brief Constructor.
 */
CGdaTranslateRaster::CGdaTranslateRaster()
{
    BMD_POINTER_INIT(mType);
}

/**
 * \brief Destructor.
 */
CGdaTranslateRaster::~CGdaTranslateRaster()
{
    BMD_POINTER_INIT(mType);
}

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CGdaTranslateRaster::Init()
{
    GDA_TYPE_CTL(mType);

    return UErrFalse;
}

/**
 * \brief To raster.
 *
 * @param aFile Destination of file.
 * @param aSrcDsCtl Source dataset controler.
 * @param aOpt Gda translate raster options.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CGdaTranslateRaster::ToRst(const UStringT *aFile,
                                     CGdaDatasetCtl *aSrcDsCtl,
                                     const GdaTranslateR2ROptT *aOpt)
{
    GdaDatasetHT srcDsH = aSrcDsCtl->Handle();

    return Translate(aFile, srcDsH, aOpt);
}

/***** Private A *****/

/**
 * \brief Translate.
 */
UErrCodeT CGdaTranslateRaster::Translate(const UStringT *aFile,
                                         GdaDatasetHT aSrcDsH,
                                         const GdaTranslateR2ROptT *aOpt)
{
    char *dstFile = (char *) aFile->ToA();
    GDALDatasetH dsH = aSrcDsH;
    GDALTranslateOptions *opt = NULL;
    NewR2ROpt((GdaTranslateR2ROptHT *) &opt, aOpt);
    int err;
    GDALTranslate(dstFile, dsH, opt, &err);
    DelR2ROpt((GdaTranslateR2ROptHT) opt);
    if (err == TRUE)
    {
        return UErrFalse;
    }

    return UErrTrue;
}

/**
 * \brief New raster options.
 */
UErrCodeT CGdaTranslateRaster::NewR2ROpt(GdaTranslateR2ROptHT *aDst,
                                         const GdaTranslateR2ROptT *aSrc)
{
    GDALTranslateOptionsForBinary *optForBin = NULL;
    UStringT dst;
    ToR2ROpt(&dst, aSrc);
    GdaArgvT argv;
    mType->NewArgv(&argv, &dst);

    *aDst = (GdaTranslateR2ROptHT) GDALTranslateOptionsNew((char **) argv,
                                                           optForBin);

    mType->DelArgv(argv);

    return UErrFalse;
}

/**
 * \brief Del raster options.
 */
UErrCodeT CGdaTranslateRaster::DelR2ROpt(const GdaTranslateR2ROptHT aOpt)
{
    GDALTranslateOptionsFree((GDALTranslateOptions *) aOpt);

    return UErrFalse;
}

/**
 * \brief To raster options.
 */
UErrCodeT CGdaTranslateRaster::ToR2ROpt(GdaTranslateR2ROptT *aDst,
                                        const GdaR2RCreateOptT *aSrc)
{
    // aDst->format = aSrc->format;
    // aDst->type = aSrc->type;

    return UErrFalse;
}

/**
 * \brief To raster options.
 */
UErrCodeT CGdaTranslateRaster::ToR2ROpt(UStringT *aDst,
                                        const GdaTranslateR2ROptT *aSrc)
{
    if (aSrc->format != GdaFormatNone)
    {
        const UStringT format = " -of ";
        UStringT formatVal;
        mType->ToFormat(&formatVal, aSrc->format);
        *aDst += format;
        *aDst += formatVal;
    }

    if (aSrc->type != UDataTNone)
    {
        const UStringT type = " -ot ";
        UStringT typeVal;
        mType->ToDataType(&typeVal, aSrc->type);
        *aDst += type;
        *aDst += typeVal;
    }

    const UStringT band = " -b ";
    // const UIntT bandCount = aSrc->bandCount;
    // for (UIntT i = 0; i < bandCount; ++i)
    // {
    //     *aDst += band;
    //     *aDst += aSrc->bandList[i];
    // }

    // Create options: " -co ".
    UStringT createOptVal;
    if (mType->ToGdaCreateOpt(&createOptVal, (GdaCreateOptHT) &aSrc->createOpt,
                              aSrc->format) == UErrFalse)
    {
        *aDst += createOptVal;
    }

    // const UStringT quiet = " -q ";
    // *aDst += quiet;

    return UErrFalse;
}

/***** Private B *****/
