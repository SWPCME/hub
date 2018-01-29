[+ AutoGen5 template -*- mode: text -*-
################################################################################
# $Id: hub_ctl.tpl 2017-10 $
#
# Project:  Hub of amg (amg: automated generator).
# Purpose:  Hub controler.
# Author:   Weiwei Huang, 898687324@qq.com
#
################################################################################
# Copyright (c) 2017-10 ~ 2017 Weiwei Huang
#
# This program is free software; you can redistribute it and/or modify it under 
# the terms of the GNU General Public License as published by the Free Software 
# Foundation, either version 3 of the License, or \(at your option\) any later 
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
+]

[+
# \brief Hub controler.
+]
[+ Define HubCtl +]
[+ (emit "Hub controler.") +]
[+ EndDef # Hub controler. +]

[+
# \brief Hub initialize.
+]
[+ Define HubInit +]
[+ (emit "Hub initialize.") +]
[+ EndDef # Hub initialize. +]

[+
# \brief Hub module.
+]
[+ Define HubModule aModule +]
[+ Include aModule +]
[+ EndDef # Hub module. +]

[+
# \brief Include the base function.
+]
[+ Include "core/core_ctl.tpl" +]
