#include <iostream>
#include "f.hpp"
using namespace std;


int main(){
    double x = 1;
    double y = 2;
    double z = 3;

    double* px = &x;
    double* py = &y;
    double* pz = &z;

    f(x,y,z);
}