# !bash --posix
################################################################################
# $Id: file_ctl.sh 2017-01 $
#
# Project:  System library of shell.
# Purpose:  System library control.
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

# \brief Initialize.
#
# \return $SH_HUB_OK, if successful; $SH_HUB_ER, if failed.
sh_sysfilectl_init()
{
    return $SH_HUB_OK
}
