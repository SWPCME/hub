/******************************************************************************
 * $Id: bsn_uniqueid.hpp 2016-08 $
 *
 * Project:  Business Logic library.
 * Purpose:  Unique identifier control definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016, Weiwei Huang
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

#ifndef BSN_UNIQUEID_HPP_INCLUDED
#define BSN_UNIQUEID_HPP_INCLUDED

#include "bsn_base.hpp"
#include "ust/ust_stringtype.hpp"
#include "ust/ust_containertype.hpp"

class CHubCtl;
class CVtrCtl;

typedef struct
{
    UStringT in;
    UStringT cfg;
    UStringT out;
} BsnUniqueIdPathT;

typedef UContainerT<UIntT, UIntT> MMaxIdByGroupIdT;
typedef UContainerT<MMaxIdByGroupIdT*, UStringT*> MGroupToMaxIdByNameT;

class BSN_LIB CBsnUniqueId
{
 public:
    CBsnUniqueId();
    ~CBsnUniqueId();

    UErrCodeT Init();
    UErrCodeT SetPath(BsnUniqueIdPathT* aPath);
    UErrCodeT Main();

 protected:
 private:
    // Fetch id.
    UErrCodeT InitMaxId();
    UIntT GroupId(UIntT aGridId);
    UIntT NewId(UIntT aGroupId, UStringT* aLayerName);

    // Hub library.
    CHubCtl* m_hub;

    // Vtr library.
    CVtrCtl* m_vtr;

    // UI Control.
    BsnUniqueIdPathT m_path;

    // Record max id in one type by name.
    MGroupToMaxIdByNameT m_gToMIdByName(UContainerCodeT aCode);
};

#endif  /* BSN_UNIQUEID_HPP_INCLUDED */
