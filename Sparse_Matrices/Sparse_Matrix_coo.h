#include <stdlib.h>


typedef struct {
  size_t n_rows;
  size_t n_cols;
  size_t n_nnz; /* number of non-zero elements in SparseMatrix */

  size_t* I; /* array of size n_nnz of row indices of V[id] in original Sparse Matrix */
  size_t* J; /* same for columns indices */ 
  double* V; /* The actual value, V[id] = Sparse[I[id], J[id]] */
} Sparse_Coordinate;

int create_Sparse_Coordinate(
    size_t n_rows, 
    size_t n_cols, 
    double* A,
    size_t n_nnz, 
    Sparse_Coordinate* A_Coo
);

int free_Sparse_Coordinate(Sparse_Coordinate* A_coo);
int print_Sparse_Coordinate( Sparse_Coordinate* A_coo);
int vector_matrix_coo(
    Sparse_Coordinate* A_coo,
    double * b,
    double * res
);



