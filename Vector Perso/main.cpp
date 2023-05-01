#include <iostream>
#include <cmath>
#include "VectorP.hpp"

using namespace std;


int main(){
    int n = 5;
    double * v;
    v = new double[n];
    v[0] = 13.2;
    v[1] = 15.2;
    v[2] = 2.3;
    v[3] = 15.0;
    v[4] = 17.0;



    //Vector v(a);
    Vector w(v);
    double m = w.normMax();
    cout << n << endl;

   /*
   double * v;
   int n = 5;
   v = new double[n];
   cout << v[0] << endl;
   cout << v[3] << endl << endl;
    */
}
