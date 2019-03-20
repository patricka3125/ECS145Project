#include <Rcpp.h>
using namespace Rcpp;

using namespace std;

unsigned int factorial(unsigned int q) 
{
	if (q == 0)
		return 1;
	return q * factorial(q - 1);
}


// [[Rcpp::export]]

NumericMatrix symmetric_pascal_matrix(int n) {
	if (n < 1)
			stop( "data is too long" );
			
/*	for(int i = 1; i <=n; ++i) {
			factorial *= i;
	}
	
*/

	NumericMatrix T(n);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 || j == 0) {
				T(i,j) = 1;
			}
			
			else {
				T(i,j) = factorial(i+j) / (factorial(i) * factorial(j));
			
			}
		}
	}
	
	return T;
	
}