// Example 29 from ditamo

#include <cubpackpp/cubpackpp.h>
#include <iostream>


using namespace cubpackpp;

real f(const Point& p)
 { 
   return fabs(p.Y())*exp(-p.Y()*p.Y()/2);
 }

int main ()
 { Point A(0,0), B(1.107148717794090503,0);
   SEMI_INFINITE_STRIP langelat(A,B);

   EvaluationCounter TikTak; TikTak.Start();
 //  std::cout.setf(std::ios::left,std::ios::adjustfield);
   std::cout.setf(std::ios::scientific,std::ios::floatfield);

   std::cout <<"The integral is " << Integrate(f,langelat,0,0.5e-4,10000);
   std::cout <<" with estimated absolute error "
        << langelat.AbsoluteError() << std::endl;

   TikTak.Stop(); std::cout<<"Number of evaluations = "<<TikTak.Read()<<std::endl;

   return 0;
 }
