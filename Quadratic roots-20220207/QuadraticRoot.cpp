#include <iostream>
#include "QuadraticRoot.hpp"

using namespace std;

pair<double,double> quadraticRoot(const double & a, const double & b, const double & c){

	double discriminant=b*b-4*a*c;

	if (discriminant <0.0){
		cout << "error: negative value for delta" << endl;
		exit(1);
	}

	discriminant=sqrt(discriminant);
	
	if (a==0){
		return make_pair(-c/b,-c/b);
	}
	else
	{
		double x1=(-b+discriminant)/(2*a);
		double x2=(-b-discriminant)/(2*a);

		return make_pair(x1,x2);
	}
}
