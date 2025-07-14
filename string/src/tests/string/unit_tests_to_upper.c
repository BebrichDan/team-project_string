#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../../s21_string.h"

// Тест 1: Проверка на преобразование строки с маленькими буквами в верхний
// регистр
START_TEST(test_to_upper_basic_conversion) {
  const char *input = "hello";
  char *result = s21_to_upper(input);
  char *expected = "HELLO";

  ck_assert_str_eq(result, expected);
  free(result);  // Освобождаем память, выделенную в функции s21_to_upper
}
END_TEST

// Тест 2: Проверка на строку, состоящую только из заглавных букв (ничего не
// изменяется)
START_TEST(test_to_upper_already_uppercase) {
  const char *input = "HELLO";
  char *result = s21_to_upper(input);
  char *expected = "HELLO";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

// Тест 3: Проверка на пустую строку
START_TEST(test_to_upper_empty_string) {
  const char *input = "";
  char *result = s21_to_upper(input);
  char *expected = "";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

// Тест 4: Проверка на строку с символами, не относящимися к буквам (например,
// пробелами или знаками препинания)
START_TEST(test_to_upper_non_alpha_characters) {
  const char *input = "hello, world!";
  char *result = s21_to_upper(input);
  char *expected = "HELLO, WORLD!";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

// Тест 5: Проверка на строку, содержащую только один символ
START_TEST(test_to_upper_single_char) {
  const char *input = "a";
  char *result = s21_to_upper(input);
  char *expected = "A";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

// Тест 6: Проверка на строку с большими и маленькими буквами
START_TEST(test_to_upper_mixed_case) {
  const char *input = "HeLLo WoRLd";
  char *result = s21_to_upper(input);
  char *expected = "HELLO WORLD";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

// Тест 7: Проверка на строку с только пробелами
START_TEST(test_to_upper_spaces_only) {
  const char *input = "    ";
  char *result = s21_to_upper(input);
  char *expected = "    ";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

// Тест 8: Проверка на строку с символами за пределами латинского алфавита
// (например, кириллица)
START_TEST(test_to_upper_non_latin_chars) {
  const char *input = "Привет мир";
  char *result = s21_to_upper(input);
  char *expected = "Привет мир";  // Функция должна оставить кириллические
                                  // символы без изменений

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

// Тест 9: Проверка на строку с символами в верхнем регистре, которые не должны
// измениться
START_TEST(test_to_upper_mixed_non_alpha) {
  const char *input = "123abc!@#";
  char *result = s21_to_upper(input);
  char *expected = "123ABC!@#";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

// Сборка всех тестов
Suite *to_upper_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_to_upper");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_to_upper_basic_conversion);
  tcase_add_test(tc_core, test_to_upper_already_uppercase);
  tcase_add_test(tc_core, test_to_upper_empty_string);
  tcase_add_test(tc_core, test_to_upper_non_alpha_characters);
  tcase_add_test(tc_core, test_to_upper_single_char);
  tcase_add_test(tc_core, test_to_upper_mixed_case);
  tcase_add_test(tc_core, test_to_upper_spaces_only);
  tcase_add_test(tc_core, test_to_upper_non_latin_chars);
  tcase_add_test(tc_core, test_to_upper_mixed_non_alpha);
  suite_add_tcase(s, tc_core);

  return s;
}
