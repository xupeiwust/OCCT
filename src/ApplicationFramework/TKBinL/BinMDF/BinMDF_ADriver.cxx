// Created on: 2002-10-29
// Created by: Michael SAZONOV
// Copyright (c) 2002-2014 OPEN CASCADE SAS
//
// This file is part of Open CASCADE Technology software library.
//
// This library is free software; you can redistribute it and/or modify it under
// the terms of the GNU Lesser General Public License version 2.1 as published
// by the Free Software Foundation, with special exception defined in the file
// OCCT_LGPL_EXCEPTION.txt. Consult the file LICENSE_LGPL_21.txt included in OCCT
// distribution for complete text of the license and disclaimer of any warranty.
//
// Alternatively, this file may be used under the terms of Open CASCADE
// commercial license or contractual agreement.

#include <BinMDF_ADriver.hxx>

IMPLEMENT_STANDARD_RTTIEXT(BinMDF_ADriver, Standard_Transient)

//=================================================================================================

BinMDF_ADriver::BinMDF_ADriver(const Handle(Message_Messenger)& theMsgDriver,
                               const Standard_CString           theName)
    : myMessageDriver(theMsgDriver)
{
  if (theName)
    myTypeName = theName;
}

//=================================================================================================

const Handle(Standard_Type)& BinMDF_ADriver::SourceType() const
{
  return NewEmpty()->DynamicType();
}
