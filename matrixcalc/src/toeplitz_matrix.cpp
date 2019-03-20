#include <Rcpp.h>
using namespace Rcpp;

using namespace std;
// [[Rcpp::export]]
NumericMatrix toeplitz_matrix(int n, NumericVector x) {
  if (n < 2)
    stop( "argument n is less than 2" );
  if(!Rf_isVector(x)) {
    stop( "argument x is not a vector" );
  }
  if (x.length() != (2 * n - 1))
    stop( "length of argument x is not comparable with n" );
  
  NumericMatrix T(n);
  
  for (int i = 0; i < n; ++i) 
    for (int j = 0; j < n; ++j)
      T(i,j) = x((i - j) + (n - 1));
  
  return T;
}
