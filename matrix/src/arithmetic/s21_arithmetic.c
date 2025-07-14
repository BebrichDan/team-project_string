#include "s21_arithmetic.h"

void s21_create_minor_matrix(matrix_t *A, int row, int col, matrix_t *minor) {
  int minor_row = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i == row) continue;
    int minor_col = 0;
    for (int j = 0; j < A->columns; j++) {
      if (j == col) continue;
      minor->matrix[minor_row][minor_col] = A->matrix[i][j];
      minor_col++;
    }

    minor_row++;
  }
}

double s21_calculate_determinant(matrix_t *A) {
  if (A->rows == 1) {
    return A->matrix[0][0];
  }
  if (A->rows == 2) {
    return A->matrix[0][0] * A->matrix[1][1] -
           A->matrix[0][1] * A->matrix[1][0];
  }

  double det = 0;
  matrix_t minor;
  minor.rows = A->rows - 1;
  minor.columns = A->columns - 1;

  minor.matrix = (double **)malloc(minor.rows * sizeof(double *));
  for (int i = 0; i < minor.rows; i++) {
    minor.matrix[i] = (double *)malloc(minor.columns * sizeof(double));
  }

  // Разложение по первой строке
  for (int j = 0; j < A->columns; j++) {
    s21_create_minor_matrix(A, 0, j, &minor);
    det += pow(-1, j) * A->matrix[0][j] * s21_calculate_determinant(&minor);
  }

  for (int i = 0; i < minor.rows; i++) {
    free(minor.matrix[i]);
  }
  free(minor.matrix);

  return det;
}

void s21_filling_in_matrix(matrix_t *A, double *array) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      A->matrix[i][j] = *array++;
    }
  }
}

int s21_infinity_matrix(matrix_t *A) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (isnan(A->matrix[i][j])) {
        return CALCULATION_ERROR;
      }
    }
  }
  return OK;
}

int s21_infinity_number(double number) {
  if (isnan(number)) {
    return CALCULATION_ERROR;
  }
  return OK;
}