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
/////////////////////////////////////////////////////////
// File : boolean.h
// History:
//   (date)          (version)
//   19 Aug 1994     V0.1 (first limited distribution)
/////////////////////////////////////////////////////////
#ifndef BOOLEAN_H
#define BOOLEAN_H

/////////////////////////////////////////////////
#include <iostream>
/////////////////////////////////////////////////
enum Boolean {False, True};

extern std::ostream& operator<<(std::ostream&,const Boolean&);

//////////////////////////////////////////////////
#endif
