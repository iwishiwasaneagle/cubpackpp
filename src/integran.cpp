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
///////////////////////////////////////////////////
// File integran.cpp
//  History:
//    (date)          (version)
//    19 Aug 1994     V0.1 (first limited distribution)
//     9 Sep 1994     V0.1a(operator added)
//    10 Sep 1994     V0.1b(constructors of ReferenceCounting added)
//    25 Jan 1996     V0.1f(unused parameter removed)
//    30 Jan 1996     V0.1g(no longer compare signed and unsigned)
//    28 Mar 1996     V0.1h(long instead of int)
//////////////////////////////////////////////////

#include "cubpackpp/integran.h"
#include "cubpackpp/error.h"
#include "cubpackpp/trnsfrm.h"
#include <iostream>
#include <math.h>

namespace cubpackpp {
//////////////////////////////////////////////////
long Integrand::Number = 0;

//////////////////////////////////////////////////////
Integrand::Integrand(Function f)
    : ReferenceCounting(), TheFunction(f), AppliedTransformations() {}

////////////////////////////////////////////////
Integrand::Integrand(const Integrand &I, Transformation *T)
    : ReferenceCounting(I),
      TheFunction(I.TheFunction), AppliedTransformations(I.AppliedTransformations) {
  Pointer<Transformation> p = T;
  AppliedTransformations += p;
}

/////////////////////////////////////////////////////////
Integrand::Integrand(const Integrand &I)
    : ReferenceCounting(I),
      TheFunction(I.TheFunction), AppliedTransformations(I.AppliedTransformations) {}

////////////////////////////////////////////////
long Integrand::NumberOfEvaluations() { return Number; }

//////////////////////////////////////////////////////
real Integrand::operator()(const Point &StartingPoint) {
  real JacProd = 1;
  Point p = StartingPoint;
  for (unsigned int i = 0; JacProd != 0 && i < AppliedTransformations.Size();
       i++) {
    AppliedTransformations[i]->Transform(JacProd, p);
  };
  if (JacProd == 0)
    return 0.0;
  real R = TheFunction(p) * fabs(JacProd);
  Number++;
  return R;
}

////////////////////////////////////////////////
real ErrorMessage(const Point &) {
  Error(True, "Error : Attempt to integrate without knowing integrand");
  return 0;
}

Integrand::Integrand()
    : ReferenceCounting(), TheFunction(ErrorMessage), AppliedTransformations() {
}

///////////////////////////////////////////////
Boolean Integrand::operator==(const Integrand &i) const {
  if ((AppliedTransformations.Size() > 0) ||
      (i.AppliedTransformations.Size() > 0))
    return False;
  return static_cast<Boolean>((getAddress(TheFunction) == getAddress( i.TheFunction)));
}
///////////////////////////////////////////////
} // namespace cubpackpp
