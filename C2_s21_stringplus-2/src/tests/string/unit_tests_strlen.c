#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../../s21_string.h"

// Тест 1: Длина непустой строки
START_TEST(test_s21_strlen_non_empty) {
  char str[] = "Hello, world!";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

// Тест 2: Длина пустой строки
START_TEST(test_s21_strlen_empty) {
  char str[] = "";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

// Тест 3: Длина строки с пробелами
START_TEST(test_s21_strlen_spaces) {
  char str[] = "   Hello, world!   ";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

// Тест 4: Длина строки с одним символом
START_TEST(test_s21_strlen_one_char) {
  char str[] = "A";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

// Тест 5: Длина строки с нулевым символом внутри
START_TEST(test_s21_strlen_null_char) {
  char str[] = "Hello\0world!";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

// Тест 6: Длина очень длинной строки (для проверки переполнения)
START_TEST(test_s21_strlen_very_long) {
  char str[10000];
  for (int i = 0; i < 9999; ++i) {
    str[i] = 'a';
  }
  str[9999] = '\0';
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

Suite *strlen_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strlen");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strlen_non_empty);
  tcase_add_test(tc_core, test_s21_strlen_empty);
  tcase_add_test(tc_core, test_s21_strlen_spaces);
  tcase_add_test(tc_core, test_s21_strlen_one_char);
  tcase_add_test(tc_core, test_s21_strlen_null_char);
  tcase_add_test(tc_core, test_s21_strlen_very_long);

  suite_add_tcase(s, tc_core);

  return s;
}