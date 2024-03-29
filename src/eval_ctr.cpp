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
/////////////////////////////////////////////
// File eval_ctr.cpp
//  History:
//    (date)          (version)
//    19 Aug 1994     V0.1 (first limited distribution)
//    28 Mar 1996     V0.1h(long instead of int)
/////////////////////////////////////////////

#include "cubpackpp/eval_ctr.h"
#include "cubpackpp/integran.h"

namespace cubpackpp {
/////////////////////////////////////////////
EvaluationCounter::EvaluationCounter() { Reset(); }

/////////////////////////////////////////////
void EvaluationCounter::Start() {
  if (!Running) {
    Strt = Integrand::NumberOfEvaluations();
    End = Strt;
    Running = True;
  };
}

/////////////////////////////////////////////
void EvaluationCounter::Stop() {
  if (Running) {
    End = Integrand::NumberOfEvaluations();
    Running = False;
  };
}

/////////////////////////////////////////////
void EvaluationCounter::Reset() {
  Bias = 0;
  Strt = Integrand::NumberOfEvaluations();
  End = Strt;
  Running = False;
}

/////////////////////////////////////////////
void EvaluationCounter::Reset(unsigned long v) {
  Bias = v;
  Strt = Integrand::NumberOfEvaluations();
  End = Strt;
  Running = False;
}

/////////////////////////////////////////////
unsigned long EvaluationCounter::Read() {
  if (Running) {
    return static_cast<unsigned long>(Integrand::NumberOfEvaluations() - Strt) + Bias;
  } else {
    return static_cast<unsigned long>(End - Strt) + Bias;
  };
}
/////////////////////////////////////////////
} // namespace cubpackpp
