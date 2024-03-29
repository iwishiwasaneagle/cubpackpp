
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
// File : psitf.h
// History:
//   (date)          (version)
//   19 Aug 1994     V0.1 (first limited distribution)
/////////////////////////////////////////////////////////
#include "cubpackpp/psitf.h"
#include "cubpackpp/T2interf.h"
#include "cubpackpp/T2tops.h"
#include "cubpackpp/passbuck.h"

namespace cubpackpp {
/////////////////////////////////////////////////////////
PARABOLIC_SEGMENT::PARABOLIC_SEGMENT(const Point &A, const Point &B,
                                     const Point &P)
    : USERINTERFACE<ParabolicSegment>() {
  Point p(-1, 0), q(0, 1), r(1, 0);
  TRIANGLE T(p, q, r);
  StoreAtomic(
      new ParabolicSegment(A, B, P),
      new PassTheBuck<Triangle, ParabolicSegment, T2toPS>(static_cast<AtomicRegion *>(T)));
}
//////////////////////////////////////////////////////////
} // namespace cubpackpp
