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
/////////////////////////////////////////////
// File point2D.c
//  History:
//    (date)          (version)
//    19 Aug 1994     V0.1 (first limited distribution)
//    25 Jan 1996     V0.1f(file name changed)
/////////////////////////////////////////////
#include "cubpackpp/point2D.h"

namespace cubpackpp {
//////////////////////////////////////////////////////
Point_2D::Point_2D() {}
//////////////////////////////////////////////////////

Point_2D::Point_2D(const Point_2D &v) : x(v.x), y(v.y) {}

//////////////////////////////////////////////////////

Point_2D::Point_2D(const real X, const real Y) : x(X), y(Y) {}

//////////////////////////////////////////////////////
Point_2D::~Point_2D() {}

//////////////////////////////////////////////////
// Other functions are inlined
//////////////////////////////////////////////////
} // namespace cubpackpp
