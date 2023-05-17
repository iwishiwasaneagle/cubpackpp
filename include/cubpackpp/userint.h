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
// File : userint.h
// History:
//   (date)          (version)
//   19 Aug 1994     V0.1 (first limited distribution)
//    8 Sep 1994     V0.1a(operator added)
//   25 Jan 1996     V0.1f(typedef introduced, code from .c to .h)
/////////////////////////////////////////////////////////
// DEFINITION OF CLASS USERINTERFACE
// -------------------------------------------------
//
// BASECLASSES:
//   COMPOUND_REGION
//
// PURPOSE:
//   base class for end-user interfaces to geometries
//
// TEMPLATES:
//   a specific Geometry (derived from Geometry)
//   must be provided
//
// METHODS:
//   CONSTRUCTORS:
//     1) USERINTERFACE()
//     ------------------
//
//     2) USERINTERFACE(const USERINTERFACE<Geometry>&)
//     ------------------------------------------------
//
//   SELECTORS:
//     None
//
//   MODIFIERS:
//     1) void Use(Processor<Geometry>* P)
//     -----------------------------------
//     forces P to be used for Process()ing.
//
//     2) LocalIntegrand(Integrand* I)
//     ------------------------------
//     sets the local integrand of all members to I
//     only to be called before Process().
//
//     3) LocalIntegrand(Function F)
//    ------------------------------
//     sets the local integrand of all members to F
//     only to be called before Process().
//

//
//   OPERATORS:
//     1) REGION_COLLECTION operator+(const COMPOUND_REGION&)
//     -----------------------------------------------------
//
//   SPECIAL:
//     1)operator AtomicRegion*()
//     ---------------------------
//     conversion to an AtomicRegion. The USERINTERFACE
//     can't be used after a call of this operator.
//
/////////////////////////////////////////////////////////
#ifndef USERINT_H
#define USERINT_H
/////////////////////////////////////////////////
#include "cubpackpp/compreg.h"
#include "cubpackpp/regcoll.h"
#include "cubpackpp/geometry.h"
#include "cubpackpp/regproc.h"
#include "cubpackpp/atomreg.h"
#include "cubpackpp/atomic.h"
#include "cubpackpp/stack.h"
#include "cubpackpp/heap.h"
/////////////////////////////////////////////////

namespace cubpackpp {
    template<class GEOMETRY>
    class USERINTERFACE : public COMPOUND_REGION {
    public:
        typedef Stack<AtomicRegion> StackAtomicRegion;
        typedef Heap<AtomicRegion> HeapAtomicRegion;

        USERINTERFACE();

        USERINTERFACE(const USERINTERFACE<GEOMETRY> &);

        ~USERINTERFACE();

        void Use(Processor<GEOMETRY> *);

        REGION_COLLECTION operator+(const COMPOUND_REGION &);

        void LocalIntegrand(Integrand *);

        void LocalIntegrand(Function);

        operator AtomicRegion *() {
            Error(SAR_ptr->Empty(),
                  "converting empty compound region to atomic.");
            return SAR_ptr->Pop();
        }

    protected:

        Pointer<StackAtomicRegion> HopelessAR_ptr;
        Pointer<StackAtomicRegion> SAR_ptr;
        Pointer<HeapAtomicRegion> HAR_ptr;
        Pointer<Integrand> Int_ptr;

        void StoreAtomic(GEOMETRY *, Processor<GEOMETRY> *);

        //void StoreAtomic(Geometry*);
        void Preprocess();

        void Improve();

        real MaxAtomicError() const;

        COMPOUND_REGION *NewCopy() const;

    };
//////////////////////////////////////////////////
} // cubpackpp
#include "cubpackpp/templist.h"

#ifdef TEMPLATEINCLUDE

#include "cubpackpp/userint.tpp"

#endif
///////////////////////////////////////////////////

#endif
