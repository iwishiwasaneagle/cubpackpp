// #  Copyright 2023 Jan-Hendrik Ewers
// #  SPDX-License-Identifier: GPL-3.0-only

#include <iostream>
#include <cubpackpp/cubpackpp.h>

real f(const Point &p) {
    real x = p.X();
    return x * x;
}

int main() {
    Point a(0, 0), b(1, 1), c(2, 0);
    TRIANGLE triangle(a,b,c);
    std::cout << "The integral is " << Integrate(f, triangle)
            << " with absolute error " << triangle.AbsoluteError() << std::endl;

    return 0;
}
