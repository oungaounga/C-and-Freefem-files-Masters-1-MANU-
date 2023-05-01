#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Vector {
    int size;
    double * values;

    public :
    Vector(int &);
    void affiche();
    double normMax();

};