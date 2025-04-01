#include "s21_string.h"

static void transition_specifier(const char **str_ptr, va_list *args,
                                 int *count, param_spec params, int *result);
static param_spec parse_format(const char **format);
static int is_digit(char c);
static int process_char(const char **str, param_spec params, va_list *args,
                        int *count);
static int process_int(const char **str, param_spec params, va_list *args,
                       int *count);
static int is_hex_digit(char c);
static int char_to_int(char c, int base);
static int process_float(const char **str, param_spec params, va_list *args,
                         int *count);
static int process_hex(const char **str, param_spec params, va_list *args,
                       int *count);
static int process_uint(const char **str, param_spec params, va_list *args,
                        int *count);
static void skip_spaces(const char **str, int *count);
static int process_string(const char **str, param_spec params, va_list *args,
                          int *count);
static void string_suppress_zero(const char **str, param_spec params,
                                 va_list *args, int *count, int *chars_read,
                                 int *res);
static int process_point(const char **str, param_spec params, va_list *args,
                         int *count);
static int hex_to_int(char c);
static int process_symbols(param_spec params, va_list *args, int count);
static int process_percent(const char **str, int *count);
static int is_space(char c);
static int process_oct(const char **str, param_spec params, va_list *args,
                       int *count);
static int char_to_lower(char str);
static int expencion_f(const char *str, const char *str_exp);
static int signature(const char **str, int *sign, int *count);
static int exp_nan_inf(const char **str, long double *value, int *d_count,
                       int *p_count);
static void option_e(const char **str, int *p_count, int width, int d_count,
                     long double *value);
static void step(const char **str, int *d_count, int *p_count);

int s21_sscanf(const char *str, const char *format, ...) {
  if (str == S21_NULL || format == S21_NULL) return -1;
  va_list args;
  va_start(args, format);
  int result = 0;
  const char *str_ptr = str;
  int count = 0;
  while (*format) {
    if (*format == '%') {
      format++;
      if (*format == '\0') break;
      param_spec params = parse_format(&format);
      transition_specifier(&str_ptr, &args, &count, params, &result);
      format++;
    } else if (is_space(*format)) {
      while (is_space(*str_ptr)) {
        str_ptr++;
        count++;
      }
      format++;
    } else {
      if (*str_ptr == '\0' || *format != *str_ptr) break;
      format++;
      str_ptr++;
    }
  }
  va_end(args);
  return result;
}

static void transition_specifier(const char **str_ptr, va_list *args,
                                 int *count, param_spec params, int *result) {
  switch (params.specifier) {
    case 'c':
      *result += process_char(str_ptr, params, args, count);
      break;
    case 'd':
    case 'i':
      *result += process_int(str_ptr, params, args, count);
      break;
    case 'e':
    case 'E':
    case 'f':
    case 'g':
    case 'G':
      *result += process_float(str_ptr, params, args, count);
      break;
    case 'o':
      *result += process_oct(str_ptr, params, args, count);
      break;
    case 'x':
    case 'X':
      *result += process_hex(str_ptr, params, args, count);
      break;
    case 'u':
      *result += process_uint(str_ptr, params, args, count);
      break;
    case 's':
      *result += process_string(str_ptr, params, args, count);
      break;
    case 'p':
      *result += process_point(str_ptr, params, args, count);
      break;
    case 'n':
      *result += process_symbols(params, args, *count);
      break;
    case '%':
      *result += process_percent(str_ptr, count);
      break;
  }
}

static param_spec parse_format(const char **format) {
  param_spec params = {0};
  if (**format == '*') {
    params.suppress = 1;
    (*format)++;
  }
  while (is_digit(**format)) {
    params.width = params.width * 10 + (**format - '0');
    (*format)++;
  }
  switch (**format) {
    case 'h':
      params.length = 1;
      (*format)++;
      break;
    case 'l':
      params.length = 2;
      (*format)++;
      if (**format == 'l') {
        params.length = 4;
        (*format)++;
      }
      break;
    case 'L':
      params.length = 3;
      (*format)++;
      break;
  }
  params.specifier = **format;
  return params;
}

static int is_digit(char c) { return (c >= '0' && c <= '9'); }

static int process_char(const char **str, param_spec params, va_list *args,
                        int *count) {
  if (*str == S21_NULL || **str == '\0') {
    return -1;
  }
  if (!params.suppress) {
    int width = params.width;
    if (params.length == 2) {
      setlocale(LC_CTYPE, "");
      wchar_t *wch_ptr = (wchar_t *)va_arg(*args, wchar_t *);
      do {
        mbstowcs(wch_ptr, *str, 1);
        *wch_ptr++ = *(*str)++;
        (*count)++;
        width--;
      } while (width > 0);
    } else {
      char *ch_ptr = va_arg(*args, char *);
      do {
        *ch_ptr++ = *(*str)++;
        (*count)++;
        width--;
      } while (width > 0);
    }

  } else {
    (*str)++;
    (*count)++;
  }
  return params.suppress ? 0 : 1;
}

static int process_int(const char **str, param_spec params, va_list *args,
                       int *count) {
  long long value = 0;
  int sign = 1;
  int base = 10;
  int flag_width = params.width > 0 ? 1 : 0;
  int digits_read = 0;
  int res = 0;
  while (is_space(**str)) {
    (*str)++;
    (*count)++;
  }
  int number_sign = signature(str, &sign, count);
  if (flag_width) digits_read += number_sign;
  if (params.specifier == 'i' && **str == '0' &&
      (is_digit(*(*str + 1)) || *(*str + 1) == 'x' || *(*str + 1) == 'X')) {
    (*str)++;
    (*count)++;
    digits_read++;
    if (**str == 'x' || **str == 'X') {
      base = 16;
      step(str, &digits_read, count);
    } else {
      base = 8;
    }
  }
  if (**str == '\t' || **str == '\n') {
    (*str)++;
    (*count)++;
  }
  while ((!flag_width || digits_read < params.width) &&
         (base == 16 ? is_hex_digit(**str) : is_digit(**str))) {
    value = value * base + char_to_int(**str, base);
    step(str, &digits_read, count);
  }
  if (!params.suppress && digits_read > 0) {
    if (base == 16 || base == 8) {
      if (value < 0) value = value - 1;
    }
    value *= sign;
    if (params.length == 0)
      *(int *)va_arg(*args, int *) = (int)value;
    else if (params.length == 1)
      *(short *)va_arg(*args, short *) = (short)value;
    else if (params.length == 2)
      *(long *)va_arg(*args, long *) = (long)value;
    else if (params.length == 4)
      *(long long *)va_arg(*args, long long *) = (long long)value;
    res = 1;
  }
  return res;
}

static int is_hex_digit(char c) {
  return (is_digit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'));
}

static int char_to_int(char c, int base) {
  int res = 0;
  if (is_digit(c)) res = (int)c - '0';
  if (base == 16) {
    if (c >= 'a' && c <= 'f') res = (int)c - 'a' + 10;
    if (c >= 'A' && c <= 'F') res = (int)c - 'A' + 10;
  }
  return res;
}

static int process_float(const char **str, param_spec params, va_list *args,
                         int *count) {
  int res = 0, sign = 1, digits_count = 0,
      flag_width = params.width > 0 ? 1 : 0;
  long double value = 0.0L;
  while (is_space(**str)) (*str)++;
  int number_sign = signature(str, &sign, count);
  if (flag_width) digits_count += number_sign;
  if ((char_to_lower(**str) == 'i' || char_to_lower(**str) == 'n') &&
      exp_nan_inf(str, &value, &digits_count, count) == 1) {
  } else {
    while (str && is_digit(**str) &&
           (!params.width || digits_count < params.width)) {
      value = value * 10.0L + (**str - '0');
      step(str, &digits_count, count);
    }
    if (str && **str == '.') {
      step(str, &digits_count, count);
      long double fraction = 0.1L;
      while (is_digit(**str) &&
             (!params.width || digits_count < params.width)) {
        value += (**str - '0') * fraction;
        fraction *= 0.1L;
        step(str, &digits_count, count);
      }
    }
    if (str && (**str == 'e' || **str == 'E') &&
        (!params.width || digits_count < params.width)) {
      option_e(str, count, params.width, digits_count, &value);
    }
  }
  value *= sign;
  if (!params.suppress && digits_count > 0) {
    if (params.length == 0)
      *(float *)va_arg(*args, float *) = (float)value;
    else if (params.length == 2)
      *(double *)va_arg(*args, double *) = (double)value;
    else if (params.length == 3)
      *(long double *)va_arg(*args, long double *) = (long double)value;
    else if (params.length == 4)
      *(long long *)va_arg(*args, long long *) = (long long)value;
    res = 1;
  }
  return res;
}

static int process_oct(const char **str, param_spec params, va_list *args,
                       int *count) {
  unsigned long long value = 0;
  int digits_read = 0;
  int sign = 1;
  int flag_width = params.width > 0 ? 1 : 0;
  while (is_space(**str)) (*str)++;
  int number_sign = signature(str, &sign, count);
  if (flag_width) digits_read += number_sign;
  if (**str == '0' && is_digit(*(*str + 1))) {
    (*str)++;
    digits_read++;
  }
  while ((**str >= '0' && **str <= '7') &&
         (!params.width || digits_read < params.width)) {
    value = (value << 3) | (**str - '0');
    (*str)++;
    digits_read++;
    (*count)++;
  }
  if (!params.suppress && digits_read > 0) {
    value *= sign;
    if (params.length == 0)
      *(unsigned int *)va_arg(*args, unsigned int *) = (unsigned int)value;
    else if (params.length == 1)
      *(unsigned short *)va_arg(*args, unsigned short *) =
          (unsigned short)value;
    else if (params.length == 2)
      *(unsigned long *)va_arg(*args, unsigned long *) = (unsigned long)value;
    else if (params.length == 4)
      *(long long *)va_arg(*args, long long *) = (long long)value;
    return 1;
  }
  return 0;
}

static int process_hex(const char **str, param_spec params, va_list *args,
                       int *count) {
  unsigned long long value = 0;
  int digits_read = 0;
  int sign = 1;
  int base = 16;
  int flag_width = params.width > 0 ? 1 : 0;
  int res = 0;
  while (is_space(**str)) {
    (*str)++;
  }
  int number_sign = signature(str, &sign, count);
  if (flag_width) digits_read += number_sign;
  if (**str == '0' && (*(*str + 1) == 'x' || *(*str + 1) == 'X')) {
    (*str) += 2;
    digits_read += 2;
    (*count) += 2;
  }
  while (is_hex_digit(**str) && (!flag_width || digits_read < params.width)) {
    value = value * base + char_to_int(**str, base);
    (*str)++;
    digits_read++;
    (*count)++;
  }
  if (!params.suppress && digits_read > 0) {
    value *= sign;
    if (params.length == 0)
      *(unsigned int *)va_arg(*args, unsigned int *) = (unsigned int)value;
    else if (params.length == 1)
      *(unsigned short *)va_arg(*args, unsigned short *) =
          (unsigned short)value;
    else if (params.length == 2)
      *(unsigned long *)va_arg(*args, unsigned long *) = (unsigned long)value;
    else if (params.length == 4)
      *(long long *)va_arg(*args, long long *) = (long long)value;
    res = 1;
  }
  return res;
}

static int process_uint(const char **str, param_spec params, va_list *args,
                        int *count) {
  unsigned long long value = 0;
  int digits_read = 0;
  int sign = 1;
  int flag_width = params.width > 0 ? 1 : 0;
  int res = 0;
  while (is_space(**str)) {
    (*str)++;
    (*count)++;
  }
  int number_sign = signature(str, &sign, count);
  if (flag_width) digits_read += number_sign;
  while (is_digit(**str) && (!params.width || digits_read < params.width)) {
    value = value * 10 + (**str - '0');
    (*str)++;
    digits_read++;
    (*count)++;
  }
  if (!params.suppress && digits_read > 0) {
    value *= sign;
    if (params.length == 0)
      *(unsigned int *)va_arg(*args, unsigned int *) = (unsigned int)value;
    else if (params.length == 1)
      *(unsigned short *)va_arg(*args, unsigned short *) =
          (unsigned short)value;
    else if (params.length == 2)
      *(unsigned long *)va_arg(*args, unsigned long *) = (unsigned long)value;
    else if (params.length == 4)
      *(long long *)va_arg(*args, long long *) = (long long)value;
    res = 1;
  }
  return res;
}

static int is_space(char c) { return (c == ' ' || c == '\t' || c == '\n'); }

static void skip_spaces(const char **str, int *count) {
  while (is_space(**str)) {
    (*str)++;
    (*count)++;
  }
}

static int process_string(const char **str, param_spec params, va_list *args,
                          int *count) {
  if (*str == S21_NULL || **str == '\0') return -1;
  int res = 0;
  skip_spaces(str, count);
  int chars_read = 0;
  if (params.suppress == 0) {
    string_suppress_zero(str, params, args, count, &chars_read, &res);
  } else {
    while (str && !is_space(**str) &&
           (!params.width || chars_read < params.width)) {
      (*str)++;
      chars_read++;
      (*count)++;
    }
  }
  return res;
}

static void string_suppress_zero(const char **str, param_spec params,
                                 va_list *args, int *count, int *chars_read,
                                 int *res) {
  if (params.length == 2) {
    setlocale(LC_CTYPE, "");
    wchar_t *wbuffer = va_arg(*args, wchar_t *);
    mbstate_t state = {0};
    while (str && !is_space(**str) &&
           (!params.width || *chars_read < params.width)) {
      s21_size_t result =
          mbrtowc(wbuffer + *chars_read, *str, MB_CUR_MAX, &state);
      if (result == (s21_size_t)-1) {
        *res = 0;
      }
      *str += result;
      (*chars_read)++;
      *count += result;
    }
    if (*chars_read > 0) {
      wbuffer[*chars_read] = L'\0';
      *res = 1;
    }
  } else {
    if (params.suppress) {
      *res = 0;
    } else {
      char *buffer = va_arg(*args, char *);
      while (str && !is_space(**str) &&
             (!params.width || *chars_read < params.width)) {
        buffer[*chars_read] = **str;
        (*str)++;
        (*chars_read)++;
        (*count)++;
      }
      if (*chars_read > 0) {
        buffer[*chars_read] = '\0';
        *res = 1;
      }
    }
  }
}

static int process_point(const char **str, param_spec params, va_list *args,
                         int *count) {
  skip_spaces(str, count);
  unsigned long long value = 0;
  int chars_read = 0;
  if ((*str)[0] == '0' && ((*str)[1] == 'x' || (*str)[1] == 'X')) {
    *str += 2;
  }
  while (str && is_hex_digit(**str) &&
         (!params.width || chars_read < params.width)) {
    value = value * 16 + hex_to_int(**str);
    (*str)++;
    chars_read++;
    (*count)++;
  }
  if (!params.suppress && chars_read > 0) {
    void **ptr = va_arg(*args, void **);
    *ptr = (void *)value;
    return 1;
  }
  return 0;
}

static int hex_to_int(char c) {
  int res = 0;
  if (c >= '0' && c <= '9') {
    res = (int)c - '0';
  }
  if (c >= 'a' && c <= 'f') {
    res = (int)c - 'a' + 10;
  }
  if (c >= 'A' && c <= 'F') {
    res = (int)c - 'A' + 10;
  }
  return res;
}

static int process_symbols(param_spec params, va_list *args, int count) {
  if (!params.suppress) {
    if (params.length == 1) {
      *(short int *)va_arg(*args, short int *) = (short int)count;
    } else if (params.length == 2) {
      *(long int *)va_arg(*args, long int *) = (long int)count;
    } else if (params.length == 3) {
      *(long long int *)va_arg(*args, long long int *) = (long long int)count;
    } else {
      *(int *)va_arg(*args, int *) = (int)count;
    }
  }
  return 0;
}

static int process_percent(const char **str, int *count) {
  skip_spaces(str, count);
  (*count) += s21_strcspn(*str, " \t\n");
  if (**str == '%') {
    (*count)++;
    (*str)++;
  }
  return 0;
}

static int signature(const char **str, int *sign, int *count) {
  int res = 0;
  if (**str == '-') {
    *sign = -1;
    (*str)++;
    (*count)++;
    res = 1;
  } else if (**str == '+') {
    (*str)++;
    (*count)++;
    res = 1;
  }
  return res;
}

static int char_to_lower(char str) {
  if (str >= 'A' && str <= 'Z') {
    str = str + ('a' - 'A');
  }
  return (int)str;
}

static int expencion_f(const char *str, const char *str_exp) {
  int res = 0;
  for (int i = 0; i < 3; i++) {
    char p = char_to_lower(str[i]);
    if (p == str_exp[i]) {
      res++;
    }
  }
  return res == 3 ? 1 : 0;
}

static int exp_nan_inf(const char **str, long double *value, int *d_count,
                       int *p_count) {
  int res = 0;
  if (expencion_f(*str, "nan")) {
    *value = NAN;
    (*str) += 3;
    *d_count += 3;
    *p_count += 3;
    res = 1;
  } else if (expencion_f(*str, "inf")) {
    *value = INFINITY;
    (*str) += 3;
    *d_count += 3;
    *p_count += 3;
    res = 1;
  }
  return res;
}

static void option_e(const char **str, int *p_count, int width, int d_count,
                     long double *value) {
  (*str)++;
  (*p_count)++;
  int exp_sign = 1;
  int exp = 0;
  signature(str, &exp_sign, p_count);
  while (str && is_digit(**str) && (!width || d_count < width)) {
    exp = exp * 10 + (**str - '0');
    (*str)++;
    (*p_count)++;
  }
  *value *= powl(10.0L, exp_sign * exp);
}

static void step(const char **str, int *d_count, int *p_count) {
  (*str)++;
  (*d_count)++;
  (*p_count)++;
}
