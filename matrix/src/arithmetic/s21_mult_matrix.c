#include "s21_arithmetic.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res;
  if (A == NULL || B == NULL || result == NULL) {
    res = ERROR;
  } else if (A->columns !=
             B->rows) {  // Для умножения матриц необходимо, чтобы число
                         // столбцов A равнялось числу строк В
    res = CALCULATION_ERROR;
  } else {
    if (s21_create_matrix(A->rows, B->columns, result) == SUCCESS) {
      res = OK;
    }
    if (res == OK && s21_infinity_matrix(A) == 0 &&
        s21_infinity_matrix(B) == 0) {
      for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->columns; j++) {
          result->matrix[i][j] = 0;
          for (int k = 0; k < A->columns; k++) {
            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
          }
        }
      }
    } else {
      res = CALCULATION_ERROR;
    }
  }
  return res;
}