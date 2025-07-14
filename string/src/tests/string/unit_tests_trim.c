#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../../s21_string.h"

// Тест 1: Проверка на корректное обрезание пробелов с обеих сторон строки
START_TEST(test_trim_basic) {
  const char *input = "  hello world  ";
  const char *trim_chars = " ";
  char *result = s21_trim(input, trim_chars);
  char *expected = "hello world";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

// Тест 2: Проверка на отсутствие символов для обрезания в строке (не
// изменяется)
START_TEST(test_trim_no_trim_chars) {
  const char *input = "hello world";
  const char *trim_chars = " ";
  char *result = s21_trim(input, trim_chars);
  char *expected = "hello world";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

// Тест 3: Проверка на обрезание символов в начале строки
START_TEST(test_trim_trim_start) {
  const char *input = "!!!hello world";
  const char *trim_chars = "!";
  char *result = s21_trim(input, trim_chars);
  char *expected = "hello world";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

// Тест 4: Проверка на обрезание символов в конце строки
START_TEST(test_trim_trim_end) {
  const char *input = "hello world###";
  const char *trim_chars = "#";
  char *result = s21_trim(input, trim_chars);
  char *expected = "hello world";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

// Тест 5: Проверка на строку с символами, которые нужно обрезать с обеих сторон
START_TEST(test_trim_trim_both_ends) {
  const char *input = "##hello world##";
  const char *trim_chars = "#";
  char *result = s21_trim(input, trim_chars);
  char *expected = "hello world";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

// Тест 6: Проверка на пустую строку (src)
START_TEST(test_trim_empty_src) {
  const char *input = "";
  const char *trim_chars = " ";
  char *result = s21_trim(input, trim_chars);
  char *expected = "";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

// Тест 7: Проверка на строку, состоящую только из символов, которые нужно
// обрезать
START_TEST(test_trim_only_trim_chars) {
  const char *input = "!!!!";
  const char *trim_chars = "!";
  char *result = s21_trim(input, trim_chars);
  char *expected = "";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

// Тест 8: Проверка на пустую строку (trim_chars)
START_TEST(test_trim_empty_trim_chars) {
  const char *input = "hello world";
  const char *trim_chars = "";
  char *result = s21_trim(input, trim_chars);
  char *expected = "hello world";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

// Тест 9: Проверка на NULL в качестве входных данных
START_TEST(test_trim_null_src) {
  const char *input = S21_NULL;
  const char *trim_chars = " ";
  char *result = s21_trim(input, trim_chars);

  ck_assert_ptr_eq(result, S21_NULL);
}
END_TEST

// Тест 10: Проверка на NULL в качестве trim_chars
START_TEST(test_trim_null_trim_chars) {
  const char *input = "hello world";
  const char *trim_chars = S21_NULL;
  char *result = s21_trim(input, trim_chars);

  ck_assert_ptr_eq(result, S21_NULL);
}
END_TEST

// Тест 11: Проверка на NULL в качестве обоих параметров
START_TEST(test_trim_null_both) {
  const char *input = S21_NULL;
  const char *trim_chars = S21_NULL;
  char *result = s21_trim(input, trim_chars);

  ck_assert_ptr_eq(result, S21_NULL);
}
END_TEST

// Сборка всех тестов
Suite *trim_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_trim");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_trim_basic);
  tcase_add_test(tc_core, test_trim_no_trim_chars);
  tcase_add_test(tc_core, test_trim_trim_start);
  tcase_add_test(tc_core, test_trim_trim_end);
  tcase_add_test(tc_core, test_trim_trim_both_ends);
  tcase_add_test(tc_core, test_trim_empty_src);
  tcase_add_test(tc_core, test_trim_only_trim_chars);
  tcase_add_test(tc_core, test_trim_empty_trim_chars);
  tcase_add_test(tc_core, test_trim_null_src);
  tcase_add_test(tc_core, test_trim_null_trim_chars);
  tcase_add_test(tc_core, test_trim_null_both);
  suite_add_tcase(s, tc_core);

  return s;
}
