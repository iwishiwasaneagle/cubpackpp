// This file is needed by gcc v2.6.2 .
// One has to compile with option -fno-implicit-templates.
//
// History:
//   (date)          (version)
//   28 Nov 1994     V0.1 (first limited distribution)
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
template class SimpleAdaptive<Parallelogram>;
template class SimpleAdaptive<Triangle>;

///////////////////////////////////////////////////////////////

#include "cubpackpp/set.h"
template class Set<AtomicRegion>;

///////////////////////////////////////////////////////////////

#include "cubpackpp/stack.h"
template class Stack<Parallelogram>;
template class Stack<AtomicRegion>;
template class Stack<Triangle>;
template class Stack<COMPOUND_REGION>;

///////////////////////////////////////////////////////////////

#include "cubpackpp/vector.h"
template class Vector<Point>;
template class Vector<unsigned int>;
template class Vector<real>;
template class Vector< Pointer<Transformation> >;

///////////////////////////////////////////////////////////////

#include "cubpackpp/vstack.h"
template class VectorStack< Pointer < Transformation > >;

///////////////////////////////////////////////////////////////

#include "cubpackpp/heap.h"
template class SubHeap<AtomicRegion,255>;
template class Heap<AtomicRegion>;

///////////////////////////////////////////////////////////////

#include "cubpackpp/atomic.h"
template class Atomic<Circle>;
template class Atomic<GeneralizedRectangle>;
template class Atomic<GeneralizedSector>;
template class Atomic<InfiniteStrip>;
template class Atomic<OutCircle>;
template class Atomic<ParabolicSegment>;
template class Atomic<Parallelogram>;
template class Atomic<Plane>;
template class Atomic<PlaneSector>;
template class Atomic<PolarRectangle>;
template class Atomic<SemiInfiniteStrip>;
template class Atomic<Triangle>;

///////////////////////////////////////////////////////////////

#include "cubpackpp/div.h"
template class Divisor<Parallelogram>;
template class Divisor<Triangle>;

///////////////////////////////////////////////////////////////

#include "cubpackpp/passbuck.h"
template class PassTheBuck<Circle,OutCircle,Invert>;
template class PassTheBuck<InfiniteStrip,SemiInfiniteStrip,IStoSIS>;
template class PassTheBuck<Parallelogram,GeneralizedRectangle,C2toGR>;
template class PassTheBuck<Plane ,InfiniteStrip,E2toIS>;
template class PassTheBuck<Triangle,ParabolicSegment,T2toPS>;

///////////////////////////////////////////////////////////////

#include "cubpackpp/pointer.h"
template class Pointer<Heap<AtomicRegion> >;
template class Pointer<Integrand>;
template class Pointer<RegionInfo>;

template class Pointer<Circle>;
template class Pointer<GeneralizedRectangle>;
template class Pointer<GeneralizedSector>;
template class Pointer<InfiniteStrip>;
template class Pointer<OutCircle>;
template class Pointer<ParabolicSegment>;
template class Pointer<Parallelogram>;
template class Pointer<Plane>;
template class Pointer<PlaneSector>;
template class Pointer<PolarRectangle>;
template class Pointer<SemiInfiniteStrip>;
template class Pointer<Triangle>;

template class Pointer<Processor<Circle> >;
template class Pointer<Processor<GeneralizedRectangle> >;
template class Pointer<Processor<GeneralizedSector> >;
template class Pointer<Processor<InfiniteStrip> >;
template class Pointer<Processor<OutCircle> >;
template class Pointer<Processor<ParabolicSegment> >;
template class Pointer<Processor<Parallelogram> >;
template class Pointer<Processor<Plane> >;
template class Pointer<Processor<PlaneSector> >;
template class Pointer<Processor<PolarRectangle> >;
template class Pointer<Processor<SemiInfiniteStrip> >;
template class Pointer<Processor<Triangle> >;

template class Pointer<Rule<Circle> >;
template class Pointer<Rule<Triangle> >;
template class Pointer<Rule<Parallelogram> >;

template class Pointer<SameShapeDivisor<Parallelogram> >;
template class Pointer<SameShapeDivisor<Triangle> >;

template class Pointer<Stack<AtomicRegion> >;
template class Pointer<Stack<COMPOUND_REGION> >;
template class Pointer<Transformation >;

///////////////////////////////////////////////////////////////

#include "cubpackpp/regproc.h"
template class Processor<Circle>;
template class Processor<GeneralizedRectangle>;
template class Processor<GeneralizedSector>;
template class Processor<InfiniteStrip>;
template class Processor<OutCircle>;
template class Processor<ParabolicSegment>;
template class Processor<Parallelogram>;
template class Processor<Plane>;
template class Processor<PlaneSector>;
template class Processor<PolarRectangle>;
template class Processor<SemiInfiniteStrip>;
template class Processor<Triangle>;

///////////////////////////////////////////////////////////////

#include "cubpackpp/rule.h"
template class Rule<Circle>;
template class Rule<Parallelogram>;
template class Rule<Triangle>;

///////////////////////////////////////////////////////////////

#include "cubpackpp/samediv.h"
template class SameShapeDivisor<Parallelogram>;
template class SameShapeDivisor<Triangle>;

///////////////////////////////////////////////////////////////

#include "cubpackpp/userint.h"
template class USERINTERFACE<Circle>;
template class USERINTERFACE<GeneralizedRectangle>;
template class USERINTERFACE<GeneralizedSector>;
template class USERINTERFACE<InfiniteStrip>;
template class USERINTERFACE<OutCircle>;
template class USERINTERFACE<ParabolicSegment>;
template class USERINTERFACE<Parallelogram>;
template class USERINTERFACE<Plane>;
template class USERINTERFACE<PlaneSector>;
template class USERINTERFACE<PolarRectangle>;
template class USERINTERFACE<SemiInfiniteStrip>;
template class USERINTERFACE<Triangle>;

///////////////////////////////////////////////////////////////
