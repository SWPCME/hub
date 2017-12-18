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

// gda
#include "gda_banddatactl.hpp"

/**
 * \brief Constructor.
 */
CGdaTypeCtl::CGdaTypeCtl()
{
    BMD_POINTER_INIT(mBandData);
}

/**
 * \brief Destructor.
 */
CGdaTypeCtl::~CGdaTypeCtl()
{
    BMD_CLASS_DEL(mBandData);
}

/**
 * \brief Initialize.
 */
UErrCodeT CGdaTypeCtl::Init()
{
    CClsCtl *cls = NULL;
    CLS_CTL(cls);
    mMem = cls->Mem();
    mStr = cls->Str();

    return UErrFalse;
}

/**
 * \brief Band data type controler.
 */
CGdaBandDataCtl *CGdaTypeCtl::BandData()
{
    BMD_CLASS_NEW(mBandData, CGdaBandDataCtl);

    return mBandData;
}

/**
 * \brief Translate UAccessCodeT to GDALAccess.
 */
UErrCodeT CGdaTypeCtl::ToAccess(GDALAccess *aDst, const UAccessCodeT aSrc)
{
    switch (aSrc)
    {
    case UAccessRead:
        *aDst = GA_ReadOnly;
        break;
    case UAccessWrite:
        *aDst = GA_Update;
        break;
    default:
        return UErrTrue;
    }

    return UErrFalse;
}

/**
 * \brief Translate UDataTCodeT to GDALDataType.
 */
UErrCodeT CGdaTypeCtl::ToDataType(GDALDataType *aDst, const UDataTCodeT aSrc)
{
    switch (aSrc)
    {
    case UDataTFloat:
        *aDst = GDT_Float64;
        break;
    case UDataTFloat32:
        *aDst = GDT_Float32;
        break;
    case UDataTInt16:
        *aDst = GDT_Int16;
        break;
    default:
        return UErrTrue;
    }

    return UErrFalse;
}

/**
 * \brief Translate GDALDataType to UDataTCodeT.
 */
UErrCodeT CGdaTypeCtl::ToDataType(UDataTCodeT *aDst, const GDALDataType aSrc)
{
    switch (aSrc)
    {
    case GDT_Float64:
        *aDst = UDataTFloat;
        break;
    case GDT_Float32:
        *aDst = UDataTFloat32;
        break;
    case GDT_Int16:
        *aDst = UDataTInt16;
        break;
    default:
        return UErrTrue;
    }

    return UErrFalse;
}

/**
 * \brief Translate UDataTCodeT to GDALDataType with string.
 */
UErrCodeT CGdaTypeCtl::ToDataType(UStringT *aDst, const UDataTCodeT aSrc)
{
    GDALDataType src;
    ToDataType(&src, aSrc);
    *aDst = GDALGetDataTypeName(src);

    return UErrFalse;
}

/**
 * \brief Translate GDALDataType with string to UDataTCodeT
 */
UErrCodeT CGdaTypeCtl::ToDataType(UDataTCodeT *aDst, const UStringT *aSrc)
{
    GDALDataType src;
    src = GDALGetDataTypeByName(aSrc->ToA());
    ToDataType(aDst, src);

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
 * \brief To gda dem processing format.
 */
UErrCodeT CGdaTypeCtl::ToDemProcFrmt(UStringT *aDst,
                                     const GdaDemProcFrmtCodeT aSrc)
{
    switch (aSrc)
    {
    case GdaDemProcFrmtSlope:
        *aDst = "slope";
        break;
    case GdaDemProcFrmtAspect:
        *aDst = "aspect";
        break;
    default:
        return UErrTrue;
    }

    return UErrFalse;
}

/**
 * \brief To argument value.
 */
UErrCodeT CGdaTypeCtl::NewArgv(GdaArgvT *aDst, const BCtnStringT *aSrc)
{
    if (aSrc == NULL)
    {
        return UErrFalse;
    }

    BItStringT *it = aSrc->Iterator();
    UIntT count = aSrc->Count();
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
 * \brief To argument value.
 * Need to free.
 */
UErrCodeT CGdaTypeCtl::NewArgv(GdaArgvT *aDst, const UStringT *aSrc)
{
    BCtnStringT srcS(UContainerList);
    const UStringT delimiters = " ";
    const UStringT token = "\"";
    UStringT *src = (UStringT *) aSrc;
    src->Split(&srcS, &delimiters, &token);

    NewArgv(aDst, &srcS);

    return UErrFalse;
}

/**
 * \brief Free Argv.
 */
UErrCodeT CGdaTypeCtl::DelArgv(GdaArgvT aArgv)
{
    char **argv = (char **) aArgv;
    if (argv == NULL)
    {
        return UErrFalse;
    }

    while (*argv != NULL)
    {
        mMem->Free((UHandleT) *argv);
        argv++;
    }

    return UErrFalse;
}

/***** Private A *****/
/***** Private B *****/
