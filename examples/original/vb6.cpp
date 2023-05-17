// Example 28 from ditamo

#include <cubpackpp/cubpackpp.h>
#include <iostream>

using namespace cubpackpp;

real f(const Point& p)
 { real y=p.Y();
   return 1/(y*y);
 }

int main ()
 { Point A(2,-1), B(1,-1);
   SEMI_INFINITE_STRIP langelat(A,B);

   EvaluationCounter TikTak; TikTak.Start();
 //  std::cout.setf(std::ios::left,std::ios::adjustfield);
   std::cout.setf(std::ios::scientific,std::ios::floatfield);

   std::cout <<"The integral is " << Integrate(f,langelat,0,0.5e-7,20000);
   std::cout <<" with estimated absolute error "
        << langelat.AbsoluteError() << std::endl;
   std::cout <<"The real error is "
        << langelat.Integral() - 1 <<std::endl;

   TikTak.Stop(); std::cout<<"Number of evaluations = "<<TikTak.Read()<<std::endl;

   return 0;
 }
