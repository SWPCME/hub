# !bash --posix
################################################################################
# $Id: hub_install.sh 2017-05 $
#
# Project:  Hub of shell.
# Purpose:  Hub install.
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

# Include
INCLUDE_HUB=~/me/usr/include/hub
INCLUDE_HUB_SH=${INCLUDE_HUB}/itpt/sh

# OS
OS_TYPE=GNU/LINUX
OS_TYPE=WINDOWS

# Directory.
HUB_DIR=../../hub
HUB_LIB_NAME_SO=libhub.so
HUB_LIB_SRC_DIR=${HUB_DIR}
HUB_LIB_SRC_FILE=${HUB_LIB_SRC_DIR}/${HUB_LIB_NAME_SO}
HUB_LIB_DEST_DIR=${HUB_DIR}/../lib
HUB_LIB_DEST_DIR=${HUB_DIR}/${HUB_LIB_NAME_SO}

# Software.
CP=cp

# Library

# Include
${CP}
