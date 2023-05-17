// #  Copyright 2023 Jan-Hendrik Ewers
// #  SPDX-License-Identifier: GPL-3.0-only

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
//File div.c
// History:
//   (date)          (version)
//   19 Aug 1994     V0.1 (first limited distribution)
/////////////////////////////////////////////////
#include "cubpackpp/div.h"

namespace cubpackpp {
/////////////////////////////////////////////////
    template<class GEOMETRY>
    Divisor<GEOMETRY>::Divisor()
            :ReferenceCounting() {
    }

//////////////////////////////////////////////////
    template<class GEOMETRY>
    Divisor<GEOMETRY>::~Divisor() {
    }
//////////////////////////////////////////////////
} // cubpackpp
