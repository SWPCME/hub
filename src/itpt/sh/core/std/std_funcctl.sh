# !bash --posix
################################################################################
# $Id: std_funcctl.sh 2017-01 $
#
# Project:  Standard library of shell.
# Purpose:  Function control.
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

# \brief Unset function in this process.
#
# \param aFunc function that needed to unset.
#
# \return $SH_HUB_OK, if successful; $SH_HUB_ER, if failed.
sh_stdfuncctl_unset()
{
    # Check parameter.
    if [ $# = 1 ]; then
        local readonly aFunc=$1
    else
        return $SH_HUB_ER
    fi

    unset -f $aFunc

    return $SH_HUB_OK
}
