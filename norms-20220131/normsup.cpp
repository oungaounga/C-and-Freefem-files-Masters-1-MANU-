#include <algorithm>// for max()
#include <cmath>

using namespace std;

/* a function that returns the maximum element in
   the jth row of the array v
   Note this alternative (and equivalent way of passing
   the array */
double maxRow(double v[][3], int const &j){

	double res = max(abs(v[j][0]), max(abs(v[j][1]), abs(v[j][2])));
	return res;

}
