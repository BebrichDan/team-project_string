#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../../s21_string.h"

// Тест 1: Проверка на нахождение символа в строке
START_TEST(test_s21_strrchr_found) {
  char *haystack = "Hello, world!";
  char needle = 'o';

  ck_assert_ptr_eq(s21_strrchr(haystack, needle), strrchr(haystack, needle));
}
END_TEST

// Тест 2: Проверка на отсутствие символа в строке
START_TEST(test_s21_strrchr_not_found) {
  char *haystack = "Hello, world!";
  char needle = 'x';

  ck_assert_ptr_eq(s21_strrchr(haystack, needle), strrchr(haystack, needle));
}
END_TEST

// Тест 3: Проверка на символ, который находится в начале строки
START_TEST(test_s21_strrchr_first_char) {
  char *haystack = "Hello, world!";
  char needle = 'H';

  ck_assert_ptr_eq(s21_strrchr(haystack, needle), strrchr(haystack, needle));
}
END_TEST

// Тест 4: Проверка на символ, который находится в конце строки
START_TEST(test_s21_strrchr_last_char) {
  char *haystack = "Hello, world!";
  char needle = '!';

  ck_assert_ptr_eq(s21_strrchr(haystack, needle), strrchr(haystack, needle));
}
END_TEST

// Тест 5: Проверка на пустую строку (haystack)
START_TEST(test_s21_strrchr_empty_haystack) {
  char *haystack = "";
  char needle = 'H';

  ck_assert_ptr_eq(s21_strrchr(haystack, needle), strrchr(haystack, needle));
}
END_TEST

// Тест 6: Проверка на пустой символ (needle)
START_TEST(test_s21_strrchr_empty_needle) {
  char *haystack = "Hello, world!";
  char needle = '\0';

  ck_assert_ptr_eq(s21_strrchr(haystack, needle), strrchr(haystack, needle));
}
END_TEST

// Тест 7: Проверка на многократное вхождение символа в строку
START_TEST(test_s21_strrchr_multiple_occurrences) {
  char *haystack = "Hello, how are you?";
  char needle = 'o';

  ck_assert_ptr_eq(s21_strrchr(haystack, needle), strrchr(haystack, needle));
}
END_TEST

// Тест 8: Проверка на символ, который не встречается в строке
START_TEST(test_s21_strrchr_not_present) {
  char *haystack = "Hello, world!";
  char needle = 'z';

  ck_assert_ptr_eq(s21_strrchr(haystack, needle), strrchr(haystack, needle));
}
END_TEST

// Сборка всех тестов
Suite *strrchr_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strrchr");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strrchr_found);
  tcase_add_test(tc_core, test_s21_strrchr_not_found);
  tcase_add_test(tc_core, test_s21_strrchr_first_char);
  tcase_add_test(tc_core, test_s21_strrchr_last_char);
  tcase_add_test(tc_core, test_s21_strrchr_empty_haystack);
  tcase_add_test(tc_core, test_s21_strrchr_empty_needle);
  tcase_add_test(tc_core, test_s21_strrchr_multiple_occurrences);
  tcase_add_test(tc_core, test_s21_strrchr_not_present);
  suite_add_tcase(s, tc_core);

  return s;
}
