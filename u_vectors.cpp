#include <Rcpp.h>
using namespace Rcpp;

using namespace std;
using namespace std::chrono;
// [[Rcpp::export]]

List u_vectors(int n) {
	if (n < 1)
		stop( "argument n is less than 2" );	
		
	NumericMatrix K(n);
	NumericMatrix I((n+1)*2);
	
	for (int i = 0; i <= (n+1)*2; ++i) {
		for (int j = 0; j <= (n+1)*2; ++j) {
			if (i == j) {
				I(i,j) = 1;
			}
			else {
				I(i,j) = 0;
			}
		}	
	}
	
	int levelCount = 1;
	int zeroInCol = 0;
	
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; ++i) {
			if (zeroInCol != 0) {
				K(i,j) = 0;
				zeroInCol = zeroInCol - 1;
			}
			else {
				K(i,j) = levelCount;
				levelCount = levelCount + 1;
			}
		}
		zeroInCol = j+1;
	}
	
	List result = List::create(Named("K") = K, Named("I") = I);
	
	return result;
	
}





// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically 
// run after the compilation.
//

/*** R

*/