#include <assert.h>
#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../s21_string.h"

// Тест 1: Базовый тест для `%u`
START_TEST(test_s21_sprintf_u_basic) {
  char buffer_standard[100];
  char buffer_custom[100];
  unsigned int expected = 42;

  sprintf(buffer_standard, "%u", expected);
  s21_sprintf(buffer_custom, "%u", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 2: Проверка флага выравнивания по левому краю (`%-10u`)
START_TEST(test_s21_sprintf_u_left_align) {
  char buffer_standard[100];
  char buffer_custom[100];
  unsigned int expected = 12345;

  sprintf(buffer_standard, "%-10u", expected);
  s21_sprintf(buffer_custom, "%-10u", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 3: Проверка минимального количества символов (`%10u`)
START_TEST(test_s21_sprintf_u_min_width) {
  char buffer_standard[100];
  char buffer_custom[100];
  unsigned int expected = 12345;

  sprintf(buffer_standard, "%10u", expected);
  s21_sprintf(buffer_custom, "%10u", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 4: Проверка минимальной длины строки с заполнением пробелами (`%.10u`)
START_TEST(test_s21_sprintf_u_precision) {
  char buffer_standard[100];
  char buffer_custom[100];
  unsigned int expected = 12345;

  sprintf(buffer_standard, "%.10u", expected);
  s21_sprintf(buffer_custom, "%.10u", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 5: Проверка комбинации флагов и размера (`%-20.15u`)
START_TEST(test_s21_sprintf_u_combined_flags) {
  char buffer_standard[100];
  char buffer_custom[100];
  unsigned int expected = 12345;

  sprintf(buffer_standard, "%-20.15u", expected);
  s21_sprintf(buffer_custom, "%-20.15u", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 6: Проверка использования нуля перед шириной (`%05u`)
START_TEST(test_s21_sprintf_u_zero_padding) {
  char buffer_standard[100];
  char buffer_custom[100];
  unsigned int expected = 12345;

  sprintf(buffer_standard, "%05u", expected);
  s21_sprintf(buffer_custom, "%05u", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 7: Проверка большого числа (`%lu`)
START_TEST(test_s21_sprintf_lu_large_number) {
  char buffer_standard[100];
  char buffer_custom[100];
  unsigned long expected = 4294967295UL;

  sprintf(buffer_standard, "%lu", expected);
  s21_sprintf(buffer_custom, "%lu", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 8: Проверка числа с флагом выравнивания по правому краю и минимальной
// длиной (%10.u)
START_TEST(test_s21_sprintf_u_right_align_min_length) {
  char buffer_standard[100];
  char buffer_custom[100];
  unsigned int expected = 12345;

  sprintf(buffer_standard, "%10.u", expected);
  s21_sprintf(buffer_custom, "%10.u", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 9: Проверка сочетания ширины и заполнения нулями (%010u)
START_TEST(test_s21_sprintf_u_width_with_zeros) {
  char buffer_standard[100];
  char buffer_custom[100];
  unsigned int expected = 12345;

  sprintf(buffer_standard, "%010u", expected);
  s21_sprintf(buffer_custom, "%010u", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 10: Проверка пустого значения (%u)
START_TEST(test_s21_sprintf_u_empty_value) {
  char buffer_standard[100];
  char buffer_custom[100];
  unsigned int expected = 0;

  sprintf(buffer_standard, "%u", expected);
  s21_sprintf(buffer_custom, "%u", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 11: Проверка очень маленького числа (`%u`)
START_TEST(test_s21_sprintf_u_small_number) {
  char buffer_standard[100];
  char buffer_custom[100];
  unsigned int expected = 1;

  sprintf(buffer_standard, "%u", expected);
  s21_sprintf(buffer_custom, "%u", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 12: Проверка числа с флагом выравнивания по правому краю (`%10u`)
START_TEST(test_s21_sprintf_u_right_align) {
  char buffer_standard[100];
  char buffer_custom[100];
  unsigned int expected = 12345;

  sprintf(buffer_standard, "%10u", expected);
  s21_sprintf(buffer_custom, "%10u", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 13: Проверка числа с флагом выравнивания по центру (`%010u`)
START_TEST(test_s21_sprintf_u_centered) {
  char buffer_standard[100];
  char buffer_custom[100];
  unsigned int expected = 12345;

  sprintf(buffer_standard, "%010u", expected);
  s21_sprintf(buffer_custom, "%010u", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 14: Проверка числа с флагом выравнивания по центру и нулевой длиной
//(`%010u`)
START_TEST(test_s21_sprintf_u_centered_zero_length) {
  char buffer_standard[100];
  char buffer_custom[100];
  unsigned int expected = 12345;

  sprintf(buffer_standard, "%010u", expected);
  s21_sprintf(buffer_custom, "%010u", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 15: Проверка числа с флагом выравнивания по левому краю и минимальной
// длиной (`%-10.u`)
START_TEST(test_s21_sprintf_u_left_align_min_length) {
  char buffer_standard[100];
  char buffer_custom[100];
  unsigned int expected = 12345;

  sprintf(buffer_standard, "%-10.u", expected);
  s21_sprintf(buffer_custom, "%-10.u", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

Suite *sprintf_u_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("sprintf_u");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_sprintf_u_basic);
  tcase_add_test(tc_core, test_s21_sprintf_u_left_align);
  tcase_add_test(tc_core, test_s21_sprintf_u_min_width);
  tcase_add_test(tc_core, test_s21_sprintf_u_precision);
  tcase_add_test(tc_core, test_s21_sprintf_u_combined_flags);
  tcase_add_test(tc_core, test_s21_sprintf_u_zero_padding);
  tcase_add_test(tc_core, test_s21_sprintf_lu_large_number);
  tcase_add_test(tc_core, test_s21_sprintf_u_right_align_min_length);
  tcase_add_test(tc_core, test_s21_sprintf_u_width_with_zeros);
  tcase_add_test(tc_core, test_s21_sprintf_u_empty_value);
  tcase_add_test(tc_core, test_s21_sprintf_u_small_number);
  tcase_add_test(tc_core, test_s21_sprintf_u_right_align);
  tcase_add_test(tc_core, test_s21_sprintf_u_centered);
  tcase_add_test(tc_core, test_s21_sprintf_u_centered_zero_length);
  tcase_add_test(tc_core, test_s21_sprintf_u_left_align_min_length);

  suite_add_tcase(s, tc_core);

  return s;
}