#include <check.h>
#include <stdio.h>
#include <string.h>

#define _GNU_SOURCE
#define STRLEN 128

#include "../../s21_string.h"

START_TEST(sscanf_f_1) {
  char *format = "%f %f %f";
  char *str =
      "1.41421356237309504880 2.71828182845904523536 3.14159265358979323846";
  float out_1, out_2, out_3;
  float s21_out_1, s21_out_2, s21_out_3;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_float_eq(s21_out_1, out_1);
  ck_assert_float_eq(s21_out_2, out_2);
  ck_assert_float_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_f_2) {
  char *format = "%f %*f %f";
  char *str =
      "1.41421356237309504880 2.71828182845904523536 3.14159265358979323846";
  float out_1, out_2;
  float s21_out_1, s21_out_2;
  int res = sscanf(str, format, &out_1, &out_2);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2);
  ck_assert_int_eq(s21_res, res);
  ck_assert_float_eq(s21_out_1, out_1);
  ck_assert_float_eq(s21_out_2, out_2);
}
END_TEST

START_TEST(sscanf_f_3) {
  char *format = "%f %7f %*ld %f";
  char *str =
      "1.41421356237309504880 2.71828182845904523536 3.14159265358979323846";
  float out_1, out_2, out_3;
  float s21_out_1, s21_out_2, s21_out_3;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_float_eq(s21_out_1, out_1);
  ck_assert_float_eq(s21_out_2, out_2);
  ck_assert_float_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_f_4) {
  char *format = "%f %*f %ld %f";
  char *str =
      "1.41421356237309504880 2.71828182845904523536 3.14159265358979323846";
  long int out_2, s21_out_2;
  float out_1, out_3;
  float s21_out_1, s21_out_3;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_float_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_float_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_f_5) {
  char *format = "%f %f %*f %f";
  char *str = "NAN -NaN +NAn -nan";
  float out_1, out_2, out_3;
  float s21_out_1, s21_out_2, s21_out_3;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_float_nan(out_1);
  ck_assert_float_nan(out_2);
  ck_assert_float_nan(out_3);
}
END_TEST

START_TEST(sscanf_f_6) {
  char *format = "%f %f %*f %f";
  char *str = "INF -Inf +INf -inf";
  float out_1, out_2, out_3;
  float s21_out_1, s21_out_2, s21_out_3;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_float_eq(s21_out_1, out_1);
  ck_assert_float_eq(s21_out_2, out_2);
  ck_assert_float_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_f_7) {
  char *format = "%Lf %Lf %Lf";
  char *str =
      "1.41421356237309504880 2.71828182845904523536 3.14159265358979323846";
  double out_1;
  double s21_out_1;
  long double out_2, out_3;
  long double s21_out_2, s21_out_3;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_double_eq_tol(s21_out_1, out_1, 1e-7);
  ck_assert_ldouble_eq_tol(s21_out_2, out_2, 1e-7);
  ck_assert_ldouble_eq_tol(s21_out_3, out_3, 1e-7);
}
END_TEST

START_TEST(sscanf_f_8) {
  char *format = "%*Lf %*Lf %Lf";
  char *str =
      "1.41421356237309504880 2.71828182845904523536 3.14159265358979323846";
  long double out_1 = 0, s21_out_1 = 0;
  int res = sscanf(str, format, &out_1);
  int s21_res = s21_sscanf(str, format, &s21_out_1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_double_eq(s21_out_1, out_1);
}
END_TEST
START_TEST(sscanf_f_9) {
  char *format = "%f";
  char *str = "text without digit";
  float out_1 = 0, s21_out_1 = 0;
  int res = sscanf(str, format, &out_1);
  int s21_res = s21_sscanf(str, format, &s21_out_1);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

Suite *sscanf_f_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_sscanf_f");
  tc = tcase_create("Core");

  tcase_add_test(tc, sscanf_f_1);
  tcase_add_test(tc, sscanf_f_2);
  tcase_add_test(tc, sscanf_f_3);
  tcase_add_test(tc, sscanf_f_4);
  tcase_add_test(tc, sscanf_f_5);
  tcase_add_test(tc, sscanf_f_6);
  tcase_add_test(tc, sscanf_f_7);
  tcase_add_test(tc, sscanf_f_8);
  tcase_add_test(tc, sscanf_f_9);

  suite_add_tcase(s, tc);
  return s;
}