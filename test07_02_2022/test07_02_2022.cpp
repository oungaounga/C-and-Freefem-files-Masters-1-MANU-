#include <iostream>

using namespace std;


int main(){
    int somme(int *a, int *b);
    int n = 10, p = 20;
    int *a =&n, *b = &p;
    // a = &n;
    // b = &p;
    somme(a, b);
    cout << "La somme est : "<< somme(a,b)<< endl;

}

int somme(int * const a, int * const b){
    int somme;
    somme = *a + *b;
    return somme;
}