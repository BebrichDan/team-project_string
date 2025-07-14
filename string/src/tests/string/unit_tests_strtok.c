#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../../s21_string.h"

START_TEST(test_s21_strtok_single_delimiter) {
  char str[] = "Hello, world, this, is, a, test";
  char *delim = ", ";
  char *token;

  // Копируем строку, чтобы избежать изменения оригинала
  char str_copy1[100];
  char str_copy2[100];
  strcpy(str_copy1, str);
  strcpy(str_copy2, str);

  token = strtok(str_copy1, delim);
  char *result1 = s21_strtok(str_copy2, delim);

  while (token != S21_NULL) {
    ck_assert_str_eq(result1, token);  // Сравниваем токены
    result1 = s21_strtok(S21_NULL, delim);
    token = strtok(S21_NULL, delim);
  }
}
END_TEST

START_TEST(test_s21_strtok_multiple_delimiters) {
  char str[] = "Hello,,world,,this,,is,,a,,test";
  char *delim = ", ";
  char *token;

  // Копируем строку, чтобы избежать изменения оригинала
  char str_copy1[100];
  char str_copy2[100];
  strcpy(str_copy1, str);
  strcpy(str_copy2, str);

  token = strtok(str_copy1, delim);
  char *result1 = s21_strtok(str_copy2, delim);

  while (token != S21_NULL) {
    ck_assert_str_eq(result1, token);  // Сравниваем токены
    result1 = s21_strtok(S21_NULL, delim);
    token = strtok(S21_NULL, delim);
  }
}
END_TEST

START_TEST(test_s21_strtok_empty_string) {
  char str[] = "";
  char *delim = ", ";

  char str_copy1[100];
  char str_copy2[100];
  strcpy(str_copy1, str);
  strcpy(str_copy2, str);

  // Проверяем, что оба результата одинаковы (S21_NULL)
  ck_assert_ptr_eq(s21_strtok(str_copy2, delim), strtok(str_copy1, delim));
}
END_TEST

START_TEST(test_s21_strtok_no_delimiters) {
  char str[] = "Hello";
  char *delim = ", ";

  char str_copy1[100];
  char str_copy2[100];
  strcpy(str_copy1, str);
  strcpy(str_copy2, str);

  // Проверяем, что оба результата одинаковы (вся строка как один токен)
  ck_assert_str_eq(s21_strtok(str_copy2, delim), strtok(str_copy1, delim));
}
END_TEST

START_TEST(test_s21_strtok_starts_with_delimiter) {
  char str[] = ",Hello,world";
  char *delim = ", ";

  char str_copy1[100];
  char str_copy2[100];
  strcpy(str_copy1, str);
  strcpy(str_copy2, str);

  // Проверяем, что обе функции возвращают одинаковые токены
  ck_assert_str_eq(s21_strtok(str_copy2, delim), strtok(str_copy1, delim));
}
END_TEST

START_TEST(test_s21_strtok_trailing_delimiters) {
  char str[] = "Hello,world,";
  char *delim = ", ";

  char str_copy1[100];
  char str_copy2[100];
  strcpy(str_copy1, str);
  strcpy(str_copy2, str);

  // Проверяем, что обе функции возвращают одинаковые токены
  ck_assert_str_eq(s21_strtok(str_copy2, delim), strtok(str_copy1, delim));
}
END_TEST

START_TEST(test_s21_strtok_multiple_calls) {
  char str[] = "one two three four";
  char *delim = " ";

  char str_copy1[100];
  char str_copy2[100];
  strcpy(str_copy1, str);
  strcpy(str_copy2, str);

  char *token1 = s21_strtok(str_copy2, delim);
  char *token2 = strtok(str_copy1, delim);

  while (token2 != S21_NULL) {
    ck_assert_str_eq(token1, token2);  // Сравниваем токены
    token1 = s21_strtok(S21_NULL, delim);
    token2 = strtok(S21_NULL, delim);
  }
}
END_TEST

START_TEST(test_s21_strtok_single_delim_at_start) {
  char str[] = "  Hello";
  char *delim = " ";

  char str_copy1[100];
  char str_copy2[100];
  strcpy(str_copy1, str);
  strcpy(str_copy2, str);

  // Проверяем, что первая строка после первого разделителя правильно
  // токенизируется
  ck_assert_str_eq(s21_strtok(str_copy2, delim), strtok(str_copy1, delim));
}
END_TEST

START_TEST(test_s21_strtok_same_delimiter_multiple_times) {
  char str[] = "abc;;;def;;;ghi";
  char *delim = ";";
  char *token;

  char str_copy1[100];
  char str_copy2[100];
  strcpy(str_copy1, str);
  strcpy(str_copy2, str);

  token = strtok(str_copy1, delim);
  char *result1 = s21_strtok(str_copy2, delim);

  while (token != S21_NULL) {
    ck_assert_str_eq(result1, token);  // Сравниваем токены
    result1 = s21_strtok(S21_NULL, delim);
    token = strtok(S21_NULL, delim);
  }
}
END_TEST

// Сборка всех тестов
Suite *strtok_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strtok");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strtok_single_delimiter);
  tcase_add_test(tc_core, test_s21_strtok_multiple_delimiters);
  tcase_add_test(tc_core, test_s21_strtok_empty_string);
  tcase_add_test(tc_core, test_s21_strtok_no_delimiters);
  tcase_add_test(tc_core, test_s21_strtok_starts_with_delimiter);
  tcase_add_test(tc_core, test_s21_strtok_trailing_delimiters);
  tcase_add_test(tc_core, test_s21_strtok_multiple_calls);
  tcase_add_test(tc_core, test_s21_strtok_single_delim_at_start);
  tcase_add_test(tc_core, test_s21_strtok_same_delimiter_multiple_times);
  suite_add_tcase(s, tc_core);

  return s;
}
