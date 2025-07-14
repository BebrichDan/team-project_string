#include <check.h>
#include <stdio.h>
#include <string.h>

#define _GNU_SOURCE
#define STRLEN 128

#include "../../s21_string.h"

START_TEST(sscanf_e_1) {
  char *format = "%e%E%E";
  char *str = "+011 -0010 0010G";
  float out_1 = 0, out_2 = 0, out_3 = 0, s21_out_1 = 0, s21_out_2 = 0,
        s21_out_3 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_float_eq(s21_out_1, out_1);
  ck_assert_float_eq(s21_out_2, out_2);
  ck_assert_float_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_e_2) {
  char *format = "%e%E%E";
  char *str = "1e2 1E0 0e2";
  float out_1 = 0, out_2 = 0, out_3 = 0, s21_out_1 = 0, s21_out_2 = 0,
        s21_out_3 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_float_eq(s21_out_1, out_1);
  ck_assert_float_eq(s21_out_2, out_2);
  ck_assert_float_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_e_3) {
  char *format = "%e%*c%E%E";
  char *str = "1e+2e .5E-1 0.4e.2";
  float out_1 = 0, out_2 = 0, out_3 = 0, s21_out_1 = 0, s21_out_2 = 0,
        s21_out_3 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_float_eq(s21_out_1, out_1);
  ck_assert_float_eq(s21_out_2, out_2);
  ck_assert_float_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_e_4) {
  char *format = "%e";
  char *str = "text without digit";
  int out_1 = 0, s21_out_1 = 0;
  int res = sscanf(str, format, &out_1);
  int s21_res = s21_sscanf(str, format, &s21_out_1);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

Suite *sscanf_e_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_sscanf_e");
  tc = tcase_create("Core");

  tcase_add_test(tc, sscanf_e_1);
  tcase_add_test(tc, sscanf_e_2);
  tcase_add_test(tc, sscanf_e_3);
  tcase_add_test(tc, sscanf_e_4);

  suite_add_tcase(s, tc);
  return s;
}