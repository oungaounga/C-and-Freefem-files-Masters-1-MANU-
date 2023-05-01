#include <iostream>
#include <cmath>
#include <vector>
using namespace std;



void f(double a, double& b, double const& c){
        

    double* pa = &a;
    double* pb = &b; // pc = &c;

    cout << "l'adresse de a est :"<< pa << endl;
    cout << "l'adresse de b est :"<< pb << endl;

    

    // cout << "a avant modification par f(double a, double& b, double const& c) : "<< a << endl;
    // a += 10;
    // cout << "a apres modification par f : "<< a << endl;

    // cout << "b avant modification par f(double a, double& b, double const& c) : "<< b << endl;
    // b += 10;
    // cout << "b apres modification par f : "<< b << endl;

    /*
    cout << "c avant modification par f(double a, double& b, double const& c) : "<< c << endl;
    c += 10;
    cout << "c apres modification par f : "<< c << endl;
    */
}