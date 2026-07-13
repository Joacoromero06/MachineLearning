#include "Sparse_Matrix_coo.h"
#include <stdio.h>

int create_Sparse_Coordinate(size_t n_rows, size_t n_cols, double* A, size_t n_nnz, Sparse_Coordinate* A_coo) {
  A_coo->n_rows = n_rows;
  A_coo->n_cols = n_cols;
  A_coo->n_nnz = n_nnz;
  
  A_coo->I = calloc(n_nnz, sizeof(size_t));
  A_coo->J = calloc(n_nnz, sizeof(size_t));
  A_coo->V = calloc(n_nnz, sizeof(double));

  double Aij;
  int nnz_id = 0;
  for (int i = 0; i < n_rows; i++){
    for (int j = 0; j < n_cols; j++){
      Aij = A[i*n_rows + j];
      if (Aij != 0) {
        A_coo->V[nnz_id] = Aij;
        A_coo->I[nnz_id] = i;
        A_coo->J[nnz_id] = j;
        nnz_id++;
      }
    }
  }
  return EXIT_SUCCESS;
}
int free_Sparse_Coordinate(Sparse_Coordinate* A_coo) {
  free(A_coo->I);
  free(A_coo->J);
  free(A_coo->V);
  return EXIT_SUCCESS;
}
int print_Sparse_Coordinate(const Sparse_Coordinate* A_coo){
  printf("\t|I\t|J\t|V");
  printf("\n-----------------------------------\n");
  for (int nnz_id = 0; nnz_id < A_coo->n_nnz; nnz_id++){
    printf("%02d\t %zu\t%zu\t%f\n", nnz_id, A_coo->I[nnz_id], A_coo->J[nnz_id], A_coo->V[nnz_id]);
  }
  return EXIT_SUCCESS;
}
      
int vector_matrix_coo(const Sparse_Coordinate* A_coo, const double* b, double* res){

  for (int i=0; i<A_coo->n_cols; i++){
    res[i] = 0;
  }
  int i, j;
  for (int nnz_id=0; nnz_id < A_coo->n_nnz; nnz_id++){
    i = A_coo->I[nnz_id];
    j = A_coo->J[nnz_id];
    res[i] = res[i] + A_coo->V[nnz_id] * b[j];
  }
  return EXIT_SUCCESS;
}
