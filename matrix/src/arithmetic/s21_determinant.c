#include "s21_arithmetic.h"

int s21_determinant(matrix_t *A, double *result) {
  int res = OK;

  if (A == NULL || result == NULL) {
    res = ERROR;
  } else if (A->rows != A->columns) {  // Определитель определен только для
                                       // квадратной матрицы
    res = CALCULATION_ERROR;
  } else {
    if (s21_infinity_matrix(A) == 0) {
      *result = s21_calculate_determinant(A);
    } else {
      res = CALCULATION_ERROR;
    }
  }

  return res;
}
