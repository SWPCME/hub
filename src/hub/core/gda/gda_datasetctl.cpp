/******************************************************************************
 * $Id: gda_datasetctl.cpp 2017-07 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Gda dataset control.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-05 ~ 2017, Weiwei Huang
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

#include "gda_datasetctl.hpp"

// base
#include "base_ctl.hpp"
// core
#include "core_ctl.hpp"
// cls
#include "cls_ctl.hpp"
#include "cls_mathctl.hpp"
#include "cls_matharith.hpp"
#include "cls_arithround.hpp"
// gda
#include "gda_ctl.hpp"
#include "gda_typectl.hpp"
#include "gda_bandctl.hpp"
// Module
#include "gdal.h"

/**
 * \brief Constructor.
 * Create file.
 */
CGdaDatasetCtl::CGdaDatasetCtl(const UStringT *aFile,
                               const GdaDatasetAttrT *aAttr,
                               const GdaDriverHT aDriver)
    : mMBand(UContainerMap)
{
    InitPointer();
    CreateDataset(aFile, aAttr, aDriver);
}

/**
 * \brief Constructor.
 * Load file.
 */
CGdaDatasetCtl::CGdaDatasetCtl(const UStringT *aFile, UAccessCodeT aAccess)
    : mMBand(UContainerMap)
{
    BMD_POINTER_INIT(mDatasetH);
    LoadDataset(aFile, aAccess);
}

/**
 * \brief Destructor.
 */
CGdaDatasetCtl::~CGdaDatasetCtl()
{
    CloseAll();
    GdaClose();
    InitPointer();
}

/**
 * \brief Initialize.
 */
UErrCodeT CGdaDatasetCtl::Init()
{
    if (mDatasetH == NULL)
    {
        return UErrTrue;
    }

    GDA_TYPE_CTL(mType);
    CClsCtl *cls;
    BMD_POINTER_INIT(cls);
    CLS_CTL(cls);
    CClsMathCtl *math = cls->Math();
    CClsMathArith *arith = math->Arith();
    mRound = arith->Round();

    return UErrFalse;
}

/**
 * \brief Handle.
 */
GdaDatasetHT CGdaDatasetCtl::Handle()
{
    return mDatasetH;
}

/**
 * \brief Get description.
 */
UStringT CGdaDatasetCtl::Description()
{
    UStringT description = GDALGetDescription(mDatasetH);

    return description;
}

/**
 * \brief Fetch the projection definition for this dataset.
 */
GdaOgrSrsT *CGdaDatasetCtl::Srs()
{
    UStringT strProjCs = GDALGetProjectionRef((GDALDatasetH) mDatasetH);
    mSrs.ImportFromWkt(&strProjCs);

    return &mSrs;
}

/**
 * \brief Flush all write cached to disk.
 */
UErrCodeT CGdaDatasetCtl::Save()
{
    GDALFlushCache((GDALDatasetH) mDatasetH);

    return UErrFalse;
}

/**
 * \brief Raster count.
 */
UErrCodeT CGdaDatasetCtl::Count(UIntT *aNum)
{
    *aNum = GDALGetRasterCount((GDALDatasetH) mDatasetH);

    return UErrFalse;
}

/**
 * \brief Add band.
 */
UErrCodeT CGdaDatasetCtl::AddBand(UDataTCodeT aDataT, UStringT *aOption)
{
    GDALDataType dataType;
    mType->ToDataType(&dataType, aDataT);
    char** option = NULL;
    GDALAddBand((GDALDatasetH) mDatasetH, dataType, option);

    return UErrFalse;
}

/**
 * \brief Get raster band with band index.
 *
 * Band index, from 1 to count of band for this dataset.
 *
 * @param aId Band index.
 * @return Handle of band contoler, if successful; NULL, if failed.
 */
CGdaBandCtl *CGdaDatasetCtl::Band(UIntT aId)
{
    return BandCtl(aId);
}

/**
 * \brief Set band.
 *
 * Set destination of band id by source of band controler.
 *
 * @param aDstId Destination of band id.
 * @param aSrcBand Source of band controler.
 */
UErrCodeT CGdaDatasetCtl::SetBand(UIntT aDstId, CGdaBandCtl *aSrcBand)
{
    CGdaBandCtl *dstBand = Band(aDstId);
    GDALRasterBandH dstBandH = (GDALRasterBandH) dstBand->Handle();
    GDALRasterBandH srcBandH = (GDALRasterBandH) aSrcBand->Handle();
    const char **opt = NULL;
    GDALProgressFunc func = NULL;
    void *data = NULL;
    CPLErr err = CE_Failure;
    err = GDALRasterBandCopyWholeRaster(srcBandH, dstBandH, opt, func, data);

    if (err == CE_None)
    {
        return UErrFalse;
    }

    return UErrTrue;
}

/**
 * \brief Get transform info.
 * Fetch the affine transformation coefficients.
 */
UErrCodeT CGdaDatasetCtl::GeoTransform(BCtnFloatT *aTransform)
{
    const UIntT kNumTransform = 6;
    double transform[kNumTransform];
    CPLErr err = GDALGetGeoTransform((GDALDatasetH) mDatasetH, transform);

    for (UIntT i = 0; i < kNumTransform; ++i)
    {
        aTransform->Add(transform[i]);
    }

    return UErrFalse;
}
/**
 * \brief Get invert transform info.
 *
 * This function will invert a standard 3x2 set of GeoTransform coefficients.
 * This converts the equation from being pixel to geo to being geo to pixel.
 */
UErrCodeT CGdaDatasetCtl::InvGeoTransform(BCtnFloatT *aInvTransform)
{
    BCtnFloatT tTransform(UContainerList);
    GeoTransform(&tTransform);
    const UIntT kNumTransform = 6;
    double transform[kNumTransform];
    for (UIntT i = 0; i < kNumTransform; ++i)
    {
        transform[i] = tTransform[i];
    }
    double invTransform[kNumTransform];
    CPLErr err = GDALInvGeoTransform(transform, invTransform);

    for (UIntT i = 0; i < kNumTransform; ++i)
    {
        aInvTransform->Add(invTransform[i]);
    }

    return UErrFalse;
}

/**
 * \brief Index to position.
 *
 * @param aDst The destination of coordinate with current coordinate system.
 * @param aSrc The source of coordinate with x belong to [0, xSize], 
 *             y belong to [0, ySize].
 */
UErrCodeT CGdaDatasetCtl::IdToPos(BMathCsC2dT *aDst, BMathCsC2dT *aSrc)
{
    BCtnFloatT transform(UContainerList);
    GeoTransform(&transform);
    UFloatT srcX = aSrc->X();
    UFloatT srcY = aSrc->Y();
    UFloatT dstX = transform[0] + srcX * transform[1] + srcY * transform[2];
    UFloatT dstY = transform[3] + srcX * transform[4] + srcY * transform[5];
    aDst->SetAll(dstX, dstY);

    return UErrFalse;
}

/**
 * \brief Position to index.
 *
 * @param aDst The source of coordinate with x belong to [0, xSize], 
 *             y belong to [0, ySize].
 * @param aSrc The destination of coordinate with current coordinate system.
 */
UErrCodeT CGdaDatasetCtl::PosToId(BMathCsC2dT *aDst, BMathCsC2dT *aSrc)
{
    UErrCodeT err = UErrFalse;
    BCtnFloatT transform(UContainerList);
    InvGeoTransform(&transform);
    UFloatT srcX = aSrc->X();
    UFloatT srcY = aSrc->Y();
    UFloatT tDstX = transform[0] + srcX * transform[1] + srcY * transform[2];
    UFloatT tDstY = transform[3] + srcX * transform[4] + srcY * transform[5];
    UFloatT dstX;
    mRound->Floor(&dstX, tDstX);
    UFloatT dstY;
    mRound->Floor(&dstY, tDstY);

    UIntT xSize;
    XSize(&xSize);
    UIntT ySize;
    YSize(&ySize);
    if (dstX >= xSize)
    {
        dstX = xSize - 1;
        err = UErrTrue;
    }
    if (dstY >= ySize)
    {
        dstY = ySize - 1;
        err = UErrTrue;
    }

    aDst->SetAll(dstX, dstY);

    return err;
}

/**
 * \brief Raster x size.
 */
UErrCodeT CGdaDatasetCtl::XSize(UIntT *aNum)
{
    *aNum = GDALGetRasterXSize((GDALDatasetH) mDatasetH);

    return UErrFalse;
}

/**
 * \brief Raster y size.
 */
UErrCodeT CGdaDatasetCtl::YSize(UIntT *aNum)
{
    *aNum = GDALGetRasterYSize((GDALDatasetH) mDatasetH);

    return UErrFalse;
}

/**
 * \brief Close band with band index.
 *
 * Band index, from 1 to count of band for this dataset.
 *
 * @param aBandId Band index.
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CGdaDatasetCtl::Close(const UIntT aBandId)
{
    MBandItT *it = mMBand.Iterator();
    if (it->Goto(aBandId) == UErrTrue)
    {
        return UErrTrue;
    }
    CGdaBandCtl *bandCtl = it->Content();
    delete bandCtl;
    mMBand.DelByKey(aBandId);

    return UErrFalse;
}

/**
 * \brief Close all band.
 *
 * It will close all band that open by this class.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CGdaDatasetCtl::CloseAll()
{
    MBandItT *it = mMBand.Iterator();

    for (it->Head(); it->State() == UErrFalse; it->Next())
    {
        const UIntT id = it->Key();
        Close(id);
    }

    return UErrFalse;
}

/**
 * \brief Projection reference.
 */
// UErrCodeT CGdaDatasetCtl::PrjRef()
// {
//     return UErrFalse;
// }

/***** Private A *****/

/**
 * \brief Init pointer.
 */
UErrCodeT CGdaDatasetCtl::InitPointer()
{
    BMD_POINTER_INIT(mRound);
    BMD_POINTER_INIT(mDatasetH);
    BMD_POINTER_INIT(mType);

    return UErrFalse;
}

/**
 * \brief Create dataset
 */
UErrCodeT CGdaDatasetCtl::CreateDataset(const UStringT *aFile,
                                        const GdaDatasetAttrT *aAttr,
                                        const GdaDriverHT aDriver)
{
    GDALDataType dataType;
    mType->ToDataType(&dataType, aAttr->dataT);
    mDatasetH = (GdaDatasetHT) GDALCreate((GDALDriverH) aDriver, aFile->ToA(),
                                          aAttr->xSize, aAttr->ySize,
                                          aAttr->nBands, dataType,
                                          aAttr->option);

    return UErrFalse;
}

/**
 * \brief Load dataset.
 */
UErrCodeT CGdaDatasetCtl::LoadDataset(const UStringT *aFile,
                                      UAccessCodeT aAccess)
{
    GDALAccess access;
    mType->ToAccess(&access, aAccess);
    mDatasetH = (GdaDatasetHT) GDALOpen(aFile->ToA(), access);

    return UErrFalse;
}

/**
 * \brief Band controler.
 */
CGdaBandCtl *CGdaDatasetCtl::BandCtl(UIntT aId)
{
    MBandItT *it = mMBand.Iterator();
    if (it->Goto(aId) == UErrFalse)
    {
        return it->Content();
    }
    CGdaBandCtl *bandCtl = NULL;
    BMD_CLASS_NEW_A_2(bandCtl, CGdaBandCtl, aId, this);
    if (bandCtl != NULL)
    {
        mMBand.Add(bandCtl, aId);
    }

    return bandCtl;
}

/**
 * \brief Close.
 */
UErrCodeT CGdaDatasetCtl::GdaClose()
{
    if (mDatasetH == NULL)
    {
        return UErrTrue;
    }

    GDALClose((GDALDatasetH) mDatasetH);

    return UErrFalse;
}

/***** Private B *****/
