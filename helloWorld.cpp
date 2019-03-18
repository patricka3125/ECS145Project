/*
 * Test cpp to see if Rcpp works as expected
 */

#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
void printHello() {
    printf("Hello world.\n");
}
