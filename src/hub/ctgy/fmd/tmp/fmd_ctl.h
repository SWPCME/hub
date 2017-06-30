/******************************************************************************
 * $Id: fmd_ctl.h 2017-04 $
 *
 * Project:  Fmd.
 * Purpose:  Fmd ctl.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017 Weiwei Huang
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

#ifndef FMD_CTL_H_INCLUDED
#define FMD_CTL_H_INCLUDED

#define FMD_OK 0
#define FMD_ERR 1

class Farsite5;
class CUniCtl;

const int kNFile = 250;
const int kNMin = 100;
const int kMDefault = 0;
const int kMAnother = 1;
const char kSAsc[5] = ".asc";
const char kSFbg[5] = ".fbg";
const char kSShp[5] = ".shp";
const char kSCsv[5] = ".csv";
const char kSTxt[5] = ".txt";

struct FmdInFileCfgT
{
    char input[kNFile];
    char landscape[kNFile];
    char ignition[kNFile];
    char barrier[kNFile];
};

struct FmdOutCfgT
{
    char file[kNFile];
    int mode;
};

struct FmdCfgT
{
    FmdInFileCfgT inFile;
    FmdOutCfgT out;
};

class CFmdCtl
{
  public:
    CFmdCtl();
    ~CFmdCtl();

    int Init(CUniCtl *aUni);
    int Launch(const FmdCfgT *aCfg);

  protected:
  private:
    /** 
     * Load file.
     */
    // Load Configue.
    int LoadFile(const char *aLandscape, const char *aInput,
                 const char *aIgnition, const char *aBarrier);
    // Load landscape file.
    int LoadLandscape(const char *aFile);
    // Load input file.
    int LoadInput(const char *aFile);
    // Load input error.
    int LoadErr(int aErr);
    // Set ignition file.
    int LoadIgnition(const char *aFile);
    // Set barrier file.
    int LoadBarrier(const char *aFile);

    /**
     * Seting and run.
     */
    // Launch farsite.
    int LaunchFarsite();
    // Set time for fire.
    int SetTime(const char *aFile, int aMode);
    int SimulateTime(double *aTime);
    int InquireInBurnPeriod(double aTime);
    int ConvertSimtimeToActualTime(double aTime, long *aMo, long *aDy,
                                   long *aHr, long *aMn, bool aMode);
    int CmMapEnvironment(int aThemeno, double aMapTime, const char *aOutTime);

    /**
     * Write file.
     */
    int WriteFile(const char *aFile, int aMode);
    // Special.
    int WriteSpecial(const char *aFile, int aMode);
    int WriteCrownFireGrid(const char *aFile, int aMode);
    int WriteIntensityGrid(const char *aFile, int aMode);
    int WriteFlameLengthGrid(const char *aFile, int aMode);
    int WriteSpreadRateGrid(const char *aFile, int aMode);
    int WriteSpreadDirectionGrid(const char *aFile, int aMode);
    int WriteHeatPerUnitAreaGrid(const char *aFile, int aMode);
    int WriteReactionIntensityGrid(const char *aFile, int aMode);
    int WriteArrivalTimeGrid(const char *aFile, int aMode);
    // Common.
    int WriteCommon(const char *aFile);
    int WriteIgnitionGrid(const char *aFile);
    int WritePerimetersShape(const char *aFile);
    int WriteSpotGrid(const char *aFile);
    int WriteSpotData(const char *aFile);
    int WriteSpotShape(const char *aFile);
    int WriteTimings(const char *aFile);

    Farsite5 *mFarsite;
    FmdCfgT mCfg;
    CUniCtl *mUni;
};

#endif  // FMD_CTL_H_INCLUDED
