/******************************************************************************
 * $Id: whub_ctl.i 2017-09 $
 *
 * Project:  whub (Wrap hub).
 * Purpose:  Api for hub.
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

%module "WHub"
%{
#include "hub_ctl.hpp"
%}

// The template obj must be at the bottom,
// for example, to process "whub_ustctl.i" must be after "whub_fmdctl.i".
%include "whub_base.i"
%include "whub_fmdctl.i"
%include "whub_ustctl.i"
%include "whub_gdactl.i"
%include "whub_ogrctl.i"
%include "whub_rstctl.i"

%pragma(java) jniclasscode=%{
     private static boolean available = false;

     static {
         try {
             System.loadLibrary("whub");
             available = true;
         } catch (UnsatisfiedLinkError e) {
             available = false;
             System.err.println("Native library load failed.");
             System.err.println(e);
         }
     }

     public static boolean isAvailable() {
         return available;
     }
%}

%pragma(java) jniclassimports=%{
import whub.*;
%}

%pragma(java) moduleimports=%{
import whub.*;
%}

typedef enum
{
    UErrFalse = 0,
    UErrTrue  = 1,
} UErrCodeT;

typedef enum
{
    UFileOperCreate = 1,
    UFileOperLoad   = 2,
    UFileOperClose  = 3,
    UFileOperDelete = 4,
} UFileOperCodeT;

/* typedef int UHandleT; */
typedef int UHandleT;
typedef int UIntT;
typedef double UFloatT;

typedef enum
{
    /* Core module */
    HubMCls = 1,                /* C language standard library. */
    HubMCcs = 2,                /* C with class standard library. */
    HubMSys = 3,                /* System library. */
    HubMOgr = 4,                /* OpenGIS Simple Features Reference 
                                   Implementation. */
    HubMGda = 5,                /* Geospatial Data Absraction. */
    HubMGsl = 6,                /* Gnu Scientific Library. */
    HubMCut = 7,                /* Client-side URL Transfer. */

    /* Wrap module */
    HubMUst = 1001,             /* Universal struct type library. */
    HubMRst = 1002,             /* Raster library. */
    HubMVtr = 1003,             /* Vector library. */

    /* Ctgy module */
    // Fire
    HubMFmd = 2001,             /* Firemod library. */
} HubCodeT;

class CHubCtl
{
  public:
    static CHubCtl* Hub();
    UErrCodeT Init();
    UErrCodeT Register(HubCodeT aCode);
    UErrCodeT RegisterAll();
    UErrCodeT Deregister(HubCodeT aCode);
    UErrCodeT DeregisterAll();
    CGdaCtl *Gda();
    COgrCtl *Ogr();
    CRstCtl *Rst();
    CFmdCtl *Fmd();
};
