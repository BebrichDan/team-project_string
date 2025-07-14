#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../../s21_string.h"

// Тест 1: Проверка на пустую подстроку (needle)
START_TEST(test_s21_strpbrk_empty_needle) {
  char *haystack = "Hello, world!";
  char *needle = "";

  ck_assert_ptr_eq(s21_strpbrk(haystack, needle), strpbrk(haystack, needle));
}
END_TEST

// Тест 2: Проверка на подстроку, которая содержится в начале строки
START_TEST(test_s21_strpbrk_found_at_start) {
  char *haystack = "Hello, world!";
  char *needle = "H";

  ck_assert_str_eq(s21_strpbrk(haystack, needle), strpbrk(haystack, needle));
}
END_TEST

// Тест 3: Проверка на подстроку, которая содержится в середине строки
START_TEST(test_s21_strpbrk_found_in_middle) {
  char *haystack = "Hello, world!";
  char *needle = "o";

  ck_assert_str_eq(s21_strpbrk(haystack, needle), strpbrk(haystack, needle));
}
END_TEST

// Тест 4: Проверка на подстроку, которая содержится в конце строки
START_TEST(test_s21_strpbrk_found_at_end) {
  char *haystack = "Hello, world!";
  char *needle = "d";

  ck_assert_str_eq(s21_strpbrk(haystack, needle), strpbrk(haystack, needle));
}
END_TEST

// Тест 5: Проверка на отсутствие подстроки
START_TEST(test_s21_strpbrk_not_found) {
  char *haystack = "Hello, world!";
  char *needle = "z";

  ck_assert_ptr_eq(s21_strpbrk(haystack, needle), strpbrk(haystack, needle));
}
END_TEST

// Тест 6: Проверка на пустую строку в haystack
START_TEST(test_s21_strpbrk_empty_haystack) {
  char *haystack = "";
  char *needle = "H";

  ck_assert_ptr_eq(s21_strpbrk(haystack, needle), strpbrk(haystack, needle));
}
END_TEST

// Тест 7: Проверка на подстроку, которая длиннее строки
START_TEST(test_s21_strpbrk_needle_longer_than_haystack) {
  char *haystack = "Hello";
  char *needle = "Hello, world!";

  ck_assert_ptr_eq(s21_strpbrk(haystack, needle), strpbrk(haystack, needle));
}
END_TEST

// Тест 8: Проверка на работу с несколькими символами в needle
START_TEST(test_s21_strpbrk_multiple_chars_in_needle) {
  char *haystack = "Hello, world!";
  char *needle = "elo";

  ck_assert_str_eq(s21_strpbrk(haystack, needle), strpbrk(haystack, needle));
}
END_TEST

// Сборка всех тестов
Suite *strpbrk_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strpbrk");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strpbrk_empty_needle);
  tcase_add_test(tc_core, test_s21_strpbrk_found_at_start);
  tcase_add_test(tc_core, test_s21_strpbrk_found_in_middle);
  tcase_add_test(tc_core, test_s21_strpbrk_found_at_end);
  tcase_add_test(tc_core, test_s21_strpbrk_not_found);
  tcase_add_test(tc_core, test_s21_strpbrk_empty_haystack);
  tcase_add_test(tc_core, test_s21_strpbrk_needle_longer_than_haystack);
  tcase_add_test(tc_core, test_s21_strpbrk_multiple_chars_in_needle);
  suite_add_tcase(s, tc_core);

  return s;
}
