#include "../arithmetic/s21_arithmetic.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  if (A == NULL || result == NULL) return ERROR;

  int res;
  if (s21_create_matrix(A->columns, A->rows, result) == SUCCESS) res = OK;

  if (res == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        // обмен индексов при транспонировании
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  }

  return res;
}