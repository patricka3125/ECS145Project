#include <Rcpp.h>
using namespace Rcpp;


using namespace std;
// [[Rcpp::export]]
NumericMatrix stirling(int n) {
  int nm1 = n - 1;
  int np1 = n + 1;
  NumericMatrix S(np1);
  
  //if(!isdigit(n))
    //throw string("argument n is not numeric");
  if (n < 1)
    throw string("argument n is less than 1");
  if (n == 1)
    return S;
  
  for (int i = 0; i <= n; ++i) {
    S(i, i) = 1;
  }
  
  for (int j = 0; j <= n; ++j) {
    S(0, j) = 0;
    S(j, 0) = 0;
  }
  
  for (int i = 1; i <= nm1; ++i) {
    for (int j = 1; j <= i; ++j) {
      S(i + 1, j) = S(i,j - 1) + j * S(i, j);
    }
  }
  
  S(0, 0) = 1;
  return S;
}


// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically 
// run after the compilation.
//

/*** R
stirling(4)
*/