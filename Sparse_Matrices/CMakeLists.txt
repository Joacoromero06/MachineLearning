cmake_minimum_required(VERSION 3.10)
project(SparseMatrix)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable (SparseMain
  Sparse_Matrix_coo.c
  main.c
)
target_include_directories(SparseMain PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
