/******************************************************************************
 * $Id: bsn_ust.cpp 2017-07 $
 *
 * Project:  Business Logic library.
 * Purpose:  Test ust control api.
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
 *****************************************************************************/

#include "bsn_ust.hpp"

// ust
#include "ust_stringtype.hpp"

// hub
#include "hub_ctl.hpp"
#include "hub_modulectl.hpp"
// cls
#include "cls_ctl.hpp"
#include "cls_stringctl.hpp"
#include "cls_memoryctl.hpp"
// ust
#include "ust_ctl.hpp"
#include "ust_stringctl.hpp"
#include "ust_fsfiletype.hpp"

/**
 * \brief Constructor.
 */
CBsnUst::CBsnUst()
{
    mHub = CHubCtl::Hub();
    mModule = mHub->RegModule();
}

/**
 * \brief Destructor.
 */
CBsnUst::~CBsnUst()
{
    mHub->DeregModule(mModule);
}

/**
 * \brief Initialize.
 */
UErrCodeT CBsnUst::Init()
{
    return UErrFalse;
}

/**
 * \brief Test.
 */
UErrCodeT CBsnUst::Test()
{
    // TestString();
    TestFs();

    return UErrFalse;
}

/***** Private A *****/

/**
 * \brief Test string.
 */
#include <string.h>
UErrCodeT CBsnUst::TestString()
{
    CClsCtl *clsCtl = (CClsCtl *) mModule->Module(HubMCls);
    CClsMemoryCtl *memCtl = clsCtl->Mem();
    // CClsStringCtl *strCtl = clsCtl->Str();
    CUstCtl *ustCtl = (CUstCtl *) mModule->Module(HubMUst);
    CUstStringCtl *ustStr = ustCtl->Str();

    // UIntT num = 1234567;
    UStringT str;
    UIntT n = 1000;
    // void *p = memCtl->Alloc(10);
    char *pChar = NULL;
    const char testStr[10] = " str";
    pChar = ustStr->MCpy(testStr);
    for (int i = 0; i < n; ++i)
    {
        pChar = (char *) memCtl->Realloc((UHandleT) pChar, 10 * (i+1));
        pChar = ustStr->Cat(pChar, testStr);
        // p = memCtl->Realloc(p, 10);
        // str += num;
        // str += " str";
        // str = str + " xyz";
        // UStringT numStr;
        // numStr += i;
        // numStr.ToConsole();
    }
    UHandleT dst;
    NewStringArgv(&dst, &str);
    // TestStringFunc(dst);

    return UErrFalse;
}

UErrCodeT CBsnUst::NewStringArgv(UHandleT *aDst, const UStringT *aSrc)
{
    CClsCtl *clsCtl = (CClsCtl *) mModule->Module(HubMCls);
    CClsMemoryCtl *memCtl = clsCtl->Mem();
    CClsStringCtl *strCtl = clsCtl->Str();

    UContainerT<UStringT> srcS(UContainerList);
    const UStringT delimiters = " ";
    UStringT *src = (UStringT *) aSrc;
    src->Split(&srcS, &delimiters);

    UIteratorT<UStringT> *it = srcS.Iterator();
    UIntT count = srcS.Count();
    char **argv = (char **) memCtl->Alloc(sizeof(char **) * (count + 1));
    argv[count] = NULL;

    it->Head();
    for (UIntT i = 0; it->State() == UErrFalse; it->Next(), ++i)
    {
        UStringT str = it->Content();
        argv[i] = (char *) memCtl->Alloc(sizeof(str.ToA()));
        argv[i] = strCtl->Cpy(argv[i], str.ToA());
    }

    *aDst = (UHandleT) argv;

    return UErrFalse;
}

UErrCodeT CBsnUst::TestStringFunc(UHandleT aArgv)
{
    CClsCtl *clsCtl = (CClsCtl *) mModule->Module(HubMCls);
    CClsMemoryCtl *memCtl = clsCtl->Mem();
    char **argv = (char **) aArgv;
    while( *argv != NULL )
    {
        memCtl->Free((UHandleT) *argv);
        ++(argv);
    }

    return UErrFalse;
}

/**
 * \brief Test container.
 */
UErrCodeT CBsnUst::TestContainer()
{
    TestCtnList();

    return UErrFalse;
}

UErrCodeT CBsnUst::TestCtnList()
{
    UContainerT<UStringT> ctn(UContainerList);
    ctn.Add("abc ");
    ctn.Add("123 ");
    ctn.Add("xyz");
    UStringT numStr;
    UIntT num = ctn.Count();
    numStr += num;
    numStr.ToConsole();
    UIteratorT<UStringT> *it = ctn.Iterator();
    for (it->Head(); it->State() == UErrFalse; it->Next())
    {
        UStringT str = (UStringT) it->Content();
        str.ToConsole();
    }

    return UErrFalse;
}

UErrCodeT CBsnUst::TestCtnMap()
{
    UContainerT<UStringT, UIntT> ctn(UContainerMap);
    ctn.Add("abc ", 1);
    ctn.Add("123 ", 2);
    ctn.Add("xyz", 3);
    UStringT numStr;
    UIntT num = ctn.Count();
    numStr += num;
    numStr.ToConsole();
    UIteratorT<UStringT, UIntT> *it = ctn.Iterator();
    for (it->Head(); it->State() == UErrFalse; it->Next())
    {
        UStringT str = (UStringT) it->Content();
        str.ToConsole();
    }

    return UErrFalse;
}

UErrCodeT CBsnUst::TestFs()
{
    UStringT testfs = ".tmp/testfs";
    UFsFileT file(&testfs);
    file.Rm(0);

    return UErrFalse;
}

/***** Private B *****/
