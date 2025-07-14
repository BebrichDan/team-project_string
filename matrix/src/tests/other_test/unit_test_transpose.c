#include <check.h>

#include "../../s21_matrix.h"

START_TEST(transpose_matrix_1) {
  matrix_t A = {0};
  matrix_t result = {0};
  matrix_t control = {0};
  int rows = 2;
  int columns = 2;
  double arrayA[] = {1.0, 2.0, 3.0, 4.0};
  double arrayCtrl[] = {1.0, 3.0, 2.0, 4.0};

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(columns, rows, &control);

  s21_filling_in_matrix(&A, arrayA);
  s21_filling_in_matrix(&control, arrayCtrl);

  ck_assert_int_eq(s21_transpose(&A, &result), OK);

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

START_TEST(transpose_matrix_2) {
  matrix_t A = {0};
  matrix_t result = {0};
  matrix_t control = {0};
  int rows = 3;
  int columns = 5;
  double arrayA[] = {1.0, 2.0,  3.0,  4.0,  5.0,  6.0,  7.0, 8.0,
                     9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0};
  double arrayCtrl[] = {1.0,  6.0, 11.0, 2.0,  7.0, 12.0, 3.0, 8.0,
                        13.0, 4.0, 9.0,  14.0, 5.0, 10.0, 15.0};

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(columns, rows, &control);

  s21_filling_in_matrix(&A, arrayA);
  s21_filling_in_matrix(&control, arrayCtrl);

  ck_assert_int_eq(s21_transpose(&A, &result), OK);

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

START_TEST(transpose_matrix_3) {
  matrix_t A = {0};
  matrix_t result = {0};
  matrix_t control = {0};
  int rows = 2;
  int columns = 2;
  double arrayA[] = {1.0, sqrt(-1), 3.0, 4.0};
  double arrayCtl[] = {1.0, 3.0, sqrt(-1), 4.0};

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &control);

  s21_filling_in_matrix(&A, arrayA);
  s21_filling_in_matrix(&control, arrayCtl);

  ck_assert_int_eq(s21_transpose(&A, &result), OK);

  for (int i = 0; i < control.rows; i++) {
    for (int j = 0; j < control.columns; j++) {
      if (i == 1 && j == 0) {
        continue;
      }
      ck_assert_double_eq(control.matrix[i][j], result.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&control);
  s21_remove_matrix(&result);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 3);
}
END_TEST

START_TEST(transpose_matrix_4) {
  matrix_t *A = NULL;
  matrix_t result = {0};

  ck_assert_int_eq(s21_transpose(A, &result), ERROR);
}
END_TEST

START_TEST(transpose_matrix_5) {
  matrix_t A = {0};
  matrix_t *result = NULL;

  ck_assert_int_eq(s21_transpose(&A, result), ERROR);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 4);
}
END_TEST

START_TEST(transpose_matrix_6) {
  matrix_t A = {0};
  matrix_t result = {0};
  matrix_t control = {0};
  int rows = 5;
  int columns = 3;
  double arrayA[] = {1.0,  6.0, 11.0, 2.0,  7.0, 12.0, 3.0, 8.0,
                     13.0, 4.0, 9.0,  14.0, 5.0, 10.0, 15.0};
  double arrayCtrl[] = {1.0, 2.0,  3.0,  4.0,  5.0,  6.0,  7.0, 8.0,
                        9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0};

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(columns, rows, &control);

  s21_filling_in_matrix(&A, arrayA);
  s21_filling_in_matrix(&control, arrayCtrl);

  ck_assert_int_eq(s21_transpose(&A, &result), OK);

  for (int i = 0; i < control.rows; i++) {
    for (int j = 0; j < control.columns; j++) {
      ck_assert_double_eq(control.matrix[i][j], result.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&control);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 5);
}
END_TEST

START_TEST(transpose_matrix_7) {
  matrix_t A = {0};
  matrix_t *result = NULL;
  int rows = 5;
  int columns = 3;
  double arrayA[] = {1.0,  6.0, 11.0, 2.0,  7.0, 12.0, 3.0, 8.0,
                     13.0, 4.0, 9.0,  14.0, 5.0, 10.0, 15.0};

  s21_create_matrix(rows, columns, &A);

  s21_filling_in_matrix(&A, arrayA);

  ck_assert_int_eq(s21_transpose(&A, result), ERROR);

  s21_remove_matrix(&A);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 6);
}
END_TEST

START_TEST(transpose_matrix_8) {
  matrix_t A = {0};
  matrix_t result;
  matrix_t control = {0};
  int rows = 2;
  int columns = 2;
  double arrayA[] = {1.0, 2.0, 3.0, 4.0};
  double arrayCtrl[] = {1.0, 3.0, 2.0, 4.0};

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(columns, rows, &control);

  s21_filling_in_matrix(&A, arrayA);
  s21_filling_in_matrix(&control, arrayCtrl);

  ck_assert_int_eq(s21_transpose(&A, &result), OK);

  for (int i = 0; i < control.rows; i++) {
    for (int j = 0; j < control.columns; j++) {
      ck_assert_double_eq(control.matrix[i][j], result.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&control);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 7);
}
END_TEST

Suite *s21_transpose_matrix_suite(void) {
  /*Создаём тестовый набор, в который сложим все тест-кейсы*/
  Suite *test_suite = suite_create("matrix transpose");

  /*Создаём тест-кейсы, в которые сложим все тестовые случаи по темам и добавим
   * их в тестовый набор*/
  TCase *case_create = tcase_create("Matrix transpose");
  tcase_add_test(case_create, transpose_matrix_1);
  tcase_add_test(case_create, transpose_matrix_2);
  tcase_add_test(case_create, transpose_matrix_3);
  tcase_add_test(case_create, transpose_matrix_4);
  tcase_add_test(case_create, transpose_matrix_5);
  tcase_add_test(case_create, transpose_matrix_6);
  tcase_add_test(case_create, transpose_matrix_7);
  tcase_add_test(case_create, transpose_matrix_8);
  suite_add_tcase(test_suite, case_create);

  return test_suite;
}