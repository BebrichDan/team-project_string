#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../../s21_string.h"

// Тест 1: Сравнение равных блоков памяти
START_TEST(test_s21_memcmp_equal_blocks) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  size_t n = sizeof(str1);
  int res = memcmp(str1, str2, n);
  res = res == 0 ? 0 : res < 0 ? -1 : 1;
  int s21_res = s21_memcmp(str1, str2, n);
  s21_res = s21_res == 0 ? 0 : res < 0 ? -1 : 1;

  ck_assert_int_eq(res, s21_res);
}
END_TEST

// Тест 2: Различие в начале
START_TEST(test_s21_memcmp_diff_at_start) {
  char str1[] = "Aello, world!";
  char str2[] = "Hello, world!";
  size_t n = sizeof(str1);
  int res = memcmp(str1, str2, n);
  res = res == 0 ? 0 : res < 0 ? -1 : 1;
  int s21_res = s21_memcmp(str1, str2, n);
  s21_res = s21_res == 0 ? 0 : res < 0 ? -1 : 1;

  ck_assert_int_eq(res, s21_res);
}
END_TEST

// Тест 3: Различие в середине
START_TEST(test_s21_memcmp_diff_in_middle) {
  char str1[] = "Hello, wArld!";
  char str2[] = "Hello, world!";
  size_t n = sizeof(str1);
  int res = memcmp(str1, str2, n);
  res = res == 0 ? 0 : res < 0 ? -1 : 1;
  int s21_res = s21_memcmp(str1, str2, n);
  s21_res = s21_res == 0 ? 0 : res < 0 ? -1 : 1;

  ck_assert_int_eq(res, s21_res);
}
END_TEST

// Тест 4: Различие в конце
START_TEST(test_s21_memcmp_diff_at_end) {
  char str1[] = "Hello, world?";
  char str2[] = "Hello, world!";
  size_t n = sizeof(str1);
  int res = memcmp(str1, str2, n);
  res = res == 0 ? 0 : res < 0 ? -1 : 1;
  int s21_res = s21_memcmp(str1, str2, n);
  s21_res = s21_res == 0 ? 0 : res < 0 ? -1 : 1;

  ck_assert_int_eq(res, s21_res);
}
END_TEST

// Тест 5: str1 короче str2
START_TEST(test_s21_memcmp_str1_shorter) {
  char str1[] = "Hello";
  char str2[] = "Hello, world!";
  size_t n = sizeof(str1);
  int res = memcmp(str1, str2, n);
  res = res == 0 ? 0 : res < 0 ? -1 : 1;
  int s21_res = s21_memcmp(str1, str2, n);
  s21_res = s21_res == 0 ? 0 : res < 0 ? -1 : 1;

  ck_assert_int_eq(res, s21_res);
}
END_TEST

// Тест 6: str2 короче str1
START_TEST(test_s21_memcmp_str2_shorter) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello";
  size_t n = sizeof(str2);
  int res = memcmp(str1, str2, n);
  res = res == 0 ? 0 : res < 0 ? -1 : 1;
  int s21_res = s21_memcmp(str1, str2, n);
  s21_res = s21_res == 0 ? 0 : res < 0 ? -1 : 1;

  ck_assert_int_eq(res, s21_res);
}
END_TEST

// Тест 7: n = 0
START_TEST(test_s21_memcmp_zero_size) {
  char str1[] = "Hello, world!";
  char str2[] = "Different string";
  size_t n = 0;
  int res = memcmp(str1, str2, n);
  res = res == 0 ? 0 : res < 0 ? -1 : 1;
  int s21_res = s21_memcmp(str1, str2, n);
  s21_res = s21_res == 0 ? 0 : res < 0 ? -1 : 1;

  ck_assert_int_eq(res, s21_res);
}
END_TEST

END_TEST
// Тест 9: разные типы данных
START_TEST(test_s21_memcmp_diff_data_types) {
  int str1[] = {1, 2, 3, 4, 5};
  int str2[] = {1, 2, 3, 4, 6};
  size_t n = sizeof(str1);
  int res = memcmp(str1, str2, n);
  res = res == 0 ? 0 : res < 0 ? -1 : 1;
  int s21_res = s21_memcmp(str1, str2, n);
  s21_res = s21_res == 0 ? 0 : res < 0 ? -1 : 1;

  ck_assert_int_eq(res, s21_res);
}
END_TEST
// Тест 10: нулевые байты в массиве
START_TEST(test_s21_memcmp_null_byte) {
  char str1[] = "hello\0world";
  char str2[] = "hello\0there";
  size_t n = sizeof(str1);
  int res = memcmp(str1, str2, n);
  res = res == 0 ? 0 : res < 0 ? -1 : 1;
  int s21_res = s21_memcmp(str1, str2, n);
  s21_res = s21_res == 0 ? 0 : res < 0 ? -1 : 1;

  ck_assert_int_eq(res, s21_res);
}
END_TEST

Suite *memcmp_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("memcmp");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_memcmp_equal_blocks);
  tcase_add_test(tc_core, test_s21_memcmp_diff_at_start);
  tcase_add_test(tc_core, test_s21_memcmp_diff_in_middle);
  tcase_add_test(tc_core, test_s21_memcmp_diff_at_end);
  tcase_add_test(tc_core, test_s21_memcmp_str1_shorter);
  tcase_add_test(tc_core, test_s21_memcmp_str2_shorter);
  tcase_add_test(tc_core, test_s21_memcmp_zero_size);
  tcase_add_test(tc_core, test_s21_memcmp_diff_data_types);
  tcase_add_test(tc_core, test_s21_memcmp_null_byte);

  suite_add_tcase(s, tc_core);

  return s;
}