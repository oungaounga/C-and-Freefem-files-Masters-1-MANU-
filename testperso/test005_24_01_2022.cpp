#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c;
    cout << "Donner les coeficients de votre polynome de second degré"<<endl;
    cout << "a ? : "<< endl;
    cin >> a;
    cout << "b ? : "<< endl;
    cin >> b;
    cout << "c ? : "<< endl;
    cin >> c;

    double delta;
    delta = (b*b) - (4*a*c);
    cout << "Le discriminant vaut :"<< delta << endl;

    if (delta == 0.0){
        double racine = -b/(2*a);
        cout << "La racine double est : +/-"<< abs(racine)<< endl;
    }
    if (delta > 0.0){
        double racineP;
        double racineN;
        racineP = (-b + sqrt(delta))/(2*a);
        racineN = (-b - sqrt(delta))/(2*a);
        cout << "Les deux racines sont : \n";
        cout << "x_1 = "<< racineP << endl;
        cout << "x_2 = "<< racineN << endl;
    } 
    else{
        cerr << "Erreur : discriminant negatif, pas de racines reelles."<< endl;
    }
}