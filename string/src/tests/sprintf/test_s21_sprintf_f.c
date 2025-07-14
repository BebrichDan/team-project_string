#include <assert.h>
#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../s21_string.h"

// Тест 1
START_TEST(test_s21_sprintf_f_plus_double) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = 42.32;

  sprintf(buffer_standard, "Double: %+f ", expected);
  s21_sprintf(buffer_custom, "Double: %+f ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 2: Правый сдвиг с фиксированной шириной
START_TEST(test_s21_sprintf_f_right_shift_fixed_width) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = 42.3;

  sprintf(buffer_standard, "Double: %10f ", expected);
  s21_sprintf(buffer_custom, "Double: %10f ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 3: Левый сдвиг с фиксированной шириной
START_TEST(test_s21_sprintf_f_left_shift_fixed_width) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = 42.3;

  sprintf(buffer_standard, "Double: %-10f ", expected);
  s21_sprintf(buffer_custom, "Double: %-10f ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 4: Фиксированная точность
START_TEST(test_s21_sprintf_f_fixed_precision) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = 42.3456789;

  sprintf(buffer_standard, "Double: %.2f ", expected);
  s21_sprintf(buffer_custom, "Double: %.2f ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 5: Специальное значение NaN
START_TEST(test_s21_sprintf_f_nan) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = NAN;

  sprintf(buffer_standard, "Double: % 5f ", expected);
  s21_sprintf(buffer_custom, "Double: % 5f ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 6: Специальное значение INF
START_TEST(test_s21_sprintf_f_inf) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = INFINITY;

  sprintf(buffer_standard, "Double: %f ", expected);
  s21_sprintf(buffer_custom, "Double: %f ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 7: Отрицательное число
START_TEST(test_s21_sprintf_f_negative_number) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = -42.3;

  sprintf(buffer_standard, "Double: %f ", expected);
  s21_sprintf(buffer_custom, "Double: %f ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 8: Комбинации флагов и размеров
START_TEST(test_s21_sprintf_f_combinations) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = 42.3456789;

  sprintf(buffer_standard, "Double: %+-10.2f ", expected);
  s21_sprintf(buffer_custom, "Double: %+-10.2f ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 9: Длинная комбинация флагов и размеров
START_TEST(test_s21_sprintf_f_complex_combination) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = 12345.67890;

  sprintf(buffer_standard, "Double: %+-20.8f ", expected);
  s21_sprintf(buffer_custom, "Double: %+-20.8f ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 10: Пространство вместо плюса для положительного числа
START_TEST(test_s21_sprintf_f_space_for_positive) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = 42.3;

  sprintf(buffer_standard, "Double: % f ", expected);
  s21_sprintf(buffer_custom, "Double: % f ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 11: Ширина поля меньше значения
START_TEST(test_s21_sprintf_f_smaller_field_width) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = 42.3;

  sprintf(buffer_standard, "Double: %2f ", expected);
  s21_sprintf(buffer_custom, "Double: %2f ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 12: Специальное значение `-INF`
START_TEST(test_s21_sprintf_f_minus_inf) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = -INFINITY;

  sprintf(buffer_standard, "Double: %f ", expected);
  s21_sprintf(buffer_custom, "Double: %f ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 13: Точность выше, чем у исходного значения
START_TEST(test_s21_sprintf_f_higher_precision) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = 42.34;

  sprintf(buffer_standard, "Double: %.5f ", expected);
  s21_sprintf(buffer_custom, "Double: %.5f ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 14: Очень маленькое число
START_TEST(test_s21_sprintf_f_very_small_number) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = 0.00000123;

  sprintf(buffer_standard, "Double: %f ", expected);
  s21_sprintf(buffer_custom, "Double: %f ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 15: Число с большим количеством знаков после запятой
START_TEST(test_s21_sprintf_f_large_decimal_part) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = 42.987607654321;

  sprintf(buffer_standard, "Double: %f ", expected);
  s21_sprintf(buffer_custom, "Double: %f ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 16: Число с большим количеством знаков после запятой
START_TEST(test_s21_sprintf_Lf_large_decimal_part) {
  char buffer_standard[100];
  char buffer_custom[100];
  long double expected = 42.98765432109876543;

  sprintf(buffer_standard, "Double: %Lf ", expected);
  s21_sprintf(buffer_custom, "Double: %Lf ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 17: Точность выше, чем у исходного значения
START_TEST(test_s21_sprintf_Lf_higher_precision) {
  char buffer_standard[100];
  char buffer_custom[100];
  long double expected = 1234345432.34;

  sprintf(buffer_standard, "Double: %.5Lf ", expected);
  s21_sprintf(buffer_custom, "Double: %.5Lf ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 18: Очень маленькое число
START_TEST(test_s21_sprintf_Lf_very_small_number) {
  char buffer_standard[100];
  char buffer_custom[100];
  long double expected = 0.00000000123;

  sprintf(buffer_standard, "Double: %Lf ", expected);
  s21_sprintf(buffer_custom, "Double: %Lf ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

Suite *sprintf_f_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("sprintf_f");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_sprintf_f_plus_double);
  tcase_add_test(tc_core, test_s21_sprintf_f_right_shift_fixed_width);
  tcase_add_test(tc_core, test_s21_sprintf_f_left_shift_fixed_width);
  tcase_add_test(tc_core, test_s21_sprintf_f_fixed_precision);
  tcase_add_test(tc_core, test_s21_sprintf_f_nan);
  tcase_add_test(tc_core, test_s21_sprintf_f_inf);
  tcase_add_test(tc_core, test_s21_sprintf_f_negative_number);
  tcase_add_test(tc_core, test_s21_sprintf_f_combinations);
  tcase_add_test(tc_core, test_s21_sprintf_f_complex_combination);
  tcase_add_test(tc_core, test_s21_sprintf_f_space_for_positive);
  tcase_add_test(tc_core, test_s21_sprintf_f_smaller_field_width);
  tcase_add_test(tc_core, test_s21_sprintf_f_minus_inf);
  tcase_add_test(tc_core, test_s21_sprintf_f_higher_precision);
  tcase_add_test(tc_core, test_s21_sprintf_f_very_small_number);
  tcase_add_test(tc_core, test_s21_sprintf_f_large_decimal_part);
  tcase_add_test(tc_core, test_s21_sprintf_Lf_higher_precision);
  tcase_add_test(tc_core, test_s21_sprintf_Lf_very_small_number);
  tcase_add_test(tc_core, test_s21_sprintf_Lf_large_decimal_part);

  suite_add_tcase(s, tc_core);

  return s;
}