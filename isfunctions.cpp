#include <Rcpp.h>


using namespace Rcpp;

using namespace std;
// [[Rcpp::export]]


// use this for:
// is.indefinite.R
// is.negative.definite.R
// is_negative_semi_definite.R
// is_positive_definite.R
// is_positive_semi_definite.R
List is_helper (List eigenvalues, int n, double tol) {

	List newvalues = clone(eigenvalues);

	for ( int i = 1 ; i <= n; i++ ) {
		double tempvalue = newvalues[i-1];
		if (tempvalue < 0)
			tempvalue = -tempvalue;
        if ( tempvalue < tol ) {
            newvalues[i-1] = 0;
        }
    }
	return newvalues;

	// usage - replace the for loop with:
	// library(Rcpp)
    // sourceCpp("../../isfunctions.cpp")
	// eigenvalues <- is_helper(eigenvalues, n, tol)

}