#include "s21_arithmetic.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res;
  if (A == NULL || result == NULL) {
    res = ERROR;
  } else if (A->rows != A->columns) {
    // Матрица алгебраических дополнений определена только для квадратной
    // матрицы
    res = CALCULATION_ERROR;
  } else {
    if (s21_create_matrix(A->rows, A->columns, result) == SUCCESS) {
      res = OK;
    }
    // Если память успешно выделена, вычисляем алгебраические дополнения
    if (res == OK) {
      if (A->rows == 1) {
        // Особый случай для матрицы 1x1
        result->matrix[0][0] = 1;
      } else {
        matrix_t minor;
        minor.rows = A->rows - 1;
        minor.columns = A->columns - 1;

        // Выделение памяти для минорной матрицы
        minor.matrix = (double **)malloc(minor.rows * sizeof(double *));
        for (int i = 0; i < minor.rows; i++) {
          minor.matrix[i] = (double *)malloc(minor.columns * sizeof(double));
        }

        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            if (s21_infinity_number(A->matrix[i][j]) != 0) {
              res = CALCULATION_ERROR;
            }
            s21_create_minor_matrix(A, i, j, &minor);
            double det = s21_calculate_determinant(&minor);
            result->matrix[i][j] = pow(-1, i + j) * det;
          }
        }

        for (int i = 0; i < minor.rows; i++) {
          free(minor.matrix[i]);
        }
        free(minor.matrix);
      }
    }
  }
  return res;
}