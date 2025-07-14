#include "s21_arithmetic.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int res;
  if (A == NULL || result == NULL) {
    res = ERROR;
  } else if (s21_infinity_number(number) != OK) {
    res = CALCULATION_ERROR;
  } else {
    if (s21_create_matrix(A->rows, A->columns, result) == SUCCESS) {
      res = OK;
    }
    if (res == OK) {
      for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->columns; j++) {
          if (s21_infinity_number(A->matrix[i][j]) == OK) {
            result->matrix[i][j] = A->matrix[i][j] * number;
          } else {
            res = CALCULATION_ERROR;
          }
        }
      }
    }
  }
  return res;
}