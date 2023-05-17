// #  Copyright 2023 Jan-Hendrik Ewers
// #  SPDX-License-Identifier: GPL-3.0-only

#include <iostream>
#include <cubpackpp/cubpackpp.h>

using namespace cubpackpp;

real f(const Point &p) {
    real x = p.X();
    return x * x;
}

int main() {
    Point A(0, 0), B(0, 1), C(1, 0);
    RECTANGLE rectangle(A, B, C);
    std::cout << "The integral is " << Integrate(f, rectangle, 0, 0.5e-4)
              << " with absolute error " << rectangle.AbsoluteError() << std::endl;
    return 0;
}

