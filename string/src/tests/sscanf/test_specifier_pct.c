#include <check.h>
#include <stdio.h>
#include <string.h>

#define _GNU_SOURCE
#define STRLEN 128

#include "../../s21_string.h"

START_TEST(sscanf_p_1) {
  char *format = "%p%p%p";
  char *str = "0x7ffddddddddd 0x7ffdcccccccc 0x7ffdbbbbbbbb";
  void *out_1, *out_2, *out_3, *s21_out_1, *s21_out_2, *s21_out_3;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_ptr_eq(s21_out_1, out_1);
  ck_assert_ptr_eq(s21_out_2, out_2);
  ck_assert_ptr_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_p_2) {
  char *format = "%p";
  char *str = "text without digit";
  int out_1 = 0, s21_out_1 = 0;
  int res = sscanf(str, format, &out_1);
  int s21_res = s21_sscanf(str, format, &s21_out_1);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sscanf_n_1) {
  char *format = "%i %*s %*s %40i %n";
  char *str = "-012 Hello, world! +0x34";
  int out_1 = 0, out_2 = 0, out_3 = 0, s21_out_1 = 0, s21_out_2 = 0,
      s21_out_3 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_pct_1) {
  char *format = "%*s %*s %d %% %*s";
  char *str = "our targer 100% result";
  int out_1 = 0, s21_out_1 = 0;
  int res = sscanf(str, format, &out_1);
  int s21_res = s21_sscanf(str, format, &s21_out_1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_float_eq(s21_out_1, out_1);
}
END_TEST

START_TEST(sscanf_pct_2) {
  char *format = "%%";
  char *str = "text without percents";
  int out_1 = 0, s21_out_1 = 0;
  int res = sscanf(str, format, &out_1);
  int s21_res = s21_sscanf(str, format, &s21_out_1);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sscanf_default_1) {
  char *format = "%d %j";
  char *str = "100 and brocen specifyre";
  int out_1 = 0, s21_out_1 = 0;
  int res = sscanf(str, format, &out_1);
  int s21_res = s21_sscanf(str, format, &s21_out_1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out_1, out_1);
}
END_TEST

Suite *sscanf_pct_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("21_sscanf_pct");
  tc = tcase_create("Core");

  tcase_add_test(tc, sscanf_p_1);
  tcase_add_test(tc, sscanf_p_2);

  tcase_add_test(tc, sscanf_n_1);

  tcase_add_test(tc, sscanf_pct_1);
  tcase_add_test(tc, sscanf_pct_2);

  tcase_add_test(tc, sscanf_default_1);

  suite_add_tcase(s, tc);
  return s;
}