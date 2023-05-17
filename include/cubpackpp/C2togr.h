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
// File : C2togr.h
// History:
//   (date)          (version)
//   19 Aug 1994     V0.1 (first limited distribution)
/////////////////////////////////////////////////////////
// DEFINITION OF CLASS C2toGR
// -------------------------------------------------
//
// BASECLASSES:
//   Transformation
//
// PURPOSE:
//   transformation from parallelogram to generalized
//   rectangle
//
// TEMPLATES:
//   None
//
// METHODS:
//   CONSTRUCTORS:
//     1) C2toGR(GeneralizedRectangle*)
//     ------------
//     The target region has to be supplied
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
//     1) void Transform(real & w, Point & p)
//     --------------------------------------
//     multiplies w by the Jacobian at p and then
//     replaces p by the transformed  point
//
/////////////////////////////////////////////////////////
#ifndef C2TOGR_H
#define C2TOGR_H
/////////////////////////////////////////////////////////
#include "cubpackpp/C2.h"
#include "cubpackpp/gr.h"
#include "cubpackpp/pointer.h"
#include "cubpackpp/trnsfrm.h"

namespace cubpackpp {
///////////////////////////////////////////////////
class C2toGR : public Transformation {
public:
  C2toGR(GeneralizedRectangle *);

  void Transform(real &w, Point &p);

private:
  Pointer<GeneralizedRectangle> GR_ptr;
};
//////////////////////////////////////////////////////
} // namespace cubpackpp
#endif
