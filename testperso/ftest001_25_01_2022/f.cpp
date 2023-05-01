#include <iostream>
using namespace std;


void f(double a, double& b, double const& c){

    double* pa = &a;
    double* pb = &b;
    cout << pb << endl;
    cout << pa << endl;
}