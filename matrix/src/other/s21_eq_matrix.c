#include "../arithmetic/s21_arithmetic.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = SUCCESS;

  if (A == NULL || B == NULL) {
    res = FAILURE;
  }
  // Проверка на валидность матриц
  else if (A->matrix == NULL || B->matrix == NULL || A->rows <= 0 ||
           A->columns <= 0 || B->rows <= 0 || B->columns <= 0) {
    res = FAILURE;
  } else if (A->rows != B->rows ||
             A->columns != B->columns) {  // Проверка размеров матриц
    res = FAILURE;
  } else {
    double res_eq = 0.0;
    for (int i = 0; i < A->rows && res == SUCCESS; i++) {
      for (int j = 0; j < A->columns && res == SUCCESS; j++) {
        res_eq = A->matrix[i][j] - B->matrix[i][j];
        if (fabs(res_eq) >= ACCURACY) {
          res = FAILURE;
        }

        if (s21_infinity_number(res_eq) == CALCULATION_ERROR) {
          res = FAILURE;
        }
      }
    }
  }

  return res;
}
