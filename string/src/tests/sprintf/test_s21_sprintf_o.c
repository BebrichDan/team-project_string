#include <assert.h>
#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../s21_string.h"

// Тест 1: Базовая проверка формата %o
START_TEST(test_s21_sprintf_o_basic_int) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = 042;

  sprintf(buffer_standard, "o: %o", expected);
  s21_sprintf(buffer_custom, "o: %o", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 2: Проверка флага # (вывод с ведущим нулем)
START_TEST(test_s21_sprintf_o_with_hash_flag) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = 42;

  sprintf(buffer_standard, "o: %#o", expected);
  s21_sprintf(buffer_custom, "o: %#o", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 3: Проверка флага - (выравнивание по левому краю)
START_TEST(test_s21_sprintf_o_with_minus_flag) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = 42;

  sprintf(buffer_standard, "o: %-8o", expected);
  s21_sprintf(buffer_custom, "o: %-8o", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 4: Проверка ширины поля и заполнения нулями
START_TEST(test_s21_sprintf_o_with_width_and_zeros) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = 42;

  sprintf(buffer_standard, "o: %08o", expected);
  s21_sprintf(buffer_custom, "o: %08o", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Проверка модификатора размера l (длинный целочисленный аргумент)
START_TEST(test_s21_sprintf_o_with_long_modifier) {
  char buffer_standard[100];
  char buffer_custom[100];
  long int expected = 123456789L;

  sprintf(buffer_standard, "o: %lo", expected);
  s21_sprintf(buffer_custom, "o: %lo", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 6: Проверка модификатора размера h (короткое целое число)
START_TEST(test_s21_sprintf_o_with_hh_modifier) {
  char buffer_standard[100];
  char buffer_custom[100];
  short expected = 0177;

  sprintf(buffer_standard, "o: %ho", expected);
  s21_sprintf(buffer_custom, "o: %ho", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 7: Проверка ширины поля и заполнения пробелами
START_TEST(test_s21_sprintf_o_with_width_and_spaces_and_minus) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = 42;

  sprintf(buffer_standard, "o: %10o", expected);
  s21_sprintf(buffer_custom, "o: %10o", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

Suite *sprintf_o_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("sprintf_o");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_sprintf_o_basic_int);
  tcase_add_test(tc_core, test_s21_sprintf_o_with_hash_flag);
  tcase_add_test(tc_core, test_s21_sprintf_o_with_minus_flag);
  tcase_add_test(tc_core, test_s21_sprintf_o_with_width_and_zeros);
  tcase_add_test(tc_core, test_s21_sprintf_o_with_long_modifier);
  tcase_add_test(tc_core, test_s21_sprintf_o_with_hh_modifier);
  tcase_add_test(tc_core, test_s21_sprintf_o_with_width_and_spaces_and_minus);

  suite_add_tcase(s, tc_core);

  return s;
}