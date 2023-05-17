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
// File : function.h
// History:
//   (date)          (version)
//   19 Aug 1994     V0.1 (first limited distribution)
/////////////////////////////////////////////////////////
// PURPOSE:
//   mapping from a Point to a real
/////////////////////////////////////////////////////////
#ifndef FUNCTION_H
#define FUNCTION_H
/////////////////////////////////////////////////////////
#include "cubpackpp/point.h"
#include "cubpackpp/real.h"

#include <functional>

namespace cubpackpp {
/////////////////////////////////////////////////////////
typedef std::function<real(const Point&)> Function;

template<typename T, typename... U>
inline size_t getAddress(std::function<T(U...)> f) {
    typedef T(fnType)(U...);
    fnType ** fnPointer = f.template target<fnType*>();
    return (size_t) *fnPointer;
}
/////////////////////////////////////////////////////////

} // namespace cubpackpp

#endif
