#include <assert.h>
#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../s21_string.h"

// Тест 1: Без флагов и модификаторов
START_TEST(test_s21_sprintf_p_no_flags) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = 23;

  sprintf(buffer_standard, "%p", &expected);
  s21_sprintf(buffer_custom, "%p", &expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 2: Ширина поля
START_TEST(test_s21_sprintf_p_width_modifier) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = 23;

  sprintf(buffer_standard, "%20p", &expected);
  s21_sprintf(buffer_custom, "%20p", &expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 3: Флаг -
START_TEST(test_s21_sprintf_p_minus_flag) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = 23;

  sprintf(buffer_standard, "%-20p", &expected);
  s21_sprintf(buffer_custom, "%-20p", &expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 4: Без флагов и модификаторов
START_TEST(test_s21_sprintf_n_basic) {
  char buffer_standard[100];
  char buffer_custom[100];
  int exp_stan = 23;
  int exp_cus = 23;

  sprintf(buffer_standard, "Drom drom drom%n", &exp_stan);
  s21_sprintf(buffer_custom, "Drom drom drom%n", &exp_cus);

  assert(exp_stan == exp_cus);
}
END_TEST

// Тест 5: Без флагов и модификаторов
START_TEST(test_s21_sprintf_percent_basic) {
  char buffer_standard[100];
  char buffer_custom[100];

  sprintf(buffer_standard, "sassam%% sam");
  s21_sprintf(buffer_custom, "sassam%% sam");

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

Suite *sprintf_p_n_percent_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("sprintf_p_n_percent");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_sprintf_p_no_flags);
  tcase_add_test(tc_core, test_s21_sprintf_p_width_modifier);
  tcase_add_test(tc_core, test_s21_sprintf_p_minus_flag);
  tcase_add_test(tc_core, test_s21_sprintf_n_basic);
  tcase_add_test(tc_core, test_s21_sprintf_percent_basic);

  suite_add_tcase(s, tc_core);

  return s;
}