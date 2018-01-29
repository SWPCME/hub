/******************************************************************************
 * $Id: whub_gdactl.i 2017-09 $
 *
 * Project:  whub (Wrap hub).
 * Purpose:  Gda api.
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

%module "WHubGda"
%{
#include "gda/gda_ctl.hpp"
#include "gda/gda_corectl.hpp"
#include "gda/gda_driversctl.hpp"
#include "gda/gda_driverctl.hpp"
#include "gda/gda_datasetctl.hpp"
#include "gda/gda_bandctl.hpp"
%}

class CGdaCtl
{
  public:
    CGdaCtl(CHubModuleCtl *aModule);
    ~CGdaCtl();

    // Init.
    UErrCodeT Init();

    // Controler.
    CGdaCoreCtl *Core();
    CGdaOgrCtl *Ogr();
    CGdaAlgCtl *Alg();
    CGdaUtilsCtl *Utils();

    // Private controler.
    CGdaTypeCtl *Type();
};

class CGdaCoreCtl
{
  public:
    UErrCodeT Init();
    CGdaDriversCtl *Drivers();
};

class CGdaDriversCtl
{
  public:
    // Init.
    UErrCodeT Init();

    // Register and deregister.
    UErrCodeT Register(const UStringT *aName);
    UErrCodeT Register(const GdaFormatCodeT aFormat);
    UErrCodeT RegisterAll();
    UErrCodeT Deregister(const UStringT *aName);
    UErrCodeT Deregister(const GdaFormatCodeT aFormat);
    UErrCodeT DeregisterAll();

    // Driver.
    CGdaDriverCtl *Driver(const UStringT *aName);
    CGdaDriverCtl *Driver(const GdaFormatCodeT aFormat);
};

class CGdaDriverCtl
{
  public:
    CGdaDriverCtl(const UStringT *aName);
    ~CGdaDriverCtl();

    UErrCodeT Init();
    CGdaDatasetCtl *Create(const UStringT *aFile, UIntT aXSize, UIntT aYSize,
                           UIntT aNBands, UDataTCodeT aDataT, char **aOption);
    CGdaDatasetCtl *Load(const UStringT *aFile, const UAccessCodeT aAccess);
    UErrCodeT Close(const UStringT *aFile);
    UErrCodeT Delete(const UStringT *aFile);
};

class CGdaDatasetCtl
{
  public:
    CGdaDatasetCtl(const UStringT *aFile, const GdaDatasetAttrT *aAttr,
                   const GdaDriverHT aDriver);
    CGdaDatasetCtl(const UStringT *aFile, UAccessCodeT aAccess);
    ~CGdaDatasetCtl();

    // Init
    UErrCodeT Init();

    // Attribute
    GdaDatasetHT Handle();
    UStringT Description();

    UErrCodeT Save();
    UErrCodeT Count(UIntT *aNum);
    UErrCodeT AddBand(UDataTCodeT aDataT, UStringT *aOption);
    CGdaBandCtl *Band(UIntT aId);
    UErrCodeT SetBand(UIntT aDstId, CGdaBandCtl *aSrcBand);
    UErrCodeT XSize(UIntT *aNum);
    UErrCodeT YSize(UIntT *aNum);
};

class CGdaBandCtl
{
  public:
    CGdaBandCtl(UDataTCodeT aDataT, const UStringT *aOption,
                CGdaDatasetCtl *aDsCtl);
    CGdaBandCtl(UIntT aId, CGdaDatasetCtl *aDsCtl);
    ~CGdaBandCtl();

    // Init.
    UErrCodeT Init();

    // Attribute.
    GdaBandHT Handle();

    // Framework.
    CGdaDatasetCtl *Up();

    // Color.
    CGdaBandColor *Color();
    UErrCodeT SetColor(CGdaBandColor *aColor);

    // Size.
    UErrCodeT BlockSize(UIntT *aX, UIntT *aY);
    UErrCodeT Min(UFloatT *aVal);
    UErrCodeT Max(UFloatT *aVal);
    UErrCodeT XSize(UIntT *aSize);
    UErrCodeT YSize(UIntT *aSize);

    // Read and write.
    UErrCodeT Read(GdaBandDataT *aData);
    UErrCodeT ReadBlock(UDataT aData, UIntT aXOff, UIntT aYOff);
    UErrCodeT Write(GdaBandDataT *aData);
};

class GdaBandDataT
{
  public:
    GdaBandDataT();
    GdaBandDataT(const UDataTCodeT aType, const BMathCsC2dT *aBegin,
                 const BMathCsC2dT *aEnd);
    ~GdaBandDataT();

    UErrCodeT SetAll(const UDataTCodeT aType, const BMathCsC2dT *aBegin,
                     const BMathCsC2dT *aEnd);
    UErrCodeT SetType(const UDataTCodeT aType);
    UErrCodeT SetBegin(const BMathCsC2dT *aBegin);
    UErrCodeT SetEnd(const BMathCsC2dT *aEnd);

    UDataTCodeT Type();
    BMathCsC2dT *Begin();
    BMathCsC2dT *End();
    UDataT Handle();
};
