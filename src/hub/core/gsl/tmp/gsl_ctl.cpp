/******************************************************************************
 * $Id: gsl_ctl.cpp 2017-05 $
 *
 * Project:  GSL (GSL: Gnu Scientific Library).
 * Purpose:  Gsl controler implementation.
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

#include "gsl_ctl.hpp"

/**
 * \brief Constructor.
 */
CGslCtl::CGslCtl()
{
    mMDriver.Init(UContainerMap);
}

/**
 * \brief Destructor.
 */
CGslCtl::~CGslCtl()
{
    DeregisterAll();
}

/**
 * \brief Initialize.
 */
UErrCodeT CGslCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Driver for numeric type.
 */
UHandleT CGslCtl::Driver(BMathNumCodeT aCode)
{
    UHandleT handle = NULL;
    Register(aCode);
    handle = mMDriver[aCode];

    return handle;
}

/***** Private A *****/

/**
 * \brief Register by numeric type.
 */
UErrCodeT CGslCtl::Register(BMathNumCodeT aCode)
{
    if (mMDriver.FindByKey(aCode) == UErrTrue)
    {
        return UErrTrue;
    }
    switch (aCode)
    {
    case BMathNumInt:
    {
        UHandleT handle = (UHandleT) (new CGslDriverCtl<UIntT>);
        ((CGslDriverCtl<UIntT> *) handle)->Init(aCode);
        mMDriver.Add(&handle, &aCode);
        break;
    }
    case BMathNumFloat:
    {
        UHandleT handle = (UHandleT) (new CGslDriverCtl<UFloatT>);
        ((CGslDriverCtl<UFloatT> *) handle)->Init(aCode);
        mMDriver.Add(&handle, &aCode);
        break;
    }
    default:
        break;
    }

    return UErrFalse;
}

/**
 * \brief Deregister.
 */
UErrCodeT CGslCtl::Deregister(BMathNumCodeT aCode)
{
    return mMDriver.DelByKey(aCode);
}

/**
 * \brief Deregister all.
 */
UErrCodeT CGslCtl::DeregisterAll()
{
    MGslDriverCtlItT *it = mMDriver.Iterator();
    for (it->Head(); it->State() == UErrFalse; it->Next())
    {
        Deregister(it->Key());
    }

    return UErrFalse;
}

/***** Private B *****/
