// Copyright (c) 1999-2014 OPEN CASCADE SAS
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

#include <StepGeom_Surface.hxx>
#include <StepShape_HalfSpaceSolid.hxx>
#include <TCollection_HAsciiString.hxx>

IMPLEMENT_STANDARD_RTTIEXT(StepShape_HalfSpaceSolid, StepGeom_GeometricRepresentationItem)

StepShape_HalfSpaceSolid::StepShape_HalfSpaceSolid() {}

void StepShape_HalfSpaceSolid::Init(const Handle(TCollection_HAsciiString)& aName,
                                    const Handle(StepGeom_Surface)&         aBaseSurface,
                                    const Standard_Boolean                  aAgreementFlag)
{
  // --- classe own fields ---
  baseSurface   = aBaseSurface;
  agreementFlag = aAgreementFlag;
  // --- classe inherited fields ---
  StepRepr_RepresentationItem::Init(aName);
}

void StepShape_HalfSpaceSolid::SetBaseSurface(const Handle(StepGeom_Surface)& aBaseSurface)
{
  baseSurface = aBaseSurface;
}

Handle(StepGeom_Surface) StepShape_HalfSpaceSolid::BaseSurface() const
{
  return baseSurface;
}

void StepShape_HalfSpaceSolid::SetAgreementFlag(const Standard_Boolean aAgreementFlag)
{
  agreementFlag = aAgreementFlag;
}

Standard_Boolean StepShape_HalfSpaceSolid::AgreementFlag() const
{
  return agreementFlag;
}
