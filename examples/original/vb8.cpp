// Example

#include <cubpackpp/cubpackpp.h>
#include <iostream>
#include <math.h>


using namespace cubpackpp;
real f(const Point& p)
 { 
   return exp(-p.Y()*p.Y());
 }

int main ()
 { Point A(0,0), B(1,0);
   INFINITE_STRIP langelat(A,B);

   EvaluationCounter TikTak; TikTak.Start();
 //  std::cout.setf(std::ios::left,std::ios::adjustfield);
   std::cout.setf(std::ios::scientific,std::ios::floatfield);

   std::cout <<"The integral is " << Integrate(f,langelat,0,0.5e-3,10000);
   std::cout <<" with estimated absolute error "
        << langelat.AbsoluteError() << std::endl;
   std::cout <<"The real error is "
        << langelat.Integral() - sqrt(M_PI) <<std::endl;

   TikTak.Stop(); std::cout<<"Number of evaluations = "<<TikTak.Read()<<std::endl;

   return 0;
 }
