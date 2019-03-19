library(matrixcalc)

# test shift right
a <- matrix(1:10000,nrow=100,ncol=100)
start <- Sys.time()
b <- shift.right(a,28,2)
end <- Sys.time()

end - start

# test lu decomposition

