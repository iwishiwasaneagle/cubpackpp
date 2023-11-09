// Example 23 from ditamo
// The function is rescaled such that the solution is 1.

#include <cubpackpp/cubpackpp.h>
#include <iostream>


using namespace cubpackpp;

real f(const Point& p)
 {
   real x=p.X() ;
   return 0.25/sqrt(x*(2.0-x));
 }

real Height(const Point& p)
  { return sqrt(4-2*p.X()); }

int main ()
 {
   Point A(0,0), B(2,0);
   GENERALIZED_RECTANGLE parabola(Height,A,B);
   Chrono TikTak;

   TikTak.Start();
   std::cout <<"The integral is " << Integrate(f,parabola,0,0.5e-4);
   TikTak.Stop();
   std::cout <<" with absolute error " << parabola.AbsoluteError() << std::endl;
   std::cout <<"Elapsed Time: " << TikTak.Read()/1000<<" seconds" << std::endl;

   return 0;
 }
