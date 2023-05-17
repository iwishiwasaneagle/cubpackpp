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
///////////
// File outs2itf.c
//  History:
//    (date)          (version)
//    19 Aug 1994     V0.1 (first limited distribution)
////////////////
#include "cubpackpp/outS2itf.h"
#include "cubpackpp/S2.h"
#include "cubpackpp/S2interf.h"
#include "cubpackpp/invert.h"
#include "cubpackpp/outS2.h"
#include "cubpackpp/passbuck.h"

namespace cubpackpp {
///////////////////////
OUT_CIRCLE::OUT_CIRCLE(const Point &c, const Point &b) {
  StoreAtomic(new OutCircle(c, b), new PassTheBuck<Circle, OutCircle, Invert>(
                                       (AtomicRegion *)CIRCLE(c, b)));
}

//////////////////////////////////////////////
OUT_CIRCLE::OUT_CIRCLE(const Point &c, real Radius) {
  StoreAtomic(new OutCircle(c, Radius),
              new PassTheBuck<Circle, OutCircle, Invert>(
                  (AtomicRegion *)CIRCLE(c, Radius)));
}
//////////////////////////////////////////////
} // namespace cubpackpp
