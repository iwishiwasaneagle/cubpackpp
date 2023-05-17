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
///////////////////////////////////////////////
// File outS2.c
//  History:
//    (date)          (version)
//    19 Aug 1994     V0.1 (first limited distribution)
////////////////////////////////////////////////
#include "cubpackpp/outS2.h"
#include "cubpackpp/invert.h"
#include "cubpackpp/passbuck.h"

namespace cubpackpp {
////////////////////////////////////////////////
OutCircle::OutCircle(const Point &C, const Point &B) : Circle(C, B) {}

///////////////////////////////////////////////
OutCircle::OutCircle(const Point &C, real r) : Circle(C, r) {}
///////////////////////////////////////////////
// Processor<OutCircle>*
// OutCircle::DefaultProcessor()
// const
//  {
// return new PassTheBuck<Circle,OutCircle,Invert>(
//  new Circle(*this));
// }
////////////////////////////////////////////////
} // namespace cubpackpp
