#ifndef S21_MATRIX
#define S21_MATRIX

#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

#define OK 0
#define ERROR 1              // некорректная матрица
#define CALCULATION_ERROR 2  // матрица, для которой нельзя провести вычисления

#define ACCURACY 0.0000001

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

// создание матрицы
int s21_create_matrix(int rows, int columns, matrix_t *result);

// удаление матрицы
void s21_remove_matrix(matrix_t *A);

// спавнение матриц
int s21_eq_matrix(matrix_t *A, matrix_t *B);

// сложение матриц
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// вычитание матриц
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// умножение матрицы на число
int s21_mult_number(matrix_t *A, double number, matrix_t *result);

// умножение двух матриц
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// транспонирование матрицы
int s21_transpose(matrix_t *A, matrix_t *result);

// минор матрицы и матрица алгебраических дополнений
int s21_calc_complements(matrix_t *A, matrix_t *result);

// определитель матрицы
int s21_determinant(matrix_t *A, double *result);

// обратная матрица
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// зпролнение матрицы из массива
void s21_filling_in_matrix(matrix_t *A, double *array);

#endif