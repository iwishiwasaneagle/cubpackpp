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
// File : E2sec.h
// History:
//   (date)          (version)
//   19 Aug 1994     V0.1 (first limited distribution)
/////////////////////////////////////////////////////////
// DEFINITION OF CLASS PlaneSector
// -------------------------------------------------
//
// BASECLASSES:
//   Geometry
//
// PURPOSE:
//   the geometry of a plane sector
//
// TEMPLATES:
//   None
//
// METHODS:
//   CONSTRUCTORS:
//     1) PlaneSector(const Point& A, const Point& B,
//                       const Point& C)
//     -------------------------------------------------
//     constructs a PlaneSector. AB should not be
//     perpendicular to BC.
//
//     2) PlaneSector(const Point& O,real r,real theta1,real,theta2)
//     ------------------------------------------------
//
//   SELECTORS:
//     1) const Point& Center() const
//     ------------------------------
//
//     2) real InnerRadius() const
//     ---------------------------
//
//     3) real SmallAngle() const
//     --------------------------
//
//     4) real BigAngle() const
//     ------------------------
//
//
//   MODIFIERS:
//     None
//
//   OPERATORS:
//     None
//
//   SPECIAL:
//     None
//
/////////////////////////////////////////////////////////
#ifndef E2SEC_H
#define E2SEC_H
/////////////////////////////////////////
#include "cubpackpp/geometry.h"
#include "cubpackpp/point.h"
#include "cubpackpp/real.h"

namespace cubpackpp {
/////////////////////////////////////////

    class PlaneSector : public Geometry {
    public:

        PlaneSector(
                const Point &A, const Point &B, const Point &C);

        PlaneSector(
                const Point &O, real r, real theta1, real theta2);

        const Point &Center() const;

        real InnerRadius() const;

        real OuterRadius() const;

        real SmallAngle() const;

        real BigAngle() const;


    private:

        Point TheCenter;
        real TheInnerRadius, TheSmallAngle, TheBigAngle;

    };
//////////////////////////////////////////////
} // cubpackpp
#endif
