#include <Rcpp.h>
using namespace Rcpp;

using namespace std;

unsigned long int factorial(unsigned long int q) 
{
	if (q == 0)
		return 1;
	return q * factorial(q - 1);
}


// [[Rcpp::export]]

NumericMatrix symmetric_pascal_matrix(int n) {
	if (n <= 1)
			stop( "data is too long" );


	NumericMatrix T(n);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 || j == 0) {
				T(i,j) = 1;
			}
			
			else {
				 unsigned long int above = i + j;
				 unsigned long int deciI = i;
				 unsigned long int deciJ = j;
				 T(i,j) = factorial(above) / (factorial(deciI) * factorial(deciJ));
			
			}
		}
	}
	
	return T;
	
}