#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../../s21_string.h"

// Тест 1: Проверка на нормальную копию строки с достаточным размером буфера
START_TEST(test_s21_strncpy_normal_copy) {
  char dest[20] = {0};
  char *src = "Hello, world!";
  size_t n = 13;

  ck_assert_str_eq(s21_strncpy(dest, src, n), strncpy(dest, src, n));
}
END_TEST

// Тест 2: Проверка на копирование, когда размер буфера меньше длины исходной
// строки
START_TEST(test_s21_strncpy_buffer_smaller_than_src) {
  char dest[10] = {0};
  char *src = "Hello, world!";
  size_t n = 9;  // Размер буфера меньше длины исходной строки

  ck_assert_str_eq(s21_strncpy(dest, src, n), strncpy(dest, src, n));
}
END_TEST

// Тест 3: Проверка на копирование с размером n, равным нулю
START_TEST(test_s21_strncpy_zero_copy) {
  char dest[20] = {0};
  char *src = "Hello, world!";
  size_t n = 0;

  ck_assert_str_eq(s21_strncpy(dest, src, n), strncpy(dest, src, n));
}
END_TEST

// Тест 4: Проверка на копирование, когда размер буфера равен длине исходной
// строки
START_TEST(test_s21_strncpy_buffer_equal_to_src) {
  char dest[20] = {0};
  char *src = "Hello, world!";
  size_t n = 13;  // Размер буфера равен длине строки

  ck_assert_str_eq(s21_strncpy(dest, src, n), strncpy(dest, src, n));
}
END_TEST

// Тест 5: Проверка на копирование, когда размер буфера больше длины строки
START_TEST(test_s21_strncpy_buffer_larger_than_src) {
  char dest[20] = {0};
  char *src = "Hello";
  size_t n = 10;  // Размер буфера больше длины строки

  ck_assert_str_eq(s21_strncpy(dest, src, n), strncpy(dest, src, n));
}
END_TEST

// Тест 6: Проверка на корректное заполнение оставшегося места нулями
START_TEST(test_s21_strncpy_fill_zeros) {
  char dest[20] = {0};
  char *src = "Hello";
  size_t n = 10;  // Размер буфера больше длины строки

  // Сначала копируем строку
  s21_strncpy(dest, src, n);

  // После копирования оставшиеся байты должны быть нулями
  ck_assert(dest[5] == '\0');
  ck_assert(dest[6] == '\0');
  ck_assert(dest[7] == '\0');
  ck_assert(dest[8] == '\0');
  ck_assert(dest[9] == '\0');
}
END_TEST

// Тест 7: Проверка на корректную работу с пустой строкой (src)
START_TEST(test_s21_strncpy_empty_src) {
  char dest[20] = {0};
  char *src = "";
  size_t n = 10;

  ck_assert_str_eq(s21_strncpy(dest, src, n), strncpy(dest, src, n));
}
END_TEST

// Тест 8: Проверка на корректную работу с пустым буфером (dest)
START_TEST(test_s21_strncpy_empty_dest) {
  char dest[20] = {0};
  char *src = "Hello";
  size_t n = 5;

  ck_assert_str_eq(s21_strncpy(dest, src, n), strncpy(dest, src, n));
}
END_TEST

// Тест 9: Проверка на корректную работу с размером n, превышающим размер
// исходной строки
START_TEST(test_s21_strncpy_n_exceeds_src_length) {
  char dest[20] = {0};
  char *src = "Hi";
  size_t n = 10;

  ck_assert_str_eq(s21_strncpy(dest, src, n), strncpy(dest, src, n));
}
END_TEST

// Тест 10: Проверка на копирование строки с нулевым символом в середине
START_TEST(test_s21_strncpy_with_null_in_middle) {
  char dest[20] = {0};
  char *src = "Hel\0lo";
  size_t n = 7;

  ck_assert_str_eq(s21_strncpy(dest, src, n), strncpy(dest, src, n));
}
END_TEST

// Сборка всех тестов
Suite *strncpy_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strncpy");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strncpy_normal_copy);
  tcase_add_test(tc_core, test_s21_strncpy_buffer_smaller_than_src);
  tcase_add_test(tc_core, test_s21_strncpy_zero_copy);
  tcase_add_test(tc_core, test_s21_strncpy_buffer_equal_to_src);
  tcase_add_test(tc_core, test_s21_strncpy_buffer_larger_than_src);
  tcase_add_test(tc_core, test_s21_strncpy_fill_zeros);
  tcase_add_test(tc_core, test_s21_strncpy_empty_src);
  tcase_add_test(tc_core, test_s21_strncpy_empty_dest);
  tcase_add_test(tc_core, test_s21_strncpy_n_exceeds_src_length);
  tcase_add_test(tc_core, test_s21_strncpy_with_null_in_middle);
  suite_add_tcase(s, tc_core);

  return s;
}
