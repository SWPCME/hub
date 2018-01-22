/******************************************************************************
 * $Id: cls_fsfiletype.hpp 2018-01 $
 *
 * Project:  C language standard library.
 * Purpose:  File system file type implemention.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2018-01 ~ 2018, Weiwei Huang
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
 ****************************************************************************/

#include "cls_fsfiletype.hpp"

/**
 * \brief Constructor.
 */
ClsFsFileT::ClsFsFileT()
{
}

/**
 * \brief Destructor.
 */
ClsFsFileT::~ClsFsFileT()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT ClsFsFileT::Init()
{
    return UErrFalse;
}

/**
 * \brief Set all value.
 */
UErrCodeT ClsFsFileT::SetAll(const UStringT *aName,
                             const ClsFsFileTypeCodeT aType)
{
    SetName(aName);
    SetType(aType);

    return UErrFalse;
}

/**
 * \brief Set name.
 */
UErrCodeT ClsFsFileT::SetName(const UStringT *aName)
{
    mName = *aName;

    return UErrFalse;
}

/**
 * \brief Set type.
 */
UErrCodeT ClsFsFileT::SetType(const ClsFsFileTypeCodeT aType)
{
    mType = aType;

    return UErrFalse;
}

/**
 * \brief Get all value.
 */
UErrCodeT ClsFsFileT::All(UStringT *aName, ClsFsFileTypeCodeT *aType) const
{
    *aName = Name();
    *aType = Type();

    return UErrFalse;
}

/**
 * \brief Get name.
 */
UStringT ClsFsFileT::Name() const
{
    return mName;
}

/**
 * \brief Get type.
 */
ClsFsFileTypeCodeT ClsFsFileT::Type() const
{
    return mType;
}
