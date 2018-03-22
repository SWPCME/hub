# !bash --posix
################################################################################
# $Id: test_main.sh 2016-08 $
#
# Project:  Test for shell.
# Purpose:  Test main.
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

# \brief Test main function.
#
# \param $aFun function that selected.
#
# \return $SH_HUB_OK, if successful; $SH_HUB_ER, if failed.
sh_test_init()
{
    # Constant.
    local readonly SH_HUBLIB_PATH="../../itpt/sh"
    local readonly SH_HUBCTL_PATH="$SH_HUBLIB_PATH/hub_ctl.sh"

    # Load.
    . $SH_HUBCTL_PATH

    # Initialize.
    sh_hubctl_init $SH_HUBLIB_PATH
    if [ $? = $SH_HUB_ER ]; then
        return $SH_HUB_ER
    fi

    return $SH_HUB_OK
}

# \brief Test main function.
#
# \param $aModule module that selected.
#
# \return $SH_HUB_OK, if successful; $SH_HUB_ER, if failed.
sh_test_main()
{
    # Initialize.
    sh_test_init
    if [ $? = $SH_HUB_ER ]; then
        return $SH_HUB_ER
    fi

    # Check parameter.
    if [ $# = 1 ]; then
        local readonly aModule="$1"
    else
        return $SH_HUB_ER
    fi

    sh_stdlibctl_load $SH_HUBLIB_SYS

    case $aModule in
        "all" )
            shpri_test_all()
            {
                sh_stdioctl_print "Test all module."
            }
            shpri_test_all
            sh_stdfuncctl_unset shpri_test_all
            ;;
        "std" )
            shpri_test_std()
            {
                sh_stdioctl_print "Test std module."
            }
            shpri_test_std
            sh_stdfuncctl_unset shpri_test_std
            ;;
        "sys" )
            shpri_test_sys()
            {
                sh_stdioctl_print "Test sys module."
            }
            shpri_test_sys
            sh_stdfuncctl_unset shpri_test_sys
            ;;
    esac
}

# \brief Main entry.
sh_test_main $1
