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
    double delta = (b*b) - (4*a*c);
    cout << "Le discriminant vaut :"<< delta << endl;
    
    enum dttype{delta > 0, delta == 0, delta < 0};

    dttype coef;

    switch(coef){
        case delta > 0 :
        double racineP, racineN;
        racineP = (-b + sqrt(delta))/(2*a);
        racineN = (-b - sqrt(delta))/(2*a);
        cout << "Les deux racines sont : \n";
        cout << "x_1 = "<< racineP << endl;
        cout << "x_2 = "<< racineN << endl;
        break;

        case delta == 0 : 
        double racine;
        racine = -b/(2*a);
        cout << "La racine double est : +/-"<< racine<< endl;
        break;


        case delta < 0 : 
        cerr << "Erreur : discriminant negatif, de racines reelles."<< endl;
        break;
    }
    
    

}