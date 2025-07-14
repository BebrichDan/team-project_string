#include <assert.h>
#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../s21_string.h"

// Тест 1
START_TEST(test_s21_sprintf_i_basic_int) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = 42;

  sprintf(buffer_standard, "%i", expected);
  s21_sprintf(buffer_custom, "%i", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 2
START_TEST(test_s21_sprintf_i_plus_int) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = 42;

  sprintf(buffer_standard, "Integer: %+i ", expected);
  s21_sprintf(buffer_custom, "Integer: %+i ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 3
START_TEST(test_s21_sprintf_i_plus_m_int) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = -42;

  sprintf(buffer_standard, "Integer: %+i ", expected);
  s21_sprintf(buffer_custom, "Integer: %+i ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 4
START_TEST(test_s21_sprintf_i_minus_int) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = -42;

  sprintf(buffer_standard, "Integer: %i ", expected);
  s21_sprintf(buffer_custom, "Integer: %i ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 5
START_TEST(test_s21_sprintf_i_zero_int) {
  char buffer_standard[100];
  char buffer_custom[100];
  long int expected = 42324354;

  sprintf(buffer_standard, "Integer: %05li ", expected);
  s21_sprintf(buffer_custom, "Integer: %05li ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 6
START_TEST(test_s21_sprintf_i_width_int) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = 42;

  sprintf(buffer_standard, "Integer: %10i ", expected);
  s21_sprintf(buffer_custom, "Integer: %10i ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 7
START_TEST(test_s21_sprintf_i_widthm_m_int) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = -42;

  sprintf(buffer_standard, "Integer: %-10i ", expected);
  s21_sprintf(buffer_custom, "Integer: %-10i ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 8
START_TEST(test_s21_sprintf_i_width_m_zero_int) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = -42;

  sprintf(buffer_standard, "Integer: %010i ", expected);
  s21_sprintf(buffer_custom, "Integer: %010i ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 9
START_TEST(test_s21_sprintf_i_width_p_int) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = 42;

  sprintf(buffer_standard, "Integer: %+10i ", expected);
  s21_sprintf(buffer_custom, "Integer: %+10i ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 10
START_TEST(test_s21_sprintf_i_width_p_zero_int) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = 42;

  sprintf(buffer_standard, "Integer: %+010i ", expected);
  s21_sprintf(buffer_custom, "Integer: %+010i ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 11
START_TEST(test_s21_sprintf_i_width_p_zero_long) {
  char buffer_standard[100];
  char buffer_custom[100];
  long expected = 42;

  sprintf(buffer_standard, "Integer: %+010li ", expected);
  s21_sprintf(buffer_custom, "Integer: %+010li ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 12
START_TEST(test_s21_sprintf_i_width_p_zero_short) {
  char buffer_standard[100];
  char buffer_custom[100];
  short expected = 42;

  sprintf(buffer_standard, "Integer: %+010hi ", expected);
  s21_sprintf(buffer_custom, "Integer: %+010hi ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 13
START_TEST(test_s21_sprintf_i_accuracy_int) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = 42;

  sprintf(buffer_standard, "Integer: %.10i ", expected);
  s21_sprintf(buffer_custom, "Integer: %.10i ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 14
START_TEST(test_s21_sprintf_i_accuracy_p_zero_int) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = 42;

  sprintf(buffer_standard, "Integer: %+10.5i ", expected);
  s21_sprintf(buffer_custom, "Integer: %+10.5i ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 15
START_TEST(test_s21_sprintf_i_accuracy_minus_int) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = -42;

  sprintf(buffer_standard, "Integer: %.10i ", expected);
  s21_sprintf(buffer_custom, "Integer: %.10i ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

Suite *sprintf_i_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("sprintf_i");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_sprintf_i_basic_int);
  tcase_add_test(tc_core, test_s21_sprintf_i_plus_int);
  tcase_add_test(tc_core, test_s21_sprintf_i_plus_m_int);
  tcase_add_test(tc_core, test_s21_sprintf_i_minus_int);
  tcase_add_test(tc_core, test_s21_sprintf_i_zero_int);
  tcase_add_test(tc_core, test_s21_sprintf_i_width_int);
  tcase_add_test(tc_core, test_s21_sprintf_i_widthm_m_int);
  tcase_add_test(tc_core, test_s21_sprintf_i_width_m_zero_int);
  tcase_add_test(tc_core, test_s21_sprintf_i_width_p_int);
  tcase_add_test(tc_core, test_s21_sprintf_i_width_p_zero_int);
  tcase_add_test(tc_core, test_s21_sprintf_i_width_p_zero_long);
  tcase_add_test(tc_core, test_s21_sprintf_i_width_p_zero_short);
  tcase_add_test(tc_core, test_s21_sprintf_i_accuracy_int);
  tcase_add_test(tc_core, test_s21_sprintf_i_accuracy_p_zero_int);
  tcase_add_test(tc_core, test_s21_sprintf_i_accuracy_minus_int);

  suite_add_tcase(s, tc_core);

  return s;
}