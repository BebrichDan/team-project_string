#include <check.h>
#include <stdio.h>
#include <string.h>

#define _GNU_SOURCE
#define STRLEN 128

#include "../../s21_string.h"

START_TEST(sscanf_s_1) {
  char *format = "%s";
  char *str = "Hello, world!";
  char out_1[STRLEN] = {0};
  char s21_out_1[STRLEN] = {0};
  int res = sscanf(str, format, &out_1);
  int s21_res = s21_sscanf(str, format, &s21_out_1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_str_eq(s21_out_1, out_1);
}
END_TEST

START_TEST(sscanf_s_2) {
  char *format = "%s";
  char *str = "";
  char out_1[STRLEN] = {0};
  char s21_out_1[STRLEN] = {0};
  int res = sscanf(str, format, &out_1);
  int s21_res = s21_sscanf(str, format, &s21_out_1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_res, -1);
}
END_TEST

START_TEST(sscanf_s_3) {
  char *format = "%s %s %s";
  char *str = "Hello,\tworld!\nHi, test!";
  char out_1[STRLEN] = {0}, out_2[STRLEN] = {0}, out_3[STRLEN] = {0};
  char s21_out_1[STRLEN] = {0}, s21_out_2[STRLEN] = {0},
       s21_out_3[STRLEN] = {0};
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_str_eq(s21_out_1, out_1);
  ck_assert_str_eq(s21_out_2, out_2);
  ck_assert_str_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_s_4) {
  char *format = "%2s %3s %4s";
  char *str = "Hello, world! Hi, test!";
  char out_1[STRLEN] = {0}, out_2[STRLEN] = {0}, out_3[STRLEN] = {0};
  char s21_out_1[STRLEN] = {0}, s21_out_2[STRLEN] = {0},
       s21_out_3[STRLEN] = {0};
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_str_eq(s21_out_1, out_1);
  ck_assert_str_eq(s21_out_2, out_2);
  ck_assert_str_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_s_5) {
  char *format = "%s %*s %s %s";
  char *str = "Hello, world! Hi, test!";
  char out_1[STRLEN] = {0}, out_2[STRLEN] = {0}, out_3[STRLEN] = {0};
  char s21_out_1[STRLEN] = {0}, s21_out_2[STRLEN] = {0},
       s21_out_3[STRLEN] = {0};
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_str_eq(s21_out_1, out_1);
  ck_assert_str_eq(s21_out_2, out_2);
  ck_assert_str_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_s_6) {
  char *format = "%s %5ls %s";
  char *str = "Hello, world! Hi, test!";
  char out_1[STRLEN] = {0}, out_3[STRLEN] = {0};
  char s21_out_1[STRLEN] = {0}, s21_out_3[STRLEN] = {0};
  wchar_t out_2[STRLEN] = {0}, s21_out_2[STRLEN] = {0};
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_str_eq(s21_out_1, out_1);
  ck_assert_mem_eq(s21_out_2, out_2, 10);
  ck_assert_str_eq(s21_out_3, out_3);
}
END_TEST

Suite *sscanf_s_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_sscanf_s");
  tc = tcase_create("Core");

  tcase_add_test(tc, sscanf_s_1);
  tcase_add_test(tc, sscanf_s_2);
  tcase_add_test(tc, sscanf_s_3);
  tcase_add_test(tc, sscanf_s_4);
  tcase_add_test(tc, sscanf_s_5);
  tcase_add_test(tc, sscanf_s_6);

  suite_add_tcase(s, tc);
  return s;
}