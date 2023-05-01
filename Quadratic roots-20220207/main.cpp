
#include <iostream>
#include <cstdlib>
#include "QuadraticRoot.hpp"

using namespace std;

int main(){

	using namespace std;
	cout<< "I will compute the root of ax^2+b^x+c"<<endl;
	double a(0);
	double b(1);
	double c(0);
	pair<double,double> result;

	cout<<"Give me a, b and c (all zeros to end)"<<endl;

	cin >> a>> b>>c;
	if(cin.fail())
	{
		cerr<<"Wrong input"<<endl;
		exit(2);
		}

	result=quadraticRoot(a,b,c);
			
	cout<<"x1= "<<result.first<<" x2= "<<result.second<<endl;

}
