/******************************************************************************
 * $Id: ogr_ctl.cpp 2017-07 $
 *
 * Project:  Ogr (OpenGIS Simple Features Reference Implementation) library.
 * Purpose:  Ogr Control.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016-08 ~ 2017, Weiwei Huang
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ****************************************************************************/

#include "ogr_ctl.hpp"

// Ogr library.
#include "ogr_api.h"

// hub
#include "hub_modulectl.hpp"
// base
#include "base_macrodefn.hpp"
// ogr
#include "ogr_typectl.hpp"
#include "ogr_driverctl.hpp"

/**
 * \brief Constructor.
 */
COgrCtl::COgrCtl(CHubModuleCtl *aModule) : mMDriver(UContainerMap)
{
    BMD_POINTER_INIT(mType);
    BMD_POINTER_INIT(mModule);
    mModule = aModule;
}

/**
 * \brief Destructor.
 */
COgrCtl::~COgrCtl()
{
    BMD_CLASS_DEL(mType);
    CleanupAll();
}

/**
 * \brief Initialize.
 *
 * Register the drivers of ogr, and initialize the handle of driver.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT COgrCtl::Init()
{
    CleanupAll();
    OgrRegisterAll();

    return UErrFalse;
}

/**
 * \brief Up.
 */
CHubModuleCtl *COgrCtl::Up()
{
    return mModule;
}

/**
 * \brief Type controler.
 */
COgrTypeCtl *COgrCtl::Type()
{
    BMD_CLASS_NEW(mType, COgrTypeCtl);

    return mType;
}

/**
 * \brief Register all driver.
 */
UErrCodeT COgrCtl::RegisterAll()
{
    UStringT defnName[OGR_F_COUNT] =
        {
            OGR_F_TAB, OGR_F_SHP, OGR_F_CSV, OGR_F_XLS, OGR_F_XLSX,
            OGR_F_SQLITE, OGR_F_JSON
        };

    for (UIntT i= 0; i < OGR_F_COUNT; ++i)
    {
        Register(&defnName[i]);
    }

    return UErrFalse;
}

/**
 * \brief Deregister all driver.
 */
UErrCodeT COgrCtl::DeregisterAll()
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
 * \brief Register driver.
 */
UErrCodeT COgrCtl::Register(const UStringT *aName)
{
    if (mMDriver.FindByKey(aName) == UErrTrue)
    {
        COgrDriverCtl *driverCtl = NULL;
        BMD_CLASS_NEW_A_1(driverCtl, COgrDriverCtl, aName);
        if (driverCtl == NULL)
        {
            return UErrTrue;
        }
        mMDriver.Add(&driverCtl, aName);
    }

    return UErrFalse;
}

/**
 * \brief Register driver.
 */
UErrCodeT COgrCtl::Register(OgrFormatCodeT aFormat)
{
    UStringT name;
    mType->ToFormat(&name, aFormat);

    return Register(&name);
}

/**
 * \brief Deregister driver.
 */
UErrCodeT COgrCtl::Deregister(const UStringT *aName)
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
 * \brief Dergister driver.
 */
UErrCodeT COgrCtl::Deregister(OgrFormatCodeT aFormat)
{
    UStringT name;
    mType->ToFormat(&name, aFormat);

    return Deregister(&name);
}

/**
 * \brief Get driver control.
 *
 * @param aName Driver name.
 *
 * @return Driver control, if successful; NULL, if failed.
 */
COgrDriverCtl *COgrCtl::Driver(const UStringT *aName)
{
    MDriverItT *it = mMDriver.Iterator();
    if (it->Goto(aName) == UErrTrue)
    {
        return NULL;
    }

    COgrDriverCtl *driverCtl = it->Content();

    return driverCtl;
}

/**
 * \brief Driver controler.
 */
COgrDriverCtl *COgrCtl::Driver(OgrFormatCodeT aFormat)
{
    UStringT name;
    mType->ToFormat(&name, aFormat);

    return Driver(&name);
}

/***** Private A *****/

/**
 * \brief Cleanup all.
 */
UErrCodeT COgrCtl::CleanupAll()
{
    DeregisterAll();
    // OgrCleanupAll();

    return UErrFalse;
}

/**
 * \brief Register all.
 *
 * Register all the driver of ogr.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT COgrCtl::OgrRegisterAll()
{
    OGRRegisterAll();

    return UErrFalse;
}

/**
 * \brief Cleanup all.
 *
 * Deregister all the driver of ogr, gdal, and all things.
 * Be carefully, it will destructor all gdal objects.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT COgrCtl::OgrCleanupAll()
{
    OGRCleanupAll();

    return UErrFalse;
}

/***** Private B *****/
