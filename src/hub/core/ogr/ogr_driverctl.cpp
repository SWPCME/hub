/******************************************************************************
 * $Id: ogr_driverctl.cpp 2017-07 $
 *
 * Project:  Ogr (OpenGIS Simple Features Reference Implementation) library.
 * Purpose:  Driver controler implementation.
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
 ****************************************************************************/

#include "ogr_driverctl.hpp"
// module.
#include "ogr_api.h"
// base
#include "base_macrodefn.hpp"
// ogr
#include "ogr_datasrcctl.hpp"

/**
 * \brief Constructor.
 */
COgrDriverCtl::COgrDriverCtl(const UStringT *aName)
{
    SetHandle(aName);
    mMDs.Init(UContainerMap);
}

/**
 * \brief Destructor.
 */
COgrDriverCtl::~COgrDriverCtl()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT COgrDriverCtl::Init()
{
    CloseAll();

    return UErrFalse;
}

/**
 * \brief Create Datasource.
 *
 * Get a handle of datasource that point to this file.
 *
 * @param aFile The file that you want to create.
 *
 * @return Handle of ogr data source, if successful; NULL, if failed.
 */
COgrDatasrcCtl* COgrDriverCtl::Create(const UStringT *aFile)
{
    return DsCtl(aFile, UFileOperCreate);
}

/**
 * \brief Load file and get the handle of data source.
 *
 * @return Hanle of data source, if successful; NULL, if failed.
 */
COgrDatasrcCtl *COgrDriverCtl::Load(const UStringT *aFile)
{
    return DsCtl(aFile, UFileOperLoad);
}

/**
 * \brief Close file.
 */
UErrCodeT COgrDriverCtl::Close(const UStringT *aFile)
{
    MDsItT *it = mMDs.Iterator();
    if (it->Goto(aFile) == UErrTrue)
    {
        return UErrTrue;
    }
    COgrDatasrcCtl *dsCtl = it->Content();
    delete dsCtl;
    mMDs.DelByKey(aFile);

    return UErrFalse;
}

/**
 * \brief Close all file.
 */
UErrCodeT COgrDriverCtl::CloseAll()
{
    MDsItT *it = mMDs.Iterator();
    for (it->Head(); it->State() == UErrFalse; it->Next())
    {
        UStringT name = it->Key();
        Close(&name);
    }

    return UErrFalse;
}

/***** Private A *****/

UErrCodeT COgrDriverCtl::SetHandle(const UStringT *aName)
{
    mDriverH = (OgrDriverHT) OGRGetDriverByName(aName->ToA());

    return UErrFalse;
}

COgrDatasrcCtl *COgrDriverCtl::DsCtl(const UStringT *aFile, UFileOperCodeT aCode)
{
    MDsItT *it = mMDs.Iterator();
    if (it->Goto(aFile) == UErrFalse)
    {
        return it->Content();
    }
    COgrDatasrcCtl *dsCtl = NULL;
    BMD_CLASS_NEW_A_3(dsCtl, COgrDatasrcCtl, aFile, aCode, mDriverH);
    if (dsCtl != NULL)
    {
        mMDs.Add(&dsCtl, aFile);
    }

    return dsCtl;
}

/***** Private B *****/
