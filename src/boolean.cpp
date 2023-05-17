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
// File boolean.cpp
//  History:
//    (date)          (version)
//    19 Aug 1994     V0.1 (first limited distribution)
////////////////////////////////////////////////

#include "cubpackpp/boolean.h"
#include <iostream>

namespace cubpackpp {
std::ostream &operator<<(std::ostream &os, const Boolean &b) {
  if (b == False) {
    os << "False ";
  } else {
    os << "True ";
  };
  return os;
}
} // namespace cubpackpp
