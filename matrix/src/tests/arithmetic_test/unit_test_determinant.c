#include <check.h>

#include "../../s21_matrix.h"

START_TEST(determinant_matrix_1) {
  matrix_t A = {0};
  double result = 0.0;
  int rows = 1;
  int columns = 1;
  double arrayA[] = {4.0};

  s21_create_matrix(rows, columns, &A);

  s21_filling_in_matrix(&A, arrayA);

  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(result, 4.0, ACCURACY);

  s21_remove_matrix(&A);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 1);
}
END_TEST

START_TEST(determinant_matrix_2) {
  matrix_t A = {0};
  double result = 0.0;
  int rows = 2;
  int columns = 2;
  double arrayA[] = {1.0, 2.0, 3.0, 4.0};

  s21_create_matrix(rows, columns, &A);

  s21_filling_in_matrix(&A, arrayA);

  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(result, -2.0, ACCURACY);

  s21_remove_matrix(&A);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 2);
}
END_TEST

START_TEST(determinant_matrix_3) {
  matrix_t A = {0};
  double result = 0.0;
  int rows = 3;
  int columns = 3;
  double arrayA[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};

  s21_create_matrix(rows, columns, &A);

  s21_filling_in_matrix(&A, arrayA);

  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(result, 0.0, ACCURACY);

  s21_remove_matrix(&A);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 3);
}
END_TEST

START_TEST(determinant_matrix_4) {
  matrix_t *A = NULL;
  double result = 0.0;

  ck_assert_int_eq(s21_determinant(A, &result), ERROR);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 4);
}
END_TEST

START_TEST(determinant_matrix_5) {
  matrix_t A = {0};
  double result = 0.0;
  int rows = 10;
  int columns = 16;

  s21_create_matrix(rows, columns, &A);

  ck_assert_int_eq(s21_determinant(&A, &result), CALCULATION_ERROR);

  s21_remove_matrix(&A);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 5);
}
END_TEST

START_TEST(determinant_matrix_6) {
  matrix_t A = {0};
  double result = 0.0;
  int rows = 3;
  int columns = 3;
  double arrayA[] = {1.0, 2.0, 3.0, 4.0, sqrt(-1), 6.0, 7.0, 8.0, 9.0};

  s21_create_matrix(rows, columns, &A);

  s21_filling_in_matrix(&A, arrayA);

  ck_assert_int_eq(s21_determinant(&A, &result), CALCULATION_ERROR);

  s21_remove_matrix(&A);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 6);
}
END_TEST

START_TEST(determinant_matrix_7) {
  matrix_t A = {0};
  double *result = NULL;
  int rows = 3;
  int columns = 3;

  s21_create_matrix(rows, columns, &A);

  ck_assert_int_eq(s21_determinant(&A, result), ERROR);

  s21_remove_matrix(&A);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 7);
}
END_TEST

START_TEST(determinant_matrix_8) {
  matrix_t A = {0};
  double result;
  int rows = 3;
  int columns = 3;
  double arrayA[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};

  s21_create_matrix(rows, columns, &A);
  s21_filling_in_matrix(&A, arrayA);

  ck_assert_int_eq(s21_determinant(&A, &result), OK);

  s21_remove_matrix(&A);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 8);
}
END_TEST

START_TEST(determinant_matrix_9) {
  matrix_t A = {0};
  double result;
  int rows = 2;
  int columns = 2;
  double arrayA[] = {1.0, 2.0, 3.0, 4.0};

  s21_create_matrix(rows, columns, &A);

  s21_filling_in_matrix(&A, arrayA);

  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(result, -2.0, ACCURACY);

  s21_remove_matrix(&A);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 9);
}
END_TEST

Suite *s21_determinant_matrix_suite(void) {
  /*Создаём тестовый набор, в который сложим все тест-кейсы*/
  Suite *test_suite = suite_create("determinant matrix");

  /*Создаём тест-кейсы, в которые сложим все тестовые случаи по темам и добавим
   * их в тестовый набор*/
  TCase *case_create = tcase_create("Determinant matrix");
  tcase_add_test(case_create, determinant_matrix_1);
  tcase_add_test(case_create, determinant_matrix_2);
  tcase_add_test(case_create, determinant_matrix_3);
  tcase_add_test(case_create, determinant_matrix_4);
  tcase_add_test(case_create, determinant_matrix_5);
  tcase_add_test(case_create, determinant_matrix_6);
  tcase_add_test(case_create, determinant_matrix_7);
  tcase_add_test(case_create, determinant_matrix_8);
  tcase_add_test(case_create, determinant_matrix_9);
  suite_add_tcase(test_suite, case_create);

  return test_suite;
}