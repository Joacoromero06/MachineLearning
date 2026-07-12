#include <stdio.h>
#include "Sparse_Matrix_coo.h"

int main(int argc, char** argv){
  /* Parameters of the practice */
  size_t n_rows = 5;
  size_t n_cols = 5;
  double A[] = {
    0, 3, 0, 2, -2,
    0, 0, 1, 0, 0,
    1, 0, -1, 0, 0,
    0, 4, 0, 0, 0,
    9, 0, 0, -1, 0
  };
  size_t n_nnz = 9;

  double b[] = {1, 2, 3, 4, 5};
  double res;
  
  /* Algorithm */
  Sparse_Coordinate A_coo;
  create_Sparse_Coordinate(n_rows, n_cols, A, n_nnz, &A_coo);
  print_Sparse_Coordinate(&A_coo);
  vector_matrix_coo(&A_coo, b, &res);

  printf("{");
  for (int i = 0; i < n_cols; i++){
    i == n_cols-1 ? printf("%f ,", b[i]) : printf("%f", b[i]);
  }
  printf("}");

  return EXIT_SUCCESS;
}
  
