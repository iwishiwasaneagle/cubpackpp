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
//File stripitf.c
// History:
//   (date)          (version)
//   19 Aug 1994     V0.1 (first limited distribution)
//////////////////////////////////////////////
#include "cubpackpp/stripitf.h"
#include "cubpackpp/passbuck.h"
#include "cubpackpp/E2interf.h"
#include "cubpackpp/E2tostrp.h"

namespace cubpackpp {
//////////////////////////////////////////////
    INFINITE_STRIP::INFINITE_STRIP(const Point &a, const Point &b)
            : USERINTERFACE<InfiniteStrip>() {
        PLANE P;
        StoreAtomic(new InfiniteStrip(a, b),
                    new PassTheBuck<Plane, InfiniteStrip,
                            E2toIS>((AtomicRegion *) P));
    }
///////////////////////////////////////////////
} // cubpackpp
