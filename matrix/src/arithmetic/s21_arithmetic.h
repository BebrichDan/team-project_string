#ifndef S21_ARITHMETIC
#define S21_ARITHMETIC

#include "../s21_matrix.h"

// вспомагательная функция для создания минормной матрицы
void s21_create_minor_matrix(matrix_t *A, int row, int columns,
                             matrix_t *minor);

// вспомогательная функция для вычисления определителя матрицы
double s21_calculate_determinant(matrix_t *A);

// запись массива array в массив А
void s21_filling_in_matrix(matrix_t *A, double *array);

// проверка значений элементов матрицы на невозможные значения
int s21_infinity_number(double number);
int s21_infinity_matrix(matrix_t *A);

#endif