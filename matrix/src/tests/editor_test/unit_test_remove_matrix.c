#include <check.h>

#include "../../s21_matrix.h"

// Вспомогательная функция для проверки освобождения памяти
static int create_and_fill_matrix(matrix_t *matrix, int rows, int columns) {
  int result = s21_create_matrix(rows, columns, matrix);
  if (result == SUCCESS) {
    // Проверяем, что в результате получилась заполненная матрица
    ck_assert_ptr_nonnull(matrix->matrix);
  }
  return result;
}

// Тест на удаление корректной матрицы
START_TEST(remove_matrix_valid) {
  matrix_t matrix;
  int rows = 3;
  int columns = 4;

  int create_result = create_and_fill_matrix(&matrix, rows, columns);
  ck_assert_int_eq(create_result, SUCCESS);

  // Удаляем матрицу
  s21_remove_matrix(&matrix);

  // Проверяем, что указатель на матрицу теперь NULL
  ck_assert_ptr_null(matrix.matrix);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 1);
}
END_TEST

// Тест на удаление матрицы с NULL-указателем на матрицу
START_TEST(remove_matrix_null_matrix) {
  matrix_t matrix;
  matrix.matrix = NULL;

  // Не должно возникнуть segmentation fault
  s21_remove_matrix(&matrix);

  ck_assert_ptr_null(matrix.matrix);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 2);
}
END_TEST

// Тест на удаление матрицы с NULL-указателем
START_TEST(remove_matrix_null) {
  // Не должно возникнуть segmentation fault
  s21_remove_matrix(NULL);

  // Просто проверяем, что тест не падает
  ck_assert(1);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 3);
}
END_TEST

// Тест на удаление матрицы после удаления
START_TEST(remove_matrix_twice) {
  matrix_t matrix;
  int rows = 2;
  int columns = 2;

  int create_result = create_and_fill_matrix(&matrix, rows, columns);
  ck_assert_int_eq(create_result, SUCCESS);

  // Удаляем матрицу первый раз
  s21_remove_matrix(&matrix);

  // Удаляем матрицу второй раз
  // Не должно возникнуть segmentation fault
  s21_remove_matrix(&matrix);

  ck_assert_ptr_null(matrix.matrix);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 4);
}
END_TEST

// Тест на удаление матрицы минимального размера
START_TEST(remove_matrix_minimum_size) {
  matrix_t matrix;
  int rows = 1;
  int columns = 1;

  int create_result = create_and_fill_matrix(&matrix, rows, columns);
  ck_assert_int_eq(create_result, SUCCESS);

  s21_remove_matrix(&matrix);

  ck_assert_ptr_null(matrix.matrix);
  printf("\x1b[42mтест %d пройден\x1b[0m\n", 5);
}
END_TEST

// Функция для создания набора тестов
Suite *s21_remove_matrix_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_remove_matrix");
  tc_core = tcase_create("Core");

  // Добавляем тесты в набор
  tcase_add_test(tc_core, remove_matrix_valid);
  tcase_add_test(tc_core, remove_matrix_null_matrix);
  tcase_add_test(tc_core, remove_matrix_null);
  tcase_add_test(tc_core, remove_matrix_twice);
  tcase_add_test(tc_core, remove_matrix_minimum_size);

  suite_add_tcase(s, tc_core);

  return s;
}