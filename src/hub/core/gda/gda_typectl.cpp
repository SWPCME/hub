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
#include "gda_typeogr.hpp"
#include "gda_banddatactl.hpp"

// GDAL
#include <cpl_string.h>

/**
 * \brief Constructor.
 */
CGdaTypeCtl::CGdaTypeCtl()
{
    BMD_POINTER_INIT(mOgr);
    BMD_POINTER_INIT(mBandData);
}

/**
 * \brief Destructor.
 */
CGdaTypeCtl::~CGdaTypeCtl()
{
    BMD_CLASS_DEL(mOgr);
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
 * \brief Ogr.
 */
CGdaTypeOgr *CGdaTypeCtl::Ogr()
{
    BMD_CLASS_NEW(mOgr, CGdaTypeOgr);

    return mOgr;
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
// UErrCodeT CGdaTypeCtl::ToGdaCreateOpt(UStringT *aDst,
//                                       const GdaCreateOptHT aSrc,
//                                       const GdaFormatCodeT aFormat)
// {
//     switch (aFormat)
//     {
//     case GdaFormatLcp:
//         break;
//     default:
//         return UErrTrue;
//     }

//     return UErrFalse;
// }

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
 * \brief To gda projection coordinate system.
 */
UErrCodeT CGdaTypeCtl::ToProjCs(UStringT *aDst, const GdaProjCsCodeT aSrc)
{
    switch (aSrc)
    {
    case GdaProjCsWgs1984:
        *aDst = "EPSG:4326";        // WGS84
        break;
    case GdaProjCsXian1980:
        *aDst = "EPSG:2383";
        break;
    case GdaProjCsNad1983:
        *aDst = "EPSG:4269";        // NAD83
        break;
    default:
        return UErrTrue;
    }
    return UErrFalse;
}

/**
 * \brief To gda projection coordinate system.
 */
UErrCodeT CGdaTypeCtl::ToProjCs(UIntT *aDst, const GdaProjCsCodeT aSrc)
{
    switch (aSrc)
    {
    case GdaProjCsWgs1984:
        *aDst = 4326;
        break;
    case GdaProjCsXian1980:
        *aDst = 2383;
        break;
    case GdaProjCsNad1983:
        *aDst = 4269;
        break;
    default:
        return UErrTrue;
    }
    return UErrFalse;
}

/**
 * \brief Wkt to GdaProjCsCodeT.
 */
UErrCodeT CGdaTypeCtl::WktToProjCs(GdaProjCsCodeT *aDst, const UStringT aSrc)
{
    UStringT projCs;
    *aDst = GdaProjCsUnknown;
    for (UIntT i = GdaProjCsCodeTBegin; i <= GdaProjCsCodeTEnd; ++i)
    {
        ProjCsToStr(&projCs, (GdaProjCsCodeT) i);
        if (aSrc.Check(&projCs) == UErrFalse)
        {
            *aDst = i;
            return UErrFalse;
        }
    }

    return UErrTrue;
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

    // allocate level 2 pointer
    BItStringT *it = aSrc->Iterator();
    UIntT count = aSrc->Count();
    char **argv = (char **) mMem->Alloc(sizeof(char *) * (count + 1));
    UIntT **argc = (UIntT **) mMem->Alloc(sizeof(UIntT *) * (count + 1));
    argv[0] = (char *) argc;

    // Move the argv to data field.
    argv++;

    // allocate level 1 pointer
    // Set the header.
    argc[0] = (UIntT *) mMem->Alloc(sizeof(UIntT));
    *(argc[0]) = count;

    it->Head();
    for (UIntT i = 0; it->State() == UErrFalse; it->Next(), ++i)
    {
        UStringT str = it->Content();
        UIntT sizeStr = str.Len() + 1;

        // process level 1 pointer of argv
        argv[i] = (char *) mMem->Alloc(sizeof(char) * sizeStr);
        argv[i] = mStr->Cpy(argv[i], str.ToA());

        // process level 1 pointer of agrc
        argc[i + 1] = (UIntT *) mMem->Alloc(sizeof(UIntT));
        *(argc[i + 1]) = sizeStr;
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
    UIntT **argc = (UIntT **)(*(argv - 1));
    if (argv == NULL)
    {
        return UErrFalse;
    }

    // free level 1 pointer.
    UIntT count = *(argc[0]);
    mMem->Free((UHandleT) argc[0]);
    for (UIntT i = 0; i < count; ++i)
    {
        char *argvTmp = argv[i];
        UStringT argvStr(argvTmp);
        UIntT sizeMove = *(argc[i + 1]) - (argvStr.Len() + 1);
        if (sizeMove < 0)
        {
            return UErrTrue;
        }
        mMem->Free((UHandleT) (argvTmp - sizeMove));
        mMem->Free((UHandleT) (*(argc + i + 1)));
    }

    // free level 2 pointer.
    mMem->Free((UHandleT) argc);
    mMem->Free((UHandleT) (argv - 1));

    return UErrFalse;
}

/***** Private A *****/

/**
 * \brief GdaProjCsCodeT to UStringT.
 */
UErrCodeT CGdaTypeCtl::ProjCsToStr(UStringT *aDst, const GdaProjCsCodeT aSrc)
{
    switch (aSrc)
    {
    case GdaProjCsWgs1984:
        *aDst = "WGS_1984";
        break;
    case GdaProjCsXian1980:
        *aDst = "Xian_1980";
        break;
    default:
        return UErrTrue;
    }

    return UErrFalse;
}

/***** Private B *****/
