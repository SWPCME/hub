################################################################################
# $Id: Makefile 2018-05 $
#
# Project:  Bsn.
# Purpose:  Bsn library makefile.
# Author:   Weiwei Huang, 898687324@qq.com
#
################################################################################
# Copyright (c) 2016-08 ~ 2017 Weiwei Huang
#
# This program is free software; you can redistribute it and/or modify it under 
# the terms of the GNU General Public License as published by the Free Software 
# Foundation, either version 3 of the License, or (at your option) any later 
# version.
#
# This program is distributed in the hope that it will be useful, but WITHOUT 
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS 
# FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more 
# details.
#
# You should have received a copy of the GNU General Public License along with 
# this program.  If not, see <http://www.gnu.org/licenses/>.
################################################################################

#
# Options.
#
# Directory.
SRC_DIR = ../../..
OBJ_DIR = $(BUILD_DIR)/$(TARGET_OS)/bsn
# Search.
INCLUDE_DIR = -I$(HUB_DIR) -I$(BASE_DIR) \
	-I$(CORE_DIR) -I$(CLS_DIR) -I$(CCS_DIR) -I${GDA_DIR} -I$(OGR_DIR) \
	-I$(GSL_DIR) -I$(CUT_DIR) -I$(PLP_DIR) -I$(PYC_DIR) \
	-I$(WRAP_DIR) -I$(UST_DIR) -I$(RST_DIR) -I$(VTR_DIR) -I$(NCC_DIR) \
	-I$(CTGY_DIR) -I$(RTK_DIR) -I$(FMD_DIR) -I$(QMT_DIR) -I$(ERA_DIR)

# Include.
OPT_LST = $(SRC_DIR)/opt.lst
include $(OPT_LST)

default: create_lib

clean: clean_lib

install: default install_lib
