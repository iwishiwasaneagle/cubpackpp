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
////////////////////////////////////////////
// File gr.c
//  History:
//    (date)          (version)
//    19 Aug 1994     V0.1 (first limited distribution)
/////////////////////////////////////////////
#include "cubpackpp/gr.h"
#include "cubpackpp/C2.h"
#include "cubpackpp/C2togr.h"
#include "cubpackpp/passbuck.h"

namespace cubpackpp {
//////////////////////////////////////////////
GeneralizedRectangle::GeneralizedRectangle(Function f, const Point &a,
                                           const Point &b)
    : Geometry(2), TheBoundary(f), TheA(a), TheB(b) {}

////////////////////////////////////////////
const Point &GeneralizedRectangle::A() const { return TheA; }

///////////////////////////////////////////
const Point &GeneralizedRectangle::B() const { return TheB; }

/////////////////////////////////////////////
real GeneralizedRectangle::Boundary(const Point &p) const {
  return (const_cast<GeneralizedRectangle *>(this))->TheBoundary(p);
}
//////////////////////////////////////////
// Processor<GeneralizedRectangle>*
// GeneralizedRectangle::DefaultProcessor()
// const
//{
// Point a(0,0),b(1,0),c(0,1);
// Parallelogram* R= new Parallelogram(a,b,c);
// return new
// PassTheBuck<Parallelogram,GeneralizedRectangle,
// C2toGR>(R);
// }
////////////////////////////////////////////
} // namespace cubpackpp
