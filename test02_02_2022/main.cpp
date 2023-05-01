#include <iostream>
#include "rational.hpp"
using namespace std;


int main(){
    Rational p(2, 3);
    Rational q(113);
    Rational r;
    Rational b; // pas d'arguemtns : prends la classe par défaut
    b = q ;
    //p.set(2., 3.);      /*Le point "." après p c'est l'accès : ie, on rentre dans la classe p, on modifie p"*/
    cout << "denominateur p : "<<p.den()<< endl;
    cout << "nominateur : q "<<q.den()<< endl;
    cout << "r numerateur : "<< r.den() << endl;
    cout << "deno b : "<< b.num()<< endl;
    cout << "num b : "<< b.den()<< endl;




}