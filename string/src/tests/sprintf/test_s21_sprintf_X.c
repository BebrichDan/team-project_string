#include <assert.h>
#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../s21_string.h"

// Тест 1: Базовая проверка `%X`
START_TEST(test_s21_sprintf_X_basic) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = 0x2af;

  sprintf(buffer_standard, "%X", expected);
  s21_sprintf(buffer_custom, "%X", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 2: Проверка минимального количества символов (`%X`)
START_TEST(test_s21_sprintf_X_min_width) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = 0x2a;

  sprintf(buffer_standard, "%X", expected);
  s21_sprintf(buffer_custom, "%X", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 3: Проверка минимальной длины строки с заполнением пробелами (`%.10X`)
START_TEST(test_s21_sprintf_X_precision) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = 0x2a;

  sprintf(buffer_standard, "%.10X", expected);
  s21_sprintf(buffer_custom, "%.10X", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 4: Проверка комбинации флагов и размера (`%-20.15X`)
START_TEST(test_s21_sprintf_X_combined_flags) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = 0x2a;

  sprintf(buffer_standard, "%-20.15X", expected);
  s21_sprintf(buffer_custom, "%-20.15X", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 5: Проверка левого выравнивания (`%-10X`)
START_TEST(test_s21_sprintf_X_left_align) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = 0x2a;

  sprintf(buffer_standard, "%-10X", expected);
  s21_sprintf(buffer_custom, "%-10X", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 6: Проверка правого выравнивания (`%10X`)
START_TEST(test_s21_sprintf_X_right_align) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = 0x2a;

  sprintf(buffer_standard, "%10X", expected);
  s21_sprintf(buffer_custom, "%10X", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 7: Проверка заполнения нулями (`%05X`)
START_TEST(test_s21_sprintf_X_zero_padding) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = 0x2a;

  sprintf(buffer_standard, "%05X", expected);
  s21_sprintf(buffer_custom, "%05X", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

Suite *sprintf_X_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("sprintf_X");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_sprintf_X_basic);
  tcase_add_test(tc_core, test_s21_sprintf_X_min_width);
  tcase_add_test(tc_core, test_s21_sprintf_X_precision);
  tcase_add_test(tc_core, test_s21_sprintf_X_combined_flags);
  tcase_add_test(tc_core, test_s21_sprintf_X_left_align);
  tcase_add_test(tc_core, test_s21_sprintf_X_right_align);
  tcase_add_test(tc_core, test_s21_sprintf_X_zero_padding);

  suite_add_tcase(s, tc_core);

  return s;
}