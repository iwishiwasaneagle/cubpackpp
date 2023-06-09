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
//////////////////////////////////////////
// File C2toS2.cpp
//  History:
//    (date)          (version)
//    19 Aug 1994     V0.1 (first limited distribution)
//////////////////////////////////////////

#include "cubpackpp/C2toS2.h"
#include "cubpackpp/trnsfrm.h"
#include <math.h>

namespace cubpackpp {
//////////////////////////////////////////
void PolarToRectangular::Transform(real &w, Point &p) {
  Point P(p.R() * cos(p.Theta()), p.R() * sin(p.Theta()));
  w *= p.R();
  p = P;
}

///////////////////////////////////////////
PolarToRectangular::PolarToRectangular() : Transformation() {}
///////////////////////////////////////////
} // namespace cubpackpp
