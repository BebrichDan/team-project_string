#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../../s21_string.h"

// Тест 1: Проверка на преобразование строки с заглавными буквами в нижний
// регистр
START_TEST(test_to_lower_basic_conversion) {
  const char *input = "HELLO";
  char *result = s21_to_lower(input);
  char *expected = "hello";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

// Тест 2: Проверка на строку, состоящую только из строчных букв (ничего не
// изменяется)
START_TEST(test_to_lower_already_lowercase) {
  const char *input = "hello";
  char *result = s21_to_lower(input);
  char *expected = "hello";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

// Тест 3: Проверка на пустую строку
START_TEST(test_to_lower_empty_string) {
  const char *input = "";
  char *result = s21_to_lower(input);
  char *expected = "";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

// Тест 4: Проверка на строку с символами, не относящимися к буквам (например,
// пробелами или знаками препинания)
START_TEST(test_to_lower_non_alpha_characters) {
  const char *input = "HELLO, WORLD!";
  char *result = s21_to_lower(input);
  char *expected = "hello, world!";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

// Тест 5: Проверка на строку, содержащую только один символ
START_TEST(test_to_lower_single_char) {
  const char *input = "A";
  char *result = s21_to_lower(input);
  char *expected = "a";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

// Тест 6: Проверка на строку с большими и маленькими буквами
START_TEST(test_to_lower_mixed_case) {
  const char *input = "HeLLo WoRLd";
  char *result = s21_to_lower(input);
  char *expected = "hello world";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

// Тест 7: Проверка на строку с только пробелами
START_TEST(test_to_lower_spaces_only) {
  const char *input = "    ";
  char *result = s21_to_lower(input);
  char *expected = "    ";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

// Тест 8: Проверка на строку с символами за пределами латинского алфавита
// (например, кириллица)
START_TEST(test_to_lower_non_latin_chars) {
  const char *input = "ПРИВЕТ мир";
  char *result = s21_to_lower(input);
  char *expected = "ПРИВЕТ мир";  // Функция должна оставить кириллические
                                  // символы без изменений

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

// Тест 9: Проверка на строку с символами в нижнем регистре, которые не должны
// измениться
START_TEST(test_to_lower_mixed_non_alpha) {
  const char *input = "123abc!@#";
  char *result = s21_to_lower(input);
  char *expected = "123abc!@#";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

// Сборка всех тестов
Suite *to_lower_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_to_lower");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_to_lower_basic_conversion);
  tcase_add_test(tc_core, test_to_lower_already_lowercase);
  tcase_add_test(tc_core, test_to_lower_empty_string);
  tcase_add_test(tc_core, test_to_lower_non_alpha_characters);
  tcase_add_test(tc_core, test_to_lower_single_char);
  tcase_add_test(tc_core, test_to_lower_mixed_case);
  tcase_add_test(tc_core, test_to_lower_spaces_only);
  tcase_add_test(tc_core, test_to_lower_non_latin_chars);
  tcase_add_test(tc_core, test_to_lower_mixed_non_alpha);
  suite_add_tcase(s, tc_core);

  return s;
}
