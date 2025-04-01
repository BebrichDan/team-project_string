#include <check.h>
#include <stdio.h>
#include <string.h>

#define _GNU_SOURCE
#define STRLEN 128

#include "../../s21_string.h"

START_TEST(sscanf_o_1) {
  char *format = "%o%o%o";
  char *str = "+011 -0010 109";
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

START_TEST(sscanf_o_2) {
  char *format = "%3o%*d%*3o%o%3o";
  char *str = "+011 -0010 109";
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

START_TEST(sscanf_o_3) {
  char *format = "%ho%23lo%*ho%lo";
  char *str = "+010 -1000000000000000000001 -0010 +1000000000000000000000";
  short int out_1 = 0, s21_out_1 = 0;
  long int out_2, out_3, s21_out_2, s21_out_3;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_o_4) {
  char *format = "%o";
  char *str = "text without digit";
  int out_1 = 0, s21_out_1 = 0;
  int res = sscanf(str, format, &out_1);
  int s21_res = s21_sscanf(str, format, &s21_out_1);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

Suite *sscanf_o_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_sscanf_o");
  tc = tcase_create("Core");

  tcase_add_test(tc, sscanf_o_1);
  tcase_add_test(tc, sscanf_o_2);
  tcase_add_test(tc, sscanf_o_3);
  tcase_add_test(tc, sscanf_o_4);

  suite_add_tcase(s, tc);
  return s;
}