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
// File : passbuck.h
// History:
//   (date)          (version)
//   19 Aug 1994     V0.1 (first limited distribution)
/////////////////////////////////////////////////////////
// DEFINITION OF CLASS PassTheBuck
// -------------------------------------------------
//
// BASECLASSES:
//   Processor<TO>
//
// PURPOSE:
//   a processor for all regions that are immediately
//   transformed into new ones.
//
// TEMPLATES:
//   FROM: the new region, an Atomic<>
//   TO: the present Geometry
//   VIA: a Transformation from FROM to TO; it should have
//        a constructor with a TO* as its only argument.
//
// METHODS:
//   CONSTRUCTORS:
//     1) PassTheBuck(AtomicRegion*)
//     ---------------------
//     The new region must be provided .
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
#ifndef PASSBUCK_H
#define PASSBUCK_H
///////////////////////////////////////////
#include "cubpackpp/pointer.h"
#include "cubpackpp/regproc.h"

namespace cubpackpp {
///////////////////////////////////////////
template <class FROM, class TO, class VIA>
class PassTheBuck : public Processor<TO> {
public:
  PassTheBuck(AtomicRegion *);

  void Process(Stack<AtomicRegion> &);

  Processor<TO> *NewCopy() const;

private:
  AtomicRegion *AR_ptr;
};
//////////////////////////////////////////
} // namespace cubpackpp
#include "cubpackpp/templist.h"

#ifdef TEMPLATEINCLUDE

#include "cubpackpp/passbuck.tpp"

#endif
//////////////////////////////////////////
#endif
