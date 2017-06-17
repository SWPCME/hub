# !bash --posix
################################################################################
# $Id: hub_modulectl.sh 2016-08 $
#
# Project:  Hub of shell.
# Purpose:  Hub module ctl.
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
sh_hubmodulectl_init()
{
    # Constant.
    local readonly baseLib=${SH_HUB_PATH}/hub_base.sh

    # Load library.
    . $baseLib
    . $SH_HUBLIB_STD

    # Initialize library.
    sh_stdctl_init

    return $SH_HUB_OK
}

# \brief Register
#
# \param aLib library that to be loaded.
#
# \return $SH_HUB_OK, if successful; $SH_HUB_ER, if failed.
sh_hubmodulectl_register()
{
    # Check parameter.
    if [ $# = 1 ]; then
        local readonly aLib="$1"
    else
        return $SH_HUB_ER
    fi

    sh_stdlibctl_load $aLib

    return $SH_HUB_OK
}
