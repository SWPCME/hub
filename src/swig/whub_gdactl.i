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
#include "gda/gda_utilsctl.hpp"
#include "gda/gda_utilstr.hpp"
#include "gda/gda_trrst.hpp"
#include "gda/gda_trrsttorsttype.hpp"
#include "gda/gda_ogrsrstype.hpp"
#include "gda/gda_ogrctrtype.hpp"
%}

typedef enum
{
    // 0 ~ 99 for raster format.
    GdaFormatNRst = 0,          /* None raster. */
    GdaFormatAsc  = 1,          /* Arc/Info ASCII Grid. */
    GdaFormatLcp  = 2,          /* FARSITE v.4 Landscape File. */
    GdaFormatDem  = 3,          /* USGSDEM. */
    GdaFormatTif  = 4,          /* GTiff. */
    GdaFormatVrt  = 5,          /* Virtual Raster. */

    // 100 ~ 199 for vector formt.
    GdaFormatNVtr   = 100,      /* None vector. */
    GdaFormatTab    = 101,
    GdaFormatShp    = 102,
    GdaFormatCsv    = 103,
    GdaFormatXls    = 104,
    GdaFormatXlsx   = 105,
    GdaFormatSqlite = 106,
    GdaFormatJson   = 107,
} GdaFormatCodeT;

typedef enum
{
    GdaProjCsUnknown  = 0,
    GdaProjCsWgs1984  = 1,
    GdaProjCsXian1980 = 2,
    GdaProjCsNad1983  = 3,
} GdaProjCsCodeT;

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

    // coordinate system info
    UErrCodeT GeoTransform(BCtnFloatT *aTransform);
    UErrCodeT InvGeoTransform(BCtnFloatT *aTransform);
    UErrCodeT IdToPos(BMathCsC2dT *aDst, BMathCsC2dT *aSrc);
    UErrCodeT PosToId(BMathCsC2dT *aDst, BMathCsC2dT *aSrc);
    UErrCodeT XSize(UIntT *aNum);
    UErrCodeT YSize(UIntT *aNum);

    // close
    UErrCodeT Close(const UIntT aBandId);
    UErrCodeT CloseAll();
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

    // Data attribute.
    UDataTCodeT DataT();
    UDataTCodeT UnitT();
    UErrCodeT SetUnitT(UDataTCodeT aUnitT);
    UFloatT NoDataVal(UErrCodeT *aErr = NULL);
    UErrCodeT SetNoDataVal(const UFloatT aVal);

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
    UErrCodeT ReadBlock(UDataHT aData, UIntT aXOff, UIntT aYOff);
    UErrCodeT Write(GdaBandDataT *aData);
};

class GdaBandDataT
{
  public:
    GdaBandDataT();
    GdaBandDataT(const UDataTCodeT aType, const BMathCsC2dT *aBegin,
                 const BMathCsC2dT *aEnd);
    GdaBandDataT(const UDataTCodeT aType, const BMathCsC2dT *aId);
    ~GdaBandDataT();

    UErrCodeT SetAll(const UDataTCodeT aType, const BMathCsC2dT *aBegin,
                     const BMathCsC2dT *aEnd);
    UErrCodeT SetType(const UDataTCodeT aType);
    UErrCodeT SetBegin(const BMathCsC2dT *aBegin);
    UErrCodeT SetEnd(const BMathCsC2dT *aEnd);

    UDataTCodeT Type();
    BMathCsC2dT *Begin();
    BMathCsC2dT *End();
    UDataHT Handle();

    UErrCodeT Data(UDataT *aData, const BMathCsC2dT *aId = NULL);
};

class CGdaUtilsCtl
{
  public:
    CGdaUtilsCtl();
    ~CGdaUtilsCtl();

    UErrCodeT Init();
    CGdaUtilsInfo *Info();
    CGdaUtilsTr *Tr();
    CGdaUtilsDem *Dem();
};

class CGdaUtilsTr
{
  public:
    CGdaUtilsTr();
    ~CGdaUtilsTr();

    UErrCodeT Init();
    CGdaTrVtr *Vtr();
    CGdaTrRst *Rst();
};

class CGdaTrRst
{
  public:
    CGdaTrRst();
    ~CGdaTrRst();

    UErrCodeT Init();
    CGdaTrRstProcCtl *ProcCtl();

    UErrCodeT ToRst(const UStringT *aDst, CGdaDatasetCtl *aSrc,
                    const GdaTrRstToRstT *aOpt);
};

class GdaTrRstToRstT
{
  public:
    GdaTrRstToRstT();
    GdaTrRstToRstT(const GdaFormatCodeT aFrmt, const BCtnStringT *aOpt);
    ~GdaTrRstToRstT();

    // Set.
    UErrCodeT SetAll(const GdaFormatCodeT aFrmt, const BCtnStringT *aOpt);
    UErrCodeT SetOpt(const BCtnStringT *aOpt);
    UErrCodeT SetFrmt(const GdaFormatCodeT aFrmt);
    UErrCodeT SetSrs(const GdaOgrSrsT *aSrs);
    UErrCodeT SetSrcWin(const BMathCsC2dT *aOff, const BMathCsC2dT *aSize);
    UErrCodeT SetBand(const BCtnIntT *aNumS);

    // Get.
    GdaFormatCodeT Frmt() const;
    GdaOgrSrsT *Srs() const;
    GdaTrRstProcHT Handle() const;
};

class GdaOgrSrsT
{
  public:
    GdaOgrSrsT();
    ~GdaOgrSrsT();

    UErrCodeT ImportFromWkt(const UStringT *aWkt);
    UErrCodeT SetProjCs(const GdaProjCsCodeT aCode);
    UErrCodeT ExportToWkt(UStringT *aWkt);
};

class GdaOgrCtrT
{
  public:
    GdaOgrCtrT();
    GdaOgrCtrT(const GdaOgrSrsT *aSrc, const GdaOgrSrsT *aDst);
    ~GdaOgrCtrT();

    UErrCodeT Tr(BMathCsC2dT *aDst, const BMathCsC2dT *aSrc);
};
