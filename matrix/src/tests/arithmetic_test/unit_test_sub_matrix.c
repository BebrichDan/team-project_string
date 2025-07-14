#include <check.h>

#include "../../s21_matrix.h"

START_TEST(sub_matrix_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  matrix_t control = {0};
  int rows = 2;
  int columns = 2;
  double arrayA[] = {10.0, 20.0, 50.0, 10.0};
  double arrayB[] = {1.0, 2.0, 5.0, 0.0};
  double arrayCtrl[] = {9.0, 18.0, 45.0, 10.0};

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &control);

  s21_filling_in_matrix(&A, arrayA);
  s21_filling_in_matrix(&B, arrayB);
  s21_filling_in_matrix(&control, arrayCtrl);

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);

  for (int i = 0; i < control.rows; i++) {
    for (int j = 0; j < control.columns; j++) {
      ck_assert_double_eq(control.matrix[i][j], result.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&control);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 1);
}
END_TEST

START_TEST(sub_matrix_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  matrix_t control = {0};
  int rows = 2;
  int columns = 2;
  double arrayA[] = {-10.0, -20.0, -50.0, -10.0};
  double arrayB[] = {1.0, 2.0, 5.0, 0.0};
  double arrayCtrl[] = {-11.0, -22.0, -55.0, -10.0};

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &control);

  s21_filling_in_matrix(&A, arrayA);
  s21_filling_in_matrix(&B, arrayB);
  s21_filling_in_matrix(&control, arrayCtrl);

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);

  for (int i = 0; i < control.rows; i++) {
    for (int j = 0; j < control.columns; j++) {
      ck_assert_double_eq(control.matrix[i][j], result.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&control);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 2);
}
END_TEST

START_TEST(sub_matrix_3) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  matrix_t control = {0};
  int rows = 2;
  int columns = 2;
  double arrayA[] = {-10.0, -20.0, -50.0, -10.0};
  double arrayB[] = {-1.0, -2.0, -5.0, 0.0};
  double arrayCtrl[] = {-9.0, -18.0, -45.0, -10.0};

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &control);

  s21_filling_in_matrix(&A, arrayA);
  s21_filling_in_matrix(&B, arrayB);
  s21_filling_in_matrix(&control, arrayCtrl);

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);

  for (int i = 0; i < control.rows; i++) {
    for (int j = 0; j < control.columns; j++) {
      ck_assert_double_eq(control.matrix[i][j], result.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&control);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 3);
}
END_TEST

START_TEST(sub_matrix_4) {
  matrix_t *A = NULL;
  matrix_t B = {0};
  matrix_t result = {0};
  int rows = 2;
  int columns = 2;

  s21_create_matrix(rows, columns, &B);

  ck_assert_int_eq(s21_sub_matrix(A, &B, &result), ERROR);

  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 4);
}
END_TEST

START_TEST(sub_matrix_5) {
  matrix_t A = {0};
  matrix_t *B = NULL;
  matrix_t result = {0};
  int rows = 2;
  int columns = 2;

  s21_create_matrix(rows, columns, &A);

  ck_assert_int_eq(s21_sub_matrix(&A, B, &result), ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 5);
}
END_TEST

START_TEST(sub_matrix_6) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t *result = NULL;
  int rows = 2;
  int columns = 2;

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  ck_assert_int_eq(s21_sub_matrix(&A, &B, result), ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 6);
}
END_TEST

START_TEST(sub_matrix_7) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  int rowsA = 2;
  int columnsA = 3;
  int rowsB = 4;
  int columnsB = 5;

  s21_create_matrix(rowsA, columnsA, &A);
  s21_create_matrix(rowsB, columnsB, &B);

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 7);
}
END_TEST

START_TEST(sub_matrix_8) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  int rows = 2;
  int columns = 2;
  double arrayA[] = {-10.0, -20.0, sqrt(-1), -10.0};
  double arrayB[] = {1.0, 2.0, 5.0, 0.0};

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  s21_filling_in_matrix(&A, arrayA);
  s21_filling_in_matrix(&B, arrayB);

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 8);
}
END_TEST

START_TEST(sub_matrix_9) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result;
  matrix_t control = {0};
  int rows = 2;
  int columns = 2;
  double arrayA[] = {10.0, 20.0, 50.0, 10.0};
  double arrayB[] = {1.0, 2.0, 5.0, 0.0};
  double arrayCtrl[] = {9.0, 18.0, 45.0, 10.0};

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &control);

  s21_filling_in_matrix(&A, arrayA);
  s21_filling_in_matrix(&B, arrayB);
  s21_filling_in_matrix(&control, arrayCtrl);

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);

  for (int i = 0; i < control.rows; i++) {
    for (int j = 0; j < control.columns; j++) {
      ck_assert_double_eq(control.matrix[i][j], result.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&control);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 9);
}
END_TEST

Suite *s21_sub_matrix_suite(void) {
  /*Создаём тестовый набор, в который сложим все тест-кейсы*/
  Suite *test_suite = suite_create("Tmatrix subtraction");

  /*Создаём тест-кейсы, в которые сложим все тестовые случаи по темам и добавим
   * их в тестовый набор*/
  TCase *case_create = tcase_create("Matrix subtraction");
  tcase_add_test(case_create, sub_matrix_1);
  tcase_add_test(case_create, sub_matrix_2);
  tcase_add_test(case_create, sub_matrix_3);
  tcase_add_test(case_create, sub_matrix_4);
  tcase_add_test(case_create, sub_matrix_5);
  tcase_add_test(case_create, sub_matrix_6);
  tcase_add_test(case_create, sub_matrix_7);
  tcase_add_test(case_create, sub_matrix_8);
  tcase_add_test(case_create, sub_matrix_9);
  suite_add_tcase(test_suite, case_create);

  return test_suite;
}