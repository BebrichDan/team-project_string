#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../../s21_string.h"

// Тест 1: Проверка на нахождение символа в начале строки
START_TEST(test_s21_memchr_found_at_start) {
  char haystack[] = "Hello, world!";
  int needle = 'H';
  size_t n = sizeof(haystack) - 1;

  ck_assert_ptr_eq(s21_memchr(haystack, needle, n),
                   memchr(haystack, needle, n));
}
END_TEST

// Тест 2: Проверка на нахождение символа в середине строки
START_TEST(test_s21_memchr_found_in_middle) {
  char haystack[] = "Hello, world!";
  int needle = 'o';
  size_t n = sizeof(haystack) - 1;

  ck_assert_ptr_eq(s21_memchr(haystack, needle, n),
                   memchr(haystack, needle, n));
}
END_TEST

// Тест 3: Проверка на нахождение символа в конце строки
START_TEST(test_s21_memchr_found_at_end) {
  char haystack[] = "Hello, world!";
  int needle = '!';
  size_t n = sizeof(haystack) - 1;

  ck_assert_ptr_eq(s21_memchr(haystack, needle, n),
                   memchr(haystack, needle, n));
}
END_TEST

// Тест 4: Проверка на отсутствие символа в строке
START_TEST(test_s21_memchr_not_found) {
  char haystack[] = "Hello, world!";
  int needle = 'z';
  size_t n = sizeof(haystack) - 1;

  ck_assert_ptr_eq(s21_memchr(haystack, needle, n),
                   memchr(haystack, needle, n));
}
END_TEST

// Тест 5: Проверка на пустую строку
START_TEST(test_s21_memchr_empty_haystack) {
  char haystack[] = "";
  int needle = 'H';
  size_t n = sizeof(haystack) - 1;

  ck_assert_ptr_eq(s21_memchr(haystack, needle, n),
                   memchr(haystack, needle, n));
}
END_TEST

// Тест 6: Проверка на размер n = 0
START_TEST(test_s21_memchr_n_equals_zero) {
  char haystack[] = "Hello, world!";
  int needle = 'H';
  size_t n = 0;

  ck_assert_ptr_eq(s21_memchr(haystack, needle, n),
                   memchr(haystack, needle, n));
}
END_TEST

// Тест 7: Проверка работы с нулевым байтом
START_TEST(test_s21_memchr_null_byte) {
  char haystack[] = "Hello\0world!";
  int needle = '\0';
  size_t n = sizeof(haystack);

  ck_assert_ptr_eq(s21_memchr(haystack, needle, n),
                   memchr(haystack, needle, n));
}
END_TEST

// Тест 8: Проверка на поиск в конце строки, когда размер поиска меньше полного
// размера строки
START_TEST(test_s21_memchr_search_in_subset) {
  char haystack[] = "Hello, world!";
  int needle = 'd';
  size_t n = 8;  // Поиск только в первых 8 байтах

  ck_assert_ptr_eq(s21_memchr(haystack, needle, n),
                   memchr(haystack, needle, n));  // memchr вернет NULL
}
END_TEST
// Тест 9: Проверка на то что c является int
START_TEST(test_s21_memchr_int_c) {
  char haystack[] = "Hello, world!";
  int needle = 72;  // 'H' as an integer
  size_t n = sizeof(haystack) - 1;
  ck_assert_ptr_eq(s21_memchr(haystack, needle, n),
                   memchr(haystack, needle, n));
}
END_TEST

Suite *memchr_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("memchr");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_memchr_found_at_start);
  tcase_add_test(tc_core, test_s21_memchr_found_in_middle);
  tcase_add_test(tc_core, test_s21_memchr_found_at_end);
  tcase_add_test(tc_core, test_s21_memchr_not_found);
  tcase_add_test(tc_core, test_s21_memchr_empty_haystack);
  tcase_add_test(tc_core, test_s21_memchr_n_equals_zero);
  tcase_add_test(tc_core, test_s21_memchr_null_byte);
  tcase_add_test(tc_core, test_s21_memchr_search_in_subset);
  tcase_add_test(tc_core, test_s21_memchr_int_c);

  suite_add_tcase(s, tc_core);

  return s;
}