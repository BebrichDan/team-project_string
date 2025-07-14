#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../../s21_string.h"

// Тест 1: Поиск символа в начале строки
START_TEST(test_s21_strchr_found_at_start) {
  char str[] = "Hello, world!";
  int c = 'H';

  ck_assert_str_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

// Тест 2: Поиск символа в середине строки
START_TEST(test_s21_strchr_found_in_middle) {
  char str[] = "Hello, world!";
  int c = 'o';

  ck_assert_str_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

// Тест 3: Поиск символа в конце строки
START_TEST(test_s21_strchr_found_at_end) {
  char str[] = "Hello, world!";
  int c = '!';

  ck_assert_str_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

// Тест 4: Поиск отсутствующего символа
START_TEST(test_s21_strchr_not_found) {
  char str[] = "Hello, world!";
  int c = 'z';

  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

// Тест 5: Поиск в пустой строке
START_TEST(test_s21_strchr_empty_string) {
  char str[] = "";
  int c = 'a';

  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

// Тест 6: Поиск нулевого символа
START_TEST(test_s21_strchr_null_char) {
  char str[] = "Hello\0world!";
  int c = '\0';

  ck_assert_str_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST
// Тест 7: C int
START_TEST(test_s21_strchr_c_int) {
  char str[] = "Hello, world!";
  int c = 108;  // l as an int

  ck_assert_str_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

Suite *strchr_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strchr");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strchr_found_at_start);
  tcase_add_test(tc_core, test_s21_strchr_found_in_middle);
  tcase_add_test(tc_core, test_s21_strchr_found_at_end);
  tcase_add_test(tc_core, test_s21_strchr_not_found);
  tcase_add_test(tc_core, test_s21_strchr_empty_string);
  tcase_add_test(tc_core, test_s21_strchr_null_char);
  tcase_add_test(tc_core, test_s21_strchr_c_int);

  suite_add_tcase(s, tc_core);

  return s;
}