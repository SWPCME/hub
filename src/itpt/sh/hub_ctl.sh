# !bash --posix
################################################################################
# $Id: hub_ctl.sh 2016-08 $
#
# Project:  Hub of shell.
# Purpose:  Hub ctl.
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
# \param aPath path of hub library.
#
# \return SH_HUB_OK.
sh_hubctl_init()
{
    # Check parameter.
    if [ $# = 0 ]; then
        local readonly aPath="."
    elif [ $# = 1 ]; then
        local readonly aPath="$1"
    else
        readonly SH_HUB_ER=1
        return $SH_HUB_ER
    fi

    # Hub path for global.
    readonly SH_HUB_PATH=$aPath

    # Constant.
    local readonly moduleCtlLib=${SH_HUB_PATH}/hub_modulectl.sh

    # Load library.
    . $moduleCtlLib

    # Initialize library.
    sh_hubmodulectl_init

    return $SH_HUB_OK
}

# \brief Register library.
#
# \param aLib library that to be loaded.
#
# \return $SH_HUB_OK, if successful; $SH_HUB_ER, if failed.
sh_hubctl_register()
{
    # Parameter
    local readonly aLib="$1"

    sh_hubmodulectl_register $aLib

    return $SH_HUB_OK
}

# \brief Register all function.
sh_hubctl_registerall()
{
    # sh_hubmodulectl_registerall

    return $SH_HUB_OK
}

# \brief Deregister library.
#
# \param aLib library that to be unloaded.
#
# \return $SH_HUB_OK, if successful; $SH_HUB_ER, if failed.
sh_hubctl_deregister()
{
    return $SH_HUB_OK
}

# \brief Deregister all function.
sh_hubctl_Deregisterall()
{
    sh_stdfuncctl_unset sh_hubctl_init

    return $SH_HUB_OK
}
