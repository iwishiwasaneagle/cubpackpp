// #  Copyright 2023 Jan-Hendrik Ewers
// #  SPDX-License-Identifier: GPL-3.0-only

#include <cubpackpp/cubpackpp.h>
#include <iostream>
#include <chrono>
#include <iomanip>

using namespace cubpackpp;

real f(const Point &p) {
    real x = p.X(), y = p.Y();
    return exp(0.5 * (-x * x - y * y));
}

int main() {
    real innerradius = 0, alfa = 0, beta = atan(2.0), total;
    const real N = 1e4;

    std::cout << "Number of runs per benchmark = " << N << std::endl << std::endl;

    std::cout.setf(std::ios::scientific, std::ios::floatfield);
    std::cout << "req. rel. error      evaluations         total time (s)     time per run (us)" << std::endl;

    for (real req_err = 0.05; req_err > 1e-12; req_err /= 10) {

        EvaluationCounter counter;
        counter.Start();
        auto start = std::chrono::high_resolution_clock::now();

        for (real i = 0; i < N; i++) {
            Point origin(i, i);
            PLANE_SECTOR wedge(origin, innerradius, alfa, beta);
            Integrate(f, wedge, 0, req_err);
        }

        counter.Stop();
        total = static_cast<real>(counter.Read());

        auto stop = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();

        std::cout << std::setprecision(2) << req_err << "              "
                  << std::setprecision(1) << total << "              ";
        std::cout << std::setprecision(3) << static_cast<double>(elapsed) * 1e-9 << "              "
                  << std::setprecision(3) << static_cast<double>(elapsed) * 1e-3 / N << std::endl;
    }
    return 0;
}
