#include <iostream>
#include <cmath>
#include <vector>
#include "f.hpp"
using namespace std;


// void f(double a, double& b, double const& c){


//     double* pa = &a;
//     double* pb = &b; // pc = &c;

//     cout << "l'adresse de a est :"<< pa << endl;
//     cout << "l'adresse de b est :"<< pb << endl;

    

    // cout << "a avant modification par f(double a, double& b, double const& c) : "<< a << endl;
    // a += 10;
    // cout << "a apres modification par f : "<< a << endl;

    // cout << "b avant modification par f(double a, double& b, double const& c) : "<< b << endl;
    // b += 10;
    // cout << "b apres modification par f : "<< b << endl;

    /*
    cout << "c avant modification par f(double a, double& b, double const& c) : "<< c << endl;
    c += 10;
    cout << "c apres modification par f : "<< c << endl;
    */
//}

int main(){
    double x = 1, y= 1, z=3;
    double* px = &x;
    double* py = &y;
    double* pz = &z;
    cout << "l'adresse de x est :"<< px << endl;
    cout << "l'adresse de y est :"<< py << endl;
    f(x,y,z);
//      cout << "y avant modification par f :"<< y<< endl;
//      cout << "avant de faire appel a f : x, une variable globale est : "<< x << endl;
//      f(x,y,z); // on ne peut pas avoir Type resultat = f(x,y,z) car f ne renvoie rien, on peut juste 
//     //dire au programme de faire tourner f en (x,y,z)
//      cout << "x, toujours une variable gloable, apres modification par f :  " << x << endl;
//       cout << "on a bien, avec x=1, y=1, z=3, f(x,y,z) =  "<< f(x,y,z) << endl;
//      cout << "On remarque la definition par copie n'a pas d'effet sur x la variable globale"<< endl << endl;
//     cout << "y apres modification :"<< y << endl<<endl;
//     cout << "De plus, si on veut modifier c à l'interieur de f, le programme renvoie une erreur"<< endl;
//     cout << "Il est bien utile de connaître les erreurs afin de pouvoir les interpreter plutard"<< endl;
}