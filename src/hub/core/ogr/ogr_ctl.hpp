/******************************************************************************
 * $Id: ogr_ctl.hpp 2016-08 $
 *
 * Project:  Ogr (OpenGIS Simple Features Reference Implementation) library.
 * Purpose:  Ogr Control.
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

#ifndef OGR_CTL_HPP_INCLUDED
#define OGR_CTL_HPP_INCLUDED

#include "ogr_base.h"
#include "ust/ust_stringtype.hpp"
#include "ust/ust_containertype.hpp"

// hub
class CHubModuleCtl;
// ogr
class COgrTypeCtl;
class COgrDriverCtl;

class OGR_LIB COgrCtl
{
  public:
    COgrCtl(CHubModuleCtl *aModule);
    ~COgrCtl();

    // Init and cleanup all.
    UErrCodeT Init();
    CHubModuleCtl *Up();

    COgrTypeCtl *Type();

    // Register and deregister driver.
    UErrCodeT RegisterAll();
    UErrCodeT DeregisterAll();
    UErrCodeT Register(const UStringT *aName);
    UErrCodeT Register(OgrFormatCodeT aFormat);
    UErrCodeT Deregister(const UStringT *aName);
    UErrCodeT Deregister(OgrFormatCodeT aFormat);

    // Get Driver.
    COgrDriverCtl *Driver(const UStringT *aName);
    COgrDriverCtl *Driver(OgrFormatCodeT aFormat);

  protected:
  private:
    typedef UContainerT<COgrDriverCtl*, UStringT> MDriverT;
    typedef UIteratorT<COgrDriverCtl*, UStringT> MDriverItT;

    UErrCodeT CleanupAll();

    // ogr
    UErrCodeT OgrRegisterAll();
    UErrCodeT OgrCleanupAll();

    CHubModuleCtl *mModule;
    COgrTypeCtl *mType;

    // Driver name to "COgrDriverCtl".
    MDriverT mMDriver;
};

#endif  /* OGR_CTL_HPP_INCLUDED */
