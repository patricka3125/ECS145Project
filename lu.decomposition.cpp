// for ( i in 1:n ) {
//     ip1 <- i + 1
//     im1 <- i - 1
//     for ( j in 1:n ) {
//         U[i,j] <- x[i,j]
//         if ( im1 > 0 ) {
//             for ( k in 1:im1 ) {
//                 U[i,j] <- U[i,j] - L[i,k] * U[k,j]
//             }
//         }
//     }
//     if ( ip1 <= n ) {
//         for ( j in ip1:n ) {
//             L[j,i] <- x[j,i]
//             if ( im1 > 0 ) {
//                 for ( k in 1:im1 ) {
//                     L[j,i] <- L[j,i] - L[j,k] * U[k,i]
//                 }
//             }
//             if ( U[i,i] == 0 )
//                 stop( "argument x is a singular matrix" )
//             L[j,i] <- L[j,i] / U[i,i]
//         }    
//     }
// }

#include <Rcpp.h>
using namespace Rcpp;

using namespace std;
// [[Rcpp::export]]
List ludecomposition(NumericMatrix L, NumericMatrix U, NumericMatrix x, int n) {

	int ip1, im1;
	// params: matrices U, x, L, int n

    for ( int i = 1; i <= n; i++) {
	    ip1 = i + 1;
	    im1 = i - 1;
	    for ( int j = 1; j <= n; j++ ) {
	        U(i-1,j-1) = x(i-1,j-1);
	        if ( im1 > 0 ) {
	            for ( int k = 1; k <= im1; k++ ) {
	                U(i-1,j-1) = U(i-1,j-1) - L(i-1,k-1) * U(k-1,j-1);
	            }
	        }
	    }
	    if ( ip1 <= n ) {
	        for ( int j = ip1; j <= n; j++ ) {
	            L(j-1,i-1) = x(j-1,i-1);
	            if ( im1 > 0 ) {
	                for ( int k = 1; k <= im1; k++ ) {
	                    L(j-1,i-1) = L(j-1,i-1) - L(j-1,k-1) * U(k-1,i-1);
	                }
	            }
	            if ( U(i-1,i-1) == 0 )
	                stop( "argument x is a singular matrix" );
	            L(j-1,i-1) = L(j-1,i-1) / U(i-1,i-1);
	        }    
	    }
	}

	List result = List::create(L, U);

	return result;
}

// in R:
// library(Rcpp)
// sourceCpp("lu.decomposition.cpp")
// return ludecomposition(L, U, x, n)