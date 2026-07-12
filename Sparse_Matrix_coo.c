#include "Sparse_Matrix_coo.h"

int create_Sparse_Matrix(size_t n_rows, size_t n_cols, double* A, size_t n_nnz, Sparse_Coordinate* A_coo) {
  A_coo->n_rows = n_rows;
  A_coo->n_cols = n_cols;
  A_coo->n_nnz = n_nnz;

  return EXIT_SUCCESS;
}

