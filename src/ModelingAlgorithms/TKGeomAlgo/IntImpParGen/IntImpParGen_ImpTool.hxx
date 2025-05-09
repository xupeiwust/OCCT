// Created on: 1992-03-26
// Created by: Laurent BUCHARD
// Copyright (c) 1992-1999 Matra Datavision
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

#ifndef _IntImpParGen_ImpTool_HeaderFile
#define _IntImpParGen_ImpTool_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <Standard_Real.hxx>
class gp_Pnt2d;
class gp_Vec2d;

//! Template class for an implicit curve.
class IntImpParGen_ImpTool
{
public:
  DEFINE_STANDARD_ALLOC

  Standard_EXPORT gp_Pnt2d Value(const Standard_Real U) const;

  Standard_EXPORT void D1(const Standard_Real U, gp_Pnt2d& P, gp_Vec2d& T) const;

  Standard_EXPORT void D2(const Standard_Real U, gp_Pnt2d& P, gp_Vec2d& T, gp_Vec2d& N) const;

  //! Computes the value of the signed distance between
  //! the point P and the implicit curve.
  Standard_EXPORT Standard_Real Distance(const gp_Pnt2d& P) const;

  //! Computes the Gradient of the Signed Distance
  //! between a point and the implicit curve, at the
  //! point P.
  Standard_EXPORT gp_Vec2d GradDistance(const gp_Pnt2d& P) const;

  //! Returns the parameter U of the point on the
  //! implicit curve corresponding to the point P.
  //! The correspondence between P and the point P(U) on
  //! the implicit curve must be coherent with the way
  //! of determination of the signed distance.
  Standard_EXPORT Standard_Real FindParameter(const gp_Pnt2d& P) const;

protected:
private:
};

#endif // _IntImpParGen_ImpTool_HeaderFile
