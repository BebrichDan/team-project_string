#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

extern Suite *strchr_suite(void);
extern Suite *strtok_suite(void);
extern Suite *strrchr_suite(void);
extern Suite *strncpy_suite(void);
extern Suite *strpbrk_suite(void);
extern Suite *strstr_suite(void);
extern Suite *strncmp_suite(void);
extern Suite *strcspn_suite(void);
extern Suite *strerror_suite(void);
extern Suite *strlen_suite(void);
extern Suite *strncat_suite(void);
extern Suite *to_upper_suite(void);
extern Suite *to_lower_suite(void);
extern Suite *trim_suite(void);
extern Suite *insert_suite(void);
extern Suite *memchr_suite(void);
extern Suite *memcmp_suite(void);
extern Suite *memcpy_suite(void);
extern Suite *memset_suite(void);

extern Suite *sprintf_c_suite(void);
extern Suite *sprintf_d_suite(void);
extern Suite *sprintf_i_suite(void);
extern Suite *sprintf_e_suite(void);
extern Suite *sprintf_E_suite(void);
extern Suite *sprintf_f_suite(void);
extern Suite *sprintf_g_suite(void);
extern Suite *sprintf_G_suite(void);
extern Suite *sprintf_o_suite(void);
extern Suite *sprintf_s_suite(void);
extern Suite *sprintf_u_suite(void);
extern Suite *sprintf_x_suite(void);
extern Suite *sprintf_X_suite(void);
extern Suite *sprintf_p_n_percent_suite(void);

extern Suite *sscanf_c_suite(void);
extern Suite *sscanf_d_suite(void);
extern Suite *sscanf_i_suite(void);
extern Suite *sscanf_e_suite(void);
extern Suite *sscanf_f_suite(void);
extern Suite *sscanf_o_suite(void);
extern Suite *sscanf_s_suite(void);
extern Suite *sscanf_u_suite(void);
extern Suite *sscanf_x_suite(void);
extern Suite *sscanf_pct_suite(void);

// Вспомогательная функция для запуска набора тестов
int run_tests(Suite *(*suite_func)(void)) {
  Suite *s;
  SRunner *sr;
  int number_failed;

  s = suite_func();        // Получаем набор тестов
  sr = srunner_create(s);  // Создаем прогонщик тестов

  srunner_run_all(sr, CK_NORMAL);  // Запуск всех тестов
  number_failed = srunner_ntests_failed(sr);  // Количество неудачных тестов
  srunner_free(sr);  // Освобождение ресурсов

  return number_failed;  // Возвращаем количество ошибок
}

int main(void) {
  int total_failed = 0;

  total_failed += run_tests(strchr_suite);
  total_failed += run_tests(strstr_suite);
  total_failed += run_tests(strpbrk_suite);
  total_failed += run_tests(strtok_suite);
  total_failed += run_tests(strncpy_suite);
  total_failed += run_tests(strrchr_suite);
  total_failed += run_tests(strncmp_suite);
  total_failed += run_tests(strcspn_suite);
  total_failed += run_tests(strerror_suite);
  total_failed += run_tests(strlen_suite);
  total_failed += run_tests(strncat_suite);
  total_failed += run_tests(memchr_suite);
  total_failed += run_tests(memcmp_suite);
  total_failed += run_tests(memcpy_suite);
  total_failed += run_tests(memset_suite);
  total_failed += run_tests(to_upper_suite);
  total_failed += run_tests(to_lower_suite);
  total_failed += run_tests(trim_suite);
  total_failed += run_tests(insert_suite);

  total_failed += run_tests(sprintf_c_suite);
  total_failed += run_tests(sprintf_d_suite);
  total_failed += run_tests(sprintf_i_suite);
  total_failed += run_tests(sprintf_e_suite);
  total_failed += run_tests(sprintf_E_suite);
  total_failed += run_tests(sprintf_f_suite);
  total_failed += run_tests(sprintf_g_suite);
  total_failed += run_tests(sprintf_G_suite);
  total_failed += run_tests(sprintf_o_suite);
  total_failed += run_tests(sprintf_s_suite);
  total_failed += run_tests(sprintf_u_suite);
  total_failed += run_tests(sprintf_x_suite);
  total_failed += run_tests(sprintf_X_suite);
  total_failed += run_tests(sprintf_p_n_percent_suite);

  total_failed += run_tests(sscanf_c_suite);
  total_failed += run_tests(sscanf_d_suite);
  total_failed += run_tests(sscanf_i_suite);
  total_failed += run_tests(sscanf_e_suite);
  total_failed += run_tests(sscanf_f_suite);
  total_failed += run_tests(sscanf_o_suite);
  total_failed += run_tests(sscanf_s_suite);
  total_failed += run_tests(sscanf_u_suite);
  total_failed += run_tests(sscanf_x_suite);
  total_failed += run_tests(sscanf_pct_suite);

  // Возвращаем результат в зависимости от количества ошибок
  return (total_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
