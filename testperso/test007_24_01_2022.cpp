#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


typedef double AD[5];

double normDow(AD v, int const &j){
        int vj = v[j];
        int normvj = sqrt(vj*vj);
        return normvj;
    }

int main(){
    
    AD v;
    for(int i = 0; i < 5; ++i){
        cout << "quelle valeur pour le "<< i+1 <<"-eme coef du vecteur ? : "<< endl;
        cin >> v[i];
    }
    //cout << v << endl;

    int j;
    cout << "Quelle coef du vecteur ? : "<< endl;
    cin >> j;
   
    double result = normDow(v, j);
    cout << result << endl;
    return 0;   
}