#include <iostream>

using namespace std;

class hasard{
    private : 
    int val[10];

    public :
    hasard(int);
    void affiche();
};

hasard::hasard(int M){
    for(int i = 0; i<10; ++i){
        val[i] = double(rand()) / RAND_MAX * M;
    }
}

void hasard::affiche(){
    for(int i = 0; i<10; ++i) cout << val[i] << " ";
    cout << "\n";
}


int main(){
    hasard v(10);
    v.affiche();
    hasard w(5);
    w.affiche();
}