#include <check.h>

#include "../../s21_matrix.h"

START_TEST(calc_complements_matrix_1) {
  matrix_t A = {0};
  matrix_t result = {0};
  matrix_t control = {0};
  int rows = 3;
  int columns = 3;
  double arrayA[] = {1.0, 2.0, 3.0, 0.0, 4.0, 2.0, 5.0, 2.0, 1.0};
  double arrayCtrl[] = {0.0, 10.0, -20.0, 4.0, -14.0, 8.0, -8.0, -2.0, 4.0};

  s21_create_matrix(rows, columns, &A);

  s21_create_matrix(rows, columns, &control);

  s21_filling_in_matrix(&A, arrayA);
  s21_filling_in_matrix(&control, arrayCtrl);

  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);

  for (int i = 0; i < control.rows; i++) {
    for (int j = 0; j < control.columns; j++) {
      ck_assert_double_eq(control.matrix[i][j], result.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&control);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 1);
}
END_TEST

START_TEST(calc_complements_matrix_2) {
  matrix_t A = {0};
  matrix_t result = {0};
  matrix_t control = {0};
  int rows = 2;
  int columns = 2;
  double arrayA[] = {2.0, -180.0, 5.0, -6.0};
  double arrayCtrl[] = {-6.0, -5.0, 180.0, 2.0};

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &control);

  s21_filling_in_matrix(&A, arrayA);
  s21_filling_in_matrix(&control, arrayCtrl);

  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);

  for (int i = 0; i < control.rows; i++) {
    for (int j = 0; j < control.columns; j++) {
      ck_assert_double_eq(control.matrix[i][j], result.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&control);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 2);
}
END_TEST

START_TEST(calc_complements_matrix_3) {
  matrix_t A = {0};
  matrix_t result = {0};
  int rows = 2;
  int columns = 2;
  double arrayA[] = {2.0, sqrt(-1), 5.0, -6.0};

  s21_create_matrix(rows, columns, &A);

  s21_filling_in_matrix(&A, arrayA);

  ck_assert_int_eq(s21_calc_complements(&A, &result), CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 3);
}
END_TEST

START_TEST(calc_complements_matrix_4) {
  matrix_t *A = NULL;
  matrix_t result = {0};

  ck_assert_int_eq(s21_calc_complements(A, &result), ERROR);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 4);
}
END_TEST

START_TEST(calc_complements_matrix_5) {
  matrix_t A = {0};
  matrix_t *result = NULL;

  ck_assert_int_eq(s21_calc_complements(&A, result), ERROR);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 5);
}
END_TEST

START_TEST(calc_complements_matrix_6) {
  matrix_t A = {0};
  matrix_t result = {0};
  int rows = 2;
  int columns = 10;

  s21_create_matrix(rows, columns, &A);

  ck_assert_int_eq(s21_calc_complements(&A, &result), CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 6);
}
END_TEST

START_TEST(calc_complements_matrix_7) {
  matrix_t A = {0};
  matrix_t result = {0};
  int rows = 2;
  int columns = 2;
  double arrayA[] = {2.0, sqrt(-1), 5.0, -6.0};

  s21_create_matrix(rows, columns, &A);

  s21_filling_in_matrix(&A, arrayA);

  ck_assert_int_eq(s21_calc_complements(&A, &result), CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 7);
}
END_TEST

START_TEST(calc_complements_matrix_8) {
  matrix_t A = {0};
  matrix_t *result = NULL;
  int rows = 2;
  int columns = 2;
  double arrayA[] = {2.0, -180.0, 5.0, -6.0};

  s21_create_matrix(rows, columns, &A);

  s21_filling_in_matrix(&A, arrayA);

  ck_assert_int_eq(s21_calc_complements(&A, result), ERROR);

  s21_remove_matrix(&A);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 8);
}
END_TEST

START_TEST(calc_complements_matrix_9) {
  matrix_t A = {0};
  matrix_t result;
  matrix_t control = {0};
  int rows = 3;
  int columns = 3;
  double arrayA[] = {1.0, 2.0, 3.0, 0.0, 4.0, 2.0, 5.0, 2.0, 1.0};
  double arrayCtrl[] = {0.0, 10.0, -20.0, 4.0, -14.0, 8.0, -8.0, -2.0, 4.0};

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &control);

  s21_filling_in_matrix(&A, arrayA);
  s21_filling_in_matrix(&control, arrayCtrl);

  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);

  for (int i = 0; i < control.rows; i++) {
    for (int j = 0; j < control.columns; j++) {
      ck_assert_double_eq(control.matrix[i][j], result.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&control);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 9);
}
END_TEST

// Инициализация и запуск тестов
Suite *s21_calc_complements_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("calc_complements");
  tc_core = tcase_create("calc_complements");

  tcase_add_test(tc_core, calc_complements_matrix_1);
  tcase_add_test(tc_core, calc_complements_matrix_2);
  tcase_add_test(tc_core, calc_complements_matrix_3);
  tcase_add_test(tc_core, calc_complements_matrix_4);
  tcase_add_test(tc_core, calc_complements_matrix_5);
  tcase_add_test(tc_core, calc_complements_matrix_6);
  tcase_add_test(tc_core, calc_complements_matrix_7);
  tcase_add_test(tc_core, calc_complements_matrix_8);
  tcase_add_test(tc_core, calc_complements_matrix_9);
  suite_add_tcase(s, tc_core);

  return s;
}