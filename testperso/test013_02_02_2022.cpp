#include <iostream>
using namespace std;


void echange(int , int );
void echange1(int & ,int &);

int main(){
    int n = 10, p = 20, c = 10, d = 20;
    cout <<"Test sans reference :"<< endl;
    cout << "avant appel : "<< n << " "<< p << endl;
    echange(n, p);
    cout << "apres appel : " << n <<" "<< p << endl << endl;

    cout <<"Test avec reference :"<< endl;
    cout << "avant appel : "<< c << " "<< d << endl;
    echange1(c, d);
    cout << "apres appel : " << c <<" "<< d << endl;


}

void echange(int a, int b){
    int c;
    cout << "debut echange : "<< a <<" "<< b << endl;
    c = a; a = b; b = c;
    cout << "fin echange : "<< a << " "<< b << endl;
}

void echange1(int &a, int &b){
    int c;
    cout << "debut echange : "<< a <<" "<< b << endl;
    c = a; a = b; b = c;
    cout << "fin echange : "<< a << " "<< b << endl;
}