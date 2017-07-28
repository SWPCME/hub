/******************************************************************************
 * $Id: gda_translateraster.hpp 2017-07 $
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
 */
UErrCodeT CGdaTranslateRaster::Init()
{
    GDA_TYPECTL(mType);

    return UErrFalse;
}

/**
 * \brief To raster.
 */
UErrCodeT CGdaTranslateRaster::ToRst(const UStringT *aDstPath,
                                     CGdaDatasetCtl *aSrcDsCtl,
                                     const GdaTranslateRstOptT *aOpt)
{
    GdaDatasetHT srcDsH = aSrcDsCtl->Handle();
    Translate(aDstPath, srcDsH, aOpt);

    return UErrFalse;
}

/***** Private A *****/

/**
 * \brief Translate.
 */
UErrCodeT CGdaTranslateRaster::Translate(const UStringT *aFile,
                                         GdaDatasetHT aSrcDsH,
                                         const GdaTranslateRstOptT *aOpt)
{
    char *pszDestFilename = (char *) aFile->ToA();
    GDALDatasetH dsH = aSrcDsH;
    GDALTranslateOptions *opt = NULL;
    NewRstOpt((GdaTranslateRstOptHT *) &opt, aOpt);
    int err;
    GDALTranslate(pszDestFilename, dsH, opt, &err);
    DelRstOpt((GdaTranslateRstOptHT) opt);
    if (err == TRUE)
    {
        return UErrFalse;
    }

    return UErrTrue;
}

/**
 * \brief New raster options.
 */
int TestArgv(char **aArgv)
{
    while( *aArgv != NULL )
    {
        UStringT str(*aArgv);
        str.ToConsole();
        ++aArgv;
    }
    return 0;
}
#include <string.h>
UErrCodeT CGdaTranslateRaster::NewRstOpt(GdaTranslateRstOptHT *aDst,
                                         const GdaTranslateRstOptT *aSrc)
{
    GDALTranslateOptionsForBinary *optForBin = NULL;
    UStringT dst;
    ToRstOpt(&dst, aSrc);
    GdaArgvT argv;
    mType->NewArgv(&argv, &dst);

    *aDst = (GdaTranslateRstOptHT) GDALTranslateOptionsNew((char **) argv, optForBin);

    mType->DelArgv(argv);

    return UErrFalse;
}

/**
 * \brief Del raster options.
 */
UErrCodeT CGdaTranslateRaster::DelRstOpt(const GdaTranslateRstOptHT aOpt)
{
    GDALTranslateOptionsFree((GDALTranslateOptions *) aOpt);

    return UErrFalse;
}

/**
 * \brief To raster options.
 */
UErrCodeT CGdaTranslateRaster::ToRstOpt(UStringT *aDst,
                                        const GdaTranslateRstOptT *aSrc)
{
    const UStringT format = " -of ";
    UStringT formatName;
    mType->ToFormat(&formatName, aSrc->format);
    *aDst += format;
    *aDst += formatName;

    // const UStringT format = " -of ";
    // *aDst += format;
    // *aDst += aSrc->outType;

    const UStringT band = " -b ";
    const UIntT bandCount = aSrc->bandCount;
    for (UIntT i = 0; i < bandCount; ++i)
    {
        *aDst += band;
        *aDst += aSrc->bandList[i];
    }

    // const UStringT quiet = " -q ";
    // *aDst += quiet;

    return UErrFalse;
}

/***** Private B *****/
