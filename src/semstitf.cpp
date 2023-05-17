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
////////////////////////////////////////////////
// File stripitf.c
//////////////////////////////////////////////
#include "cubpackpp/semstitf.h"
#include "cubpackpp/passbuck.h"
#include "cubpackpp/stripitf.h"
#include "cubpackpp/sttosmst.h"

namespace cubpackpp {
//////////////////////////////////////////////
SEMI_INFINITE_STRIP::SEMI_INFINITE_STRIP(const Point &a, const Point &b)
    : USERINTERFACE<SemiInfiniteStrip>() {
  Point orig(0, 0), one(1, 0);
  INFINITE_STRIP I(orig, one);
  StoreAtomic(new SemiInfiniteStrip(a, b),
              new PassTheBuck<InfiniteStrip, SemiInfiniteStrip, IStoSIS>(
                  (AtomicRegion *)I));
}
///////////////////////////////////////////////
} // namespace cubpackpp
