#include "Full_Mat.hpp"
#include "Abstract_Mat.hpp"
//#include "Vector.hpp"
using namespace std;


//le pointeur est un lien ?


Full_Mat::Full_Mat(int size, double value):Abstract_Mat(size){
    n_rows = size;
    n_cols = size;
    values = new double*[n_cols];
    // ici values est un pointeur vers le 1er element du tableau de taille n_cols
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


Full_Mat::Full_Mat(Full_Mat const &A):Abstract_Mat(A.n_rows){
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

Full_Mat::~Full_Mat()
{
    for (int ii =0; ii<n_cols; ++ii)
    {
    delete [] values[ii];
    }
    delete [] values;
    // cout << "Destruction de la matrice "<< values << endl;

}


Full_Mat& Full_Mat::operator=(const Full_Mat& A){
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
    return *this;

}

std::ostream& operator<< (std::ostream& s, const Full_Mat& A){
        for(int i=0; i<A.n_rows;i++){
        s << "\n"<< i <<"-th row:   \n";
        for(int j = 0; j<A.n_cols; j++){
            s << A.values[i][j]<<" ";
            if (j%10==9)s << "\n";
        }
            return s;
        }
        return s;
}


double* Full_Mat::operator[](int i) const{
    return values[i];
}

Vector Full_Mat::operator*(const Vector &v) const {
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
        cout << "operator* : bad Full_Mat/vector sizes" << endl;
        return 0;
    }
}