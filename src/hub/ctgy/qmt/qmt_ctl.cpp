/******************************************************************************
 * $Id: qmt_ctl.cpp 2018-01 $
 *
 * Project:  QMT (QMT: Quantized Mesh Tile).
 * Purpose:  QMT controler implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2018-01 ~ 2018, Weiwei Huang
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

#include "qmt_ctl.hpp"

// hub
#include "hub_modulectl.hpp"
// qmt
#include "qmt_terrtile.hpp"

/**
 * \brief Constructor.
 */
CQmtCtl::CQmtCtl(CHubModuleCtl *aModule)
{
    InitPointer();
    mModule = aModule;
}

/**
 * \brief Destructor.
 */
CQmtCtl::~CQmtCtl()
{
    BMD_CLASS_DEL(mTerrTile);
}

/**
 * \brief Initialize.
 */
UErrCodeT CQmtCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Terrain tile.
 */
CQmtTerrTile *CQmtCtl::TerrTile()
{
    BMD_CLASS_NEW(mTerrTile, CQmtTerrTile);

    return mTerrTile;
}

/***** Private A *****/
UErrCodeT CQmtCtl::InitPointer()
{
    BMD_POINTER_INIT(mModule);
    BMD_POINTER_INIT(mTerrTile);

    return UErrFalse;
}

/***** Private B *****/
