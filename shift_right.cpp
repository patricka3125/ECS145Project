#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector shift_right(RObject mat, Function a, Function b,
        int cols=1, int fill=0) {
    if(!Rf_isMatrix(mat)) {
        stop("argument A is not a numeric matrix");
    }
    NumericMatrix num_mat = as<NumericMatrix>(mat);

    if(cols > 0) {
        /*
        int start = num_mat.nrow() * num_mat.ncol() - 1;
        int end = num_mat.ncol();
        for(int i=start; i >= end; i--) {
            num_mat[i] = num_mat[i-num_mat.ncol()];
        }

        for(int i=num_mat.ncol() - 1; i >=0; i--) {
            num_mat[i] = fill;
        }
        */

        NumericMatrix sub_mat = 
            num_mat(Range(0,num_mat.nrow()-1),Range(0,num_mat.ncol() - 2));
        return shift_right(a(b(fill,num_mat.nrow()),sub_mat),a,b,cols-1,fill);

        //return shift_right(num_mat,cols-1,fill);
    }
    return num_mat;
}
