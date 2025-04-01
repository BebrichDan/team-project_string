#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../../s21_string.h"

// Тест 1: Сравнение равных строк
START_TEST(test_s21_strncmp_equal_strings) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  size_t n = s21_strlen(str1);
  int res = strncmp(str1, str2, n);
  res = res == 0 ? 0 : res < 0 ? -1 : 1;
  int s21_res = s21_strncmp(str1, str2, n);
  s21_res = s21_res == 0 ? 0 : res < 0 ? -1 : 1;

  ck_assert_int_eq(res, s21_res);
}
END_TEST

// Тест 2: Сравнение строк с различием в начале
START_TEST(test_s21_strncmp_diff_at_start) {
  char str1[] = "Aello, world!";
  char str2[] = "Hello, world!";
  size_t n = s21_strlen(str1);
  int res = strncmp(str1, str2, n);
  res = res == 0 ? 0 : res < 0 ? -1 : 1;
  int s21_res = s21_strncmp(str1, str2, n);
  s21_res = s21_res == 0 ? 0 : res < 0 ? -1 : 1;

  ck_assert_int_eq(res, s21_res);
}
END_TEST

// Тест 3: Сравнение строк с различием в середине
START_TEST(test_s21_strncmp_diff_in_middle) {
  char str1[] = "Hello, wArld!";
  char str2[] = "Hello, world!";
  size_t n = s21_strlen(str1);
  int res = strncmp(str1, str2, n);
  res = res == 0 ? 0 : res < 0 ? -1 : 1;
  int s21_res = s21_strncmp(str1, str2, n);
  s21_res = s21_res == 0 ? 0 : res < 0 ? -1 : 1;

  ck_assert_int_eq(res, s21_res);
}
END_TEST

// Тест 4: Сравнение строк с различием в конце
START_TEST(test_s21_strncmp_diff_at_end) {
  char str1[] = "Hello, world?";
  char str2[] = "Hello, world!";
  size_t n = s21_strlen(str1);
  int res = strncmp(str1, str2, n);
  res = res == 0 ? 0 : res < 0 ? -1 : 1;
  int s21_res = s21_strncmp(str1, str2, n);
  s21_res = s21_res == 0 ? 0 : res < 0 ? -1 : 1;

  ck_assert_int_eq(res, s21_res);
}
END_TEST

// Тест 5: Сравнение с пустой строкой (str1)
START_TEST(test_s21_strncmp_empty_str1) {
  char str1[] = "";
  char str2[] = "Hello, world!";
  size_t n = s21_strlen(str2);
  int res = strncmp(str1, str2, n);
  res = res == 0 ? 0 : res < 0 ? -1 : 1;
  int s21_res = s21_strncmp(str1, str2, n);
  s21_res = s21_res == 0 ? 0 : res < 0 ? -1 : 1;

  ck_assert_int_eq(res, s21_res);
}
END_TEST

// Тест 6: Сравнение с пустой строкой (str2)
START_TEST(test_s21_strncmp_empty_str2) {
  char str1[] = "Hello, world!";
  char str2[] = "";
  size_t n = s21_strlen(str1);
  int res = strncmp(str1, str2, n);
  res = res == 0 ? 0 : res < 0 ? -1 : 1;
  int s21_res = s21_strncmp(str1, str2, n);
  s21_res = s21_res == 0 ? 0 : res < 0 ? -1 : 1;

  ck_assert_int_eq(res, s21_res);
}
END_TEST

// Тест 7: Сравнение с нулевым n
START_TEST(test_s21_strncmp_zero_n) {
  char str1[] = "Hello, world!";
  char str2[] = "Different";
  size_t n = 0;
  int res = strncmp(str1, str2, n);
  res = res == 0 ? 0 : res < 0 ? -1 : 1;
  int s21_res = s21_strncmp(str1, str2, n);
  s21_res = s21_res == 0 ? 0 : res < 0 ? -1 : 1;

  ck_assert_int_eq(res, s21_res);
}
END_TEST
// Тест 8: Сравнение, когда str2 длиннее str1
START_TEST(test_s21_strncmp_str2_longer) {
  char str1[] = "Hello";
  char str2[] = "Hello, world!";
  size_t n = s21_strlen(str2);
  int res = strncmp(str1, str2, n);
  res = res == 0 ? 0 : res < 0 ? -1 : 1;
  int s21_res = s21_strncmp(str1, str2, n);
  s21_res = s21_res == 0 ? 0 : res < 0 ? -1 : 1;

  ck_assert_int_eq(res, s21_res);
}
END_TEST
// Тест 9: Сравнение, когда str1 длиннее str2
START_TEST(test_s21_strncmp_str1_longer) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello";
  size_t n = s21_strlen(str1);
  int res = strncmp(str1, str2, n);
  res = res == 0 ? 0 : res < 0 ? -1 : 1;
  int s21_res = s21_strncmp(str1, str2, n);
  s21_res = s21_res == 0 ? 0 : res < 0 ? -1 : 1;

  ck_assert_int_eq(res, s21_res);
}
END_TEST
// Тест 10: сравнение с разным регистром
START_TEST(test_s21_strncmp_case_diff) {
  char str1[] = "hello";
  char str2[] = "Hello";
  size_t n = s21_strlen(str1);
  int res = strncmp(str1, str2, n);
  res = res == 0 ? 0 : res < 0 ? -1 : 1;
  int s21_res = s21_strncmp(str1, str2, n);
  s21_res = s21_res == 0 ? 0 : res < 0 ? -1 : 1;

  ck_assert_int_eq(res, s21_res);
}
END_TEST

Suite *strncmp_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strncmp");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strncmp_equal_strings);
  tcase_add_test(tc_core, test_s21_strncmp_diff_at_start);
  tcase_add_test(tc_core, test_s21_strncmp_diff_in_middle);
  tcase_add_test(tc_core, test_s21_strncmp_diff_at_end);
  tcase_add_test(tc_core, test_s21_strncmp_empty_str1);
  tcase_add_test(tc_core, test_s21_strncmp_empty_str2);
  tcase_add_test(tc_core, test_s21_strncmp_zero_n);
  tcase_add_test(tc_core, test_s21_strncmp_str2_longer);
  tcase_add_test(tc_core, test_s21_strncmp_str1_longer);
  tcase_add_test(tc_core, test_s21_strncmp_case_diff);

  suite_add_tcase(s, tc_core);

  return s;
}