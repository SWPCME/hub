/******************************************************************************
 * $Id: gda_driversctl.cpp 2017-07 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Core drivers controler implementation.
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

#include "gda_driversctl.hpp"

// Gdal library.
#include "gdal.h"

// base
#include "base_ctl.hpp"
// core
#include "core_ctl.hpp"
// gda
#include "gda_ctl.hpp"
#include "gda_typectl.hpp"
#include "gda_driverctl.hpp"

/**
 * \brief Constructor.
 */
CGdaDriversCtl::CGdaDriversCtl() : mMDriver(UContainerMap)
{
    BMD_POINTER_INIT(mType);
}

/**
 * \brief Destructor.
 */
CGdaDriversCtl::~CGdaDriversCtl()
{
    CleanupAll();
    BMD_POINTER_INIT(mType);
}

/**
 * \brief Initialize.
 *
 * Register the drivers of gda, and initialize the handle of driver.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CGdaDriversCtl::Init()
{
    GDA_TYPE_CTL(mType);
    CleanupAll();
    GdaRegisterAll();

    return UErrFalse;
}

/**
 * \brief Register.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CGdaDriversCtl::Register(const UStringT *aName)
{
    if (mMDriver.FindByKey(aName) == UErrTrue)
    {
        CGdaDriverCtl *driverCtl = NULL;
        BMD_CLASS_NEW_A_1(driverCtl, CGdaDriverCtl, aName);
        if (driverCtl == NULL)
        {
            return UErrTrue;
        }
        mMDriver.Add(&driverCtl, aName);
    }

    return UErrFalse;
}

/**
 * \brief Register.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CGdaDriversCtl::Register(const GdaFormatCodeT aFormat)
{
    UStringT name;
    mType->ToFormat(&name, aFormat);

    return Register(&name);
}

/**
 * \brief Register all with gdal.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CGdaDriversCtl::RegisterAll()
{
    UStringT defnName[GDA_F_COUNT] =
        {
            GDA_F_ASC, GDA_F_LCP, GDA_F_DEM, GDA_F_TIF, GDA_F_VRT
        };
    for (UIntT i= 0; i < GDA_F_COUNT; ++i)
    {
        Register(&defnName[i]);
    }

    return UErrFalse;
}

/**
 * \brief Deregister by driver name.
 */
UErrCodeT CGdaDriversCtl::Deregister(const UStringT *aName)
{
    MDriverItT *it = mMDriver.Iterator();
    if (it->Goto(aName) == UErrTrue)
    {
        return UErrTrue;
    }

    delete it->Content();
    mMDriver.Del(it->Content());

    return UErrFalse;
}

/**
 * \brief Deregister by format code.
 */
UErrCodeT CGdaDriversCtl::Deregister(const GdaFormatCodeT aFormat)
{
    UStringT name;
    mType->ToFormat(&name, aFormat);

    return Deregister(&name);
}

/**
 * \brief Deregister all.
 */
UErrCodeT CGdaDriversCtl::DeregisterAll()
{
    MDriverItT *it = mMDriver.Iterator();
    for (it->Head(); it->State() == UErrFalse; it->Next())
    {
        UStringT name = it->Key();
        Deregister(&name);
    }

    return UErrFalse;
}

/**
 * \brief Get driver control.
 *
 * @param aName Driver name.
 * @return Driver control, if successful; NULL, if failed.
 */
CGdaDriverCtl *CGdaDriversCtl::Driver(const UStringT *aName)
{
    MDriverItT *it = mMDriver.Iterator();
    if (it->Goto(aName) == UErrTrue)
    {
        return NULL;
    }

    CGdaDriverCtl *driverCtl = it->Content();

    return driverCtl;
}

/**
 * \brief Get driver control.
 *
 * @param aFormat Format code.
 * @return Driver control, if successful; NULL, if failed.
 */
CGdaDriverCtl *CGdaDriversCtl::Driver(const GdaFormatCodeT aCode)
{
    UStringT name;
    mType->ToFormat(&name, aCode);

    return Driver(&name);
}

/***** Private A *****/

/**
 * \brief Ogr register all.
 */
UErrCodeT CGdaDriversCtl::GdaRegisterAll()
{
    GDALAllRegister();

    return UErrFalse;
}

/**
 * \brief Destroy driver manager.
 */
UErrCodeT CGdaDriversCtl::DestroyDriverManager()
{
    GDALDestroyDriverManager();

    return UErrFalse;
}

/**
 * \brief Destroy.
 * if you use this api the RegisterAll will be failed.
 */
UErrCodeT CGdaDriversCtl::Destroy()
{
    GDALDestroy();

    return UErrFalse;
}


/**
 * \brief Cleanup All.
 *
 * Cleanup all the driver of gda.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CGdaDriversCtl::CleanupAll()
{
    DeregisterAll();
    DestroyDriverManager();

    return UErrFalse;
}

/***** Private B *****/
