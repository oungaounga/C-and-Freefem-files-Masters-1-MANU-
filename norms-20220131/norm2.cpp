#include <cmath>
#include "type_def.hpp"

/* a function that computes the norm of the element
   in the jth row of the array v. I could also have defined it
   as double normRow(double (*v)[3], int const &j)
*/

double normRow(AD* v, int const &j){

	double res = v[j][0]*v[j][0] + v[j][1]*v[j][1] + v[j][2]*v[j][2];
	return sqrt(res);

}
