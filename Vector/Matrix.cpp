#include "Matrix.hpp"
#include "Vector.hpp"
using namespace std;


//le pointeur est un lien ?


Matrix::Matrix(int size, double value){
    n_rows = size;
    n_cols = size;
    values = new double*[n_cols];// ici values est un pointeur vers le 1er element du tableau de taille n_cols
                                 // en fait, values pointe vers tout le tableau, il est par défaut pointé vers le 
                                 // premier element, puis on peut parcourir le reste du tableau
                                 //Le plus important est d'avoir le 1er element du tableau
    for (int ii =0; ii<n_rows; ++ii){
        values[ii] = new double[n_rows];
    }

    for (int i_row =0; i_row<n_rows; ++i_row){
        for (int i_col =0; i_col<n_cols; ++i_col)
        {
            values[i_row][i_col] = value;
        }  //values[i] = *values +i 
    }
}

/*
Matrix::Matrix(){
    n_rows = 0;
    n_cols = 0;
    values = nullptr;
}
*/

Matrix::Matrix(Matrix const &A){
    if(A.values == 0){values = nullptr;}
    else
    {
        n_rows = A.n_rows;
        n_cols = A.n_cols;
        // values = A.values //ne fonctionne pas
        values = new double*[n_cols];
        for (int ii =0; ii<n_rows; ++ii)
        {
            values[ii] = new double[n_rows];
        }
        for (int i_row =0; i_row<n_rows; ++i_row)
        {
            for (int i_col =0; i_col<n_cols; ++i_col)
            {
                values[i_row][i_col] = A.values[i_row][i_col];
            }  //values[i] = *values +i 
        }
    }

}

Matrix::~Matrix()
{
    for (int ii =0; ii<n_cols; ++ii)
    {
    delete [] values[ii];
    }
    delete [] values;
    // cout << "Destruction de la matrice "<< values << endl;

}

/*
for(int i_rows=0; i_rows<n_rows; ++i_rows){
    for(int i_cols=0; i_cols<n_cols; ++i_cols){

    }

}
*/

Matrix& Matrix::operator=(const Matrix& A){
    if (&A == this){
        return *this;
    }
    else
    {
        for (int i=0; i<n_cols; ++i){
            delete [] values[i];
        }
        delete [] values;
        n_rows = A.n_rows;
        n_cols = A.n_cols;
        values = new double*[n_cols];
        for (int ii =0; ii<n_rows; ++ii)
        {
            values[ii] = new double[n_rows];
            }
        for (int i_row =0; i_row<n_rows; ++i_row)
        {
            for (int i_col =0; i_col<n_cols; ++i_col)
            {
                values[i_row][i_col] = A.values[i_row][i_col];
                }  //values[i] = *values +i 
        return *this;
        }
        

    }

}

std::ostream& operator<< (std::ostream& s, const Matrix& A){
        for(int i=0; i<A.n_rows;i++){
        s << "\n"<< i <<"-th row:   \n";
        for(int j = 0; j<A.n_cols; j++){
            s << A.values[i][j]<<" ";
            if (j%10==9)s << "\n";
        }
            s;
        }
        return s;
}


double* Matrix::operator[](int i) const{
    return values[i];
}

Vector Matrix::operator*(const Vector &v) const {
    if(v.size()==n_cols){
    Vector result(n_rows);
    for (int i=0; i<n_rows; ++i){
        for (int j=0; j<n_cols; ++j){
            result[i] += values[i][j]*v[j];
            }
        }
    return result;
    }
    else{
        cout << "operator* : bad matrix/vector sizes" << endl;
    }
}

int Matrix::CG(Vector& x, const Vector& b, double& eps, int & iter){
    if (n_rows != b.size()){
        cout << "CG : matrix and vector sizes do not match" << endl;
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
        Vector mp = (*this)*p;                     // one matrix-vector multiply
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

} // end CG()
