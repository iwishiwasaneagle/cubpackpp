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
// File : E2secprc.h
// History:
//   (date)          (version)
//   19 Aug 1994     V0.1 (first limited distribution)
/////////////////////////////////////////////////////////
// DEFINITION OF CLASS PlaneSector_Processor
// -------------------------------------------------
//
// BASECLASSES:
//   Processor<PlaneSector>
//
// PURPOSE:
//   transforms the plane sector into a semi-infinite strip
//
// TEMPLATES:
//   None
//
// METHODS:
//   CONSTRUCTORS:
//     1)PlaneSector_Processor()
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
#ifndef E2SECPRC_H
#define E2SECPRC_H
//////////////////////////////////////////////
#include "cubpackpp/E2sec.h"
#include "cubpackpp/regproc.h"

namespace cubpackpp {
/////////////////////////////////////////////
class PlaneSector_Processor : public Processor<PlaneSector> {
public:
  PlaneSector_Processor();

  void Process(Stack<AtomicRegion> &);

  Processor<PlaneSector> *NewCopy() const;
};
/////////////////////////////////////////////
} // namespace cubpackpp
#endif
