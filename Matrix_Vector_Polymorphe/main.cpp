#include <iostream>
#include <cassert>
#include <cmath>

#include "Vector.hpp"
#include "Abstract_Mat.hpp"
#include "Full_Mat.hpp"

class Vector;
class Abstract_Mat;
class Full_Mat;



using namespace std;

int main()
{
    int n = 20, m = 20;
    Full_Mat mat1(n,m);
    for(int i = 0; i<n; i++){
         for (int j = 0; j <m; j++){
             mat1[i][j] = n/(abs(i-j) + 1.0);
         }
    }
    Vector vec1(n);
    for (int i = 0; i <n; i++) vec1[i] = i;
    Vector res(vec1.size());
    // Vector res(vec1.size());
    Abstract_Mat* ptm = &mat1;
    double eps = 1.0e-14;
    int iter = 200;
    int ret = ptm->Conjugate_Gradient(res, vec1, eps, iter);
    if (ret==0) cout << "CG returned succefuly \n";

    cout << iter << "iterations used" << "\n";
    cout << "Residual in CG = "<< eps << "\n";



    //on déclare les vecteurs dans un scope afin de supprimer le vecte
    //dès la création


    //pour appeler une fonction dans une classe, il faut passer
    //par un objet de la classe, n'est pas appelé automatiquement
    /*
    Vector v2(5, 5);
    v2.affiche();

    int size = 10;
    Vector v3(size);
    
    Vector v4(v2); //va utiliser la constructeur par défaut Vector(int
    v4.affiche(); // équivaut à affiche(v4)

    std::cout << "coucou" << endl;

    Vector v5();
    //v4=v5;


    std::cout << " " << endl;
    std::cout << "v3[1 = "<< v3[1]<< endl;

    std::cout << " " << endl;
    v3[1] = 1;
    std::cout << "v#[1]" << v3[1]<< endl;

    std::cout << " " << endl;
    for (int ii = 0; ii <v3.size(); ++ii){
        v3[ii] = 10*ii;
        cout << "v3["<<ii<<"]="<<v3[ii]<<endl;
        }


    std::cout << "affichage de v2 via surcharge << "<< endl;
    std::cout << v3 << endl;

    Vector v6 = -v3;
    cout << v6 << endl;
    Vector v7 = v6-v3;
    cout << v7 << endl;
    Vector v8 = v7 + v3;
    cout << v8 << endl;

    double result = dot(v8, v3);
    cout << "dot product : " << result << endl;
    cout <<"two norm : "<< v2.twonorm()<< endl;
    cout << "norme max : "<< v2.maxnorm()<< endl;
    
    Vector v(5, 1);
    cout << v << endl;
    Matrix A(5, 3);
    cout << A << endl;
    Vector w(5);
    w = A*v;
    cout << w << endl;
*/


    




}