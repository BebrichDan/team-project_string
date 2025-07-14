#include <check.h>

#include "../../s21_matrix.h"

START_TEST(mult_matrix_number_1) {
  matrix_t A = {0};
  matrix_t result = {0};
  matrix_t control = {0};
  int rows = 2;
  int columns = 3;
  double arrayA[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  double multiplier = 4.0;
  double arrayCtrl[] = {4.0, 8.0, 12.0, 16.0, 20.0, 24.0};

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &control);

  s21_filling_in_matrix(&A, arrayA);
  s21_filling_in_matrix(&control, arrayCtrl);

  ck_assert_int_eq(s21_mult_number(&A, multiplier, &result), OK);

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

START_TEST(mult_matrix_number_2) {
  matrix_t A = {0};
  matrix_t result = {0};
  matrix_t control = {0};
  int rows = 2;
  int columns = 3;
  double arrayA[] = {-1.0, 2.0, -3.0, -4.0, 5.0, -6.0};
  double multiplier = 4.0;
  double arrayCtrl[] = {-4.0, 8.0, -12.0, -16.0, 20.0, -24.0};

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &control);

  s21_filling_in_matrix(&A, arrayA);
  s21_filling_in_matrix(&control, arrayCtrl);

  ck_assert_int_eq(s21_mult_number(&A, multiplier, &result), OK);

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

START_TEST(mult_matrix_number_3) {
  matrix_t A = {0};
  matrix_t result = {0};
  matrix_t control = {0};
  int rows = 2;
  int columns = 3;
  double arrayA[] = {-1.0, 2.0, -3.0, -4.0, 5.0, -6.0};
  double multiplier = 0.0;
  double arrayCtrl[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &control);

  s21_filling_in_matrix(&A, arrayA);
  s21_filling_in_matrix(&control, arrayCtrl);

  ck_assert_int_eq(s21_mult_number(&A, multiplier, &result), OK);

  for (int i = 0; i < control.rows; i++) {
    for (int j = 0; j < control.columns; j++) {
      ck_assert_double_eq(control.matrix[i][j], result.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&control);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 3);
}
END_TEST

START_TEST(mult_matrix_number_4) {
  matrix_t *A = NULL;
  matrix_t result = {0};
  double multiplier = 3.0;

  ck_assert_int_eq(s21_mult_number(A, multiplier, &result), ERROR);

  s21_remove_matrix(&result);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 4);
}
END_TEST

START_TEST(mult_matrix_number_5) {
  matrix_t A = {0};
  matrix_t *result = NULL;
  int rows = 2;
  int columns = 3;
  double arrayA[] = {-1.0, 2.0, -3.0, -4.0, 5.0, -6.0};
  double multiplier = 2.0;

  s21_create_matrix(rows, columns, &A);

  s21_filling_in_matrix(&A, arrayA);

  ck_assert_int_eq(s21_mult_number(&A, multiplier, result), ERROR);

  s21_remove_matrix(&A);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 5);
}
END_TEST

START_TEST(mult_matrix_number_6) {
  matrix_t A = {0};
  matrix_t result = {0};
  int rows = 2;
  int columns = 3;
  double arrayA[] = {-1.0, 2.0, -3.0, -4.0, 5.0, -6.0};
  double multiplier = sqrt(-1.0);

  s21_create_matrix(rows, columns, &A);

  s21_filling_in_matrix(&A, arrayA);

  ck_assert_int_eq(s21_mult_number(&A, multiplier, &result), CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 6);
}
END_TEST

START_TEST(mult_matrix_number_7) {
  matrix_t A = {0};
  matrix_t result = {0};
  int rows = 2;
  int columns = 3;
  double arrayA[] = {-1.0, sqrt(-1.0), -3.0, -4.0, 5.0, -6.0};
  double multiplier = 2.0;

  s21_create_matrix(rows, columns, &A);

  s21_filling_in_matrix(&A, arrayA);

  ck_assert_int_eq(s21_mult_number(&A, multiplier, &result), CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 7);
}
END_TEST

START_TEST(mult_matrix_number_8) {
  matrix_t A = {0};
  matrix_t result;
  matrix_t control = {0};
  int rows = 2;
  int columns = 3;
  double arrayA[] = {-1.0, 2.0, -3.0, -4.0, 5.0, -6.0};
  double multiplier = 0.0;
  double arrayCtrl[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &control);

  s21_filling_in_matrix(&A, arrayA);
  s21_filling_in_matrix(&control, arrayCtrl);

  ck_assert_int_eq(s21_mult_number(&A, multiplier, &result), OK);

  for (int i = 0; i < control.rows; i++) {
    for (int j = 0; j < control.columns; j++) {
      ck_assert_double_eq(control.matrix[i][j], result.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&control);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 8);
}
END_TEST

Suite *s21_mult_matrix_number_suite(void) {
  /*Создаём тестовый набор, в который сложим все тест-кейсы*/
  Suite *test_suite = suite_create("matrix multiplication number");

  /*Создаём тест-кейсы, в которые сложим все тестовые случаи по темам и добавим
   * их в тестовый набор*/
  TCase *case_create = tcase_create("Matrix multiplication number");

  tcase_add_test(case_create, mult_matrix_number_1);
  tcase_add_test(case_create, mult_matrix_number_2);
  tcase_add_test(case_create, mult_matrix_number_3);
  tcase_add_test(case_create, mult_matrix_number_4);
  tcase_add_test(case_create, mult_matrix_number_5);
  tcase_add_test(case_create, mult_matrix_number_6);
  tcase_add_test(case_create, mult_matrix_number_7);
  tcase_add_test(case_create, mult_matrix_number_8);
  suite_add_tcase(test_suite, case_create);

  return test_suite;
}