#include <iostream>
using namespace std;


class point{
    private: 
    double abs;
    double ord;

    public :
    //void init(double, double);
    point(double, double);
    point();
    void deplace(double, double);
    void affiche();
    //~point();
};


/*
void point::init(double x, double y){
    abs = x;
    ord = y;
}
*/

void point::deplace(double dx, double dy){
    abs += dx;
    ord += dy;
}

void point::affiche(){
    cout << "("<< abs << ","<< ord <<")" << endl;
}


point::point(double x, double y){
    abs = x;
    ord = y;
}


class test{
    public : 
    int num;
    test(int n);
    ~test();
};  

test::test(int n){
    num = n;
    cout << "Appel construct"<< endl;
}

test::~test(){
    cout << "Appel destruct"<< endl;
}

int foo(int &x){
    int no = x*2 + 3;
    return no;
}



int main(){
    point a(3.14, 0.33);
    //a.abs = 5;
    //a.ord = 13;
    //a.init(1,1);
    a.affiche();
    cout << "apres deplacement : " << endl;
    a.deplace(0.5, 0.5);
    a.affiche();

    test b(3);
    cout << foo(b.num) << endl;

    //cout << b.num << endl;
    

}