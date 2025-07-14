#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_matrix.h"

extern Suite *s21_create_matrix_suite(void);
extern Suite *s21_remove_matrix_suite(void);
extern Suite *s21_calc_complements_suite(void);
extern Suite *s21_inverse_matrix_suite(void);
extern Suite *s21_determinant_matrix_suite(void);

extern Suite *s21_mult_matrix_suite(void);
extern Suite *s21_mult_matrix_number_suite(void);
extern Suite *s21_sub_matrix_suite(void);
extern Suite *s21_sum_matrix_suite(void);
extern Suite *s21_eq_matrix_suite(void);
extern Suite *s21_transpose_matrix_suite(void);

int run_tests(Suite *(*suite_func)(void)) {
  Suite *s;
  SRunner *sr;
  int number_failed;

  s = suite_func();        // Получаем набор тестов
  sr = srunner_create(s);  // Создаем прогонщик тестов

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return number_failed;
}

int main(void) {
  int total_failed = 0;

  total_failed += run_tests(s21_create_matrix_suite);
  total_failed += run_tests(s21_remove_matrix_suite);
  total_failed += run_tests(s21_calc_complements_suite);
  total_failed += run_tests(s21_inverse_matrix_suite);
  total_failed += run_tests(s21_determinant_matrix_suite);
  total_failed += run_tests(s21_mult_matrix_suite);
  total_failed += run_tests(s21_mult_matrix_number_suite);
  total_failed += run_tests(s21_sub_matrix_suite);
  total_failed += run_tests(s21_sum_matrix_suite);
  total_failed += run_tests(s21_eq_matrix_suite);
  total_failed += run_tests(s21_transpose_matrix_suite);

  printf("error all: %d\n", total_failed);

  return (total_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}