#pragma once
#include "Vector.hpp"
class Vector;

class Abstract_Mat
{
    protected :
        int n_rows;
        int n_cols;

    public:
    int nrows(){return n_rows;};
    int ncols(){return n_cols;};
    Abstract_Mat(int size){n_rows = size; n_cols = size;};
    virtual Vector operator*(const Vector&) const = 0; 
    //Le =0, c'est pour dire que l'utilisateur n'a pas le droit
    //de créer des objets du type Abstract_Mat
    int Conjugate_Gradient(Vector& x, const Vector& b, double eps, int & iter);
    //virtual ~Abstract_Mat();
};