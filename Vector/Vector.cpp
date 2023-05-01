#include <iostream>
#include <cmath>
#include "Vector.hpp"
using namespace std;

Vector::Vector(int size,double value){
    cout << " "<< endl;
    M_size= size;
    M_data= new double[size];
    //cout << "Constructeur: allocation du tableau: " << M_data << endl;
    for (int kk=0; kk<M_size;++kk){
        M_data[kk]=value;
    }
}

Vector::~Vector(){
    //cout << "destruction du vecteur: " << M_data << endl;
    delete[] M_data;
}

void Vector::affiche(){
    cout << " "<< endl;
    cout << "Les composantes du vecteur sont " <<endl;
    cout << " "<< endl;
    for (int ii=0;ii<M_size;++ii){
        cout << "v["<< ii+1 << "] " << M_data[ii] << endl;
    }
    cout << " "<< endl;
}

//copy constructor
Vector::Vector(Vector const &v) {
    v.M_size==0? M_data = nullptr : M_data = new double[v.M_size];
    M_size= v.M_size;
    //cout << "Copy constructor: allocation du vecteur: " << M_data << " de taille ";
    //cout << " " << endl;
    for (int kk=0;kk<M_size;++kk) M_data[kk]=v.M_data[kk];
}


/*
Vector::Vector(Vector const &v):M_data(v.M_size==0?0: new double[v.M_size]), M_size
    for(int ii=0; ii<M_size; ++ii){
        M_data[ii] = v.M_data[ii];
    }
    cout << "Constructeur de copie : allocation du tableau :"<< M_data<< "de taille
    }

    */

//assignment operator
Vector& Vector::operator=(Vector const&v){
    if (this!= &v){
        delete[] M_data;
        M_data= new double[M_size=v.M_size];
       // cout << "Assign du vecteur: "<<v.M_data<<"\n";
        for(int kk=0;kk<M_size;++kk) {
            M_data[kk]=v.M_data[kk];
        }
        cout << " "<<endl;
    }
    return *this;
}

//subscript operator value
double& Vector::operator[](int i){return M_data[i];}

double Vector::operator[](int i)const{return M_data[i];}

// double Vector::operator[](int i) const{
//     return M_data[i];
// }

int Vector::size() const {
    return M_size;
}

//Surchage opérateur de sortie
std::ostream& operator<< (std::ostream& s, const Vector& v){
        using std::endl;
        for(int i=0; i<v.M_size;i++){
        s << "v["<< i <<"] "<< v[i] << endl;
        }
        return s;
}

//Surchage opérateur + 
Vector operator+(const Vector& vv){
    return vv;
}

//Surchage opérateur + 
Vector operator-(const Vector& vv){
    Vector tmp(vv.size());
    for(int ii=0;ii<vv.size();++ii) tmp[ii]=-vv[ii];
    return tmp;
}

Vector operator+(const Vector& v1, const Vector& v2)
{
    if(v1.size() == v2.size())
    {
        Vector tmp(v1.size());
        for(int ii=0; ii<v1.size(); ++ii) tmp[ii] = v1[ii] + v2[ii];
        return tmp;
    }
    else{
        cout << "operator+ : vectors dimensions do not match" << endl;
        exit(0);
    }
}

Vector operator-(const Vector& v1, const Vector& v2)
{
    if(v1.size() == v2.size())
    {
        Vector tmp(v1.size());
        for(int ii=0; ii<v1.size(); ++ii) tmp[ii] = v1[ii] - v2[ii];
        return tmp;
    }
    else{
        cout << "operator- : vectors dimensions do not match" << endl;
        exit(0);
    }
}

Vector operator*(double a, const Vector& v){
    Vector tm(v.M_size);
    for(int i = 0; i<v.M_size ; i++){
        tm[i] = a*v[i];
        return tm;
    }
    
}

Vector operator*(const Vector& vec, double scalar){
    Vector tm(vec.M_size);
    for(int i = 0; i<vec.M_size ; i++){
        tm[i] = scalar*vec[i];
        return tm;
    }



}



double dot(const Vector& v1, const Vector& v2) {
    if ( v1.M_size != v2.M_size){
        cout << "Bad vec size"<< endl;
        exit(0);
    }
    double tm = v1[0]*v2[0];
    for(int i=1; i <v1.M_size; ++i) tm += v1[i]*v2[i];
    return tm;

}

Vector& Vector::operator+=(const Vector& vec){
    if (M_size != vec.M_size){
        cout << "operator += bad vec sizes" << endl;
        exit(0);
    }
    for (int i=0; i < M_size; ++i){
        vec.M_data[i+1] += vec.M_data[i];
        }

}

Vector& Vector::operator-=(const Vector& vec){
    if (M_size != vec.M_size){
        cout << "operator -= bad vec sizes" << endl;
        exit(0);
    }
    for (int i=0; i < M_size; ++i){
        vec.M_data[i+1] -= vec.M_data[i];
        }

}

/*
double Vector::maxnorm()const {
    double max = abs(M_data[0]);
    for (int i=1; i< M_size; ++i){
        if (max<abs(M_data[i])){
            max = abs(M_data[i]);
        }
    }
    return max;

}
*/

double Vector::maxnorm()const {
    double max = abs(M_data[0]);
    for (int i=1; i< M_size; ++i){
        if (max<abs(M_data[i])){
            max = abs(M_data[i]);
        }
    }
    return max;

}

double Vector::twonorm()const{
    double nm = pow(abs(M_data[0]), 2);
    for (int i=1; i<M_size; i++){
        double vi = abs(M_data[i]);
        nm += vi*vi;
        }
    return sqrt(nm);

}