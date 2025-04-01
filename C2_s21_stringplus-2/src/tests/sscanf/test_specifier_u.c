#include <check.h>
#include <stdio.h>
#include <string.h>

#define _GNU_SOURCE
#define STRLEN 128

#include "../../s21_string.h"

START_TEST(sscanf_u_1) {
  char *format = "%u%u%u";
  char *str = "+010 -001 4294967296";
  unsigned int out_1 = 0, out_2 = 0, out_3 = 0, s21_out_1 = 0, s21_out_2 = 0,
               s21_out_3 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_u_2) {
  char *format = "%3u%*d%*3u%u%3u";
  char *str = "+010 -001 42A4967296";
  unsigned int out_1 = 0, out_2 = 0, out_3 = 0, s21_out_1 = 0, s21_out_2 = 0,
               s21_out_3 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_u_3) {
  char *format = "%hu%23lu%*hu%lu";
  char *str = "+010 -1 -0010 4294967296";
  short unsigned int out_1 = 0, s21_out_1 = 0;
  long unsigned int out_2, out_3, s21_out_2, s21_out_3;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_u_4) {
  char *format = "%u";
  char *str = "text without digit";
  int out_1 = 0, s21_out_1 = 0;
  int res = sscanf(str, format, &out_1);
  int s21_res = s21_sscanf(str, format, &s21_out_1);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

Suite *sscanf_u_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_sscanf_u");
  tc = tcase_create("Core");

  tcase_add_test(tc, sscanf_u_1);
  tcase_add_test(tc, sscanf_u_2);
  tcase_add_test(tc, sscanf_u_3);
  tcase_add_test(tc, sscanf_u_4);

  suite_add_tcase(s, tc);
  return s;
}