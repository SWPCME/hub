# !bash --posix
################################################################################
# $Id: std_libctl.sh 2017-01 $
#
# Project:  Standard library of shell.
# Purpose:  library control.
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

# \brief Load library in this process.
#
# \param aLib file of lib.
#
# \return $SH_HUB_OK, if successful; $SH_HUB_ER, if failed.
sh_stdlibctl_load()
{
    # Check parameter.
    if [ $# = 1 ]; then
        local readonly aLib=$1
    else
        return $SH_HUB_ER
    fi

    . $aLib

    return $SH_HUB_OK
}

# \brief Get version of library.
#
# \param aLib file of lib.
#
# \return $SH_HUB_OK, if successful; $SH_HUB_ER, if failed.
sh_stdlibctl_ver()
{
    return $SH_HUB_OK
}
