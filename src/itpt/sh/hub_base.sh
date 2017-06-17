# !bash --posix
################################################################################
# $Id: hub_base.sh 2016-08 $
#
# Project:  Hub base of shell.
# Purpose:  Hub base.
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
# GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.
################################################################################

# \brief Hub status.
readonly SH_HUB_OK=0
readonly SH_HUB_ER=1

# \brief Hub path.
readonly SH_HUBPATH_CORE=${SH_HUB_PATH}/core
readonly SH_HUBPATH_STD=${SH_HUBPATH_CORE}/std
readonly SH_HUBPATH_SYS=${SH_HUBPATH_CORE}/sys

# \brief Hub library.
readonly SH_HUBLIB_STD=${SH_HUBPATH_STD}/std_ctl.sh
readonly SH_HUBLIB_SYS=${SH_HUBPATH_SYS}/sys_ctl.sh
