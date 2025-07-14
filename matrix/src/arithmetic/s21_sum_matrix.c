#include "s21_arithmetic.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res;
  if (A == NULL || B == NULL || result == NULL) {
    res = ERROR;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    res = CALCULATION_ERROR;
  } else if (s21_infinity_matrix(A) != OK || s21_infinity_matrix(B) != OK) {
    res = CALCULATION_ERROR;
  } else {
    if (s21_create_matrix(A->rows, A->columns, result) == SUCCESS) {
      res = OK;
    }
    if (res == OK) {
      for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
      }
    }
  }
  return res;
}