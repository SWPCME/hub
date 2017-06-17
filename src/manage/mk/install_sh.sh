# !bash --posix
################################################################################
# $Id: me_installsh.sh 2017-05 $
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

# Directory.
# Source.
PRJ_DIR=../../../
SRC_DIR=${PRJ_DIR}/src
ITPT_DIR=${SRC_DIR}/itpt
SH_SRC_DIR=${ITPT_DIR}/sh
# Destination.
ME_DIR=~/me
USR_DIR=${ME_DIR}/usr
INCLUDE_DIR=${USR_DIR}/include
INCLUDE_HUB_DIR=${INCLUDE_DIR}/hub
INCLUDE_ITPT_DIR=${INCLUDE_HUB_DIR}/itpt
INCLUDE_SH_DIR=${INCLUDE_ITPT_DIR}

# Software.
CPDIR="cp -r"
MKDIR="mkdir -p"

# Check
if [ ! -d $INCLUDE_SH_DIR ] ; then
    $MKDIR $INCLUDE_SH_DIR
fi

$CPDIR $SH_SRC_DIR $INCLUDE_SH_DIR
