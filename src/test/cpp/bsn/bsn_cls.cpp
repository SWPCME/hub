/******************************************************************************
 * $Id: bsn_cls.cpp 2017-07 $
 *
 * Project:  Business Logic library.
 * Purpose:  Test cls control api implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-06 ~ 2017, Weiwei Huang
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
 *****************************************************************************/

#include "bsn_cls.hpp"

// cls
#include "cls_ctl.hpp"
#include "cls_timectl.hpp"
#include "cls_ioctl.hpp"
#include "cls_iocommonctl.hpp"

/**
 * \brief Constructor.
 */
CBsnCls::CBsnCls()
{
}

/**
 * \brief Destructor.
 */
CBsnCls::~CBsnCls()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CBsnCls::Init()
{
    CHubCtl *hubCtl = CHubCtl::Hub();

    hubCtl->Register(HubMCls);
    mCls = (CClsCtl *) hubCtl->Module(HubMCls);

    return UErrFalse;
}

/**
 * \brief Test.
 */
UErrCodeT CBsnCls::Test()
{
    CClsTimeCtl *timeCtl = mCls->Time();
    CClsIoCtl *ioCtl = mCls->Io();
    CClsIoCommonCtl *cmnCtl = ioCtl->Common();

    BTimeTmT tm;
    timeCtl->Current(&tm);
    cmnCtl->PrintF("year = %d, month = %d, day = %d\n",
                   tm.year, tm.mon, tm.mday);
    cmnCtl->PrintF("hour = %d, min = %d, sec = %d\n",
                   tm.hour, tm.min, tm.sec);

    return UErrFalse;
}
