#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (A == NULL || result == NULL) return ERROR;
  if (A->rows != A->columns)
    return CALCULATION_ERROR;  // обратная матрица существует только у
                               // квадратной матрицы

  // Вычисляем определитель
  double determinant = 0.0;
  if (s21_determinant(A, &determinant) != OK) return CALCULATION_ERROR;

  if (fabs(determinant) < ACCURACY)
    return CALCULATION_ERROR;  // обратная матрица существует, если
                               // определитель не 0

  // Создаем матрицу алгебраических дополнений
  matrix_t complements;
  if (s21_calc_complements(A, &complements) != OK) return CALCULATION_ERROR;

  // Создаем транспонированную матрицу алгебраических дополнений
  matrix_t transposed;
  if (s21_transpose(&complements, &transposed) != OK) {
    s21_remove_matrix(&complements);
    return CALCULATION_ERROR;
  }

  int res = ERROR;
  if (s21_create_matrix(A->rows, A->columns, result) == SUCCESS) res = OK;

  if (res == OK) {
    // Делим каждый элемент транспонированной матрицы алгебраических
    // дополнений на определитель
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = transposed.matrix[i][j] / determinant;
      }
    }
  }
  s21_remove_matrix(&complements);
  s21_remove_matrix(&transposed);

  return res;
}
