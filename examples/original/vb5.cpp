// Example 5 from ditamo

#include <cubpackpp/cubpackpp.h>
#include <iostream>


using namespace cubpackpp;

real f(const Point& p)
 { real x=p.X() , y=p.Y();
   return p.Y();
 }

real Height(const Point& p)
  { real x=p.X();
    return sqrt(4*cos(x)*cos(x)/9 - 16*sin(x)*sin(x)/25);
  }

int main ()
 { Point A(0,0), B(atan(5.0/6.0),0);
   GENERALIZED_RECTANGLE lemniscate(Height,A,B);

   EvaluationCounter TikTak; TikTak.Start();
 //  std::cout.setf(std::ios::left,std::ios::adjustfield);
   std::cout.setf(std::ios::scientific,std::ios::floatfield);

   std::cout <<"The integral is " << Integrate(f,lemniscate,0,0.5e-7,10000);
   std::cout <<" with estimated absolute error "
        << lemniscate.AbsoluteError() << std::endl;
   std::cout <<"The real error is "
        << lemniscate.Integral() - (2-11*atan(5.0/6.0)/15)/15 <<std::endl;

   TikTak.Stop(); std::cout<<"Number of evaluations = "<<TikTak.Read()<<std::endl;

   return 0;
 }
