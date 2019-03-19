#include <Rcpp.h>
using namespace Rcpp;

using namespace std;
using namespace std::chrono;
// [[Rcpp::export]]


NumericMatrix fibonacci_matrix(int n) {
	if (n < 1)
		stop( "argument n is less than 2" );

	NumericMatrix T(n+1);
	
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			if ((i-j+2) <= 0) {
				T(i,j) = 0;
			}
			else {
			 	int num = i-j+2;
				int f[i-j+3]; 
				f[0] = 0; 
  				f[1] = 1; 
  				if (num == 0) 
  					T(i,j) = 0;
  				else if (num == 1)
  					T(i,j) = 1;
  				else if (num == 2)
  					T(i,j) = 1;
  				else if (num == 3)
  				 	T(i,j) = 2;
  				else {
  					T(i,j) = T(i-1,j) + T(i-2, j);
  				}
  			
			}
		} 
	} 
	
	return T;
	
} 

// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically 
// run after the compilation.
//

/*** R

*/
