#pragma once
#include <iostream>
#include <cassert>
#include <cmath>
#include "Vector.hpp" // non suffisant, il faut une decla forward
#include "Abstract_Mat.hpp"
using namespace std;

class Vector;
class Abstract_Mat;

class Full_Mat : public Abstract_Mat
{
   private :
   // int n_rows;
   // int n_cols;
   double** values;
   public :
    //constructor : 
   Full_Mat(int size, double value=0.);
   Full_Mat (Full_Mat const &);
   //Methods : 

   int Conjugate_Gradient(Vector& x, const Vector& b, double& eps, int & iter);

   //Operators Overload
   Full_Mat& operator=(const Full_Mat&);
   double* operator[](int i) const;
   friend ostream& operator<<(ostream&, const Full_Mat&);
   Vector operator*(const Vector &) const;

   // Full_Mat(int size, double value);

   //destructor : 
   ~Full_Mat();





};