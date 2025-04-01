#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../../s21_string.h"

// Тест 1: Конкатенация строк с полным копированием
START_TEST(test_s21_strncat_full_copy) {
  char dest[50] = "Hello, ";
  char src[] = "world!";
  size_t n = s21_strlen(src);
  char expected_dest[50] = "Hello, ";

  ck_assert_str_eq(s21_strncat(dest, src, n), strncat(expected_dest, src, n));
}
END_TEST

// Тест 2: Конкатенация строк с частичным копированием
START_TEST(test_s21_strncat_partial_copy) {
  char dest[50] = "Hello, ";
  char src[] = "world!";
  size_t n = 3;
  char expected_dest[50] = "Hello, ";

  ck_assert_str_eq(s21_strncat(dest, src, n), strncat(expected_dest, src, n));
}
END_TEST

// Тест 3: Конкатенация с пустой исходной строкой
START_TEST(test_s21_strncat_empty_src) {
  char dest[50] = "Hello, ";
  char src[] = "";
  size_t n = 5;
  char expected_dest[50] = "Hello, ";

  ck_assert_str_eq(s21_strncat(dest, src, n), strncat(expected_dest, src, n));
}
END_TEST

// Тест 4: Конкатенация с пустой целевой строкой
START_TEST(test_s21_strncat_empty_dest) {
  char dest[50] = "";
  char src[] = "Hello, world!";
  size_t n = 10;
  char expected_dest[50] = "";

  ck_assert_str_eq(s21_strncat(dest, src, n), strncat(expected_dest, src, n));
}
END_TEST

// Тест 5: Конкатенация с нулевым n
START_TEST(test_s21_strncat_zero_n) {
  char dest[50] = "Hello, ";
  char src[] = "world!";
  size_t n = 0;
  char expected_dest[50] = "Hello, ";

  ck_assert_str_eq(s21_strncat(dest, src, n), strncat(expected_dest, src, n));
}
END_TEST

// Тест 6: Конкатенация, когда dest не заканчивается \0
START_TEST(test_s21_strncat_dest_not_null_terminated) {
  char dest[50] = {'H', 'e', 'l', 'l', 'o', '\0', 'x', 'y'};
  char src[] = "world";
  size_t n = 3;
  char expected_dest[50] = {'H', 'e', 'l', 'l', 'o', '\0', 'x', 'y'};

  ck_assert_str_eq(s21_strncat(dest, src, n), strncat(expected_dest, src, n));
}
END_TEST

// Тест 7: Конкатенация, когда n больше длинны src
START_TEST(test_s21_strncat_n_greater_than_src_len) {
  char dest[50] = "Hello, ";
  char src[] = "world!";
  size_t n = 10;
  char expected_dest[50] = "Hello, ";
  ck_assert_str_eq(s21_strncat(dest, src, n), strncat(expected_dest, src, n));
}
END_TEST

Suite *strncat_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strncat");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strncat_full_copy);
  tcase_add_test(tc_core, test_s21_strncat_partial_copy);
  tcase_add_test(tc_core, test_s21_strncat_empty_src);
  tcase_add_test(tc_core, test_s21_strncat_empty_dest);
  tcase_add_test(tc_core, test_s21_strncat_zero_n);
  tcase_add_test(tc_core, test_s21_strncat_dest_not_null_terminated);
  tcase_add_test(tc_core, test_s21_strncat_n_greater_than_src_len);

  suite_add_tcase(s, tc_core);

  return s;
}