#pragma once
 #include <iostream>
 #include <cassert>
 #include <cmath>

 using namespace std;

class Vector {
    private : 
    
    double * M_data; int M_size;

    
    public :

    //Construction
    Vector(int size, double v = 0);  //constructeur ? on est pas obligé de mettre v
    Vector(Vector const &v); //copie de vecteurs
    int size() const; //{return M_size;}
    void affiche();
    
    //delete operator
    ~Vector();
    
    //overload operators 
    Vector& operator =(Vector const &v);
    double& operator [](int i); //const{return M_data[i];}
    //Rmq : - [] est unaire (il prend un seul argument)
    //-Operator : Effectue un operation. Unaire : Effectue une operation
    //sur un seul argument. Binaire : Effectue une operation sur deux
    //argument etc..
    //- L'opérateur [] fournit la i-ième (-1) valeur du vecteur
    //souhaité. Ici nos vecteur sont des doubles, donc la fonction 
    //opetaor+ renvoie un double, elle est donc du type double.. 
    double operator[](int i) const; //{return M_data[i];}
    //C'est une définition inline
    friend Vector operator+(const Vector&);
    friend Vector operator-(const Vector&);
    friend Vector operator+(Vector const&, Vector const &);
    friend Vector operator-(Vector const&, Vector const &);
    friend Vector operator*(double , const Vector &);
    friend Vector operator*(const Vector&, double);

    friend double dot(const Vector&, const Vector&);
    double maxnorm() const;// le const à la fin veut dire que la fonction peut travailler sur des const, mais pas obligatoirement un const en arg
    double twonorm() const;
    Vector& operator+=(const Vector& vec);
    Vector& operator-=(const Vector& vec);

    //Le terme ami c'est pour donner l'accès au membres privées
    //Une fonction ami est une fonction indé

    //Les Class::foo c'est pour les fonctions membres


    //overload of <<
    friend std::ostream& operator << (std::ostream&, const Vector&); 
};