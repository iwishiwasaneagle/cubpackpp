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
   real Integral_est, Error_est;
   Boolean Success;

   EvaluationCounter TikTak; TikTak.Start();
   std::cout.setf(std::ios::scientific,std::ios::floatfield);

   do
     {
      Integrate(f,langelat,Integral_est,Error_est,Success,0,0.5e-7,10000);
      std::cout <<"The integral is " << Integral_est;
      std::cout <<" with estimated absolute error "
           << Error_est << std::endl;
      std::cout <<"The real error is "
           << Integral_est - 1 <<std::endl;
      std::cout << "-------------------------------------------------"<<std::endl;
     }
   while ( ! Success );

   TikTak.Stop(); std::cout<<"Total number of evaluations = "
                      <<TikTak.Read()<<std::endl;

   return 0;
 }
