#include <assert.h>
#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../s21_string.h"

// Тест 1: Базовый случай с плавающей точкой
START_TEST(test_s21_sprintf_E_basic_double) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = 42.32;

  sprintf(buffer_standard, "Double: %e", expected);
  s21_sprintf(buffer_custom, "Double: %e", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 2: Использование флага `+`
START_TEST(test_s21_sprintf_E_plus_flag) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = 987.654321;

  sprintf(buffer_standard, "Double with + flag: %+e", expected);
  s21_sprintf(buffer_custom, "Double with + flag: %+e", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 3: Использование флага `-`
START_TEST(test_s21_sprintf_E_minus_flag) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = -543.210987;

  sprintf(buffer_standard, "Double with - flag: %-e", expected);
  s21_sprintf(buffer_custom, "Double with - flag: %-e", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 4: Использование флага `#`
START_TEST(test_s21_sprintf_E_hash_flag) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = 12.3456789;

  sprintf(buffer_standard, "Double with # flag: %#e", expected);
  s21_sprintf(buffer_custom, "Double with # flag: %#e", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 5: Использование флага `0`
START_TEST(test_s21_sprintf_E_zero_flag) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = 765.4321098;

  sprintf(buffer_standard, "Double with 0 flag: %0e", expected);
  s21_sprintf(buffer_custom, "Double with 0 flag: %0e", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 6: Использование ширины поля
START_TEST(test_s21_sprintf_E_width_field) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = 98.7654321;

  sprintf(buffer_standard, "Double with width field: %10e", expected);
  s21_sprintf(buffer_custom, "Double with width field: %10e", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 7: Использование точности
START_TEST(test_s21_sprintf_E_precision) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = 234.5678901;

  sprintf(buffer_standard, "Double with precision: %.3e", expected);
  s21_sprintf(buffer_custom, "Double with precision: %.3e", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 8: Проверка числа с минимальной точностью
START_TEST(test_s21_sprintf_E_number_with_minimal_precision) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = 99999.99999;

  sprintf(buffer_standard, "Number with minimal precision: %.1e", expected);
  s21_sprintf(buffer_custom, "Number with minimal precision: %.1e", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 9: Проверка отрицательного числа с шириной и точностью
START_TEST(test_s21_sprintf_E_negative_with_width_and_precision) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = -12345.678901;

  sprintf(buffer_standard, "Negative number with width and precision: %10.3e",
          expected);
  s21_sprintf(buffer_custom, "Negative number with width and precision: %10.3e",
              expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 10: Проверка очень маленького числа с точностью
START_TEST(test_s21_sprintf_E_very_small_number_with_precision) {
  char buffer_standard[100];
  char buffer_custom[100];
  long double expected = 0.00001234567;

  sprintf(buffer_standard, "Very small number with precision: %.15Le",
          expected);
  s21_sprintf(buffer_custom, "Very small number with precision: %.15Le",
              expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 11: Проверка очень большого числа с точностью
START_TEST(test_s21_sprintf_E_very_large_number_with_precision) {
  char buffer_standard[100];
  char buffer_custom[100];
  long double expected = 1234567890.09876543;

  sprintf(buffer_standard, "Very large number with precision: %.10Le",
          expected);
  s21_sprintf(buffer_custom, "Very large number with precision: %.10Le",
              expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 12: Проверка числа с нулевой точностью
START_TEST(test_s21_sprintf_E_number_with_zero_precision) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = 7654.32109;

  sprintf(buffer_standard, "Number with zero precision: %0.3e", expected);
  s21_sprintf(buffer_custom, "Number with zero precision: %0.3e", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 13: Проверка числа с максимальной точностью
START_TEST(test_s21_sprintf_E_number_with_maximal_precision) {
  char buffer_standard[100];
  char buffer_custom[100];
  long double expected = 0.00123456789;

  sprintf(buffer_standard, "Number with maximal precision: %.15Le", expected);
  s21_sprintf(buffer_custom, "Number with maximal precision: %.15Le", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 14: Проверка числа с флагом `' '`
START_TEST(test_s21_sprintf_E_space_flag) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = 1234.56789;

  sprintf(buffer_standard, "Number with space flag: % e", expected);
  s21_sprintf(buffer_custom, "Number with space flag: % e", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 15: Проверка числа с флагом `'+'` и шириной
START_TEST(test_s21_sprintf_E_plus_flag_and_width) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = 54321.09876;

  sprintf(buffer_standard, "Number with plus flag and width: %+10.3e",
          expected);
  s21_sprintf(buffer_custom, "Number with plus flag and width: %+10.3e",
              expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 16: Проверка числа с флагом `'-'` и точностью
START_TEST(test_s21_sprintf_E_minus_flag_and_precision) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = -98765.4321;

  sprintf(buffer_standard, "Number with minus flag and precision: %-10.3e",
          expected);
  s21_sprintf(buffer_custom, "Number with minus flag and precision: %-10.3e",
              expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 17: Проверка числа с флагом `'#'` и шириной
START_TEST(test_s21_sprintf_E_hash_flag_and_width) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = 1234.56789;

  sprintf(buffer_standard, "Number with hash flag and width: %#10.3e",
          expected);
  s21_sprintf(buffer_custom, "Number with hash flag and width: %#10.3e",
              expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 18: Проверка числа с комбинацией флагов '0', '+' и точностью
START_TEST(test_s21_sprintf_E_zero_plus_flags_and_precision) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = 3456.78901;

  sprintf(buffer_standard,
          "Number with zero, plus flags and precision: %0+10.3e", expected);
  s21_sprintf(buffer_custom,
              "Number with zero, plus flags and precision: %0+10.3e", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 19: Проверка числа с флагом '0' и точностью
START_TEST(test_s21_sprintf_E_zero_flag_and_precision) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = 7654.32109;

  sprintf(buffer_standard, "Number with zero flag and precision: %010.3e",
          expected);
  s21_sprintf(buffer_custom, "Number with zero flag and precision: %010.3e",
              expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 20: Проверка числа с комбинацией флагов '+', '#' и шириной
START_TEST(test_s21_sprintf_E_plus_hash_flags_and_width) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = 9876.54321;

  sprintf(buffer_standard, "Number with plus, hash flags and width: %+#10.3e",
          expected);
  s21_sprintf(buffer_custom, "Number with plus, hash flags and width: %+#10.3e",
              expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 21: Проверка числа с комбинацией флагов ' ', '#' и шириной
START_TEST(test_s21_sprintf_E_space_hash_flags_and_width) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = 2345.67890;

  sprintf(buffer_standard, "Number with space, hash flags and width: % #10.3e",
          expected);
  s21_sprintf(buffer_custom,
              "Number with space, hash flags and width: % #10.3e", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 22: Комбинация флагов и ширины
START_TEST(test_s21_sprintf_E_combined_flags_and_width) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = -876.543210;

  sprintf(buffer_standard, "Double with combined flags and width: %+010.3e",
          expected);
  s21_sprintf(buffer_custom, "Double with combined flags and width: %+010.3e",
              expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST
Suite *sprintf_e_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("sprintf_e");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_sprintf_E_basic_double);
  tcase_add_test(tc_core, test_s21_sprintf_E_plus_flag);
  tcase_add_test(tc_core, test_s21_sprintf_E_minus_flag);
  tcase_add_test(tc_core, test_s21_sprintf_E_hash_flag);
  tcase_add_test(tc_core, test_s21_sprintf_E_zero_flag);
  tcase_add_test(tc_core, test_s21_sprintf_E_width_field);
  tcase_add_test(tc_core, test_s21_sprintf_E_precision);
  tcase_add_test(tc_core, test_s21_sprintf_E_number_with_minimal_precision);
  tcase_add_test(tc_core, test_s21_sprintf_E_negative_with_width_and_precision);
  tcase_add_test(tc_core, test_s21_sprintf_E_very_small_number_with_precision);
  tcase_add_test(tc_core, test_s21_sprintf_E_very_large_number_with_precision);
  tcase_add_test(tc_core, test_s21_sprintf_E_number_with_zero_precision);
  tcase_add_test(tc_core, test_s21_sprintf_E_number_with_maximal_precision);
  tcase_add_test(tc_core, test_s21_sprintf_E_space_flag);
  tcase_add_test(tc_core, test_s21_sprintf_E_plus_flag_and_width);
  tcase_add_test(tc_core, test_s21_sprintf_E_minus_flag_and_precision);
  tcase_add_test(tc_core, test_s21_sprintf_E_hash_flag_and_width);
  tcase_add_test(tc_core, test_s21_sprintf_E_zero_plus_flags_and_precision);
  tcase_add_test(tc_core, test_s21_sprintf_E_zero_flag_and_precision);
  tcase_add_test(tc_core, test_s21_sprintf_E_plus_hash_flags_and_width);
  tcase_add_test(tc_core, test_s21_sprintf_E_space_hash_flags_and_width);
  tcase_add_test(tc_core, test_s21_sprintf_E_combined_flags_and_width);

  suite_add_tcase(s, tc_core);

  return s;
}