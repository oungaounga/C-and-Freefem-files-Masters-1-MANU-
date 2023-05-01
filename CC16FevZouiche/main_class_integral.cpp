#include <iostream>
#include <cmath>
#include "class_definite_integral.hpp"
using namespace std;

double square(double d) 
{
  return d*d; 
}

int main(){

    definite_integral f1(0., 5.,square);
    definite_integral f2(0., 5., sqrt);

    int n = 100;
    double result1 = f1.trapezoidal(n);
    double result2 = f2.trapezoidal(n);
    cout <<"Integral of x^2 on ["<<f1.lowbd()<< ","<<f1.upbd();
    cout << "] with n = 100 is : "<< result1 << endl;
    cout <<"Integral of sqrt on ["<<f2.lowbd()<< ","<<f2.upbd();
    cout << "] with n = 100 is : "<< result2 << endl;
    f1.change_bounds(0., 1.);
    f2.change_bounds(0., 1.);
    double result1b = f1.trapezoidal(n);
    double result2b = f2.trapezoidal(n);
    cout <<"Integral of x^2 on ["<<f1.lowbd()<< ","<<f1.upbd();
    cout << "] with n = 100 is : "<< result1b << endl;
    cout <<"Integral of sqrt on ["<<f2.lowbd()<< ","<<f2.upbd();
    cout << "] with n = 100 is : "<< result2b << endl;
}
