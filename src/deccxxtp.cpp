// This file is needed by cxx, The Decalpha C++ compiler.
//
// History:
//   (date)          (version)
//   19 Aug 1994     V0.1 (first limited distribution)
//
#include "cubpackpp/cubpackpp.h"
#include "cubpackpp/C2togr.h"
#include "cubpackpp/outS2.h"
#include "cubpackpp/invert.h"
#include "cubpackpp/T2tops.h"
#include "cubpackpp/sttosmst.h"
#include "cubpackpp/E2tostrp.h"

///////////////////////////////////////////////////////////////

#include "cubpackpp/s_adapt.h"
namespace cubpackpp {
#pragma define_template SimpleAdaptive<Parallelogram>
#pragma define_template SimpleAdaptive<Triangle>

} // cubpackpp
///////////////////////////////////////////////////////////////

#include "cubpackpp/set.h"
namespace cubpackpp {
#pragma define_template Set<AtomicRegion>

} // cubpackpp
///////////////////////////////////////////////////////////////

#include "cubpackpp/stack.h"
namespace cubpackpp {
#pragma define_template Stack<Parallelogram>
#pragma define_template Stack<AtomicRegion>
#pragma define_template Stack<Triangle>
#pragma define_template Stack<COMPOUND_REGION>

} // cubpackpp
///////////////////////////////////////////////////////////////

#include "cubpackpp/vector.h"
namespace cubpackpp {
#pragma define_template Vector<Point>
#pragma define_template Vector<unsigned int>
#pragma define_template Vector<real>
#pragma define_template Vector< Pointer<Transformation> >

} // cubpackpp
///////////////////////////////////////////////////////////////

#include "cubpackpp/vstack.h"
namespace cubpackpp {
#pragma define_template VectorStack< Pointer < Transformation > >

} // cubpackpp
///////////////////////////////////////////////////////////////

#include "cubpackpp/heap.h"
namespace cubpackpp {
#pragma define_template SubHeap<AtomicRegion,255>
#pragma define_template Heap<AtomicRegion>

} // cubpackpp
///////////////////////////////////////////////////////////////

#include "cubpackpp/atomic.h"
namespace cubpackpp {
#pragma define_template Atomic<Circle>
#pragma define_template Atomic<GeneralizedRectangle>
#pragma define_template Atomic<GeneralizedSector>
#pragma define_template Atomic<InfiniteStrip>
#pragma define_template Atomic<OutCircle>
#pragma define_template Atomic<ParabolicSegment>
#pragma define_template Atomic<Parallelogram>
#pragma define_template Atomic<Plane>
#pragma define_template Atomic<PlaneSector>
#pragma define_template Atomic<PolarRectangle>
#pragma define_template Atomic<SemiInfiniteStrip>
#pragma define_template Atomic<Triangle>

} // cubpackpp
///////////////////////////////////////////////////////////////

#include "cubpackpp/div.h"
namespace cubpackpp {
#pragma define_template Divisor<Parallelogram>
#pragma define_template Divisor<Triangle>

} // cubpackpp
///////////////////////////////////////////////////////////////

#include "cubpackpp/passbuck.h"
namespace cubpackpp {
#pragma define_template PassTheBuck<Circle,OutCircle,Invert>
#pragma define_template PassTheBuck<InfiniteStrip,SemiInfiniteStrip,IStoSIS>
#pragma define_template PassTheBuck<Parallelogram,GeneralizedRectangle,C2toGR>
#pragma define_template PassTheBuck<Plane ,InfiniteStrip,E2toIS>
#pragma define_template PassTheBuck<Triangle,ParabolicSegment,T2toPS>

} // cubpackpp
///////////////////////////////////////////////////////////////

#include "cubpackpp/pointer.h"
namespace cubpackpp {
#pragma define_template Pointer<Heap<AtomicRegion> >
#pragma define_template Pointer<Integrand>
#pragma define_template Pointer<RegionInfo>

#pragma define_template Pointer<Circle>
#pragma define_template Pointer<GeneralizedRectangle>
#pragma define_template Pointer<GeneralizedSector>
#pragma define_template Pointer<InfiniteStrip>
#pragma define_template Pointer<OutCircle>
#pragma define_template Pointer<ParabolicSegment>
#pragma define_template Pointer<Parallelogram>
#pragma define_template Pointer<Plane>
#pragma define_template Pointer<PlaneSector>
#pragma define_template Pointer<PolarRectangle>
#pragma define_template Pointer<SemiInfiniteStrip>
#pragma define_template Pointer<Triangle>

#pragma define_template Pointer<Processor<Circle> >
#pragma define_template Pointer<Processor<GeneralizedRectangle> >
#pragma define_template Pointer<Processor<GeneralizedSector> >
#pragma define_template Pointer<Processor<InfiniteStrip> >
#pragma define_template Pointer<Processor<OutCircle> >
#pragma define_template Pointer<Processor<ParabolicSegment> >
#pragma define_template Pointer<Processor<Parallelogram> >
#pragma define_template Pointer<Processor<Plane> >
#pragma define_template Pointer<Processor<PlaneSector> >
#pragma define_template Pointer<Processor<PolarRectangle> >
#pragma define_template Pointer<Processor<SemiInfiniteStrip> >
#pragma define_template Pointer<Processor<Triangle> >

#pragma define_template Pointer<Rule<Circle> >
#pragma define_template Pointer<Rule<Triangle> >
#pragma define_template Pointer<Rule<Parallelogram> >

#pragma define_template Pointer<SameShapeDivisor<Parallelogram> >
#pragma define_template Pointer<SameShapeDivisor<Triangle> >

#pragma define_template Pointer<Stack<AtomicRegion> >
#pragma define_template Pointer<Stack<COMPOUND_REGION> >
#pragma define_template Pointer<Transformation >

} // cubpackpp
///////////////////////////////////////////////////////////////

#include "cubpackpp/regproc.h"
namespace cubpackpp {
#pragma define_template Processor<Circle>
#pragma define_template Processor<GeneralizedRectangle>
#pragma define_template Processor<GeneralizedSector>
#pragma define_template Processor<InfiniteStrip>
#pragma define_template Processor<OutCircle>
#pragma define_template Processor<ParabolicSegment>
#pragma define_template Processor<Parallelogram>
#pragma define_template Processor<Plane>
#pragma define_template Processor<PlaneSector>
#pragma define_template Processor<PolarRectangle>
#pragma define_template Processor<SemiInfiniteStrip>
#pragma define_template Processor<Triangle>

} // cubpackpp
///////////////////////////////////////////////////////////////

#include "cubpackpp/rule.h"
namespace cubpackpp {
#pragma define_template Rule<Circle>
#pragma define_template Rule<Parallelogram>
#pragma define_template Rule<Triangle>

} // cubpackpp
///////////////////////////////////////////////////////////////

#include "cubpackpp/samediv.h"
namespace cubpackpp {
#pragma define_template SameShapeDivisor<Parallelogram>
#pragma define_template SameShapeDivisor<Triangle>

} // cubpackpp
///////////////////////////////////////////////////////////////

#include "cubpackpp/userint.h"
namespace cubpackpp {
#pragma define_template USERINTERFACE<Circle>
#pragma define_template USERINTERFACE<GeneralizedRectangle>
#pragma define_template USERINTERFACE<GeneralizedSector>
#pragma define_template USERINTERFACE<InfiniteStrip>
#pragma define_template USERINTERFACE<OutCircle>
#pragma define_template USERINTERFACE<ParabolicSegment>
#pragma define_template USERINTERFACE<Parallelogram>
#pragma define_template USERINTERFACE<Plane>
#pragma define_template USERINTERFACE<PlaneSector>
#pragma define_template USERINTERFACE<PolarRectangle>
#pragma define_template USERINTERFACE<SemiInfiniteStrip>
#pragma define_template USERINTERFACE<Triangle>

} // cubpackpp
///////////////////////////////////////////////////////////////
