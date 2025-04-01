#include <check.h>
#include <stdio.h>

#define _GNU_SOURCE
#define STRLEN 128

#include "../../s21_string.h"

START_TEST(sscanf_c_1) {
  char *format = "%c";
  char *str = "He\tllo, world!";
  char out = 0, s21_out = 0;
  int res = sscanf(str, format, &out);
  int s21_res = s21_sscanf(str, format, &s21_out);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out, out);
}
END_TEST

START_TEST(sscanf_c_2) {
  char *format = "%c";
  char *str = "";
  char out = 0, s21_out = 0;
  int res = sscanf(str, format, &out);
  int s21_res = s21_sscanf(str, format, &s21_out);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sscanf_c_3) {
  char *format = "%10c %c %c";
  char *str = "Hello world!";
  char out_1[STRLEN] = {0}, s21_out_1[STRLEN] = {0};
  char out_2 = 0, out_3 = 0, s21_out_2 = 0, s21_out_3 = 0;
  int res = sscanf(str, format, out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_mem_eq(s21_out_1, out_1, 10);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_c_4) {
  char *format = "%c %c %c";
  char *str = "He\tllo, world!";
  char out_1 = 0, out_2 = 0, out_3 = 0, s21_out_1 = 0, s21_out_2 = 0,
       s21_out_3 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_c_5) {
  char *format = "%c %*c %c %c";
  char *str = "He\tllo, world!";
  char out_1 = 0, out_2 = 0, out_3 = 0, s21_out_1 = 0, s21_out_2 = 0,
       s21_out_3 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_c_6) {
  char *format = "%lc%llc%Lc";
  char *str = "English Юникод держи!";
  wchar_t out_1 = 0, out_2 = 0, out_3 = 0, s21_out_1 = 0, s21_out_2 = 0,
          s21_out_3 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_c_7) {
  char *format = "%c%cello %c";
  char *str = "Hello world!";
  char out_1 = 0, out_2 = 0, out_3 = 0, s21_out_1 = 0, s21_out_2 = 0,
       s21_out_3 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
}
END_TEST

Suite *sscanf_c_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_sscanf_c");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, sscanf_c_1);
  tcase_add_test(tc_core, sscanf_c_2);
  tcase_add_test(tc_core, sscanf_c_3);
  tcase_add_test(tc_core, sscanf_c_4);
  tcase_add_test(tc_core, sscanf_c_5);
  tcase_add_test(tc_core, sscanf_c_6);
  tcase_add_test(tc_core, sscanf_c_7);

  suite_add_tcase(s, tc_core);
  return s;
}