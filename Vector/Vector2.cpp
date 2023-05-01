#include "Vector.hpp"
using namespace std;

Vector::Vector(int size,double value){
    cout << " "<< endl;
    M_size= size;
    M_data= new double[size];
    cout << "Constructeur: allocation du tableau: " << M_data << endl;
    for (int kk=0; kk<M_size;++kk){
        M_data[kk]=value;
    }
}

Vector::~Vector(){
    cout << "destruction du vecteur: " << M_data << endl;
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
Vector::Vector(Vector const &v){
    v.M_size==0? M_data = nullptr : M_data = new double[v.M_size];
    M_size= v.M_size;
    cout << "Copy constructor: allocation du vecteur: " << M_data << " de taille " << M_size << "\n";
    cout << " " << endl;
    for (int kk=0;kk<M_size;++kk) M_data[kk]=v.M_data[kk];
}

//assignment operator
Vector& Vector::operator=(Vector const&v){
    if (this!= &v){
        delete[] M_data;
        M_data= new double[M_size=v.M_size];
        cout << "Assign du vecteur: "<<v.M_data<<"\n";
        for(int kk=0;kk<M_size;++kk) M_data[kk]=v.M_data[kk];
        cout << " "<<endl;
    }
    return *this;
}

//subscript operator value
double& Vector::operator[](int i){
    return M_data[i];
}

double Vector::operator[](int i) const{
    return M_data[i];
}

int Vector::size(){
    return M_size;
}

//Surchage opérateur de sortie
std::ostream& operator << (std::ostream& s, const Vector& v){
        using std::endl;
        s << "Srucharge opérateur <<: traille du vecteur " << v.M_size << endl;
        for (int i=0;i<v.M_size;i++) {
            s << i << " " << v[i] << endl;
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