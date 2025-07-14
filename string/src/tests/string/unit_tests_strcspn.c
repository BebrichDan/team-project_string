#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../../s21_string.h"

// Тест 1: Нет совпадений
START_TEST(test_s21_strcspn_no_match) {
  char str1[] = "abcdefg";
  char str2[] = "xyz";

  ck_assert_uint_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

// Тест 2: Совпадение в начале str1
START_TEST(test_s21_strcspn_match_at_start) {
  char str1[] = "abcdefg";
  char str2[] = "a";

  ck_assert_uint_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

// Тест 3: Совпадение в середине str1
START_TEST(test_s21_strcspn_match_in_middle) {
  char str1[] = "abcdefg";
  char str2[] = "c";

  ck_assert_uint_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

// Тест 4: Совпадение в конце str1
START_TEST(test_s21_strcspn_match_at_end) {
  char str1[] = "abcdefg";
  char str2[] = "g";

  ck_assert_uint_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

// Тест 5: str2 пустая
START_TEST(test_s21_strcspn_empty_str2) {
  char str1[] = "abcdefg";
  char str2[] = "";

  ck_assert_uint_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

// Тест 6: str1 пустая
START_TEST(test_s21_strcspn_empty_str1) {
  char str1[] = "";
  char str2[] = "abc";

  ck_assert_uint_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

// Тест 7: Все символы str1 есть в str2
START_TEST(test_s21_strcspn_all_match) {
  char str1[] = "abc";
  char str2[] = "abcdef";

  ck_assert_uint_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST
// Тест 8: str2  несколько символов
START_TEST(test_s21_strcspn_multiple_chars) {
  char str1[] = "hello world";
  char str2[] = "ow";
  ck_assert_uint_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST
// Тест 9: str1  несколько символов
START_TEST(test_s21_strcspn_multiple_chars_str1) {
  char str1[] = "abcabcabc";
  char str2[] = "b";

  ck_assert_uint_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST
Suite *strcspn_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strcspn");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strcspn_no_match);
  tcase_add_test(tc_core, test_s21_strcspn_match_at_start);
  tcase_add_test(tc_core, test_s21_strcspn_match_in_middle);
  tcase_add_test(tc_core, test_s21_strcspn_match_at_end);
  tcase_add_test(tc_core, test_s21_strcspn_empty_str2);
  tcase_add_test(tc_core, test_s21_strcspn_empty_str1);
  tcase_add_test(tc_core, test_s21_strcspn_all_match);
  tcase_add_test(tc_core, test_s21_strcspn_multiple_chars);
  tcase_add_test(tc_core, test_s21_strcspn_multiple_chars_str1);

  suite_add_tcase(s, tc_core);

  return s;
}