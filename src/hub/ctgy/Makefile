################################################################################
# $Id: Makefile 2017-05 $
#
# Project:  Makefile of ctgy.
# Purpose:  Project management.
# Author:   Weiwei Huang, 898687324@qq.com
#
################################################################################
# Copyright (c) 2016 ~ 2017 Weiwei Huang
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
HUB_DIR = ..
# Search.
INCLUDE_DIR = -I$(HUB_DIR) -I$(BASE_DIR) -I$(CLS_DIR) -I$(CCS_DIR) \
	-I$(SYS_DIR) -I$(OGR_DIR) -I$(UST_DIR) -I$(EARTH_DIR) -I$(FMD_DIR)

# Include.
HUB_MAKEOPT = $(HUB_DIR)/hub_makeopt.mk
include $(HUB_MAKEOPT)

default: target_dir_default create_obj

clean: target_dir_clean clean_obj

install: target_dir_install
