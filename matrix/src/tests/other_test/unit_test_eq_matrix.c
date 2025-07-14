#include <check.h>

#include "../../s21_matrix.h"

START_TEST(eq_matrix_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  double arrayA[] = {1.0, 2.0, 5.0, 0.0, 2.0, 15.0};
  double arrayB[] = {1.0, 2.0, 5.0, 0.0, 2.0, 15.0};

  s21_create_matrix(2, 3, &A);
  s21_filling_in_matrix(&A, arrayA);
  s21_create_matrix(2, 3, &B);
  s21_filling_in_matrix(&B, arrayB);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 1);
}
END_TEST

START_TEST(eq_matrix_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  double arrayA[] = {10.0, 20.0, 50.0, 10.0, 20.0, 150.0};
  double arrayB[] = {1.0, 2.0, 5.0, 0.0, 2.0, 15.0};

  s21_create_matrix(2, 3, &A);
  s21_filling_in_matrix(&A, arrayA);
  s21_create_matrix(2, 3, &B);
  s21_filling_in_matrix(&B, arrayB);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 2);
}
END_TEST

START_TEST(eq_matrix_3) {
  matrix_t A = {0};
  matrix_t B = {0};
  double arrayA[] = {1.0, 2.0, 5.0, 0.0, 2.0, 15.0};
  double arrayB[] = {10.0, 20.0, 50.0, 10.0, 20.0, 150.0};

  s21_create_matrix(2, 3, &A);
  s21_filling_in_matrix(&A, arrayA);
  s21_create_matrix(2, 3, &B);
  s21_filling_in_matrix(&B, arrayB);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 3);
}
END_TEST

START_TEST(eq_matrix_4) {
  matrix_t A = {0};
  matrix_t B = {0};
  double arrayA[] = {0.0000005, 0.0000233, 0.0000045, -0.0000044};
  double arrayB[] = {0.0000005, 0.0000233, 0.0000045, -0.0000044};

  s21_create_matrix(2, 2, &A);
  s21_filling_in_matrix(&A, arrayA);
  s21_create_matrix(2, 2, &B);
  s21_filling_in_matrix(&B, arrayB);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 4);
}
END_TEST

START_TEST(eq_matrix_5) {
  matrix_t A = {0};
  matrix_t B = {0};
  double arrayA[] = {0.0000000000001, 0.0000000000002, 0.000000000004,
                     -0.000000000006};
  double arrayB[] = {0.0000000000004, 0.0000000000003, 0.000000000004,
                     -0.000000000005};

  s21_create_matrix(2, 2, &A);
  s21_filling_in_matrix(&A, arrayA);
  s21_create_matrix(2, 2, &B);
  s21_filling_in_matrix(&B, arrayB);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 5);
}
END_TEST

START_TEST(eq_matrix_6) {
  matrix_t A = {0};
  matrix_t B = {0};
  double arrayA[] = {0.0000001, 0.0000003, 0.0000001, -0.0000002};
  double arrayB[] = {0.0000002, 0.0000001, 0.0000001, -0.0000001};

  s21_create_matrix(2, 2, &A);
  s21_filling_in_matrix(&A, arrayA);
  s21_create_matrix(2, 2, &B);
  s21_filling_in_matrix(&B, arrayB);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 6);
}
END_TEST

START_TEST(eq_matrix_7) {
  matrix_t A = {0};
  matrix_t B = {0};
  double arrayA[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  double arrayB[] = {0.0, 0.0, 0.0, 0.0};

  s21_create_matrix(2, 3, &A);
  s21_filling_in_matrix(&A, arrayA);
  s21_create_matrix(2, 2, &B);
  s21_filling_in_matrix(&B, arrayB);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 7);
}
END_TEST

START_TEST(eq_matrix_8) {
  matrix_t A = {0};
  matrix_t B = {0};
  double arrayA[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  double arrayB[] = {0.0, 0.0, 0.0, 0.0};

  s21_create_matrix(6, 1, &A);
  s21_filling_in_matrix(&A, arrayA);
  s21_create_matrix(4, 1, &B);
  s21_filling_in_matrix(&B, arrayB);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 8);
}
END_TEST

START_TEST(eq_matrix_9) {
  matrix_t A = {0};
  matrix_t B = {0};
  double arrayA[] = {0.0, sqrt(-1.0), 0.0, 0.0, 0.0, 0.0};
  double arrayB[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

  s21_create_matrix(3, 2, &A);
  s21_filling_in_matrix(&A, arrayA);
  s21_create_matrix(3, 2, &B);
  s21_filling_in_matrix(&B, arrayB);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 9);
}
END_TEST

START_TEST(eq_matrix_10) {
  matrix_t A = {0};
  matrix_t *B = NULL;
  double arrayA[] = {10.1, 5.2, 5.0, 5.0, 0.0, 0.0};

  s21_create_matrix(3, 2, &A);
  s21_filling_in_matrix(&A, arrayA);

  ck_assert_int_eq(s21_eq_matrix(&A, B), FAILURE);

  s21_remove_matrix(&A);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 10);
}
END_TEST

START_TEST(eq_matrix_11) {
  matrix_t *A = NULL;
  matrix_t B = {0};
  double arrayB[] = {10.1, 5.2, 5.0, 5.0, 0.0, 0.0};

  s21_create_matrix(3, 2, &B);
  s21_filling_in_matrix(&B, arrayB);

  ck_assert_int_eq(s21_eq_matrix(A, &B), FAILURE);

  s21_remove_matrix(&B);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 11);
}
END_TEST

Suite *s21_eq_matrix_suite(void) {
  /*Создаём тестовый набор, в который сложим все тест-кейсы*/
  Suite *test_suite = suite_create("matrix comparison");

  /*Создаём тест-кейсы, в которые сложим все тестовые случаи по темам и добавим
   * их в тестовый набор*/
  TCase *case_create = tcase_create("Matrix comparison");
  tcase_add_test(case_create, eq_matrix_1);
  tcase_add_test(case_create, eq_matrix_2);
  tcase_add_test(case_create, eq_matrix_3);
  tcase_add_test(case_create, eq_matrix_4);
  tcase_add_test(case_create, eq_matrix_5);
  tcase_add_test(case_create, eq_matrix_6);
  tcase_add_test(case_create, eq_matrix_7);
  tcase_add_test(case_create, eq_matrix_8);
  tcase_add_test(case_create, eq_matrix_9);
  tcase_add_test(case_create, eq_matrix_10);
  tcase_add_test(case_create, eq_matrix_11);
  suite_add_tcase(test_suite, case_create);

  return test_suite;
}