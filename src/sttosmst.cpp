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
/////////////////////////////////////////////////
// File sttosmt.c
//  History:
//    (date)          (version)
//    19 Aug 1994     V0.1 (first limited distribution)
////////////////////////////////////////////////
#include "cubpackpp/sttosmst.h"
#include "cubpackpp/point.h"
#include <iostream>
#include <math.h>

namespace cubpackpp {
////////////////////////////////////////////
void IStoSIS::Transform(real &w, Point &p) {
  //    cout << p;
  SemiInfiniteStrip &s = *SIS_ptr;
  Point D = s.B() - s.A();
  Point C(-D.Y(), D.X());
  //    if (p.Y() > 600)   // goed voor double
  //    if (p.Y() > 60)
  if (p.Y() > log(REAL_MAX) * 6.0 / 7.0) {
    w = 0;
    return;
  };
  C = C / C.Length();
  w *= D.Length() * exp(p.Y());
  p = s.A() + exp(p.Y()) * C + p.X() * D;
  //   cout << p << endl;
}

///////////////////////////////////////////////////
IStoSIS::IStoSIS(SemiInfiniteStrip *g) : Transformation(), SIS_ptr(g) {}
//////////////////////////////////////////////////
} // namespace cubpackpp
