#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../../s21_string.h"

// Тест 1: Проверка на вставку строки в начало
START_TEST(test_insert_start_index_zero) {
  const char *src = "world";
  const char *str = "hello ";
  size_t start_index = 0;
  char *result = s21_insert(src, str, start_index);
  char *expected = "hello world";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

// Тест 2: Проверка на вставку строки в середину
START_TEST(test_insert_middle) {
  const char *src = "hello world";
  const char *str = " beautiful";
  size_t start_index = 5;  // Вставка после "hello"
  char *result = s21_insert(src, str, start_index);
  char *expected = "hello beautiful world";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

// Тест 3: Проверка на вставку строки в конец
START_TEST(test_insert_end) {
  const char *src = "hello";
  const char *str = " world";
  size_t start_index = 5;  // Вставка в конец
  char *result = s21_insert(src, str, start_index);
  char *expected = "hello world";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

// Тест 4: Проверка на строку, в которой вставка происходит после последнего
// символа
START_TEST(test_insert_start_index_larger_than_src_len) {
  const char *src = "hello";
  const char *str = " world";
  size_t start_index = 10;  // Индекс больше длины строки
  char *result = s21_insert(src, str, start_index);

  ck_assert_ptr_eq(result, S21_NULL);
}
END_TEST

// Тест 5: Проверка на пустую строку источника (src)
START_TEST(test_insert_empty_src) {
  const char *src = "";
  const char *str = "hello";
  size_t start_index = 0;
  char *result = s21_insert(src, str, start_index);
  char *expected = "hello";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

// Тест 6: Проверка на пустую строку для вставки (str)
START_TEST(test_insert_empty_str) {
  const char *src = "hello world";
  const char *str = "";
  size_t start_index = 5;
  char *result = s21_insert(src, str, start_index);
  char *expected = "hello world";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

// Тест 7: Проверка на NULL в качестве исходной строки (src)
START_TEST(test_insert_null_src) {
  const char *src = S21_NULL;
  const char *str = "hello";
  size_t start_index = 0;
  char *result = s21_insert(src, str, start_index);

  ck_assert_ptr_eq(result, S21_NULL);
}
END_TEST

// Тест 8: Проверка на NULL в качестве строки для вставки (str)
START_TEST(test_insert_null_str) {
  const char *src = "hello";
  const char *str = S21_NULL;
  size_t start_index = 0;
  char *result = s21_insert(src, str, start_index);

  ck_assert_ptr_eq(result, S21_NULL);
}
END_TEST

// Тест 9: Проверка на NULL для обеих строк
START_TEST(test_insert_null_both) {
  const char *src = S21_NULL;
  const char *str = S21_NULL;
  size_t start_index = 0;
  char *result = s21_insert(src, str, start_index);

  ck_assert_ptr_eq(result, S21_NULL);
}
END_TEST

// Сборка всех тестов
Suite *insert_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_insert");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_insert_start_index_zero);
  tcase_add_test(tc_core, test_insert_middle);
  tcase_add_test(tc_core, test_insert_end);
  tcase_add_test(tc_core, test_insert_start_index_larger_than_src_len);
  tcase_add_test(tc_core, test_insert_empty_src);
  tcase_add_test(tc_core, test_insert_empty_str);
  tcase_add_test(tc_core, test_insert_null_src);
  tcase_add_test(tc_core, test_insert_null_str);
  tcase_add_test(tc_core, test_insert_null_both);
  suite_add_tcase(s, tc_core);

  return s;
}
