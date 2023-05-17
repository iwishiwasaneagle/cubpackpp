#include <cubpackpp/cubpackpp.h>
#include <iostream>

using namespace cubpackpp;
real f(const Point& p)
  { real x=p.X();
    return x*x;
  }

int main()
  { Point p1(0,0), p2(1,1), p3(2,0);
    TRIANGLE T(p1,p2,p3);
    std::cout << "The integral is " << Integrate(f,T) << std::endl;

    return 0;
  }
