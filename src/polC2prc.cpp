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
//File polC2prc.c
// History:
//   (date)          (version)
//   19 Aug 1994     V0.1 (first limited distribution)
/////////////////////////////////////////////////////////
#include "cubpackpp/polC2prc.h"
#include "cubpackpp/C2toS2.h"
#include "cubpackpp/translat.h"
#include "cubpackpp/integran.h"
#include "cubpackpp/polC2.h"
#include "cubpackpp/C2interf.h"
#include "cubpackpp/atomic.h"
namespace cubpackpp {

////////////////////////////////////////////////////////

void
PolarRectangle_Processor::Process( Stack<AtomicRegion>& Offspring)
  {
  PolarRectangle& G = Geometry();
  Point P1(G.InnerRadius(),G.SmallAngle()), P2(G.OuterRadius(),G.SmallAngle()),
        P3(G.OuterRadius(),G.BigAngle());
  AtomicRegion* A ;
  A= (AtomicRegion*) PARALLELOGRAM(P2,P1,P3);
  Integrand I1(LocalIntegrand(),new Translation(G.Center()));
  A->LocalIntegrand(new Integrand(I1, new PolarToRectangular));
  Offspring.Push(A);
  }
/////////////////////////////////////////////////
PolarRectangle_Processor::PolarRectangle_Processor()
  :Processor<PolarRectangle>()
  {
  }
/////////////////////////////////////////////////       
Processor<PolarRectangle>*
PolarRectangle_Processor::NewCopy()
const
  {
  return new PolarRectangle_Processor(*this);
  }
////////////////////////////////////////////////
} // cubpackpp
