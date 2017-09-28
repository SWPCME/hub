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
#include "gda/gda_utilsctl.hpp"
#include "gda/gda_utilstranslate.hpp"
#include "gda/gda_translatevector.hpp"
#include "gda/gda_translateraster.hpp"
%}

%include "whub_ctl.i"
%include "whub_ustctl.i"

class CGdaCtl
{
  public:
    CGdaCtl();
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

class CGdaUtilsCtl
{
  public:
    UErrCodeT Init();
    CGdaUtilsInfo *Info();
    CGdaUtilsTranslate *Translate();
};

class CGdaUtilsTranslate
{
  public:
    UErrCodeT Init();
    CGdaTranslateVector *Vector();
    CGdaTranslateRaster *Raster();
};

class CGdaTranslateVector
{
  public:
    UErrCodeT Init();

    // To vector.
    UErrCodeT ToVtr(const UStringT *aDstFile, COgrDatasrcCtl *aSrcDs,
                    const GdaTranslateV2VOptT *aOpt);

    // To raster.
    UErrCodeT ToRst(CGdaDatasetCtl *aDstDs, COgrDatasrcCtl *aSrcDs,
                    const GdaV2RLoadOptT *aOpt);
    UErrCodeT ToRst(const UStringT *aDstFile, COgrDatasrcCtl *aSrcDs,
                    const GdaV2RCreateOptT *aOpt);
    UErrCodeT ToRst(CGdaBandCtl *aDstBand, COgrLayerCtl *aSrcLayer,
                    const UStringT *aSrcFieldName);
};

class CGdaTranslateRaster
{
  public:
    UErrCodeT Init();
    UErrCodeT ToRst(const UStringT *aFile, CGdaDatasetCtl *aSrcDsCtl,
                    const GdaTranslateR2ROptT *aOpt);
};
