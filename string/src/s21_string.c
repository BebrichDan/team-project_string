#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>
#ifdef __APPLE__
#include "s21_errorApple.h"
#else
#include "s21_errorLinux.h"
#endif

void *s21_memchr(const void *str, int c, s21_size_t n) {
  void *result = S21_NULL;
  const unsigned char *str_b = (const unsigned char *)str;
  for (s21_size_t i = 0; i < n; i++) {
    if (str_b[i] == (unsigned char)c) {
      result = (void *)(str_b + i);
      break;
    }
  }
  return result;
}

int s21_memcmp(const void *str_1, const void *str_2, s21_size_t n) {
  int result = 0;
  const unsigned char *str_b_1 = (const unsigned char *)str_1;
  const unsigned char *str_b_2 = (const unsigned char *)str_2;
  for (s21_size_t i = 0; i < n; i++) {
    if (str_b_1[i] != str_b_2[i]) {
      result = str_b_1[i] - str_b_2[i];
      break;
    }
  }
  return result;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned int *dest_four_b = (unsigned int *)dest;
  const unsigned int *src_four_b = (const unsigned int *)src;
  while (n >= sizeof(unsigned int)) {
    *dest_four_b++ = *src_four_b++;
    n -= sizeof(unsigned int);
  }
  unsigned char *dest_one_b = (unsigned char *)dest_four_b;
  const unsigned char *src_one_b = (const unsigned char *)src_four_b;
  while (n > 0) {
    *dest_one_b++ = *src_one_b++;
    n -= sizeof(unsigned char);
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *str_b = (unsigned char *)str;
  unsigned char ch = (unsigned char)c;
  for (s21_size_t i = 0; i < n; i++) {
    str_b[i] = ch;
  }
  return str;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *ptr_dest = dest;
  while (*ptr_dest != '\0') ptr_dest++;
  while (n > 0) {
    *ptr_dest = *src;
    ptr_dest++;
    src++;
    n--;
  }
  *ptr_dest = '\0';
  return dest;
}

char *s21_strchr(const char *str, int c) {
  if (str == S21_NULL) return S21_NULL;

  char *result = S21_NULL;
  s21_size_t len_str = s21_strlen(str);

  if (c == '\0') {
    return (char *)&str[len_str];
  }

  for (s21_size_t i = 0; i < len_str; i++) {
    if (str[i] == c) {
      result = (char *)&str[i];
      return result;
    }
  }
  return S21_NULL;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int res = 0;
  while (n > 0 && *str1 && (*str1 == *str2)) {
    str1++;
    str2++;
    n--;
  }
  if (n > 0) {
    res = (unsigned char)*str1 - (unsigned char)*str2;
  }
  return res;
}

char *s21_strncpy(char *destination, const char *source, size_t num) {
  size_t i = 0;
  while (i < num && source[i] != '\0') {
    destination[i] = source[i];
    i++;
  }
  destination[i] = '\0';

  return destination;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t len = 0;
  while (*str1) {
    const char *temp = str2;
    while (*temp && *temp != *str1) {
      temp++;
    }
    if (*temp) {
      break;
    }
    str1++;
    len++;
  }
  return len;
}

void s21_errnum_tostring(char *str, int num) {  //??
  int i, rem, len = 0, n;
  n = num;
  while (n != 0) {
    len++;
    n /= 10;
  }
  if (num >= 0) {
    for (i = 0; i < len; i++) {
      rem = num % 10;
      num = num / 10;
      str[len - (i + 1)] = rem + '0';
    }
  } else {
    len++;
    str[0] = '-';
    for (i = 0; i < len - 1; i++) {
      rem = num % 10;
      num = num / 10;
      str[len - (i + 1)] = rem + '0';
      if (i == len - 2) {
        str[len - (i + 1)] = (-1 * rem) + '0';
      }
    }
  }
  str[len] = '\0';
}
char *s21_strerror(int errnum) {
  char *ptr = S21_NULL;
  if (errnum >= MAX_ERRLIST || errnum <= MIN_ERRLIST) {
    static char part1[64];
    static char part2[33];
    s21_errnum_tostring(part2, errnum);
    s21_strncpy(part1, ERROR, sizeof(ERROR));
    part1[sizeof(part1) - 1] = '\0';
    s21_strncat(part1, part2, sizeof(part1) - s21_strlen(part1) - 1);
    ptr = part1;
  } else {
    ptr = (char *)maserror[errnum];
  }
  return ptr;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;

  for (int i = 0; str[i] != '\0'; i++) len++;

  return len;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  if (str2 == S21_NULL || *str2 == '\0') {
    return S21_NULL;
  }

  char *result = S21_NULL;
  s21_size_t len_str1 = s21_strlen(str1);
  s21_size_t len_str2 = s21_strlen(str2);

  for (s21_size_t i = 0; i < len_str1; i++) {
    for (s21_size_t j = 0; j < len_str2; j++) {
      if (str1[i] == str2[j]) {
        result = (char *)&str1[i];
        return result;
      }
    }
  }

  return S21_NULL;
}

char *s21_strrchr(const char *str, int c) {
  if (str == S21_NULL) return S21_NULL;

  char *result = S21_NULL;
  s21_size_t len_str = s21_strlen(str);

  if (c == '\0') {
    return (char *)&str[len_str];
  }

  for (int i = len_str - 1; i >= 0; i--) {
    if (str[i] == c) {
      result = (char *)&str[i];
      return result;
    }
  }
  return S21_NULL;
}

char *s21_strstr(const char *haystack, const char *needle) {
  if (*needle == '\0') {
    return (char *)haystack;
  }

  s21_size_t len_str1 = s21_strlen(haystack);
  s21_size_t len_str2 = s21_strlen(needle);

  if (len_str2 > len_str1) {
    return S21_NULL;
  }

  char *result = S21_NULL;

  for (s21_size_t i = 0; i <= len_str1 - len_str2; i++) {
    s21_size_t j;
    for (j = 0; j < len_str2; j++) {
      if (haystack[i + j] != needle[j]) {
        break;
      }
    }

    if (j == len_str2) {
      result = (char *)&haystack[i];
      break;
    }
  }

  return result;
}

char *s21_strtok(char *str, const char *delim) {
  static char *ptr = S21_NULL;
  char *beginning;

  if (str != S21_NULL) {
    ptr = str;
  }

  if (ptr == S21_NULL) {
    return S21_NULL;
  }

  while (*ptr && s21_strchr(delim, *ptr) != S21_NULL) {
    ptr++;
  }

  if (*ptr == '\0') {
    return S21_NULL;
  }

  beginning = ptr;

  while (*ptr && s21_strchr(delim, *ptr) == S21_NULL) {
    ptr++;
  }

  if (*ptr != '\0') {
    *ptr = '\0';
    ptr++;
  }

  return beginning;
}

// C#

void *s21_to_upper(const char *str) {
  s21_size_t str_len = s21_strlen(str);
  char *ptr_to_upper_string = malloc(str_len + 1);
  char *movable_pointer_to_str = ptr_to_upper_string;

  if (movable_pointer_to_str == S21_NULL) return S21_NULL;

  int character_code_difference = 32;

  for (s21_size_t i = 0; i < str_len; i++) {
    if ((int)str[i] >= 97 && (int)str[i] <= 122)
      *(movable_pointer_to_str++) = ((int)str[i]) - character_code_difference;
    else
      *(movable_pointer_to_str++) = str[i];
  }
  *movable_pointer_to_str = '\0';
  return ptr_to_upper_string;
}

void *s21_to_lower(const char *str) {
  s21_size_t str_len = s21_strlen(str);
  char *ptr_to_upper_string = malloc(str_len + 1);
  char *movable_pointer_to_str = ptr_to_upper_string;

  if (movable_pointer_to_str == S21_NULL) return S21_NULL;

  int character_code_difference = 32;

  for (s21_size_t i = 0; i < str_len; i++) {
    if ((int)str[i] >= 65 && (int)str[i] <= 90)
      *(movable_pointer_to_str++) = ((int)str[i]) + character_code_difference;
    else
      *(movable_pointer_to_str++) = str[i];
  }
  *movable_pointer_to_str = '\0';
  return ptr_to_upper_string;
}

void *s21_insert(const char *src, const char *str, size_t start_index) {
  if (src == S21_NULL || str == S21_NULL) return S21_NULL;

  s21_size_t src_len = s21_strlen(src);
  s21_size_t str_len = s21_strlen(str);

  if (start_index > src_len) return S21_NULL;

  char *ptr_new_string = malloc(src_len + str_len + 1);

  s21_strncpy(ptr_new_string, src, start_index);
  s21_strncpy(ptr_new_string + start_index, str, str_len);
  s21_strncpy(ptr_new_string + start_index + str_len, src + start_index,
              src_len - start_index);

  return ptr_new_string;
}

bool is_trim_char(char c, const char *trim_chars) {
  while (*trim_chars != '\0') {
    if (c == *trim_chars) return true;

    trim_chars++;
  }
  return false;
}
void *s21_trim(const char *src, const char *trim_chars) {
  if (src == S21_NULL || trim_chars == S21_NULL) return S21_NULL;

  size_t start_index = 0;

  while (src[start_index] != '\0' && is_trim_char(src[start_index], trim_chars))
    start_index++;

  size_t end_index = s21_strlen(src);

  while (end_index > start_index &&
         is_trim_char(src[end_index - 1], trim_chars))
    end_index--;

  if (start_index == end_index) {
    char *empty_str = malloc(1);

    if (empty_str == S21_NULL) return S21_NULL;

    empty_str[0] = '\0';
    return empty_str;
  }

  size_t len = end_index - start_index;
  char *trimmed_str = malloc(len + 1);
  if (trimmed_str == S21_NULL) return S21_NULL;

  s21_strncpy(trimmed_str, src + start_index, len);

  return trimmed_str;
}
