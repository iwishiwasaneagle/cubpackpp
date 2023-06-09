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
// File : polC2prc.h
// History:
//   (date)          (version)
//   19 Aug 1994     V0.1 (first limited distribution)
/////////////////////////////////////////////////////////
// DEFINITION OF CLASS PolarRectangle_Processor
// -------------------------------------------------
//
// BASECLASSES:
//   Processor<PolarRectangle>
//
// PURPOSE:
//   transforms the polar rectangle into a rectangle
//
// TEMPLATES:
//   None
//
// METHODS:
//   CONSTRUCTORS:
//     1)PolarRectangle_Processor()
//     ----------------------------
//
//   SELECTORS:
//     None
//
//   MODIFIERS:
//     None
//
//   OPERATORS:
//     None
//
//   SPECIAL:
//     1) void Process(Stack<AtomicRegion>&)
//     -------------------------------------------------
//     see Processor<>
//
//     2) virtual Processor<Geometry>* NewCopy() const=0
//     -------------------------------------------------
//
//     makes a new copy (using the copy constructor) and
//     returns a pointer to it.
/////////////////////////////////////////////////////////
#ifndef POLC2PRC_H
#define POLC2PRC_H
//////////////////////////////////////////////
#include "cubpackpp/polC2.h"
#include "cubpackpp/regproc.h"

namespace cubpackpp {
/////////////////////////////////////////////
class PolarRectangle_Processor : public Processor<PolarRectangle> {
public:
  PolarRectangle_Processor();

  void Process(Stack<AtomicRegion> &);

  Processor<PolarRectangle> *NewCopy() const;
};
/////////////////////////////////////////////
} // namespace cubpackpp
#endif
