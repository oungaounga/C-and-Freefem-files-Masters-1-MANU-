#include <iostream>
#include <cmath>
using namespace std;


double * deuxRacines(double a, double b, double c, double delta){
    static double v[2];
    double x1, x2;
    x1 = (-b - sqrt(delta))/2*a;
    x2 = (-b + sqrt(delta))/2*a;
    v[0] = x1;
    v[1] = x2;
    return v;
}