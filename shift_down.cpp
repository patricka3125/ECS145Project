#include <Rcpp.h>
using namespace Rcpp;

using namespace std;
// [[Rcpp::export]]
NumericMatrix shiftDown(NumericMatrix A, int rows = 1, int fill = 0) {
  if(!Rf_isMatrix(A)) {
    stop("argument A is not a numeric matrix");
  }
  if ( rows < 0 )
    stop( "Argument rows is not positive" );
  
  if (rows > 0) {
    double x = double(fill);
    NumericVector xx(A.ncol(), x);
    A(rows - 1, _) = xx;
    return shiftDown(A, rows - 1, fill);
  }
  
  return A;
}


/*** R
*/
