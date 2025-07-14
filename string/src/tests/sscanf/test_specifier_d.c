#include <check.h>
#include <stdio.h>
#include <string.h>

#define _GNU_SOURCE
#define STRLEN 128

#include "../../s21_string.h"

START_TEST(sscanf_d_1) {
  char *format = "%d %d %d";
  char *str = "1 2  3 4";
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

START_TEST(sscanf_d_2) {
  char *format = "%1d %2d %3d";
  char *str = "0001 2 3 4";
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

START_TEST(sscanf_d_3) {
  char *format = NULL;
  char *str = "0001 2 3 4";
  int out_1 = 0, out_2 = 0, out_3 = 0, s21_out_1 = 0, s21_out_2 = 0,
      s21_out_3 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sscanf_d_4) {
  char *format = "%d 3%d 5%*d %d";
  char *str = "12 34 56 7";
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

START_TEST(sscanf_d_5) {
  char *format = "%d/%d/%d";
  char *str = "24/07/2024";
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

START_TEST(sscanf_d_6) {
  char *format = "%d / %d / %d";
  char *str = "24/07/2024";
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

START_TEST(sscanf_d_7) {
  char *format = "%d%d%d";
  char *str = "1\t2\n3 4";
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

START_TEST(sscanf_d_8) {
  char *format = "%d %d %d";
  char *str = "+1 +02 -3 4";
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

START_TEST(sscanf_d_9) {
  char *format = "%ld %d %*ld %lld";
  char *str = "1 -2 -3 +4";
  long int out_1 = 0, s21_out_1 = 0;
  long long int out_3 = 0, s21_out_3 = 0;
  int out_2 = 0, s21_out_2 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_d_10) {
  char *format = "%hd %d %*hd %hd";
  char *str = "1 -2 -3 +4";
  short int out_1 = 0, out_3 = 0, s21_out_1 = 0, s21_out_3 = 0;
  int out_2 = 0, s21_out_2 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
}
END_TEST

Suite *sscanf_d_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_sscanf_d");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, sscanf_d_1);
  tcase_add_test(tc_core, sscanf_d_2);
  tcase_add_test(tc_core, sscanf_d_3);
  tcase_add_test(tc_core, sscanf_d_4);
  tcase_add_test(tc_core, sscanf_d_5);
  tcase_add_test(tc_core, sscanf_d_6);
  tcase_add_test(tc_core, sscanf_d_7);
  tcase_add_test(tc_core, sscanf_d_8);
  tcase_add_test(tc_core, sscanf_d_9);
  tcase_add_test(tc_core, sscanf_d_10);

  suite_add_tcase(s, tc_core);
  return s;
}