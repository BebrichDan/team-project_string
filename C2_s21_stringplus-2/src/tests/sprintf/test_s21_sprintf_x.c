#include <assert.h>
#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../s21_string.h"

// Тест 1: Базовая проверка `%x`
START_TEST(test_s21_sprintf_x_basic) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = 0x2af;

  sprintf(buffer_standard, "%x", expected);
  s21_sprintf(buffer_custom, "%x", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 2: Проверка минимального количества символов (`%x`)
START_TEST(test_s21_sprintf_x_min_width) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = 0x2a;

  sprintf(buffer_standard, "%x", expected);
  s21_sprintf(buffer_custom, "%x", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 3: Проверка минимальной длины строки с заполнением пробелами (`%.10x`)
START_TEST(test_s21_sprintf_x_precision) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = 0x2a;

  sprintf(buffer_standard, "%.10x", expected);
  s21_sprintf(buffer_custom, "%.10x", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 4: Проверка комбинации флагов и размера (`%-20.15x`)
START_TEST(test_s21_sprintf_x_combined_flags) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = 0x2a;

  sprintf(buffer_standard, "%-20.15x", expected);
  s21_sprintf(buffer_custom, "%-20.15x", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 5: Проверка левого выравнивания (`%-10x`)
START_TEST(test_s21_sprintf_x_left_align) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = 0x2a;

  sprintf(buffer_standard, "%-10x", expected);
  s21_sprintf(buffer_custom, "%-10x", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 6: Проверка правого выравнивания (`%10x`)
START_TEST(test_s21_sprintf_x_right_align) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = 0x2a;

  sprintf(buffer_standard, "%#10x", expected);
  s21_sprintf(buffer_custom, "%#10x", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 7: Проверка заполнения нулями (`%05x`)
START_TEST(test_s21_sprintf_x_zero_padding) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = 0x2a;

  sprintf(buffer_standard, "%05x", expected);
  s21_sprintf(buffer_custom, "%05x", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

Suite *sprintf_x_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("sprintf_x");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_sprintf_x_basic);
  tcase_add_test(tc_core, test_s21_sprintf_x_min_width);
  tcase_add_test(tc_core, test_s21_sprintf_x_precision);
  tcase_add_test(tc_core, test_s21_sprintf_x_combined_flags);
  tcase_add_test(tc_core, test_s21_sprintf_x_left_align);
  tcase_add_test(tc_core, test_s21_sprintf_x_right_align);
  tcase_add_test(tc_core, test_s21_sprintf_x_zero_padding);

  suite_add_tcase(s, tc_core);

  return s;
}