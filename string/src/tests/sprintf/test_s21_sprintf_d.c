#include <assert.h>
#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../s21_string.h"

// Тест 1
START_TEST(test_s21_sprintf_d_basic_int) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = 42;

  sprintf(buffer_standard, "%d", expected);
  s21_sprintf(buffer_custom, "%d", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 2
START_TEST(test_s21_sprintf_d_plus_int) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = 42;

  sprintf(buffer_standard, "Integer: %+d ", expected);
  s21_sprintf(buffer_custom, "Integer: %+d ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 3
START_TEST(test_s21_sprintf_d_plus_m_int) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = -42;

  sprintf(buffer_standard, "Integer: %+d ", expected);
  s21_sprintf(buffer_custom, "Integer: %+d ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 4
START_TEST(test_s21_sprintf_d_minus_int) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = -42;

  sprintf(buffer_standard, "Integer: %d ", expected);
  s21_sprintf(buffer_custom, "Integer: %d ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 5
START_TEST(test_s21_sprintf_d_zero_int) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = 42;

  sprintf(buffer_standard, "Integer: %05d ", expected);
  s21_sprintf(buffer_custom, "Integer: %05d ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 6
START_TEST(test_s21_sprintf_d_width_int) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected_1 = 42;
  int expected_2 = 4;

  sprintf(buffer_standard, "Integer: %10d %10d ", expected_1, expected_2);
  s21_sprintf(buffer_custom, "Integer: %10d %*d ", expected_1, expected_2);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 7
START_TEST(test_s21_sprintf_d_widthm_m_int) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = -42;

  sprintf(buffer_standard, "Integer: %-10d ", expected);
  s21_sprintf(buffer_custom, "Integer: %-10d ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 8
START_TEST(test_s21_sprintf_d_width_m_zero_int) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = -42;

  sprintf(buffer_standard, "Integer: %010d ", expected);
  s21_sprintf(buffer_custom, "Integer: %010d ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 9
START_TEST(test_s21_sprintf_d_width_p_int) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = 42;

  sprintf(buffer_standard, "Integer: %+10d ", expected);
  s21_sprintf(buffer_custom, "Integer: %+10d ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 10
START_TEST(test_s21_sprintf_d_width_p_zero_int) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = 42;

  sprintf(buffer_standard, "Integer: %+010d ", expected);
  s21_sprintf(buffer_custom, "Integer: %+010d ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 11
START_TEST(test_s21_sprintf_d_width_p_zero_long) {
  char buffer_standard[100];
  char buffer_custom[100];
  long expected = 42;

  sprintf(buffer_standard, "Integer: %+010ld ", expected);
  s21_sprintf(buffer_custom, "Integer: %+010ld ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 12
START_TEST(test_s21_sprintf_d_width_p_zero_short) {
  char buffer_standard[100];
  char buffer_custom[100];
  short expected = 42;

  sprintf(buffer_standard, "Integer: %+010hd ", expected);
  s21_sprintf(buffer_custom, "Integer: %+010hd ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 13
START_TEST(test_s21_sprintf_d_accuracy_int) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected_1 = 42;
  int expected_2 = 4;

  sprintf(buffer_standard, "Integer: %.10d %.10d ", expected_1, expected_2);
  s21_sprintf(buffer_custom, "Integer: %.10d %.*d ", expected_1, expected_2);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 14
START_TEST(test_s21_sprintf_d_accuracy_p_zero_int) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = 42;

  sprintf(buffer_standard, "Integer: %+10.5d ", expected);
  s21_sprintf(buffer_custom, "Integer: %+10.5d ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 15
START_TEST(test_s21_sprintf_d_accuracy_minus_int) {
  char buffer_standard[100];
  char buffer_custom[100];
  int expected = -42;

  sprintf(buffer_standard, "Integer: %.10d ", expected);
  s21_sprintf(buffer_custom, "Integer: %.10d ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 16
START_TEST(test_s21_sprintf_ld_widthm_m_int) {
  char buffer_standard[100];
  char buffer_custom[100];
  long expected = -2147483646;

  sprintf(buffer_standard, "Integer: %-10ld ", expected);
  s21_sprintf(buffer_custom, "Integer: %-10ld ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 17
START_TEST(test_s21_sprintf_ld_width_m_zero_int) {
  char buffer_standard[100];
  char buffer_custom[100];
  long expected = -2147483646;

  sprintf(buffer_standard, "Integer: %010ld ", expected);
  s21_sprintf(buffer_custom, "Integer: %010ld ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 18
START_TEST(test_s21_sprintf_ld_width_p_int) {
  char buffer_standard[100];
  char buffer_custom[100];
  long expected = -2147483646;

  sprintf(buffer_standard, "Integer: %+10.5ld ", expected);
  s21_sprintf(buffer_custom, "Integer: %+10.5ld ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 19
START_TEST(test_s21_sprintf_ld_width_p_zero_int) {
  char buffer_standard[100];
  char buffer_custom[100];
  long expected = 2147483646;

  sprintf(buffer_standard, "Integer: %+010ld ", expected);
  s21_sprintf(buffer_custom, "Integer: %+010ld ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 20
START_TEST(test_s21_sprintf_ld_width_p_zero_long) {
  char buffer_standard[100];
  char buffer_custom[100];
  long expected = -1423423957;

  sprintf(buffer_standard, "Integer: %+010ld ", expected);
  s21_sprintf(buffer_custom, "Integer: %+010ld ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 21
START_TEST(test_s21_sprintf_ld_width_p_zero_short) {
  char buffer_standard[100];
  char buffer_custom[100];
  short expected = 20000;

  sprintf(buffer_standard, "Integer: %10.2hd ", expected);
  s21_sprintf(buffer_custom, "Integer: %10.2hd ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 22
START_TEST(test_s21_sprintf_ld_accuracy_int) {
  char buffer_standard[100];
  char buffer_custom[100];
  long expected = 1423423957;

  sprintf(buffer_standard, "Integer: %.10ld ", expected);
  s21_sprintf(buffer_custom, "Integer: %.10ld ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 23
START_TEST(test_s21_sprintf_ld_accuracy_p_zero_int) {
  char buffer_standard[100];
  char buffer_custom[100];
  long expected = 1423423957;

  sprintf(buffer_standard, "Integer: %+10.5ld ", expected);
  s21_sprintf(buffer_custom, "Integer: %+10.5ld ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 24
START_TEST(test_s21_sprintf_ld_accuracy_minus_int) {
  char buffer_standard[100];
  char buffer_custom[100];
  long expected = -1423423957;

  sprintf(buffer_standard, "Integer: %.10ld ", expected);
  s21_sprintf(buffer_custom, "Integer: %.10ld ", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

Suite *sprintf_d_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("sprintf_d");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_sprintf_d_basic_int);
  tcase_add_test(tc_core, test_s21_sprintf_d_plus_int);
  tcase_add_test(tc_core, test_s21_sprintf_d_plus_m_int);
  tcase_add_test(tc_core, test_s21_sprintf_d_minus_int);
  tcase_add_test(tc_core, test_s21_sprintf_d_zero_int);
  tcase_add_test(tc_core, test_s21_sprintf_d_width_int);
  tcase_add_test(tc_core, test_s21_sprintf_d_widthm_m_int);
  tcase_add_test(tc_core, test_s21_sprintf_d_width_m_zero_int);
  tcase_add_test(tc_core, test_s21_sprintf_d_width_p_int);
  tcase_add_test(tc_core, test_s21_sprintf_d_width_p_zero_int);
  tcase_add_test(tc_core, test_s21_sprintf_d_width_p_zero_long);
  tcase_add_test(tc_core, test_s21_sprintf_d_width_p_zero_short);
  tcase_add_test(tc_core, test_s21_sprintf_d_accuracy_int);
  tcase_add_test(tc_core, test_s21_sprintf_d_accuracy_p_zero_int);
  tcase_add_test(tc_core, test_s21_sprintf_d_accuracy_minus_int);
  tcase_add_test(tc_core, test_s21_sprintf_ld_widthm_m_int);
  tcase_add_test(tc_core, test_s21_sprintf_ld_width_m_zero_int);
  tcase_add_test(tc_core, test_s21_sprintf_ld_width_p_int);
  tcase_add_test(tc_core, test_s21_sprintf_ld_width_p_zero_int);
  tcase_add_test(tc_core, test_s21_sprintf_ld_width_p_zero_long);
  tcase_add_test(tc_core, test_s21_sprintf_ld_width_p_zero_short);
  tcase_add_test(tc_core, test_s21_sprintf_ld_accuracy_int);
  tcase_add_test(tc_core, test_s21_sprintf_ld_accuracy_p_zero_int);
  tcase_add_test(tc_core, test_s21_sprintf_ld_accuracy_minus_int);

  suite_add_tcase(s, tc_core);

  return s;
}