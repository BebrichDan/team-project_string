#include <assert.h>
#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../s21_string.h"

// Тест 1
START_TEST(test_s21_sprintf_c_basic_char) {
  char buffer_standard[100];
  char buffer_custom[100];
  char expected = 'A';

  sprintf(buffer_standard, "Character: %c", expected);
  s21_sprintf(buffer_custom, "Character: %c", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 2
START_TEST(test_s21_sprintf_c_space_char) {
  char buffer_standard[100];
  char buffer_custom[100];
  char expected = ' ';

  sprintf(buffer_standard, "%c", expected);
  s21_sprintf(buffer_custom, "%c", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 3
START_TEST(test_s21_sprintf_c_digit_char) {
  char buffer_standard[100];
  char buffer_custom[100];
  char expected = '5';

  sprintf(buffer_standard, "\n%c\n", expected);
  s21_sprintf(buffer_custom, "\n%c\n", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 4
START_TEST(test_s21_sprintf_c_special_char) {
  char buffer_standard[100];
  char buffer_custom[100];
  char expected = '\n';

  sprintf(buffer_standard, "\n%cCharacter", expected);
  s21_sprintf(buffer_custom, "\n%cCharacter", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 5
START_TEST(test_s21_sprintf_c_unicode_char) {
  char buffer_standard[100];
  char buffer_custom[100];
  char expected = 0xA9;

  sprintf(buffer_standard, "Character%cCharacter", expected);
  s21_sprintf(buffer_custom, "Character%cCharacter", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 6
START_TEST(test_s21_sprintf_c_null_char) {
  char buffer_standard[100];
  char buffer_custom[100];
  char expected = '\0';

  sprintf(buffer_standard, "Character%cCharacter", expected);
  s21_sprintf(buffer_custom, "Character%cCharacter", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 7
START_TEST(test_s21_sprintf_c_mixed_char) {
  char buffer_standard[100];
  char buffer_custom[100];
  char expected = 'Z';

  sprintf(buffer_standard, "Start-%c-End", expected);
  s21_sprintf(buffer_custom, "Start-%c-End", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 8
START_TEST(test_s21_sprintf_c_multiple_chars) {
  char buffer_standard[100];
  char buffer_custom[100];
  char first = 'X';
  char second = 'Y';
  char third = 'Z';

  sprintf(buffer_standard, "%c-%c-%c", first, second, third);
  s21_sprintf(buffer_custom, "%c-%c-%c", first, second, third);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 9
START_TEST(test_s21_sprintf_c_negative_char) {
  char buffer_standard[100];
  char buffer_custom[100];
  char expected = -65;

  sprintf(buffer_standard, "Negative char: %c", expected);
  s21_sprintf(buffer_custom, "Negative char: %c", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 10
START_TEST(test_s21_sprintf_c_basic_wchar) {
  char buffer_standard[100];
  char buffer_custom[100];
  wchar_t expected = L'Ω';

  swprintf((wchar_t *)buffer_standard, sizeof(buffer_standard),
           L"Wide char: %lc", expected);
  s21_sprintf(buffer_custom, "Wide char: %lc", expected);

  wchar_t wbuf_custom[100];
  mbstowcs(wbuf_custom, buffer_custom, sizeof(buffer_custom));

  assert(wcscmp((wchar_t *)buffer_standard, wbuf_custom) == 0);
}
END_TEST

// Тест 11
START_TEST(test_s21_sprintf_c_unicode_wchar) {
  char buffer_standard[100];
  char buffer_custom[100];
  wchar_t expected = L'🙂';

  swprintf((wchar_t *)buffer_standard, sizeof(buffer_standard), L"Emoji: %lc",
           expected);
  s21_sprintf(buffer_custom, "Emoji: %lc", expected);

  wchar_t wbuf_custom[100];
  mbstowcs(wbuf_custom, buffer_custom, sizeof(buffer_custom));

  assert(wcscmp((wchar_t *)buffer_standard, wbuf_custom) == 0);
}
END_TEST

// Тест 12
START_TEST(test_s21_sprintf_c_multiple_wchars) {
  char buffer_standard[100];
  char buffer_custom[100];
  wchar_t first = L'α';
  wchar_t second = L'β';
  wchar_t third = L'γ';

  swprintf((wchar_t *)buffer_standard, sizeof(buffer_standard), L"%lc-%lc-%lc",
           first, second, third);
  s21_sprintf(buffer_custom, "%lc-%lc-%lc", first, second, third);

  wchar_t wbuf_custom[100];
  mbstowcs(wbuf_custom, buffer_custom, sizeof(buffer_custom));

  assert(wcscmp((wchar_t *)buffer_standard, wbuf_custom) == 0);
}
END_TEST

// Тест 13
START_TEST(test_s21_sprintf_c_null_wchar) {
  char buffer_standard[100];
  char buffer_custom[100];
  wchar_t expected = L'\0';

  swprintf((wchar_t *)buffer_standard, sizeof(buffer_standard),
           L"Null wchar: %lc", expected);
  s21_sprintf(buffer_custom, "Null wchar: %lc", expected);

  wchar_t wbuf_custom[100];
  mbstowcs(wbuf_custom, buffer_custom, sizeof(buffer_custom));

  assert(wcscmp((wchar_t *)buffer_standard, wbuf_custom) == 0);
}
END_TEST

// Тест 14
START_TEST(test_s21_sprintf_c_char_min_width) {
  char buffer_standard[100];
  char buffer_custom[100];
  char expected = 'B';

  sprintf(buffer_standard, "Char: |%5c|", expected);
  s21_sprintf(buffer_custom, "Char: |%5c|", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 15
START_TEST(test_s21_sprintf_c_wchar_left_align) {
  char buffer_standard[100];
  char buffer_custom[100];
  wchar_t expected = L'Δ';

  swprintf((wchar_t *)buffer_standard, sizeof(buffer_standard),
           L"Wide char: |%-5lc|", expected);
  s21_sprintf(buffer_custom, "Wide char: |%-5lc|", expected);

  wchar_t wbuf_custom[100];
  mbstowcs(wbuf_custom, buffer_custom, sizeof(buffer_custom));

  assert(wcscmp((wchar_t *)buffer_standard, wbuf_custom) == 0);
}
END_TEST

// Тест 16
START_TEST(test_s21_sprintf_c_null_w_char) {
  char buffer_standard[100];
  char buffer_custom[100];
  char expected = '\0';

  sprintf(buffer_standard, "Character%5cCharacter", expected);
  s21_sprintf(buffer_custom, "Character%5cCharacter", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

// Тест 17
START_TEST(test_s21_sprintf_c_null_left_char) {
  char buffer_standard[100];
  char buffer_custom[100];
  char expected = '\0';

  sprintf(buffer_standard, "Character%-5cCharacter", expected);
  s21_sprintf(buffer_custom, "Character%-5cCharacter", expected);

  assert(strcmp(buffer_standard, buffer_custom) == 0);
}
END_TEST

Suite *sprintf_c_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("sprintf_c");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_sprintf_c_basic_char);
  tcase_add_test(tc_core, test_s21_sprintf_c_space_char);
  tcase_add_test(tc_core, test_s21_sprintf_c_digit_char);
  tcase_add_test(tc_core, test_s21_sprintf_c_special_char);
  tcase_add_test(tc_core, test_s21_sprintf_c_unicode_char);
  tcase_add_test(tc_core, test_s21_sprintf_c_null_char);
  tcase_add_test(tc_core, test_s21_sprintf_c_mixed_char);
  tcase_add_test(tc_core, test_s21_sprintf_c_multiple_chars);
  tcase_add_test(tc_core, test_s21_sprintf_c_negative_char);
  // Тесты для %lc
  tcase_add_test(tc_core, test_s21_sprintf_c_basic_wchar);
  tcase_add_test(tc_core, test_s21_sprintf_c_unicode_wchar);
  tcase_add_test(tc_core, test_s21_sprintf_c_multiple_wchars);
  tcase_add_test(tc_core, test_s21_sprintf_c_null_wchar);
  tcase_add_test(tc_core, test_s21_sprintf_c_char_min_width);
  tcase_add_test(tc_core, test_s21_sprintf_c_wchar_left_align);
  tcase_add_test(tc_core, test_s21_sprintf_c_null_w_char);
  tcase_add_test(tc_core, test_s21_sprintf_c_null_left_char);

  suite_add_tcase(s, tc_core);

  return s;
}