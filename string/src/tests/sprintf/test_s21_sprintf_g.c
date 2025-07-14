#include <assert.h>
#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../s21_string.h"

// Тест 1: Базовый случай с плавающей точкой
START_TEST(test_s21_sprintf_g_basic_double) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = 42.3;

  sprintf(buffer_standard, "Double: %g", expected);
  s21_sprintf(buffer_custom, "Double: %g", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 2: Проверка флага '+'
START_TEST(test_s21_sprintf_g_plus_flag) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = 42.3;

  sprintf(buffer_standard, "Double with + flag: %+g", expected);
  s21_sprintf(buffer_custom, "Double with + flag: %+g", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 3: Проверка флага ' '
START_TEST(test_s21_sprintf_g_space_flag) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = 32.3;

  sprintf(buffer_standard, "Double with space flag: % .4g", expected);
  s21_sprintf(buffer_custom, "Double with space flag: % .4g", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 4: Проверка флага '#'
START_TEST(test_s21_sprintf_g_hash_flag) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = 0.00034243;

  sprintf(buffer_standard, "Double with hash flag: %#g", expected);
  s21_sprintf(buffer_custom, "Double with hash flag: %#g", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 5: Проверка ширины поля
START_TEST(test_s21_sprintf_g_width_field) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = 42.3;

  sprintf(buffer_standard, "Double with width field: %10g", expected);
  s21_sprintf(buffer_custom, "Double with width field: %10g", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 6: Проверка точности вывода
START_TEST(test_s21_sprintf_g_precision) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = 42.3456789;

  sprintf(buffer_standard, "Double with precision: %.3g", expected);
  s21_sprintf(buffer_custom, "Double with precision: %.3g", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 7: Проверка отрицательного значения
START_TEST(test_s21_sprintf_g_negative_value) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = -42.3;

  sprintf(buffer_standard, "Negative Double: %g", expected);
  s21_sprintf(buffer_custom, "Negative Double: %g", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 8: Проверка комбинации флагов и ширины поля
START_TEST(test_s21_sprintf_g_combined_flags_and_width) {
  char buffer_standard[100];
  char buffer_custom[100];
  long double expected = 433442336.3332423;

  sprintf(buffer_standard, "Combined flags and width: %+10Lg", expected);
  s21_sprintf(buffer_custom, "Combined flags and width: %+10Lg", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 9: Проверка комбинации флагов, ширины поля и точности
START_TEST(test_s21_sprintf_g_combined_flags_width_precision) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = 42.3456789;

  sprintf(buffer_standard, "Combined flags, width, and precision: %+10.3g",
          expected);
  s21_sprintf(buffer_custom, "Combined flags, width, and precision: %+10.3g",
              expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 10: Проверка ширины поля и знака '-'
START_TEST(test_s21_sprintf_g_width_minus_sign) {
  char buffer_standard[100];
  char buffer_custom[100];
  long double expected = -42.3;

  sprintf(buffer_standard, "Width and minus sign: %-#10Lg", expected);
  s21_sprintf(buffer_custom, "Width and minus sign: %-#10Lg", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 11: Проверка точности и знака '+'
START_TEST(test_s21_sprintf_g_precision_plus_sign) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = 42.3456789;

  sprintf(buffer_standard, "Precision and plus sign: %+.3g", expected);
  s21_sprintf(buffer_custom, "Precision and plus sign: %+.3g", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 12: Проверка точности и знака ' '
START_TEST(test_s21_sprintf_g_precision_space_sign) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = 42.3456789;

  sprintf(buffer_standard, "Precision and space sign: % .3g", expected);
  s21_sprintf(buffer_custom, "Precision and space sign: % .3g", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 13: Проверка ширины поля и точности
START_TEST(test_s21_sprintf_g_width_precision) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = 42.3456789;

  sprintf(buffer_standard, "Width and precision: %10.3g", expected);
  s21_sprintf(buffer_custom, "Width and precision: %10.3g", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 14: Проверка ширины поля и точности с флагом '#'
START_TEST(test_s21_sprintf_g_width_precision_hash_flag) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = 42.3456789;

  sprintf(buffer_standard, "Width, precision, and hash flag: %#10.3g",
          expected);
  s21_sprintf(buffer_custom, "Width, precision, and hash flag: %#10.3g",
              expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 15: Проверка ширины поля и точности с флагом '0' (нулевая подстановка)
START_TEST(test_s21_sprintf_g_width_precision_zero_padding) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = 42.3456789;

  sprintf(buffer_standard, "Width, precision, and zero padding: %010.3g",
          expected);
  s21_sprintf(buffer_custom, "Width, precision, and zero padding: %010.3g",
              expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 16: Проверка точности и флага '#'
START_TEST(test_s21_sprintf_g_precision_hash_flag) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = 4542342.34544;

  sprintf(buffer_standard, "Precision and hash flag: %#.3g", expected);
  s21_sprintf(buffer_custom, "Precision and hash flag: %#.3g", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 17: Проверка точности и знака '-' с отрицательным значением
START_TEST(test_s21_sprintf_g_precision_minus_sign_negative_value) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = -42.3456789;

  sprintf(buffer_standard, "Precision and minus sign for negative value: %.3g",
          expected);
  s21_sprintf(buffer_custom,
              "Precision and minus sign for negative value: %.3g", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 18: Проверка ширины поля и знака '+' с отрицательным значением
START_TEST(test_s21_sprintf_g_width_plus_sign_negative_value) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected_1 = -42.3;
  double expected_2 = -423444.3;

  sprintf(buffer_standard,
          "Width and plus sign for negative value: %+10g %+10g", expected_1,
          expected_2);
  s21_sprintf(buffer_custom,
              "Width and plus sign for negative value: %+10g %+*g", expected_1,
              expected_2);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 19: Проверка ширины поля и знака ' ' с отрицательным значением
START_TEST(test_s21_sprintf_g_width_space_sign_negative_value) {
  char buffer_standard[100];
  char buffer_custom[100];
  long double expected = -423242342.3;

  sprintf(buffer_standard, "Width and space sign for negative value:%13Lg",
          expected);
  s21_sprintf(buffer_custom, "Width and space sign for negative value:% 13Lg",
              expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 20
START_TEST(test_s21_sprintf_g_infinity) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = INFINITY;

  sprintf(buffer_standard, "Width and space sign for negative value: % 10g",
          expected);
  s21_sprintf(buffer_custom, "Width and space sign for negative value: % 10g",
              expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 21
START_TEST(test_s21_sprintf_g_nan) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = NAN;

  sprintf(buffer_standard, "Width and space sign for negative value: % 10g",
          expected);
  s21_sprintf(buffer_custom, "Width and space sign for negative value: % 10g",
              expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 22
START_TEST(test_s21_sprintf_g_minus_infinity) {
  char buffer_standard[100];
  char buffer_custom[100];
  double expected = -INFINITY;

  sprintf(buffer_standard, "Width and space sign for negative value: % 10g",
          expected);
  s21_sprintf(buffer_custom, "Width and space sign for negative value: % 10g",
              expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 19: Проверка ширины поля и знака ' ' с отрицательным значением
START_TEST(test_s21_sprintf_Lg_width_space_sign_negative_value) {
  char buffer_standard[100];
  char buffer_custom[100];
  long double expected = -423242342.3;

  sprintf(buffer_standard, "Width and space sign for negative value: % 10Lg",
          expected);
  s21_sprintf(buffer_custom, "Width and space sign for negative value: % 10Lg",
              expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

Suite *sprintf_g_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("sprintf_g");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_sprintf_g_basic_double);
  tcase_add_test(tc_core, test_s21_sprintf_g_plus_flag);
  tcase_add_test(tc_core, test_s21_sprintf_g_space_flag);
  tcase_add_test(tc_core, test_s21_sprintf_g_hash_flag);
  tcase_add_test(tc_core, test_s21_sprintf_g_width_field);
  tcase_add_test(tc_core, test_s21_sprintf_g_precision);
  tcase_add_test(tc_core, test_s21_sprintf_g_negative_value);
  tcase_add_test(tc_core, test_s21_sprintf_g_combined_flags_and_width);
  tcase_add_test(tc_core, test_s21_sprintf_g_combined_flags_width_precision);
  tcase_add_test(tc_core, test_s21_sprintf_g_width_minus_sign);
  tcase_add_test(tc_core, test_s21_sprintf_g_precision_plus_sign);
  tcase_add_test(tc_core, test_s21_sprintf_g_precision_space_sign);
  tcase_add_test(tc_core, test_s21_sprintf_g_width_precision);
  tcase_add_test(tc_core, test_s21_sprintf_g_width_precision_hash_flag);
  tcase_add_test(tc_core, test_s21_sprintf_g_width_precision_zero_padding);
  tcase_add_test(tc_core, test_s21_sprintf_g_precision_hash_flag);
  tcase_add_test(tc_core,
                 test_s21_sprintf_g_precision_minus_sign_negative_value);
  tcase_add_test(tc_core, test_s21_sprintf_g_width_plus_sign_negative_value);
  tcase_add_test(tc_core, test_s21_sprintf_g_width_space_sign_negative_value);
  tcase_add_test(tc_core, test_s21_sprintf_g_infinity);
  tcase_add_test(tc_core, test_s21_sprintf_g_nan);
  tcase_add_test(tc_core, test_s21_sprintf_g_minus_infinity);
  tcase_add_test(tc_core, test_s21_sprintf_Lg_width_space_sign_negative_value);

  suite_add_tcase(s, tc_core);

  return s;
}