[+ AutoGen5 template -*- mode: text -*-
################################################################################
# $Id: asf_ioctl.tpl 2017-10 $
#
# Project:  Hub of amg (amg: automated generator).
# Purpose:  Asf input and output controler.
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
# \brief Asf io controler.
+]
[+ Define Asf +]
[+ (emit "Asf input and output controler.") +]
[+ EndDef # Asf io controler. +]

[+
# \brief Get Valuable.
+]
[+ Define HubAsfGet aVal +]
[+ (get (get "aVal")) +]
[+ EndDef # HubAsfGet +]

[+
# \brief Output.
+]
[+ Define HubAsfEmit aVal +]
[+ (emit (HubAsfGet "aVal")) +]
[+ EndDef # HubAsfEmit +]