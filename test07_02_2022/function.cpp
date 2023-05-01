#include <iostream>
#include <cstdlib>
#include <utility>
#include <cmath>
#include "function.hpp"

using namespace std;

std::pair<double, double>Roots(const double &a, const double &b, const double &c)
{
    double discri = b*b-4*a*c;
    
    // if (discri<0.0)
    // {
    //     cout<<"Discriminant negatif"<< endl;
    //     exit(1);
    // }
    
    if (discri == 0.0)
    {
        double x0 = -b/(2*a);
        make_pair(x0, x0);
    }
    
    else
    {
        double x1 = (-b - sqrt(discri))/2*a;
        double x2 = (-b + sqrt(discri))/2*a;
        make_pair(x1, x2);
    }
}