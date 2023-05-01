#pragma once
#include <iostream>
#include <cassert>
#include <cmath>
#include "Vector.hpp" // non suffisant, il faut une decla forward
using namespace std;

class Vector;
class Matrix 
{
    public :
    //constructor : 
    Matrix(int size, double value=0.);
    Matrix(Matrix const &);
    //Matrix();
    int nrows(){return n_rows;};
    int ncols(){return n_cols;};
    Matrix& operator=(const Matrix&);
    //Vector operator*(const Vector&) const;
    double* operator[](int i) const;
    friend ostream& operator<<(ostream&, const Matrix&);
    Vector operator*(const Vector &) const;

    //Matrix(int size, double value);


    int CG(Vector& x, const Vector& b, double& eps, int & iter);

    
    //destructor : 
    ~Matrix();

    private :
    int n_rows;
    int n_cols;
    double** values;



};