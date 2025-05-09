// Copyright (c) 2023 OPEN CASCADE SAS
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

#include <AIS_AnimationAxisRotation.hxx>

IMPLEMENT_STANDARD_RTTIEXT(AIS_AnimationAxisRotation, AIS_BaseAnimationObject)

//=================================================================================================

AIS_AnimationAxisRotation::AIS_AnimationAxisRotation(
  const TCollection_AsciiString&        theAnimationName,
  const Handle(AIS_InteractiveContext)& theContext,
  const Handle(AIS_InteractiveObject)&  theObject,
  const gp_Ax1&                         theAxis,
  const Standard_Real                   theAngleStart,
  const Standard_Real                   theAngleEnd)
    : AIS_BaseAnimationObject(theAnimationName, theContext, theObject),
      myRotAxis(theAxis),
      myAngleStart(theAngleStart),
      myAngleEnd(theAngleEnd)
{
  //
}

//=================================================================================================

void AIS_AnimationAxisRotation::update(const AIS_AnimationProgress& theProgress)
{
  if (myObject.IsNull())
  {
    return;
  }

  gp_Trsf       aTrsf;
  Standard_Real aCurrentAngle =
    (1.0 - theProgress.LocalNormalized) * myAngleStart + theProgress.LocalNormalized * myAngleEnd;
  aTrsf.SetRotation(myRotAxis, aCurrentAngle);
  updateTrsf(aTrsf);
}
