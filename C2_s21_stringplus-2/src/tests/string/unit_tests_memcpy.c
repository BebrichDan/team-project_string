#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../../s21_string.h"  // Замените на ваш заголовочный файл, если он называется иначе

// Тест 1: Копирование строки в строку (полное совпадение)
START_TEST(test_s21_memcpy_full_copy) {
  char src[] = "Hello, world!";
  char dest[20];
  size_t n = strlen(src) + 1;

  ck_assert_mem_eq(s21_memcpy(dest, src, n), memcpy(dest, src, n), n);
}
END_TEST

// Тест 2: Копирование части строки
START_TEST(test_s21_memcpy_partial_copy) {
  char src[] = "Hello, world!";
  char dest[20];
  size_t n = 5;

  ck_assert_mem_eq(s21_memcpy(dest, src, n), memcpy(dest, src, n), n);
}
END_TEST

// Тест 3: Копирование в пустую строку
START_TEST(test_s21_memcpy_empty_dest) {
  char src[] = "Hello, world!";
  char dest[20] = "";
  size_t n = strlen(src) + 1;

  ck_assert_mem_eq(s21_memcpy(dest, src, n), memcpy(dest, src, n), n);
}
END_TEST

// Тест 4: Копирование из пустой строки
START_TEST(test_s21_memcpy_empty_src) {
  char src[] = "";
  char dest[20] = "Some data";
  size_t n = strlen(src) + 1;

  ck_assert_mem_eq(s21_memcpy(dest, src, n), memcpy(dest, src, n), n);
}
END_TEST

// Тест 5: Копирование с нулевым размером
START_TEST(test_s21_memcpy_zero_size) {
  char src[] = "Hello, world!";
  char dest[20] = "Some data";
  size_t n = 0;

  ck_assert_mem_eq(s21_memcpy(dest, src, n), memcpy(dest, src, n), n);
}
END_TEST

// // Тест 6: Копирование с перекрытием (dest начинается раньше src)
// START_TEST(test_s21_memcpy_overlap_dest_before_src) {
//     char buffer[50] = "abcdefghij";
//     char *dest = buffer;
//     char *src = buffer + 2;
//     size_t n = 5;

//     memmove(buffer, "abcdefghij", 50); // Используем memmove, чтобы
//     подготовить исходный массив ck_assert_mem_eq(s21_memcpy(dest, src, n),
//     memcpy(dest, src, n), n);
// }
// END_TEST

// // Тест 7: Копирование с перекрытием (src начинается раньше dest)
// START_TEST(test_s21_memcpy_overlap_src_before_dest) {
//     char buffer[50] = "abcdefghij";
//     char *dest = buffer + 2;
//     char *src = buffer;
//     size_t n = 5;
//     memmove(buffer, "abcdefghij", 50);// Используем memmove, чтобы
//     подготовить исходный массив ck_assert_mem_eq(s21_memcpy(dest, src, n),
//     memcpy(dest, src, n), n);
// }
// END_TEST

// Тест 8: Копирование в начало той же области памяти
START_TEST(test_s21_memcpy_copy_to_start) {
  char buffer[50] = "abcdefghij";
  char *dest = buffer;
  char *src = buffer;
  size_t n = 5;
  ck_assert_mem_eq(s21_memcpy(dest, src, n), memcpy(dest, src, n), n);
}
END_TEST

// Тест 9: Копирование с разными типами данных
START_TEST(test_s21_memcpy_different_data_types) {
  int src[] = {1, 2, 3, 4, 5};
  int dest[5];
  size_t n = sizeof(src);

  ck_assert_mem_eq(s21_memcpy(dest, src, n), memcpy(dest, src, n), n);
}
END_TEST
// Тест 10: Копирование с неполным int
START_TEST(test_s21_memcpy_not_full_int) {
  char src[] = "abcdefgh";
  char dest[10];
  size_t n = 5;
  ck_assert_mem_eq(s21_memcpy(dest, src, n), memcpy(dest, src, n), n);
}
END_TEST
// Тест 11: Копирование размера меньшего int
START_TEST(test_s21_memcpy_less_than_int) {
  char src[] = "abcdefgh";
  char dest[10];
  size_t n = 3;
  ck_assert_mem_eq(s21_memcpy(dest, src, n), memcpy(dest, src, n), n);
}
END_TEST

Suite *memcpy_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("memcpy");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_memcpy_full_copy);
  tcase_add_test(tc_core, test_s21_memcpy_partial_copy);
  tcase_add_test(tc_core, test_s21_memcpy_empty_dest);
  tcase_add_test(tc_core, test_s21_memcpy_empty_src);
  tcase_add_test(tc_core, test_s21_memcpy_zero_size);
  // tcase_add_test(tc_core, test_s21_memcpy_overlap_dest_before_src);
  // tcase_add_test(tc_core, test_s21_memcpy_overlap_src_before_dest);
  tcase_add_test(tc_core, test_s21_memcpy_copy_to_start);
  tcase_add_test(tc_core, test_s21_memcpy_different_data_types);
  tcase_add_test(tc_core, test_s21_memcpy_not_full_int);
  tcase_add_test(tc_core, test_s21_memcpy_less_than_int);

  suite_add_tcase(s, tc_core);

  return s;
}