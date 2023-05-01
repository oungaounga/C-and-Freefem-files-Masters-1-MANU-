#include <iostream>

#include "type_def.hpp"
#include "norm2.hpp"
#include "normsup.hpp"

using namespace std;

int main () {
  // AD * v;  // equivalent to double (*v)[3];
	// double (*w)[3];

  int n=300; // The second dimension (normally is read from a file)
	int m=100;
  // //v = new double[n][3];
  v = new AD[n];
	w = new AD[m];

  // Let us fill the array with some values, normally
  // they are read from a file
  for (int i=0;i<n;++i)
    for (int j=0; j<3; ++j) v[i][j]=double(i*j);

	for (int i=0;i<m;++i)
    for (int j=0; j<3; ++j) w[i][j]=10.0*double(i*j);

  // cout<< "The fourth row of v: ";
  // cout<< v[3][0]<<" " <<v[3][1]<<" "<<v[3][2]<<endl;
  cout<< "Its norm is        :"<<normRow(v,3)<<endl;
  cout<< "The max element  is:"<<maxRow(v,3)<<endl;

  cout<< "   "<<endl;

	cout<< "Its norm is        :"<<normRow(w,3)<<endl;
  cout<< "The max element  is:"<<maxRow(w,3)<<endl;

  delete [] v;// clear the memory
	delete [] w;
}
