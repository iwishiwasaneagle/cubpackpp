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
//File gritf.c
// History:
//   (date)          (version)
//   19 Aug 1994     V0.1 (first limited distribution)
//////////////////////////////////////////////
#include "cubpackpp/gritf.h"
#include "cubpackpp/passbuck.h"
#include "cubpackpp/C2.h"
#include "cubpackpp/C2interf.h"
#include "cubpackpp/C2togr.h"
#include "cubpackpp/point.h"

namespace cubpackpp {
//////////////////////////////////////////////
    GENERALIZED_RECTANGLE::GENERALIZED_RECTANGLE(Function f, const Point &a, const Point &b)
            : USERINTERFACE<GeneralizedRectangle>() {
        Point A(0, 0), B(1, 0), C(0, 1);
        PARALLELOGRAM R(A, B, C);
        StoreAtomic(new GeneralizedRectangle(f, a, b),
                    new PassTheBuck<Parallelogram, GeneralizedRectangle,
                            C2toGR>((AtomicRegion *) R));
    }
///////////////////////////////////////////////
} // cubpackpp
