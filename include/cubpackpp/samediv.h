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
// File : samediv.h
// History:
//   (date)          (version)
//   19 Aug 1994     V0.1 (first limited distribution)
/////////////////////////////////////////////////////////
// DEFINITION OF CLASS SameShapeDivisor
// -------------------------------------------------
//
// BASECLASSES:
//   Divisor<T>
//
// PURPOSE:
//   a divisor that produces parts of the same shape as
//   the original
//
// TEMPLATES:
//   T, the Geometry to be divided.
//
// METHODS:
//   CONSTRUCTORS:
//     1) SameShapeDivisor()
//     ---------------------
//
//   SELECTORS:
//     1) virtual int NumberOfParts() const
//    -------------------------------
//
//   MODIFIERS:
//     None
//
//   OPERATORS:
//     None
//
//   SPECIAL:
//     1) virtual void Apply( const T& ,
//                            Stack<T>& Offspring)
//     --------------------------------------------------
//     performs the division
//
/////////////////////////////////////////////////////////
#ifndef SAMEDIV_H
#define SAMEDIV_H
////////////////////////////////////////////
#include "cubpackpp/div.h"
#include "cubpackpp/stack.h"
#include "cubpackpp/vector.h"

namespace cubpackpp {
////////////////////////////////////////////
    template<class GEOMETRY>
    class SameShapeDivisor : public Divisor<GEOMETRY> {
    public:

        SameShapeDivisor();

        virtual int NumberOfParts() const = 0;

        virtual void Apply(const GEOMETRY &, Stack<GEOMETRY> &, const Vector<unsigned int> &) = 0;

        virtual ~SameShapeDivisor();
    };
/////////////////////////////////////////////
} // cubpackpp
#include "cubpackpp/templist.h"

#ifdef TEMPLATEINCLUDE

#include "cubpackpp/samediv.tpp"

#endif
/////////////////////////////////////////////
#endif
