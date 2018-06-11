/******************************************************************************
 * $Id: whub_ogrctl.i 2018-06 $
 *
 * Project:  whub (Wrap hub).
 * Purpose:  Api for ust.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-09 ~ 2017, Weiwei Huang
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

%module "WHubUst"
%{
// swig
/* #include <utility> */
// ust
#include "ust/ust_stringtype.hpp"
#include "ust/ust_containertype.hpp"
#include "ust/ust_iteratortype.hpp"
#include "ust/ust_datatype.hpp"
%}

typedef enum
{
    /** 
     * \brief Memory.
     */
    UContainerList    = 1,      /* Pointer: None. */
    UContainerVector  = 2,      /* Pointer: None. */
    UContainerSet     = 3,      /* Pointer: None. */
    UContainerUset    = 4,      /* Pointer: None. */
    UContainerMap     = 5,      /* Pointer: None. */
    UContainerUmap    = 6,      /* Pointer: None. */
    UContainerMList   = 11,     /* Pointer: ContentT. */
    UContainerMVector = 12,     /* Pointer: ContentT. */
    UContainerMSet    = 13,     /* Pointer: ContentT. */
    UContainerMUset   = 14,     /* Pointer: ContentT. */
    UContainerMcMap   = 15,     /* Pointer: ContentT. */
    UContainerMkMap   = 16,     /* Pointer: KeyT. */
    UContainerMMap    = 17,     /* Pointer: ContentT and KeyT. */
    UContainerMcUmap  = 18,     /* Pointer: ContentT. */

    /**
     * \brief Disk.
     */
    UContainerSqlite  = 51,     /* Pointer: None. */
} UContainerCodeT;

class UStringT
{
 public:
    UStringT();
    UStringT(const UStringT *aStr);
    UStringT(const char *aStr);
    ~UStringT();

    UErrCodeT Add(const UStringT *aStr);
    UErrCodeT Add(const char *aStr);
    const char *ToA() const;
    UErrCodeT ToConsole();
};

template <typename ContentT, typename KeyT = UIntT>
class UContainerT
{
  public:
    /* typedef ContentT first_type; */
    /* typedef UIntT second_type; */
    UContainerT(const UContainerCodeT aCode);
    ~UContainerT();

    // Attribute
    UContainerCodeT Code();
    UstContainerHT Handle();
    UIntT Count();

    UErrCodeT Add(const ContentT &aContent);
    UErrCodeT Add(const ContentT &aContent, const KeyT &aKey);
    UErrCodeT Del(const ContentT &aContent);
    UErrCodeT DelByKey(const KeyT &aKey);
    UErrCodeT Clear();
    UErrCodeT Find(const ContentT &aContent);
    UErrCodeT FindByKey(const KeyT &aKey);
    /* UErrCodeT Sort(); */
    /* UErrCodeT SortByKey(); */

    // Iterator.
    UIteratorT<ContentT, KeyT> *Iterator();

    // Get content and key by each other.
    ContentT Content(const KeyT &aKey);
    /* const KeyT Key(const ContentT &aContent); */
};

template <typename ContentT, typename KeyT = UIntT>
class UIteratorT
{
  public:
    UIteratorT();
    ~UIteratorT();

    UErrCodeT Init(CUstContainerCtl<ContentT, KeyT> *aCtn);
    UErrCodeT Head(const USequenceCodeT aCode = USequenceOrder);
    UErrCodeT Goto(const KeyT *aKey);
    UErrCodeT Goto(const KeyT &aKey);
    UErrCodeT Next();
    UErrCodeT State();
    ContentT Content();
    KeyT Key();
    UErrCodeT Add(const ContentT &aContent, const KeyT &aKey);

  protected:
  private:
    CUstContainerCtl<ContentT, KeyT> *mCtn;
};

class UDataT
{
  public:
    UDataT();
    UDataT(const UDataHT aDataH, const UDataTCodeT aCode);
    ~UDataT();

    UErrCodeT SetHandle(UDataHT aDataH);
    UErrCodeT SetCode(UDataTCodeT aCode);

    UErrCodeT ToS(UStringT *aVal);
};

/**
 * \brief Template.
 * The "typedef" must be before the "UContainerT" and "UIteratorT".
 */
/**
 * \brief UContainerT for base.
 */
%template(BCtnIntT) UContainerT<UIntT>;
%template(BItIntT) UIteratorT<UIntT>;
%template(BCtnStringT) UContainerT<UStringT>;
%template(BItStringT) UIteratorT<UStringT>;
/**
 * \brief UContainerT for fmd.
 */
%template(FmdCfgWeatherCtnT) UContainerT<FmdCfgWeatherT>;
%template(FmdCfgFuelMoistureCtnT) UContainerT<FmdCfgFuelMoistureT>;
