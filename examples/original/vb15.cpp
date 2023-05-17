// The `House' example with on each subregion a different integrand.

#include <cubpackpp/cubpackpp.h>
#include <iostream>

using namespace cubpackpp;
real f1(const Point& p)
 { 
     return ( p.X()*p.X() );
 }

real f2(const Point& p)
 {
     return ( p.Y()*p.Y() );
 }

int main ()
 {
   TRIANGLE Roof( Point(0,1), Point(2,1), Point(1,2));
   RECTANGLE Walls( Point(0,0), Point(0,1), Point(2,0));
   REGION_COLLECTION House = Walls + Roof;
   Roof.LocalIntegrand(f1);
   Walls.LocalIntegrand(f2);
   EvaluationCounter count;

   count.Start();
   std::cout <<"The integral is " << Integrate(House);
   std::cout <<" with estimated absolute error " << House.AbsoluteError()
        << std::endl;
   std::cout <<"The contributions of the subregions are:"<<std::endl;
   std::cout <<"  Walls: integral = "<<Walls.Integral()
        <<", error = " << Walls.AbsoluteError() << std::endl;
   std::cout <<"  Roof:  integral = "<<Roof.Integral()
        <<" , error = " << Roof.AbsoluteError() << std::endl;
   count.Stop();
   std::cout <<"The exact value is 2/3 + 7/6 = 11/6" << std::endl;
   std::cout << count.Read() << " function evaluations were used." << std::endl;

   return 0;
 }
