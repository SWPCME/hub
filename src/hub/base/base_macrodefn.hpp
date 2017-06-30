/******************************************************************************
 * $Id: base_macrodefn.hpp 2016-08 $
 *
 * Project:  Base.
 * Purpose:  Macro definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016 ~ 2017 Weiwei Huang
 *
 * This program is free software; you can redistribute it and/or modify it 
 * under the terms of the GNU General Public License as published by the Free 
 * Software Foundation, either version 3 of the License, or (at your option) 
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT 
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for 
 * more details.
 *
 * You should have received a copy of the GNU General Public License along 
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 *****************************************************************************/

#ifndef BASE_MACRODEFN_HPP_INCLUDED
#define BASE_MACRODEFN_HPP_INCLUDED

#define BMD_POINTER_INIT(aName) \
    aName = NULL

#define BMD_CLASS_H(aName, aClass) \
    ((aClass *) aName)
    
#define BMD_CLASS_NEWH(aName, aClass, aHandle) \
    if (aName == NULL)                         \
    {                                          \
        aName = (aHandle *) new aClass;        \
        BMD_CLASS_H(aName, aClass)->Init();    \
    }

#define BMD_CLASS_ONEWH(aName, aClass, aHandle) \
    if (aName == NULL)                          \
    {                                           \
        aName = (aHandle *) new aClass;         \
    }

#define BMD_CLASS_NEW(aName, aClass) \
    BMD_CLASS_NEWH(aName, aClass, aClass)

#define BMD_CLASS_DELH(aName, aClass) \
    if (aName != NULL)                \
    {                                 \
        delete (aClass *) aName;      \
        BMD_POINTER_INIT(aName);      \
    }

#define BMD_CLASS_DEL(aName) \
    if (aName != NULL)       \
    {                        \
        delete aName;        \
    }

#define BMD_BASE_CTL(aCtl) CBaseCtl *aCtl = CBaseCtl::Base()

#define BMD_CORE_CTL(aCtl)                      \
    BMD_BASE_CTL(baseCtl);                      \
    CCoreCtl *aCtl = baseCtl->Core()

#define BMD_WRAP_CTL(aCtl)                             \
    BMD_BASE_CTL(baseCtl);                             \
    CWrapCtl *aCtl = baseCtl->Wrap()

#define BMD_CTGY_CTL(aCtl)                          \
    BMD_BASE_CTL(baseCtl);                          \
    CCtgyCtl *aCtl = baseCtl->Ctgy()

#endif  // BASE_MACRODEFN_HPP_INCLUDED
