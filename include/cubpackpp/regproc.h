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
// File : regproc.h
// History:
//   (date)          (version)
//   19 Aug 1994     V0.1 (first limited distribution)
/////////////////////////////////////////////////////////
// DEFINITION OF CLASS Processor
// -------------------------------------------------
//
// BASECLASSES:
//   ReferenceCounting
//
// PURPOSE:
//   abstract base class for region processors. these
//   either compute an integral or an error over a given
//   GEOMETRY or convert it to another GEOMETRY.
//   the processor has access to the GEOMETRY through
//   a pointer to an atomic region.
//
// TEMPLATES:
//   the GEOMETRY that the Processor is meant to operate
//   on must be specified as a template argument.
//
// METHODS:
//   CONSTRUCTORS:
//     1) Processor()
//     --------------
//
//   SELECTORS:
//     None
//
//   MODIFIERS:
//     1) void LocalAtomic(Atomic<GEOMETRY>* G)
//     -------------------------------------------
//     specifies the AtomicRegion to process
//     this should happen before the first call of Process()
//
//
//   OPERATORS:
//     None
//
//   SPECIAL:
//     1) virtual void Process( Stack<AtomicRegion>& Offspring)
//     -----------------------------------------------------
//     after a call of Process() one of the following
//     statements will be true:
//        I) Offspring is empty.
//           The processor will have computed new
//           values for integral and error.
//           They will be stored in the RegionInfo
//           of the atomic region, possibly along
//           with some other information like
//           hopelessness.
//        II)Offspring is non-empty.
//           The region has produced
//           offspring and can be deleted.
//
//     2) virtual Processor<GEOMETRY>* NewCopy() const=0
//     -------------------------------------------------
//
//     makes a new copy (using the copy constructor) and
//     returns a pointer to it.
/////////////////////////////////////////////////////////
#ifndef REGPROC_H
#define REGPROC_H
////////////////////////////////////////////
#include "cubpackpp/refcount.h"
#include "cubpackpp/pointer.h"
#include "cubpackpp/atomreg.h"
#include "cubpackpp/stack.h"
#include "cubpackpp/real.h"
#include "cubpackpp/integran.h"
/////////////////////////////////////////////

template <class GEOMETRY>
class Atomic;

template <class GEOMETRY>
class Processor: public ReferenceCounting
  {
  public:

  Processor();
  void LocalAtomic(Atomic<GEOMETRY>* );
  virtual Processor<GEOMETRY>* NewCopy() const=0;
  virtual void Process( Stack<AtomicRegion>& Offspring)=0;
  virtual ~Processor();

  protected:

  Integrand& LocalIntegrand() const;
  GEOMETRY& Geometry() const;
  real& Integral();
  real& AbsoluteError();
  Atomic<GEOMETRY>& LocalAtomic() const;
  RegionInfo& LocalRegionInfo() const;


  private:

  Atomic<GEOMETRY>* A_ptr;
  };


/////////////////////////////////////////////
#include "cubpackpp/templist.h"
#ifdef TEMPLATEINCLUDE
#include "cubpackpp/regproc.tpp"
#endif
/////////////////////////////////////////////
#endif
