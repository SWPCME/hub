/******************************************************************************
 * $Id: qmt_terrtile.cpp 2018-02 $
 *
 * Project:  QMT (QMT: Quantized Mesh Tile).
 * Purpose:  QMT terrain tile implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2018-02 ~ 2018, Weiwei Huang
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

#include "qmt_terrtile.hpp"

// python
#include <Python.h>
// pyqmt
#include "quantized_mesh_tile.h"

/**
 * \brief Constructor.
 */
CQmtTerrTile::CQmtTerrTile()
{
    // Create a new core module of pyc for the part of this module.
    // Boiler plate init Python.
    Py_SetProgramName((wchar_t *) "libhub");
    Py_Initialize();

    // Init our config module into Python memory.
    PyInit_pyqmt();
}

/**
 * \brief Destructor.
 */
CQmtTerrTile::~CQmtTerrTile()
{
    // Cleanup python before exit.
    Py_Finalize ();
}

/**
 * \brief Initialize.
 */
UErrCodeT CQmtTerrTile::Init()
{
    return UErrFalse;
}

/**
 * \brief Decode.
 */
UErrCodeT CQmtTerrTile::Decode()
{
    char *filePath = NULL;
    float bounds[4][3][3] = {
      {{7.3828125, 44.6484375, 303.3},
       {7.3828125, 45.0, 320.2},
       {7.5585937, 44.82421875, 310.2}},
      {{7.3828125, 44.6484375, 303.3},
       {7.734375, 44.6484375, 350.3},
       {7.734375, 44.6484375, 350.3}},
      {{7.734375, 44.6484375, 350.3},
       {7.734375, 45.0, 330.3},
       {7.5585937, 44.82421875, 310.2}},
      {{7.734375, 45.0, 330.3},
       {7.5585937, 44.82421875, 310.2},
       {7.3828125, 45.0, 320.2}}
    };
    int hasLighting = 0;
    int hasWatermask = 0;
    int gzipped = 0;

    pyqmt_decode(filePath, bounds, hasLighting, hasWatermask, gzipped);

    return UErrFalse;
}
