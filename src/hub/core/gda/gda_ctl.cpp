/******************************************************************************
 * $Id: gda_ctl.cpp 2017-05 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Implementation of gda control.
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

#include "gda_ctl.hpp"

// Gdal library.
#include "gdal.h"

// Module
#include "gda_typectl.hpp"
#include "gda_driverctl.hpp"

/**
 * \brief Constructor.
 */
CGdaCtl::CGdaCtl()
{
    mType = new CGdaTypeCtl();
    mMDriverH.Init(UContainerMap);
    mMDriverCtl.Init(UContainerMap);
}

/**
 * \brief Destructor.
 */
CGdaCtl::~CGdaCtl()
{
    CleanupAll();
    delete mType;
}

/**
 * \brief Initialize.
 *
 * Register the drivers of gda, and initialize the handle of driver.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CGdaCtl::Init()
{
    RegisterAll();
    InitDriver();

    return UErrFalse;
}

/**
 * \brief Get driver control.
 *
 * @param aName Driver name.
 * @return Driver control, if successful; NULL, if failed.
 */
CGdaDriverCtl *CGdaCtl::Driver(UStringT *aName)
{
    CGdaDriverCtl *driverCtl;
    if (mMDriverCtl.FindByKey(aName) == UErrTrue)
    {
        driverCtl = new CGdaDriverCtl(mMDriverH[aName]);
        mMDriverCtl.Add(&driverCtl, aName);
    }

    driverCtl = mMDriverCtl.Content(aName);

    return driverCtl;
}

/***** Private A *****/

/**
 * \brief Initialize Driver.
 *
 * Initialize driver of the handle.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CGdaCtl::InitDriver()
{
    UStringT defnName[GDA_RASTER_FORMATS_COUNT] =
        {
            GDA_RASTER_ASC_NAME, GDA_RASTER_LCP_NAME
        };
    UStringT defnSuffix[GDA_RASTER_FORMATS_COUNT] =
        {
            GDA_RASTER_ASC_SUFFIX, GDA_RASTER_LCP_SUFFIX
        };
    for (UIntT i= 0; i < GDA_RASTER_FORMATS_COUNT; ++i)
    {
        UHandleT handle = NULL;
        GetDriver((GdaDriverHT *) &handle, &defnName[i]);
        mMDriverH.Add(&handle, &defnName[i]);
    }

    return UErrFalse;
}

/**
 * \brief Get Driver.
 *
 * Get driver by name of the format.
 *
 * @param aHandle The handle of driver.
 * @param aName The name of driver.
 *
 * @return UErrFalse, if successful; Others, if failed.
 */
UErrCodeT CGdaCtl::GetDriver(GdaDriverHT *aHandle, const UStringT* aName)
{
    *aHandle = (GdaDriverHT) GDALGetDriverByName(aName->ToA());
    if (*aHandle == NULL)
    {
        return UErrTrue;
    }

    return UErrFalse;
}

/**
 * \brief Get driver by serial number.
 */
UErrCodeT CGdaCtl::GetDriver(GdaDriverHT *aHandle, UIntT aNum)
{
    *aHandle = (GdaDriverHT) GDALGetDriver(aNum);
    if (*aHandle == NULL)
    {
        return UErrTrue;
    }

    return UErrFalse;
}

/**
 * \brief Get driver count.
 */
UErrCodeT CGdaCtl::DriverCount(UIntT *aNum)
{
    *aNum = GDALGetDriverCount();

    return UErrFalse;
}

/**
 * \brief Register all with gdal.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CGdaCtl::RegisterAll()
{
    GDALAllRegister();

    return UErrFalse;
}

/**
 * \brief Register.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CGdaCtl::Register()
{
    // GDALRegisterDriver((int) aNum);

    return UErrFalse;
}

/**
 * \brief Deregister by driver name.
 */
UErrCodeT CGdaCtl::Deregister(UStringT *aDriver)
{
    if (mMDriverH.FindByKey(*aDriver) == UErrFalse)
    {
        GDALDeregisterDriver(mMDriverH.Content(*aDriver));
    }

    return UErrFalse;
}

/**
 * \brief Deregister by handle.
 */
UErrCodeT CGdaCtl::Deregister(GdaDriverHT aDriver)
{
    GDALDeregisterDriver((GDALDriverH) aDriver);

    return UErrFalse;
}

/**
 * \brief Deregister all.
 */
UErrCodeT CGdaCtl::DeregisterAll()
{
    MGdaDriverHItT *it = mMDriverH.Iterator();
    for (it->Head(); it->State() == UErrFalse; it->Next())
    {
        GDALDestroyDriver(it->Content());
    }

    UIntT driverCount;
    DriverCount(&driverCount);
    for (UIntT i = 0; i < driverCount; i++)
    {
        GdaDriverHT driverH = NULL;
        if (GetDriver((GdaDriverHT*) &driverH, i) == UErrTrue)
        {
            continue;
        }
        Deregister(driverH);
        GDALDestroyDriver((GDALDriverH) driverH);
    }

    return UErrFalse;
}

/**
 * \brief Destroy.
 */
UErrCodeT CGdaCtl::Destroy()
{
    GDALDestroyDriverManager();
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
UErrCodeT CGdaCtl::CleanupAll()
{
    DeregisterAll();
    Destroy();

    return UErrFalse;
}

/***** Private B *****/
