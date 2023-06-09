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
// File : atomic.h
// History:
//   (date)          (version)
//   19 Aug 1994     V0.1 (first limited distribution)
//   25 Jan 1996     V0.1f(typedef introduced)
/////////////////////////////////////////////////////////
// DEFINITION OF CLASS Atomic
// -------------------------------------------------
//
// BASECLASSES:
//   AtomicRegion
//
// PURPOSE:
//   provides a base class to all atomic regions.
//   provides a means for constructing them, as well
//   as for altering their integrand or processor
//   provides a method for processing them
//
// TEMPLATES:
//   it should be instantiated with a class Geometry
//   derived from Geometry
//   this Geometry should have a member
//     Processor<Geometry>* DefaultProcessor() const.
//
// METHODS:
//   CONSTRUCTORS:
//     1) Atomic(Geometry* G, Processor<Geometry>* P )
//     ------------------------------------------
//     constructs an atomic region with *G as its geometry
//     and *P as its processor
//
//
//   SELECTORS:
//     None
//
//   MODIFIERS:
//     1) Use(Processor<Geometry>* P)
//     -----------------------------
//     to change the processor to be used
//
//     2) LocalIntegrand(Integrand* I)
//     -------------------------------
//     to change the integrand
//
//   OPERATORS:
//     None
//
//   SPECIAL:
//     1) Process( Stack<AtomicRegion>& Offspring)
//     -------------------------------------------
//     attempts to compute an integral and an error
//     estimate. possible offspring is returned.
//
/////////////////////////////////////////////////////////
#ifndef ATOMIC_H
#define ATOMIC_H
////////////////////////////////////////////
#include "cubpackpp/atomreg.h"
#include "cubpackpp/regproc.h"

namespace cubpackpp {
//////////////////////////////////////////
template <class GEOMETRY> class Atomic : public AtomicRegion {
  friend

      class Processor<GEOMETRY>;

public:
  typedef Processor<GEOMETRY> ProcessorGEOMETRY;

  Atomic(GEOMETRY *, Processor<GEOMETRY> *);

  void Use(Processor<GEOMETRY> *);

  void Process(Stack<AtomicRegion> &Offspring);

  void LocalIntegrand(Integrand *);

private:
  Pointer<GEOMETRY> G_ptr;
  Pointer<ProcessorGEOMETRY> RP_ptr;
  Pointer<Integrand> I_ptr;

  RegionInfo *LocalRegionInfo();
};
///////////////////////////////////////////////
} // namespace cubpackpp
#include "cubpackpp/templist.h"

#ifdef TEMPLATEINCLUDE

#include "cubpackpp/atomic.tpp"

#endif
///////////////////////////////////////////////
#endif
