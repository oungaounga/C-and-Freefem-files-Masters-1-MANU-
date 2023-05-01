#include "rational.hpp"
using namespace std;


    Rational::Rational(int num, int den):M_n(num), M_d(den){
        M_normalize();
    }
    // Rational::Rational(int num, int den){
    //     M_n = num;
    //     M_d = den;
    //     M_normalize();
    // }
    Rational::Rational(int num){
        M_n = num;
        M_d = 1;
    }
    Rational::Rational(){  //c'est la classe par défaut
        M_n = 12;
        M_d = 13;
    }
    Rational& Rational::operator =(Rational const & p){
        M_n = p.M_n;
        M_d = p.M_d;

        return *this;
    }


    //On aurait pû définir cet opérateur dans un autre 
    //fichier vu qu'il fait pas partie de la classe
    Rational operator -(Rational const & p){
        Rational t;
        t.M_n = -p.M_n;
        t.M_d = -p.M_d;

        return t;
    }   

    //on veut définir l'opération somme entre deux rationnels:
     Rational operator +(Rational const &p, Rational const &q){
         Rational t;
         //...
         if(p.Md == p.Md){
             //..
         }

         else{
             //..
         }
     }

    //def : copy constructor
    Rational::Rational(Rational const & p){
        M_n = p.M_n;
        M_d = p.M_d;
    }


    //def : destructor 
    Rational::~Rational(){}
    //void Rational::set(int num, int den){M_n = num; M_d = den;}  //ici les deux poits permettent de rentrer dans la classe
    
    
    int Rational::num() const {return M_n;}
    int Rational::den() const {return M_d;}

    void Rational::M_normalize(){
        // remplacer m_n et M_n par des nombres premiers entre eux
        // Utilise l'algorithme d'Euclide
    }
//toutes les definitions on les mets ici