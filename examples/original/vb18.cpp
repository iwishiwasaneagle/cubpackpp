//  Bivariate normal distribution
//  Note that special purpose methods exist for this type of integral.

#include <cubpackpp/cubpackpp.h>
#include <iostream>

using namespace cubpackpp;
// The integral depends on the following 3 parameters:
real rho, a, b;
real N;                   // This is used to save work

real f(const Point& p)
 { real x=p.X() , y=p.Y();
   return exp(N*(-x*x+2*rho*x*y-y*y)) ;
 }

int main ()
 {
   EvaluationCounter count;
   real c;

   // Read the 3 parameters from standard input:
   std::cout << "Give a,b and rho ( |rho| < 1 ): ";
   std::cin >> a >> b >> rho;

   // Define the region of integration:
   Point Center(a,b);
   PLANE_SECTOR quadrant(Center,0.0, M_PI , 3*M_PI/2);

   c = 1.0/(2.0*M_PI*sqrt(1.0 - rho*rho));
   N = 1.0/(2.0 - 2.0*rho*rho);
   count.Start();
   std::cout <<"The integral is " << Integrate(f,quadrant,0,0.5e-6)*c;
   std::cout <<" with absolute error " << quadrant.AbsoluteError()*c << std::endl;
   count.Stop();
   std::cout << count.Read() << " function evaluations were used." << std::endl;

   return 0;
 }
