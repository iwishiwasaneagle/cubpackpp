#include <cubpackpp/cubpackpp.h>
#include <iostream>

using namespace cubpackpp;
real f(const Point& p)
 { real r=p.Length();
   return 1.0/(1.0+r*r*r*r); }

int main ()
 { Point origin(0,0);
   real radius=1;
   CIRCLE cir(origin,radius);

   std::cout <<"The integral is " << Integrate(f, cir, 0, 1.0e-6, 10000);
   std::cout <<" with absolute error " << cir.AbsoluteError() << std::endl;

   return 0;
 }
