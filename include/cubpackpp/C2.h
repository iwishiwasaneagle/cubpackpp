// #  Copyright 2023 Jan-Hendrik Ewers
// #  SPDX-License-Identifier: GPL-3.0-only

/////////////////////////////////////////////////////////
//                                                     //
//    Cubpack++                                        //
//                                                     //
//        A Package For Automatic Cubature             //
//                                                     //
//        Authors : Ronald Cools                       //
//                  Dirk Laurie                        //
//                  Luc Pluym                          //
//                                                     //
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
// File : C2.h
// History:
//   (date)          (version)
//   19 Aug 1994     V0.1 (first limited distribution)
/////////////////////////////////////////////////////////
// DEFINITION OF CLASS Parallelogram
// -------------------------------------------------
//
// BASECLASSES:
//   Geometry
//
// PURPOSE:
//   the geometry of a 2D parallelogram
//
// TEMPLATES:
//   None
//
// METHODS:
//   CONSTRUCTORS:
//     1)Parallelogram(const Point& A,
//                     const Point& B,
//                     const Point& C)
//     -------------------------------
//     constructs a parallelogram with vertices
//     A, B, C and D= B+C-A.
//
//   SELECTORS:
//     1) const Point& Vertex (int i ) const
//     -------------------------------------
//     returns the i-th vertex. 0<=i<3
//     referring to the constructor, i=0 returns A,
//     i=1 B and i=2 C. D can't be retrieved.
//
//     2) real Volume() const
//     ----------------------
//
//     3) Processor<Parallelogram>* DefaultProcessor()const
//     ----------------------------------------------------
//
//
//   MODIFIERS:
//     1) void Volume(real)
//     --------------------
//     informs the par. about its volume, in order to
//     avoid computation of it
//
//   OPERATORS:
//     None
//
//   SPECIAL:
//     None
//
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
#ifndef C2_H
#define C2_H
/////////////////////////////////////////////////////////

#include "cubpackpp/boolean.h"
#include "cubpackpp/geometry.h"
#include "cubpackpp/point.h"
#include "cubpackpp/real.h"
#include "cubpackpp/regproc.h"
#include "cubpackpp/vector.h"

namespace cubpackpp {
/////////////////////////////////////////////////////////
class Parallelogram : public ::cubpackpp::Geometry {
public:
  Parallelogram(const Point &, const Point &, const Point &);

  const Point &Vertex(unsigned int) const;

  real Volume() const;

  void Volume(real);

private:
  Vector<Point> Vertices;
  real TheVolume;
  Boolean TheVolumeKnown;

  void ComputeVolume();
};
/////////////////////////////////////////////////////////
} // namespace cubpackpp
#endif
