#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../../s21_string.h"

// Тест 1: Заполнение массива символом
START_TEST(test_s21_memset_fill_char) {
  char buffer[20];
  char expected[20];
  int c = 'A';
  size_t n = sizeof(buffer);

  s21_memset(buffer, c, n);
  memset(expected, c, n);

  ck_assert_mem_eq(buffer, expected, n);
}
END_TEST

// Тест 2: Заполнение массива нулями
START_TEST(test_s21_memset_fill_zero) {
  char buffer[20] = "some data";
  char expected[20] = "some data";
  int c = 0;
  size_t n = sizeof(buffer);

  s21_memset(buffer, c, n);
  memset(expected, c, n);

  ck_assert_mem_eq(buffer, expected, n);
}
END_TEST

// Тест 3: Заполнение части массива
START_TEST(test_s21_memset_partial_fill) {
  char buffer[20] = "some data";
  char expected[20] = "some data";
  int c = 'X';
  size_t n = 10;

  s21_memset(buffer, c, n);
  memset(expected, c, n);

  ck_assert_mem_eq(buffer, expected, n);
}
END_TEST

// Тест 4: Заполнение с нулевым размером
START_TEST(test_s21_memset_zero_size) {
  char buffer[20] = "some data";
  char expected[20] = "some data";
  int c = 'Y';
  size_t n = 0;

  s21_memset(buffer, c, n);
  memset(expected, c, n);

  ck_assert_mem_eq(buffer, expected, n);
}
END_TEST

// Тест 5: Заполнение уже заполненного массива
START_TEST(test_s21_memset_fill_filled_array) {
  char buffer[20] = "old data";
  char expected[20] = "old data";
  int c = 'B';
  size_t n = sizeof(buffer);

  s21_memset(buffer, c, n);
  memset(expected, c, n);

  ck_assert_mem_eq(buffer, expected, n);
}
END_TEST
// Тест 6: Заполнение int
START_TEST(test_s21_memset_fill_int) {
  int buffer[5];
  int expected[5];
  int c = 100;
  size_t n = sizeof(buffer);

  s21_memset(buffer, c, n);
  memset(expected, c, n);

  ck_assert_mem_eq(buffer, expected, n);
}
END_TEST
// Тест 7: Заполнение не целым int
START_TEST(test_s21_memset_not_full_int) {
  char buffer[10] = "abcdefghi";
  char expected[10] = "abcdefghi";
  int c = 'Z';
  size_t n = 5;

  s21_memset(buffer, c, n);
  memset(expected, c, n);

  ck_assert_mem_eq(buffer, expected, n);
}
END_TEST

Suite *memset_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("memset");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_memset_fill_char);
  tcase_add_test(tc_core, test_s21_memset_fill_zero);
  tcase_add_test(tc_core, test_s21_memset_partial_fill);
  tcase_add_test(tc_core, test_s21_memset_zero_size);
  tcase_add_test(tc_core, test_s21_memset_fill_filled_array);
  tcase_add_test(tc_core, test_s21_memset_fill_int);
  tcase_add_test(tc_core, test_s21_memset_not_full_int);

  suite_add_tcase(s, tc_core);

  return s;
}