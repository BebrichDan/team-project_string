#include <assert.h>
#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../s21_string.h"

// Тест 1: Базовый тест для `%s` без дополнительных флагов
START_TEST(test_s21_sprintf_s_basic_string) {
  char buffer_standard[100];
  char buffer_custom[100];
  char *expected = "";

  sprintf(buffer_standard, "%s  s", expected);
  s21_sprintf(buffer_custom, "%s  s", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 2: Проверка флага выравнивания по левому краю (`%-10s`)
START_TEST(test_s21_sprintf_s_left_align) {
  char buffer_standard[100];
  char buffer_custom[100];
  char *expected = "Привет";

  int size = sprintf(buffer_standard, "%-20s", expected);
  int s21_size = s21_sprintf(buffer_custom, "%-20s", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
  assert(s21_size == size);
}
END_TEST

// Тест 3: Проверка минимального количества символов (`%10s`)
START_TEST(test_s21_sprintf_s_min_width) {
  char buffer_standard[100];
  char buffer_custom[100];
  char *expected = "Привет";

  int size = sprintf(buffer_standard, "%20s", expected);
  int s21_size = s21_sprintf(buffer_custom, "%20s", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
  assert(s21_size == size);
}
END_TEST

// Тест 4: Проверка минимальной длины строки с заполнением пробелами (`%.10s`)
START_TEST(test_s21_sprintf_s_precision) {
  char buffer_standard[100];
  char buffer_custom[100];
  char *expected = "Привет";

  sprintf(buffer_standard, "%.10s", expected);
  s21_sprintf(buffer_custom, "%.10s", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 5: Проверка комбинации флагов и размера (`%-20.15s`)
START_TEST(test_s21_sprintf_s_combined_flags) {
  char buffer_standard[100];
  char buffer_custom[100];
  char *expected = "Привет мир!";

  sprintf(buffer_standard, "%-20.15s", expected);
  s21_sprintf(buffer_custom, "%-20.15s", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 6: Проверка длинного строкового значения (`%50s`)
START_TEST(test_s21_sprintf_s_long_string) {
  char buffer_standard[100];
  char buffer_custom[100];
  char *expected = "Это очень длинный строковой литерал для тестирования.";

  sprintf(buffer_standard, "%50s", expected);
  s21_sprintf(buffer_custom, "%50s", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 7: Проверка использования нуля перед шириной (`%5s`)
START_TEST(test_s21_sprintf_s_padding) {
  char buffer_standard[100];
  char buffer_custom[100];
  wchar_t *expected = L"🙂🙂🙂🙂🙂";

  swprintf((wchar_t *)buffer_standard, sizeof(buffer_standard), L"Emoji: %5ls",
           expected);
  s21_sprintf(buffer_custom, "Emoji: %5ls", expected);

  wchar_t wbuf_custom[100];
  mbstowcs(wbuf_custom, buffer_custom, sizeof(buffer_custom));

  assert(wcscmp((wchar_t *)buffer_standard, wbuf_custom) == 0);
}
END_TEST

Suite *sprintf_s_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("sprintf_s");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_sprintf_s_basic_string);
  tcase_add_test(tc_core, test_s21_sprintf_s_left_align);
  tcase_add_test(tc_core, test_s21_sprintf_s_min_width);
  tcase_add_test(tc_core, test_s21_sprintf_s_precision);
  tcase_add_test(tc_core, test_s21_sprintf_s_combined_flags);
  tcase_add_test(tc_core, test_s21_sprintf_s_long_string);
  tcase_add_test(tc_core, test_s21_sprintf_s_padding);

  suite_add_tcase(s, tc_core);

  return s;
}