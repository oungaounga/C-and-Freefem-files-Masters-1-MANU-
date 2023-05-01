#include <iostream>
using namespace std;
// exemple pointeur


int main(){
    int a = 5;
    int b = 14;
    int * pa = nullptr; // défini un poiteur non spécifié (dangling pointer)
    pa = &a; // pointe pa vers a
    *pa = 7; // change la valeur de la variable qui est pointée par a, donc a devient a = 7
    cout << "la valeur de a est : "<< a << endl;
    cout << "pa pointe vers : " << *pa << "avec l'adresse" << pa << endl;
    int * pa2 = nullptr;
    pa2 = &a;
    cout << "pa2 : "<< pa2 << endl;
    *pa = 113;
    cout << "maintenant pa : "<< *pa <<" avec l'adresse : "<< pa << endl;
    cout << "et pa2 : "<< *pa2 << " avec l'adresse : "<< pa2 << endl;
    int * pb = nullptr;
    pb = &b;
    if (*pa == *pb){
        cout << "correct"<< endl;
    }
    else{
        cout<<"faux"<< endl;
    }
    /*
    if (a<10){
        int c = 13;
        pa = &c;
        cout << "pa est :"<< *pa << endl;
    }
    pa = nullptr;
    cout << "pa est aussi : " <<*pa << endl;
    */

   // Exemple reference : 
   int & ra = a;
   cout << "a alias : "<< ra;

}