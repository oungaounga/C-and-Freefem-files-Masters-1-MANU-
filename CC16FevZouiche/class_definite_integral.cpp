#include <iostream>
#include <cmath>
#include "class_definite_integral.hpp"
using namespace std;


//constructor
definite_integral::definite_integral(double a, double b, pfn f){
    lower = a;
    upper = b;
    integrand = f;
}


double definite_integral::trapezoidal(int n) const {
    double h = (upper-lower)/n;
    double integralP[n];
    double integral = 0.0;
    pfn f = integrand;
    for (int i=0; i<n; ++i){
        integralP[i] = (f(lower+(i*h))+f(lower+(i+1)*h))*(h/2);
        integral = integral + integralP[i];
    }
    return integral;
}

