/******************************************************************************
 * $Id: gda_banddatactl.cpp 2017-12 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Gda band data controler implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-12 ~ 2017, Weiwei Huang
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

#include "gda_banddatactl.hpp"

// base
#include "base_ctl.hpp"
// core
#include "core_ctl.hpp"
// cls
#include "cls_ctl.hpp"
#include "cls_memoryctl.hpp"

/**
 * \brief Constructor.
 */
CGdaBandDataCtl::CGdaBandDataCtl()
{
    BMD_POINTER_INIT(mMem);
}

/**
 * \brief Destructor.
 */
CGdaBandDataCtl::~CGdaBandDataCtl()
{
    BMD_POINTER_INIT(mMem);
}

/**
 * \brief Initialize.
 */
UErrCodeT CGdaBandDataCtl::Init()
{
    CClsCtl *cls = NULL;
    CLS_CTL(cls);
    mMem = cls->Mem();

    return UErrFalse;
}

/**
 * \brief New data.
 */
UErrCodeT CGdaBandDataCtl::New(UDataT *aData, const UDataTCodeT aType,
                               const BMathCsC2dT *aBegin,
                               const BMathCsC2dT *aEnd)
{
    UIntT sizeType = 8;
    if (aType == UDataTInt16)
    {
        sizeType = 2;
    }
    UIntT sizeRegion = (aEnd->X() - aBegin->X()) * (aEnd->Y() - aBegin->Y());
    UIntT size = sizeType * sizeRegion;
    *aData = mMem->Alloc(size);

    return UErrFalse;
}

/**
 * \brief Delete data.
 */
UErrCodeT CGdaBandDataCtl::Del(UDataT *aData)
{
    mMem->Free(aData);

    return UErrFalse;
}
