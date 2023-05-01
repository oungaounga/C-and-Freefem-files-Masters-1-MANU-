// #pragma once
#include "Abstract_Mat.hpp"
#include "Full_Mat.hpp"
#include "Vector.hpp"
#include <iostream>
#include <cmath>

using namespace std;

/*
Abstract_Mat::Abstract_mat(Full_Mat const &A){

}
*/

int Abstract_Mat::Conjugate_Gradient(Vector& x, const Vector& b, double eps, int 
& iter){
    if (n_rows != b.size()){
        cout << "CG : Full_Mat and vector sizes do not match" << endl;
    }

    const int maxiter = iter;
    Vector r = b - (*this)*x;
    Vector z = r;
    Vector p = z;
    double zr = dot(z,r);
    const double stp = eps*b.twonorm();

    if (r.maxnorm() == 0.0){
        eps = 0.0;
        iter = 0;
        return 0;
    }
    for (iter = 0; iter < maxiter; iter++) {     // main loop of CG method
        Vector mp = (*this)*p;                     // one Full_Mat-vector multiply
        double pap = dot(mp,p);                         // one of two inner products
        double alpha = zr/pap;                          // pap is 0 only when r is 0
        x += alpha*p;                              // update the iterative soln
        r -= alpha*mp;                             // update residual
        if (r.twonorm() <= stp) break;             // stop if convergence achieved

    //z = preconding(r,prec);                    // preconditioning
        z=r;
        double zrold = zr;
        zr = dot(z,r);                             // another of two inner products
        double beta= zr/zrold;                          // zrold = 0 only when r is 0
        p = z + beta*p;                            // update search direction
        }
  eps = r.twonorm();
  if (iter == maxiter) return 1;
  else return 0;

}