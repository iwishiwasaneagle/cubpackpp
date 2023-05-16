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
// File : error.h
// History:
//   (date)          (version)
//   19 Aug 1994     V0.1 (first limited distribution)
/////////////////////////////////////////////////////////
// PURPOSE
//  void Error(Boolean b,char* message) is an error
//  checking and reporting routine. if b is true then
//  message is printed on stderr and the program is
//  aborted.
/////////////////////////////////////////////////////////
#ifndef ERROR_H
#define ERROR_H
////////////////////////////////////////
#include "cubpackpp/boolean.h"
#include <stdlib.h>
#include <iostream>
////////////////////////////////////////
inline void Error(int b,const char* message)
  {
  if (b)
    {
    std::cerr << message <<std::endl;
    std::cerr.flush();
    abort();
    };
  }
////////////////////////////////////////
#endif
