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
//////////////////////////////////////////////////
//File geometry.c
// History:
//   (date)          (version)
//   19 Aug 1994     V0.1 (first limited distribution)
///////////////////////////////////////////////////
#include "cubpackpp/geometry.h"

namespace cubpackpp {
///////////////////////////////////////////////////
    Geometry::Geometry(unsigned int Dim)
            : TheDimension(Dim) {
    }

///////////////////////////////////////////////////
    unsigned int
    Geometry::Dimension()
    const {
        return TheDimension;
    }
//////////////////////////////////////////////////
} // cubpackpp
