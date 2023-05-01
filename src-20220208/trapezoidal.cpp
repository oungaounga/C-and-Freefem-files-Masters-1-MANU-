#include <iostream>
#include <math.h>

#include "trapezoidal.hpp"

using namespace std;

double trapezoidal(double a, double b, pfn f, int n){
    double integral = 0.0; //the integral
    double integralP[n]; //integral of f between each two points of discretization
    double h = (b-a)/n; // step h
    int i; //an int to use in loops
    
    for (i=0; i<n; ++i){
        integralP[i] = (f(a+(i*h))+f(a+(i+1)*h))*(h/2);
        integral = integral + integralP[i];
    }
    return integral;
}