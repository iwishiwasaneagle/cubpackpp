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
    REGION_COLLECTION triangles;

    for (int i = 0; i < 100; i++) {
        Point A(i, i), B(i, i + 1), C(i + 1, i);
        triangles += TRIANGLE(A, B, C);
    }

    std::cout << "The integral is " << Integrate(f, triangles, 0, 0.5e-4)
              << " with absolute error " << triangles.AbsoluteError() << std::endl;
    return 0;
}
