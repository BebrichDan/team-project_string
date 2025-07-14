#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows <= 0 || columns <= 0 || result == NULL) return FAILURE;

  // память для массива указателей на строки
  result->matrix = (double **)malloc(rows * sizeof(double *));

  if (result->matrix == NULL) return FAILURE;

  result->rows = rows;
  result->columns = columns;

  // память для каждой строки
  for (int i = 0; i < rows; i++) {
    result->matrix[i] = (double *)malloc(columns * sizeof(double));
    if (result->matrix[i] == NULL) {
      s21_remove_matrix(result);
      return FAILURE;
    }
    for (int j = 0; j < columns; j++) {
      result->matrix[i][j] = 0.0;
    }
  }

  return SUCCESS;
}