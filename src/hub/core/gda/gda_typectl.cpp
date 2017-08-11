/******************************************************************************
 * $Id: gda_typectl.hpp 2017-05 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Gda type control.
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
 ****************************************************************************/

#include "gda_typectl.hpp"

// base
#include "base_ctl.hpp"
// core
#include "core_ctl.hpp"
// cls
#include "cls_ctl.hpp"
#include "cls_stringctl.hpp"
#include "cls_memoryctl.hpp"

/**
 * \brief Constructor.
 */
CGdaTypeCtl::CGdaTypeCtl()
{
}

/**
 * \brief Destructor.
 */
CGdaTypeCtl::~CGdaTypeCtl()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CGdaTypeCtl::Init()
{
    CBaseCtl *baseCtl = CBaseCtl::Base();
    CCoreCtl *coreCtl = baseCtl->Core();
    CClsCtl *clsCtl = coreCtl->Cls();
    mMem = clsCtl->Mem();
    mStr = clsCtl->Str();

    return UErrFalse;
}

/**
 * \brief Translate UAccessCodeT to GDALAccess.
 */
UErrCodeT CGdaTypeCtl::ToAccess(GDALAccess *aDest, const UAccessCodeT aSrc)
{
    switch (aSrc)
    {
    case UAccessRead:
        *aDest = GA_ReadOnly;
        break;
    case UAccessWrite:
        *aDest = GA_Update;
        break;
    default:
        return UErrTrue;
    }

    return UErrFalse;
}

/**
 * \brief Translate UDataTCodeT to GDALDataType.
 */
UErrCodeT CGdaTypeCtl::ToDataType(GDALDataType *aDest, UDataTCodeT aSrc)
{
    switch (aSrc)
    {
    case UDataTFloat:
        *aDest = GDT_Float64;
        break;
    case UDataTInt16:
        *aDest = GDT_Int16;
        break;
    default:
        return UErrTrue;
    }

    return UErrFalse;
}

/**
 * \brief Translate UDataTCodeT to GDALDataType with string.
 */
UErrCodeT CGdaTypeCtl::ToDataType(UStringT *aDst, UDataTCodeT aSrc)
{
    switch (aSrc)
    {
    case UDataTFloat:
        *aDst = "Float64";
        break;
    case UDataTInt16:
        *aDst = "Int16";
        break;
    default:
        return UErrTrue;
    }

    return UErrFalse;
}

/**
 * \brief To format.
 */
UErrCodeT CGdaTypeCtl::ToFormat(UStringT *aDest, const GdaFormatCodeT aSrc)
{
    switch (aSrc)
    {
    case GdaFormatAsc:
        *aDest = GDA_F_ASC;
        break;
    case GdaFormatDem:
        *aDest = GDA_F_DEM;
        break;
    case GdaFormatLcp:
        *aDest = GDA_F_LCP;
        break;
    case GdaFormatTif:
        *aDest = GDA_F_TIF;
        break;
    case GdaFormatVrt:
        *aDest = GDA_F_VRT;
        break;
    default:
        return UErrTrue;
    }

    return UErrFalse;
}

/**
 * \brief To gda create opt.
 */
UErrCodeT CGdaTypeCtl::ToGdaCreateOpt(UStringT *aDst,
                                      const GdaCreateOptHT aSrc,
                                      const GdaFormatCodeT aFormat)
{
    switch (aFormat)
    {
    case GdaFormatLcp:
        ToLcpCreateOpt(aDst, (GdaR2RLcpCreateOptT *) aSrc);
        break;
    default:
        return UErrTrue;
    }

    return UErrFalse;
}

/**
 * \brief To linear unit.
 */
UErrCodeT CGdaTypeCtl::ToLinearUnit(UStringT *aDst,
                                    const GdaLinearUnitCodeT aSrc)
{
    switch (aSrc)
    {
    case GdaLinearUnitDefault:
        *aDst = "SET_FROM_SRS";
        break;
    case GdaLinearUnitMeter:
        *aDst = "METER";
        break;
    case GdaLinearUnitFoot:
        *aDst = "FOOT";
        break;
    case GdaLinearUnitKilometer:
        *aDst = "KILOMETER";
        break;
    default:
        return UErrTrue;
    }

    return UErrFalse;
}

/**
 * \brief To argument value.
 * Need to free.
 */
UErrCodeT CGdaTypeCtl::NewArgv(GdaArgvT *aDst, const UStringT *aSrc)
{
    UContainerT<UStringT> srcS(UContainerList);
    const UStringT delimiters = " ";
    const UStringT token = "\"";
    UStringT *src = (UStringT *) aSrc;
    src->Split(&srcS, &delimiters, &token);

    UIteratorT<UStringT> *it = srcS.Iterator();
    UIntT count = srcS.Count();
    char **argv = (char **) mMem->Alloc(sizeof(char *) * (count + 1));
    argv[count] = NULL;

    it->Head();
    for (UIntT i = 0; it->State() == UErrFalse; it->Next(), ++i)
    {
        UStringT str = it->Content();
        argv[i] = (char *) mMem->Alloc(sizeof(char) * (str.Len() + 1));
        argv[i] = mStr->Cpy(argv[i], str.ToA());
    }

    *aDst = (GdaArgvT) argv;

    return UErrFalse;
}

/**
 * \brief Free Argv.
 */
UErrCodeT CGdaTypeCtl::DelArgv(GdaArgvT aArgv)
{
    char **argv = (char **) aArgv;
    while (*argv != NULL)
    {
        mMem->Free((UHandleT) *argv);
        argv++;
    }

    return UErrFalse;
}

/***** Private A *****/

/**
 * \brief To lcp create options.
 */
UErrCodeT CGdaTypeCtl::ToLcpCreateOpt(UStringT *aDst,
                                      const GdaR2RLcpCreateOptT *aSrc)
{
    // Band.
    const UStringT kBand = " -b ";
    const GdaLcpBandT *bandValue = &aSrc->band;
    *aDst += kBand;
    *aDst += bandValue->elevation;
    *aDst += kBand;
    *aDst += bandValue->slope;
    *aDst += kBand;
    *aDst += bandValue->aspect;
    *aDst += kBand;
    *aDst += bandValue->fuelModels;
    *aDst += kBand;
    *aDst += bandValue->canopyCover;

    // Latitude.
    const UStringT kLatitude = " -co LATITUDE=";
    if ((aSrc->latitude > 90) || (aSrc->latitude < -90))
    {
        return UErrTrue;
    }
    *aDst += kLatitude;
    *aDst += aSrc->latitude;

    // Linear unit.
    const UStringT kLinear = " -co LINEAR_UNIT=";
    UStringT linearUnit;
    ToLinearUnit(&linearUnit, aSrc->linearUnit);
    *aDst += kLinear;
    *aDst += linearUnit;

    // End.
    *aDst += " ";

    return UErrFalse;
}

/***** Private B *****/
