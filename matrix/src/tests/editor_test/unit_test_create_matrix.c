#include <check.h>

#include "../../s21_matrix.h"

START_TEST(create_matrix_valid) {
  matrix_t mat;
  int result = s21_create_matrix(3, 3, &mat);
  ck_assert_int_eq(result, SUCCESS);
  ck_assert_int_eq(mat.rows, 3);
  ck_assert_int_eq(mat.columns, 3);
  // Проверка, что элементы матрицы инициализированы нулями
  for (int i = 0; i < mat.rows; i++) {
    for (int j = 0; j < mat.columns; j++) {
      ck_assert_double_eq(mat.matrix[i][j], 0.0);
    }
  }
  s21_remove_matrix(&mat);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 1);
}
END_TEST

START_TEST(create_matrix_zero_rows) {
  matrix_t mat;
  int result = s21_create_matrix(0, 3, &mat);
  ck_assert_int_eq(result, FAILURE);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 2);
}
END_TEST

START_TEST(create_matrix_zero_columns) {
  matrix_t mat;
  int result = s21_create_matrix(3, 0, &mat);
  ck_assert_int_eq(result, FAILURE);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 3);
}
END_TEST

START_TEST(create_matrix_null_result) {
  int result = s21_create_matrix(3, 3, NULL);
  ck_assert_int_eq(result, FAILURE);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 4);
}
END_TEST

START_TEST(create_matrix_negative_rows) {
  matrix_t mat;
  int result = s21_create_matrix(-1, 3, &mat);
  ck_assert_int_eq(result, FAILURE);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 5);
}
END_TEST

START_TEST(create_matrix_negative_columns) {
  matrix_t mat;
  int result = s21_create_matrix(3, -2, &mat);
  ck_assert_int_eq(result, FAILURE);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 6);
}
END_TEST
START_TEST(create_matrix_10x10) {
  matrix_t mat;
  int result = s21_create_matrix(10, 10, &mat);
  ck_assert_int_eq(result, SUCCESS);
  ck_assert_int_eq(mat.rows, 10);
  ck_assert_int_eq(mat.columns, 10);
  for (int i = 0; i < mat.rows; i++) {
    for (int j = 0; j < mat.columns; j++) {
      ck_assert_double_eq(mat.matrix[i][j], 0.0);
    }
  }
  s21_remove_matrix(&mat);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 7);
}
END_TEST

START_TEST(create_matrix_4x4) {
  matrix_t mat;
  int result = s21_create_matrix(4, 4, &mat);
  ck_assert_int_eq(result, SUCCESS);
  ck_assert_int_eq(mat.rows, 4);
  ck_assert_int_eq(mat.columns, 4);
  for (int i = 0; i < mat.rows; i++) {
    for (int j = 0; j < mat.columns; j++) {
      ck_assert_double_eq(mat.matrix[i][j], 0.0);
    }
  }
  s21_remove_matrix(&mat);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 8);
}
END_TEST

START_TEST(create_matrix_12x5) {
  matrix_t mat;
  int result = s21_create_matrix(12, 5, &mat);
  ck_assert_int_eq(result, SUCCESS);
  ck_assert_int_eq(mat.rows, 12);
  ck_assert_int_eq(mat.columns, 5);
  for (int i = 0; i < mat.rows; i++) {
    for (int j = 0; j < mat.columns; j++) {
      ck_assert_double_eq(mat.matrix[i][j], 0.0);
    }
  }
  s21_remove_matrix(&mat);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 9);
}
END_TEST

/*Проверяем заполнение матрицы со значенями*/
START_TEST(create_matrix_10) {
  matrix_t matrix = {0};
  int row = 5, col = 8;
  ck_assert_int_eq(s21_create_matrix(row, col, &matrix), SUCCESS);
  matrix.matrix[1][1] = 5.0;
  ck_assert_int_eq(matrix.matrix[1][1], 5);
  ck_assert(matrix.rows == row && matrix.columns == col);
  s21_remove_matrix(&matrix);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 10);
}
END_TEST

START_TEST(create_matrix_11) {
  matrix_t matrix = {0};
  int row = 5, col = 8;
  ck_assert_int_eq(s21_create_matrix(row, col, &matrix), SUCCESS);
  matrix.matrix[0][0] = 5.0;
  ck_assert_int_eq(matrix.matrix[0][0], 5);
  ck_assert(matrix.rows == row && matrix.columns == col);
  s21_remove_matrix(&matrix);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 11);
}
END_TEST

START_TEST(create_matrix_12) {
  matrix_t matrix = {0};
  int row = 5, col = 5;
  ck_assert_int_eq(s21_create_matrix(row, col, &matrix), SUCCESS);
  matrix.matrix[3][2] = -15.0;
  ck_assert_int_eq(matrix.matrix[3][2], -15);
  ck_assert(matrix.rows == row && matrix.columns == col);
  s21_remove_matrix(&matrix);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 12);
}
END_TEST

Suite *s21_create_matrix_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_create_matrix");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, create_matrix_valid);
  tcase_add_test(tc_core, create_matrix_zero_rows);
  tcase_add_test(tc_core, create_matrix_zero_columns);
  tcase_add_test(tc_core, create_matrix_null_result);
  tcase_add_test(tc_core, create_matrix_negative_rows);
  tcase_add_test(tc_core, create_matrix_negative_columns);
  tcase_add_test(tc_core, create_matrix_10x10);
  tcase_add_test(tc_core, create_matrix_4x4);
  tcase_add_test(tc_core, create_matrix_12x5);
  tcase_add_test(tc_core, create_matrix_10);
  tcase_add_test(tc_core, create_matrix_11);
  tcase_add_test(tc_core, create_matrix_12);

  suite_add_tcase(s, tc_core);

  return s;
}