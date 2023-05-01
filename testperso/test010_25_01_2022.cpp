#include <iostream>
using namespace std;

int main(){
    double b = 3.0;
    double& z = b;
    cout << z <<endl;
    b = b +10;
    cout << z << endl;
    double* pb = &b;
    *pb = *pb + 10;
    cout << "*pb = "<< *pb << endl;
    cout << "z = "<< z << endl;
    cout << "b = "<< b << endl;

}