#include "VectorP.hpp"


Vector::Vector(int & size){
        values = new double[size];
        for (int i=0; i < size; ++i){
            cout << "Le " << i <<"-eme element du vecteur ? :";
            cin >> values[i];
        } 
    }

void Vector::affiche(){
    int i = 0;
    for(i=0; i<size; ++i){
        cout << "v["<< i+1 <<"] ="<< values[i];
    }
}

Vector::Vector(double  &v){
    size = sizeof(v);
    for(int i=0; i < size; i++){
        values[i] = v[i];
    }
}

double Vector::normMax() {
    double norme = values[0];
    int M = size;
    for (int i=0; i<M; ++i){
        if(norme < values[i]){
            norme = values[i];
        }
        /*
        else{
            norme = norme;
        }
        */
    }
    return norme;
}