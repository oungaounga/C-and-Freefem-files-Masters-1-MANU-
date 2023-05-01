#include <iostream>
#include <cmath>
#include "test012f1.hpp"
#include "test012f2.hpp"
#include "test012f3.hpp"

using namespace std;


int main(){
    int a, b, c;
    cout << "Donner la valeur de a : ";
    cin >> a;
    cout << endl;
    cout << "Donner la valeur de b : ";
    cin >> b;
    cout << endl;
    cout << "Donner la valeur de c : ";
    cin >> c;
    cout << endl;


    double delta = descri(a,b,c);

    cout << "Le discriminant vaut : "<< delta << endl;

    if (delta > 0){
        int x1, x2;
        double *v = nullptr;
        v = deuxRacines(a, b, c, delta);
        x1 = v[0];
        x2 = v[1];
        cout << "Les deux racines sont : "<< endl;
        cout << "x1 = "<< x1 << endl;
        cout << "x2 = "<< x2 << endl;
    }

    else if (delta == 0){
        double x0 = racineDouble(a, b);
        cout << "La racine double est x0 = +/- "<< abs(x0) << endl;
    }

    else{
        cerr<<"Descriminant negatif, pas de racines réelles"<< endl;
    }



}