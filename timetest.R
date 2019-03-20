library(matrixcalc)

# test shift right
a <- matrix(1:10000,nrow=100,ncol=100)
start <- Sys.time()
b <- shift.right(a,28,2)
end <- Sys.time()

end - start

# test lu decomposition
start_og <- Sys.time()
stir_og <- stirling.matrix(4)
end_og <- Sys.time()

end_og - start_og

start <- Sys.time()
stir <- stirling(4)
end <- Sys.time()

end - start
