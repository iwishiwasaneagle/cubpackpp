// Example 20 from ditamo
// exact value = 4/15

#include <cubpackpp/cubpackpp.h>
#include <iostream>

using namespace cubpackpp;
real f(const Point& p)
 { real x=p.X() , y=p.Y() ;
   return
       sqrt(1-x-y);
 }

int main ()
 {
   Point origin(0,0),p1(1,0),p2(0,1);
   TRIANGLE ditamo20(origin,p1,p2);

   EvaluationCounter count;

   count.Start();
   std::cout <<"The integral is " << Integrate(f,ditamo20,0,0.5e-4,10000);
   std::cout <<" with absolute error " << ditamo20.AbsoluteError() << std::endl;
   count.Stop();
   std::cout << count.Read() << " function evaluations were used." << std::endl;

   return 0;
 }
