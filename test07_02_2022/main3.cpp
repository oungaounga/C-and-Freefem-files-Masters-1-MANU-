#include <iostream>
#include <cstdlib>
#include "function.hpp"

using namespace std;

int main(){
    int a, b, c;
    pair<double, double> resultat;
    cout << "Donnez les coeficients de votre polynome de la forme : ax^2 + bx + c :\n";
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "c = "; cin >> c;

    if (cin.fail()){
        cout << "Donnez des réels"<< endl;
        exit(1);
    }

    
    resultat = Roots(a,b,c);
    if (resultat.first == resultat.second){
        cout << "La racine double est x0 = "<< resultat.first<< endl;
    }
    else{
        cout << "Les racines sont :"<< endl;
        cout << "x1 = "<< resultat.first<< endl;
        cout << "x2 = "<< resultat.second<< endl;
    }



}