/******************************************************************************
 * $Id: vtr_frmtgjson.hpp 2017-12 $
 *
 * Project:  Vector Info Process.
 * Purpose:  Format for GeoJSON implementation.
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
 *****************************************************************************/

#include "vtr_frmtgjson.hpp"

// base
// #include "base_ctl.hpp"
// core
// #include "core_ctl.hpp"
// cls
// #include "cls_ctl.hpp"
// #include "cls_filesctl.hpp"
// #include "cls_fileswork.hpp"
// #include "cls_filescreate.hpp"
// gda
// #include "gda_ctl.hpp"
// #include "gda_corectl.hpp"
// #include "gda_driversctl.hpp"
// #include "gda_driverctl.hpp"
// #include "gda_datasetctl.hpp"
// #include "gda_bandctl.hpp"
// #include "gda_utilsctl.hpp"
// #include "gda_utilstr.hpp"
// #include "gda_trrst.hpp"
// #include "gda_trrsttorsttype.hpp"
// ust
#include "ust_filetype.hpp"

/**
 * \brief Constructor.
 */
CVtrFrmtGjson::CVtrFrmtGjson()
{
}

/**
 * \brief Destructor.
 */
CVtrFrmtGjson::~CVtrFrmtGjson()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CVtrFrmtGjson::Init()
{
    // CGdaCoreCtl *core = NULL;
    // GDA_CORE_CTL(core);
    // mDrs = core->Drivers();

    // CGdaUtilsCtl *utils = NULL;
    // GDA_UTILS_CTL(utils);
    // mTr = utils->Tr();

    return UErrFalse;
}

/**
 * \brief Translate string to file.
 */
UErrCodeT CVtrFrmtGjson::ToFile(const UStringT *aFile, const UStringT *aStr)
{
    UstFileOperCodeT oper = UstFileOperWt;
    UFileT src(aFile, oper);
    src.Write(aStr);

    return UErrFalse;
}

/**
 * \brief Translate file to string.
 */
UErrCodeT CVtrFrmtGjson::ToStr(UStringT *aStr, const UStringT *aFile)
{
    *aStr = "";
    UstFileOperCodeT oper = UstFileOperRt;
    UFileT src(aFile, oper);
    UStringT tmp;
    while (src.Eof() == UErrTrue)
    {
        src.ReadRow(&tmp);
        *aStr += tmp;
    }

    return UErrFalse;
}

/***** Private A *****/

/**
 * \brief Initialize pointer.
 */
// UErrCodeT CVtrFrmtGjson::InitPointer()
// {
//     // BMD_POINTER_INIT(mDrs);
//     // BMD_POINTER_INIT(mTr);

//     return UErrFalse;
// }

/***** Private B *****/
