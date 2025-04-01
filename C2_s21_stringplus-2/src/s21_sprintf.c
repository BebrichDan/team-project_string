#include "s21_string.h"

#define INT_TO_COUNT(name, type)        \
  int name(type x, int num_sistem) {    \
    int size_num = 1;                   \
    type ucopy = x >= 0 ? x : x * (-1); \
    do {                                \
      size_num++;                       \
      ucopy /= num_sistem;              \
    } while (ucopy > 0);                \
    return size_num;                    \
  }
INT_TO_COUNT(int_to_count, int)
INT_TO_COUNT(lint_to_count, long)

#define INTU_TO_COUNT(name, type)    \
  int name(type x, int num_sistem) { \
    int size_num = 1;                \
    type ucopy = x;                  \
    do {                             \
      size_num++;                    \
      ucopy /= num_sistem;           \
    } while (ucopy > 0);             \
    return size_num;                 \
  }
INTU_TO_COUNT(uint_to_count, unsigned int)
INTU_TO_COUNT(ulint_to_count, unsigned long)

#define INT_TO_STR(name, type)                                         \
  void name(type x, char *buf, int size_num, int num_sistem, int plus, \
            int *sign) {                                               \
    type ucopy = x >= 0 ? x : x * (-1);                                \
    int minus = x >= 0 ? 0 : 1;                                        \
    if (minus) *sign = -1;                                             \
    if (plus) *sign = 1;                                               \
    for (int i = size_num - 2; i >= 0; i--) {                          \
      buf[i] = "0123456789ABCDEF"[ucopy % num_sistem];                 \
      ucopy /= num_sistem;                                             \
    }                                                                  \
    buf[size_num - 1] = '\0';                                          \
  }
INT_TO_STR(int_to_str, int)
INT_TO_STR(lint_to_str, long)

#define INTU_TO_STR(name, type)                                \
  void name(type x, char *buf, int size_num, int num_sistem) { \
    type ucopy = x;                                            \
    for (int i = size_num - 2; i >= 0; i--) {                  \
      buf[i] = "0123456789ABCDEF"[ucopy % num_sistem];         \
      ucopy /= num_sistem;                                     \
    }                                                          \
    buf[size_num - 1] = '\0';                                  \
  }
INTU_TO_STR(uint_to_str, unsigned int)
INTU_TO_STR(ulint_to_str, unsigned long)

#define OPTION_G(name, type)                         \
  static int name(type arg) __attribute__((unused)); \
  static int name(type arg) {                        \
    int res = 0;                                     \
    if (arg < 1.0) {                                 \
      while (arg < 1.0) {                            \
        arg *= 10.0;                                 \
        if (arg < 1.0) res++;                        \
      }                                              \
    } else if (arg > 1.0) {                          \
      while (arg > 1.0) {                            \
        arg /= 10.0;                                 \
        res--;                                       \
      }                                              \
    }                                                \
    return res;                                      \
  }
OPTION_G(option_g, double)
OPTION_G(option_lg, long double)

// функция записи обработоной строки
static int save_str(char *str, va_list *args, const char *format);
// функция записи структуры с символами и значениями спецификации
static Specification save_specifier(const char **format, const char *pred_width,
                                    const char *pred_accuracy);
// воспомогательные функции для записи структуры спецификации
static int check_sp_ch(const char **format, char *sp, char *sps);
static int check_sp_flags(const char **format, struct Flags *flag);
static int bool_flags(const char format);
static int check_sp_int(const char **format, char *sp, char *sps);
// проверяет спецификатор и приводит тип в соответствие с спецификатором
static int initialization_arg(Specification specification, char **str,
                              va_list *args);
// функции обработки спецификаторов
static int specifier_c(Specification specification, char **str, va_list *args);
static int specifier_d_i(Specification specification, char **str,
                         va_list *args);
static int specifier_f_e_E(Specification specification, char **str,
                           va_list *args);
static int specifier_g_G(Specification specification, char **str,
                         va_list *args);
static int specifier_o(Specification specification, char **str, va_list *args);
static int specifier_s(Specification specification, char **str, va_list *args);
static int specifier_u(Specification specification, char **str, va_list *args);
static int specifier_x_X(Specification specification, char **str,
                         va_list *args);
static int specifier_p(Specification specification, char **str, va_list *args);
// функции для работы с дополнительными флагами спецификатора
static int option_diouxX(int size_n, Specification specification, char **str,
                         const char *num_str, int sign);
static int save_number_dioxX(Specification specification, va_list *args,
                             int *size_n, int size_sistem, char **num_str,
                             int *sign);
static int save_number_u(Specification specification, va_list *args,
                         int *size_n, int size_sistem, char **num_str,
                         int *plus);
static int save_number_d_feE(Specification specification, va_list *args,
                             char **num_str, int *sign);
static int save_number_ld_feE(Specification specification, va_list *args,
                              char **num_str, int *sign);
static int save_number_d_gG(Specification specification, va_list *args,
                            char **num_str, int *sign, int *flag);
static int save_number_ld_gG(Specification specification, va_list *args,
                             char **num_str, int *sign, int *flag);
static int option_feEgG(Specification specification, char **str, char *num_str,
                        int sign, int flag);
// воспомогательные функции для работы с преобразованием спецификации в текст
static int count_n(char *str, const char *str_spec);
static void copy_str(char *str, const char *pred_str, int n);
static void copy_spec(char *str, const char *str_spec);
static void copy_str_sp(char **str, const char *str_spec);
static int len_str(char *str);
static int str_to_int(char *str);
static void width_ch(struct Flags flag, char **str, int space);
static void accurary_ch(char **str, int space);
static int string_to_lower(char *str);
static void option_together_f_e_E_g_G(char *num_str, const char *int_str,
                                      const char *float_str, int size_float,
                                      const char *exp, char specifer, int flag,
                                      int hash);
static int double_to_int(char **int_str, long arg_i, int size_sistem, int plus,
                         int *size_n, int *sign);
static void double_to_exponential(double *num, char *buffer);
static void ldouble_to_exponential(long double *num, char *buffer);
static int dinamic_data(char **data, int size);
static void double_to_str(double x, char *buf, int size_float);
static void ldouble_to_str(long double x, char *buf, int size_float);
static long double ldouble_to_round(long double x, int size_float);
static double double_to_round(double x, int size_float);
static void double_gG_to_str(double x, char *buf, int size_float);
static void ldouble_gG_to_str(long double x, char *buf, int size_float);
static void signature(int sign, char **str);
static int exception_feEgG(double arg, int *sign, char **str, int flag);
static int exception_lfeEgG(long double arg, int *sign, char **str, int flag);
static void exception_c(char **str, char *str_spec);

int s21_sprintf(char *str, const char *format, ...) {
  int result = 0;
  va_list args;
  va_start(args, format);
  result = save_str(str, &args, format);
  va_end(args);
  return result;
}

static int save_str(char *str, va_list *args, const char *format) {
  int res = 0;
  char *res_str = str;
  char width[SIZE_NUM] = {'\0'};
  char accuracy[SIZE_NUM] = {'\0'};
  // int res = 0;
  while (*format != '\0') {
    if (*format == '%') {
      ++format;
      if (*format == '%') {
        *str++ = *format++;
      } else if (*format == 'n') {
        int *n_ptr = va_arg(*args, int *);
        *n_ptr = count_n(res_str, str);
        ++format;
      } else {
        Specification specification = save_specifier(&format, width, accuracy);
        copy_str(width, specification.width, SIZE_NUM);
        copy_str(accuracy, specification.accuracy, SIZE_NUM);
        if (specification.specifer != '\0') {
          char *str_spec = S21_NULL;
          res += initialization_arg(specification, &str_spec, args);
          copy_str_sp(&str, str_spec);
          if (specification.specifer == 'c') exception_c(&str, str_spec);
          free(str_spec);
        }
      }
    } else {
      *str++ = *format++;
    }
  }
  *str = '\0';
  if (res == 0)
    res = count_n(res_str, str);
  else
    res = -1;
  return res;
}

static Specification save_specifier(
    const char **format, const char *pred_width,
    const char *pred_accuracy) {  // записывает struct
  Specification specification = {'\0'};
  char point = '\0';
  int flag = 0;
  while (!check_sp_ch(format, &specification.specifer, SPECIFIERS)) {
    int res;
    if (!flag && check_sp_flags(format, &specification.flag) >= 1) {
    } else if (point == '\0' &&
               (res = check_sp_int(format, specification.width, FIGURE)) >= 1) {
      if (res == 2) copy_str(specification.width, pred_width, SIZE_NUM);
    } else if (**format == '.') {
      point = *(*format)++;
    } else if (point == '.' && !specification.flag.accuracy &&
               specification.accuracy[0] == '\0') {
      if (**format == '0') specification.flag.accuracy = true;
      if ((res = check_sp_int(format, specification.accuracy, FIGURE)) >= 1) {
        if (res == 2) copy_str(specification.accuracy, pred_accuracy, SIZE_NUM);
      }
    } else if ((check_sp_ch(format, &specification.length, LENGTH_S)) == 1) {
    } else {
      break;
    }
    flag = 1;
  }
  return specification;
}

static int check_sp_ch(const char **format, char *sp, char *sps) {
  int result = 0;
  for (int i = 0; i < len_str(sps); i++) {
    if (sps[i] == **format) {
      result = 1;
      *sp = *(*format)++;
      break;
    }
  }
  return result;
}

static int check_sp_flags(const char **format, struct Flags *flag) {
  int result = 0;
  while (bool_flags(**format)) {
    if (**format == '-') {
      (*flag).minus = true;
      result++;
      (*format)++;
    } else if (**format == '+') {
      (*flag).plus = true;
      result++;
      (*format)++;
    } else if (**format == ' ') {
      (*flag).space = true;
      result++;
      (*format)++;
    } else if (**format == '#') {
      (*flag).hash = true;
      result++;
      (*format)++;
    } else if (**format == '0') {
      (*flag).zero = true;
      result++;
      (*format)++;
    }
  }
  return result;
}

static int bool_flags(const char format) {
  int result = 0;
  for (int i = 0; i < len_str(FLAGS); i++) {
    if (FLAGS[i] == format) {
      result = 1;
      break;
    }
  }
  return result;
}

static int check_sp_int(const char **format, char *sp, char *sps) {
  int result = 0;
  if (**format == '*') {
    (*format)++;
    result = 2;
  } else {
    int size_n = SIZE_NUM;
    while (check_sp_ch(format, sp, sps) && size_n != 0) {
      sp++;
      size_n--;
      result = 1;
    }
  }
  return result;
}

static int initialization_arg(Specification specification, char **str,
                              va_list *args) {
  int res = 0;
  char spec = specification.specifer;
  if (spec == 'c')
    res = specifier_c(specification, str, args);
  else if (spec == 'd' || spec == 'i')
    res = specifier_d_i(specification, str, args);
  else if (spec == 'E' || spec == 'f' || spec == 'e')
    res = specifier_f_e_E(specification, str, args);
  else if (spec == 'g' || spec == 'G')
    res = specifier_g_G(specification, str, args);
  else if (spec == 'o')
    res = specifier_o(specification, str, args);
  else if (spec == 's')
    res = specifier_s(specification, str, args);
  else if (spec == 'u')
    res = specifier_u(specification, str, args);
  else if (spec == 'x' || spec == 'X')
    res = specifier_x_X(specification, str, args);
  else if (spec == 'p')
    res = specifier_p(specification, str, args);
  return res;
}

static int specifier_c(Specification specification, char **str, va_list *args) {
  int res = 0;
  int size = 2;
  char *ch_str = S21_NULL;
  char *res_str = S21_NULL;
  int count_width = str_to_int(specification.width) - 1;
  if (count_width < 0) count_width = 0;
  if (specification.length == '\0') {
    res = dinamic_data(&ch_str, size);
    ch_str[0] = (char)va_arg(*args, int);
    ch_str[1] = '\0';
  } else if (specification.length == 'l') {
    setlocale(LC_CTYPE, "");
    wchar_t wch = (wchar_t)va_arg(*args, wchar_t);
    char mbstr[MB_CUR_MAX + 1];
    size = wctomb(mbstr, wch);
    if (size == -1) {
      ch_str = S21_NULL;
      res = -1;
    }
    dinamic_data(&ch_str, size + 1);
    if (wctomb(ch_str, wch) == -1) {
      ch_str = S21_NULL;
      res = -1;
    }
    if (ch_str != S21_NULL) ch_str[size] = '\0';
  }
  dinamic_data(&res_str, size + count_width + 1);
  *str = res_str;
  if (!specification.flag.minus)
    width_ch(specification.flag, &res_str, count_width);
  if (ch_str[0] != '\0') {
    copy_str_sp(&res_str, ch_str);
    if (specification.flag.minus)
      width_ch(specification.flag, &res_str, count_width);
  }
  *res_str = '\0';
  free(ch_str);
  return res;
}

static int specifier_d_i(Specification specification, char **str,
                         va_list *args) {
  int res;
  int size_n = 0;
  int size_sistem = 10;
  char *num_str = S21_NULL;
  int sign = 0;
  res = save_number_dioxX(specification, args, &size_n, size_sistem, &num_str,
                          &sign);
  res =
      res != 0 ? res : option_diouxX(size_n, specification, str, num_str, sign);
  free(num_str);
  return res;
}

static int specifier_f_e_E(Specification specification, char **str,
                           va_list *args) {
  int res;
  char *num_str = S21_NULL;
  int sign = 0;
  if (specification.length != 'L')
    res = save_number_d_feE(specification, args, &num_str, &sign);
  else
    res = save_number_ld_feE(specification, args, &num_str, &sign);
  res = res != 0 ? res : option_feEgG(specification, str, num_str, sign, 0);
  free(num_str);
  return res;
}

static int specifier_g_G(Specification specification, char **str,
                         va_list *args) {
  int res;
  int flag = 0;
  char *num_str = S21_NULL;
  int sign = 0;
  if (specification.length != 'L')
    res = save_number_d_gG(specification, args, &num_str, &sign, &flag);
  else
    res = save_number_ld_gG(specification, args, &num_str, &sign, &flag);
  res = res != 0 ? res : option_feEgG(specification, str, num_str, sign, flag);
  free(num_str);
  return res;
}

static int specifier_o(Specification specification, char **str, va_list *args) {
  int res;
  int size_n = 0;
  int size_sistem = 8;
  char *num_str = S21_NULL;
  int sign = 0;
  res = save_number_dioxX(specification, args, &size_n, size_sistem, &num_str,
                          &sign);
  res =
      res != 0 ? res : option_diouxX(size_n, specification, str, num_str, sign);
  free(num_str);
  return res;
}

static int specifier_s(Specification specification, char **str, va_list *args) {
  int result;
  char *str_width = S21_NULL;
  char *res_str = S21_NULL;
  int count_accuracy = str_to_int(specification.accuracy);
  int size = 0;
  if (specification.length != 'l') {
    char *val = (char *)va_arg(*args, char *);
    if (specification.accuracy[0] == '\0' && !specification.flag.accuracy)
      size = len_str(val) + 1;
    else
      size = count_accuracy + 1;
    result = dinamic_data(&str_width, size);
    copy_str(str_width, val, size - 1);
  } else {
    setlocale(LC_CTYPE, "");
    const wchar_t *wch = (wchar_t *)va_arg(*args, wchar_t *);
    if (specification.accuracy[0] == '\0' && !specification.flag.accuracy)
      size = (int)((wcslen(wch) + 1) * MB_CUR_MAX);
    else
      size = count_accuracy + 1;
    result = dinamic_data(&str_width, size);
    if (wcstombs(str_width, wch, size + 1) == (size_t)-1) {
      str_width = S21_NULL;
      result = -1;
    }
  }
  int count_width = str_to_int(specification.width) - (size - 1);
  if (count_width < 0) count_width = 0;
  result =
      result != 0 ? result : dinamic_data(&res_str, size + count_width + 2);
  *str = res_str;
  if (!specification.flag.minus)
    width_ch(specification.flag, &res_str, count_width);
  copy_str_sp(&res_str, str_width);
  if (specification.flag.minus)
    width_ch(specification.flag, &res_str, count_width);
  *res_str = '\0';
  free(str_width);
  return result;
}

static int specifier_u(Specification specification, char **str, va_list *args) {
  int res;
  int size_n = 0;
  int size_sistem = 10;
  char *num_str = S21_NULL;
  int sign = 0;
  res =
      save_number_u(specification, args, &size_n, size_sistem, &num_str, &sign);
  res =
      res != 0 ? res : option_diouxX(size_n, specification, str, num_str, sign);
  free(num_str);
  return res;
}

static int specifier_x_X(Specification specification, char **str,
                         va_list *args) {
  int res;
  int size_n = 0;
  int size_sistem = 16;
  char *num_str = S21_NULL;
  int sign = 0;
  res = save_number_dioxX(specification, args, &size_n, size_sistem, &num_str,
                          &sign);
  if (specification.specifer == 'x')
    res = res != 0 ? res : string_to_lower(num_str);
  res =
      res != 0 ? res : option_diouxX(size_n, specification, str, num_str, sign);
  free(num_str);
  return res;
}

static int specifier_p(Specification specification, char **str, va_list *args) {
  int result;
  int size = 0;
  int size_sistem = 16;
  char *sistem = "0x";
  char *num = S21_NULL;
  char *res_str = S21_NULL;
  void *p = (void *)va_arg(*args, void *);
  size_t address = (size_t)p;
  size = ulint_to_count(address, size_sistem);
  result = dinamic_data(&num, size);
  ulint_to_str(address, num, size, size_sistem);
  result = result != 0 ? result : string_to_lower(num);
  int count_width =
      str_to_int(specification.width) - (size + len_str(sistem) - 1);
  if (count_width < 0) count_width = 0;
  result = result != 0
               ? result
               : dinamic_data(&res_str, size + len_str(sistem) + count_width);
  *str = res_str;
  if (!specification.flag.minus)
    width_ch(specification.flag, &res_str, count_width);
  copy_str_sp(&res_str, sistem);
  copy_str_sp(&res_str, num);
  if (specification.flag.minus)
    width_ch(specification.flag, &res_str, count_width);
  *res_str++ = '\0';
  free(num);
  return result;
}

static int option_diouxX(int size_n, Specification specification, char **str,
                         const char *num_str, int sign) {
  int res;
  char *res_str = S21_NULL;
  int count_width = str_to_int(specification.width);
  int count_accurary = str_to_int(specification.accuracy) - (size_n - 1);
  int size_hash = 0;
  int usign = sign >= 0 ? sign : -sign;
  if (specification.flag.hash) {
    if (specification.specifer == 'o') size_hash++;
    if (specification.specifer == 'x' || specification.specifer == 'X')
      size_hash += 2;
  }
  if (count_accurary < 0) count_accurary = 0;
  count_width -= (size_n + count_accurary + size_hash);
  if (sign == 0) count_width++;
  if (count_width < 0) count_width = 0;

  res = dinamic_data(&res_str, size_n + count_width + count_accurary + usign +
                                   specification.flag.space + size_hash);
  *str = res_str;
  if (specification.flag.space) *res_str++ = ' ';
  if (!specification.flag.minus) {
    if (specification.flag.zero) signature(sign, &res_str);
    width_ch(specification.flag, &res_str, count_width);
  }
  if ((specification.specifer == 'o' || specification.specifer == 'x' ||
       specification.specifer == 'X') &&
      specification.flag.hash) {
    *res_str++ = '0';
    if (specification.specifer == 'x')
      *res_str++ = 'x';
    else if (specification.specifer == 'X')
      *res_str++ = 'X';
  }
  if (!specification.flag.zero) signature(sign, &res_str);
  accurary_ch(&res_str, count_accurary);
  copy_str_sp(&res_str, num_str);
  if (specification.flag.minus)
    width_ch(specification.flag, &res_str, count_width);
  *res_str = '\0';
  return res;
}

static int save_number_dioxX(Specification specification, va_list *args,
                             int *size_n, int size_sistem, char **num_str,
                             int *sign) {
  int res;
  int plus = 0;
  if (specification.length != 'l') {
    int arg = va_arg(*args, int);
    if (arg > 0 && specification.flag.plus) plus = 1;
    *size_n = int_to_count(arg, size_sistem);
    res = dinamic_data(num_str, *size_n + specification.flag.plus);
    int_to_str(arg, *num_str, *size_n, size_sistem, plus, sign);
  } else {
    long arg = va_arg(*args, long);
    if (arg > 0 && specification.flag.plus) plus = 1;
    *size_n = lint_to_count(arg, size_sistem);
    res = dinamic_data(num_str, *size_n + specification.flag.plus);
    lint_to_str(arg, *num_str, *size_n, size_sistem, plus, sign);
  }
  return res;
}

static int save_number_u(Specification specification, va_list *args,
                         int *size_n, int size_sistem, char **num_str,
                         int *plus) {
  int res;
  if (specification.length != 'l') {
    unsigned int arg = va_arg(*args, unsigned int);
    if (arg > 0 && specification.flag.plus) *plus = 1;
    *size_n = uint_to_count(arg, size_sistem);
    res = dinamic_data(num_str, *size_n);
    uint_to_str(arg, *num_str, *size_n, size_sistem);
  } else {
    unsigned long arg = va_arg(*args, unsigned long);
    if (arg > 0 && specification.flag.plus) *plus = 1;
    *size_n = ulint_to_count(arg, size_sistem);
    res = dinamic_data(num_str, *size_n);
    ulint_to_str(arg, *num_str, *size_n, size_sistem);
  }
  return res;
}

static int save_number_d_feE(Specification specification, va_list *args,
                             char **num_str, int *sign) {
  int res;
  double arg = va_arg(*args, double);
  if (isnan(arg) || isinf(arg)) {
    res = exception_feEgG(arg, sign, num_str, specification.flag.plus);
  } else {
    int plus = 0, size_float = 6, size_exp = 4, size_sistem = 10, size_n = 0;
    char *int_str, *float_str, *exp = S21_NULL;
    res = dinamic_data(&exp, size_exp);
    if (specification.flag.accuracy || specification.accuracy[0] != '\0')
      size_float = str_to_int(specification.accuracy);
    if (specification.specifer == 'e' || specification.specifer == 'E') {
      arg = double_to_round(arg, size_float);
      double_to_exponential(&arg, exp);
    }
    arg = double_to_round(arg, size_float);
    long arg_i = (long)arg;
    if (arg > 0.0 && specification.flag.plus) plus = 1;
    double_to_int(&int_str, arg_i, size_sistem, plus, &size_n, sign);
    double arg_f = arg - (double)arg_i;
    if (arg_f < 0.0) arg_f = -arg_f;
    res = res != 0 ? res : dinamic_data(&float_str, size_float + 1);
    double_to_str(arg_f, float_str, size_float);
    res = res != 0 ? res
                   : dinamic_data(num_str,
                                  size_n + plus + size_float + size_exp + 3);
    if (res == 0)
      option_together_f_e_E_g_G(*num_str, int_str, float_str, size_float, exp,
                                specification.specifer, 0,
                                specification.flag.hash);
    free(int_str);
    free(float_str);
    free(exp);
  }
  return res;
}

static int save_number_ld_feE(Specification specification, va_list *args,
                              char **num_str, int *sign) {
  int res;
  long double arg = va_arg(*args, long double);
  if (isnan(arg) || isinf(arg)) {
    res = exception_lfeEgG(arg, sign, num_str, specification.flag.plus);
  } else {
    int plus = 0, size_float = 6, size_exp = 4, size_sistem = 10, size_n = 0;
    char *int_str, *float_str, *exp = S21_NULL;
    res = dinamic_data(&exp, size_exp);
    if (specification.flag.accuracy || specification.accuracy[0] != '\0')
      size_float = str_to_int(specification.accuracy);
    if (specification.specifer == 'e' || specification.specifer == 'E') {
      arg = ldouble_to_round(arg, size_float);
      ldouble_to_exponential(&arg, exp);
    }
    arg = ldouble_to_round(arg, size_float);
    long arg_i = (long)arg;
    if (arg > 0.0 && specification.flag.plus) plus = 1;
    double_to_int(&int_str, arg_i, size_sistem, plus, &size_n, sign);
    long double arg_f = arg - (long double)arg_i;
    if (arg_f < 0.0) arg_f = -arg_f;
    res = res != 0 ? res : dinamic_data(&float_str, size_float + 1);
    ldouble_to_str(arg_f, float_str, size_float);
    res = res != 0 ? res
                   : dinamic_data(num_str,
                                  size_n + plus + size_float + size_exp + 3);
    if (res == 0)
      option_together_f_e_E_g_G(*num_str, int_str, float_str, size_float, exp,
                                specification.specifer, 0,
                                specification.flag.hash);
    free(int_str);
    free(float_str);
    free(exp);
  }
  return res;
}

static int save_number_d_gG(Specification specification, va_list *args,
                            char **num_str, int *sign, int *flag) {
  int res;
  double arg = va_arg(*args, double);
  if (isnan(arg) || isinf(arg)) {
    res = exception_feEgG(arg, sign, num_str, specification.flag.plus);
  } else {
    int plus = 0, size_float = 1, size_exp = 4, size_sistem = 10, size_n = 0;
    char *int_str, *float_str, *exp = S21_NULL;
    if (arg > 0.0 && specification.flag.plus) plus = 1;
    res = dinamic_data(&exp, size_exp);
    if (specification.accuracy[0] != '\0')
      size_float = str_to_int(specification.accuracy);
    double arg_unsig = arg;
    if (arg < 0.0) arg_unsig = -arg_unsig;
    int count_f = specification.accuracy[0] != '\0' ? size_float : 0;
    if ((-option_g(arg_unsig) + count_f) > 6 && count_f < 6) {
      arg = double_to_round(arg, size_float);
      double_to_exponential(&arg, exp);
      arg_unsig = arg;
      if (arg < 0.0) arg_unsig = -arg_unsig;
      (*flag)++;
    }
    if (specification.accuracy[0] == '\0') size_float = 6;
    size_float += option_g(arg_unsig);
    if (size_float < 0) size_float = 0;
    arg = double_to_round(arg, size_float);
    long arg_i = (long)arg;
    res = res != 0 ? res
                   : double_to_int(&int_str, arg_i, size_sistem, plus, &size_n,
                                   sign);
    double arg_f = arg - (double)arg_i;
    if (arg_f < 0.0) arg_f = -arg_f;
    res = res != 0 ? res : dinamic_data(&float_str, size_float + 1);
    if (specification.flag.hash)
      double_to_str(arg_f, float_str, size_float);
    else
      double_gG_to_str(arg_f, float_str, size_float);
    res = res != 0 ? res
                   : dinamic_data(num_str,
                                  size_n + plus + size_float + size_exp + 3);
    if (res == 0)
      option_together_f_e_E_g_G(*num_str, int_str, float_str, size_float, exp,
                                specification.specifer, *flag,
                                specification.flag.hash);
    free(int_str);
    free(float_str);
    free(exp);
  }
  return res;
}

static int save_number_ld_gG(Specification specification, va_list *args,
                             char **num_str, int *sign, int *flag) {
  int res;
  long double arg = va_arg(*args, long double);
  if (isnan(arg) || isinf(arg)) {
    res = exception_lfeEgG(arg, sign, num_str, specification.flag.plus);
  } else {
    int plus = 0, size_float = 1, size_exp = 4, size_sistem = 10, size_n = 0;
    char *int_str, *float_str, *exp = S21_NULL;
    if (arg > 0.0 && specification.flag.plus) plus = 1;
    res = dinamic_data(&exp, size_exp);
    if (specification.accuracy[0] != '\0')
      size_float = str_to_int(specification.accuracy);
    long double arg_unsig = arg;
    if (arg < 0.0) arg_unsig = -arg_unsig;
    int count_f = specification.accuracy[0] != '\0' ? size_float : 0;
    if ((-option_lg(arg_unsig) + count_f) > 6 && count_f < 6) {
      arg = ldouble_to_round(arg, size_float);
      ldouble_to_exponential(&arg, exp);
      arg_unsig = arg;
      if (arg < 0.0) arg_unsig = -arg_unsig;
      (*flag)++;
    }
    if (specification.accuracy[0] == '\0') size_float = 6;
    size_float += option_lg(arg_unsig);
    if (size_float < 0) size_float = 0;
    arg = ldouble_to_round(arg, size_float);
    long arg_i = (long)arg;
    res = res != 0 ? res
                   : double_to_int(&int_str, arg_i, size_sistem, plus, &size_n,
                                   sign);
    long double arg_f = arg - (long double)arg_i;
    if (arg_f < 0.0) arg_f = -arg_f;
    res = res != 0 ? res : dinamic_data(&float_str, size_float + 1);
    if (specification.flag.hash)
      ldouble_to_str(arg_f, float_str, size_float);
    else
      ldouble_gG_to_str(arg_f, float_str, size_float);
    res = res != 0 ? res
                   : dinamic_data(num_str,
                                  size_n + plus + size_float + size_exp + 3);
    if (res == 0)
      option_together_f_e_E_g_G(*num_str, int_str, float_str, size_float, exp,
                                specification.specifer, *flag,
                                specification.flag.hash);
    free(int_str);
    free(float_str);
    free(exp);
  }
  return res;
}

static int dinamic_data(char **data, int size) {
  int res = 0;
  *data = (char *)malloc(size * sizeof(char));
  if (*data == S21_NULL) {
    res = -1;
  }
  return res;
}

static void option_together_f_e_E_g_G(char *num_str, const char *int_str,
                                      const char *float_str, int size_float,
                                      const char *exp, char specifer, int flag,
                                      int hash) {
  copy_str_sp(&num_str, int_str);
  if (size_float || hash) {
    *num_str++ = '.';
    copy_str_sp(&num_str, float_str);
  }
  if (specifer == 'e' || (specifer == 'g' && flag))
    *num_str++ = 'e';
  else if (specifer == 'E' || (specifer == 'G' && flag))
    *num_str++ = 'E';
  if ((specifer == 'e' || specifer == 'E') ||
      ((specifer == 'g' || specifer == 'G') && flag))
    copy_str_sp(&num_str, exp);
  *num_str = '\0';
}

static int option_feEgG(Specification specification, char **str, char *num_str,
                        int sign, int flag) {
  int res;
  char *res_str = S21_NULL;
  int usign = sign >= 0 ? sign : -sign;
  int count_width = str_to_int(specification.width);
  count_width -= (len_str(num_str) + 1);
  if (sign == 0) count_width++;
  if (count_width < 0) count_width = 0;
  res = dinamic_data(&res_str, len_str(num_str) + count_width + usign +
                                   specification.flag.space + 1);
  *str = res_str;
  if (specification.flag.space) {
    if (specification.specifer == 'g' || specification.specifer == 'G') {
      if (!flag)
        *res_str++ = ' ';
      else if (count_width > 0)
        *res_str++ = ' ';
    } else {
      *res_str++ = ' ';
    }
  }
  if (!specification.flag.minus) {
    if (specification.flag.zero) signature(sign, &res_str);
    width_ch(specification.flag, &res_str, count_width);
  }
  if (!specification.flag.zero) signature(sign, &res_str);
  copy_str_sp(&res_str, num_str);
  if (specification.flag.minus)
    width_ch(specification.flag, &res_str, count_width);
  *res_str = '\0';
  return res;
}

static int count_n(char *str, const char *str_spec) {
  int count = 0;
  while (str != str_spec) {
    str++;
    count++;
  }
  return count;
}

static int double_to_int(char **int_str, long arg_i, int size_sistem, int plus,
                         int *size_n, int *sign) {
  int res;
  *size_n = lint_to_count(arg_i, size_sistem);
  res = dinamic_data(int_str, *size_n + plus);
  lint_to_str(arg_i, *int_str, *size_n, size_sistem, plus, sign);
  return res;
}

static void copy_str(char *str, const char *pred_str, int n) {
  for (int i = 0; i < n; i++) {
    str[i] = pred_str[i];
    if (pred_str[i] == '\0') break;
    if (i == n - 1) str[n] = '\0';
  }
}

static void copy_spec(char *str, const char *str_spec) {
  while (*str_spec != '\0') {
    *str++ = *str_spec++;
  }
}

static void copy_str_sp(char **str, const char *str_spec) {
  while (*str_spec != '\0') {
    *(*str)++ = *str_spec++;
  }
}

static int len_str(char *str) {
  int res = 0;
  do {
    res++;
    str++;
  } while (*str != '\0');
  return res;
}

static int str_to_int(char *str) {
  int result = 0;
  int sign = 1;
  if (*str != '\0') {
    if (*str == '-') {
      sign = -1;
      str++;
    }
    while (*str >= '0' && *str <= '9') {
      result = result * 10 + (*str - '0');
      str++;
    }
  }
  return result * sign;
}

static void width_ch(struct Flags flag, char **str, int space) {
  char ch = ' ';
  if (flag.zero) ch = '0';
  if (flag.space) space--;
  while (space > 0) {
    **str = ch;
    (*str)++;
    space--;
  }
}

static void accurary_ch(char **str, int space) {
  while (space > 0) {
    **str = '0';
    (*str)++;
    space--;
  }
}

static int string_to_lower(char *str) {
  int res = 0;
  if (str == S21_NULL) {
    res = -1;
  }

  while (str != S21_NULL && *str != '\0') {
    if (*str >= 'A' && *str <= 'F') {
      *str = *str + ('a' - 'A');
    }
    str++;
  }
  return res;
}

static void double_to_exponential(double *num, char *buffer) {
  char exp[] = "+00";
  double p_num = *num;
  int sign_int = 0;
  if (*num < 0.0) p_num = -p_num;
  int exponent = 0;
  while (p_num >= 10.0) {
    p_num /= 10.0;
    exponent++;
  }
  while (p_num < 1.0) {
    p_num *= 10.0;
    exponent--;
  }
  char sign = (exponent < 0) ? '-' : '+';
  exp[0] = sign;
  exponent = (exponent < 0) ? -exponent : exponent;
  if (exponent < 10) {
    exp[1] = '0';
    char num_str[2];
    int_to_str(exponent, num_str, 2, 10, false, &sign_int);
    exp[2] = num_str[0];
  } else {
    char num_str[3];
    int_to_str(exponent, num_str, 3, 10, false, &sign_int);
    exp[1] = num_str[0];
    exp[2] = num_str[1];
  }
  if (*num < 0)
    *num = -p_num;
  else
    *num = p_num;
  exp[3] = '\0';
  copy_spec(buffer, exp);
  buffer[3] = '\0';
}

static void ldouble_to_exponential(long double *num, char *buffer) {
  char exp[] = "+00";
  long double p_num = *num;
  int sign_int = 0;
  if (*num < 0.0) p_num = -p_num;
  int exponent = 0;
  while (p_num >= 10.0) {
    p_num /= 10.0;
    exponent++;
  }
  while (p_num < 1.0) {
    p_num *= 10.0;
    exponent--;
  }
  char sign = (exponent < 0) ? '-' : '+';
  exp[0] = sign;
  exponent = (exponent < 0) ? -exponent : exponent;
  if (exponent < 10) {
    exp[1] = '0';
    char num_str[2];
    int_to_str(exponent, num_str, 2, 10, false, &sign_int);
    exp[2] = num_str[0];
  } else {
    char num_str[3];
    int_to_str(exponent, num_str, 3, 10, false, &sign_int);
    exp[1] = num_str[0];
    exp[2] = num_str[1];
  }
  if (*num < 0)
    *num = -p_num;
  else
    *num = p_num;
  exp[3] = '\0';
  copy_spec(buffer, exp);
  buffer[3] = '\0';
}

static double double_to_round(double x, int size_float) {
  double factor = pow(10, size_float);
  return round(x * factor) / factor;
}

static long double ldouble_to_round(long double x, int size_float) {
  double factor = pow(10, size_float);
  return roundl(x * factor) / factor;
}

static void double_to_str(double x, char *buf, int size_float) {
  double factor = pow(10, size_float);
  double value = round(x * factor);
  for (int i = size_float - 1; i >= 0; i--) {
    buf[i] = "0123456789"[(unsigned long long)value % 10];
    value /= 10;
  }
  buf[size_float] = '\0';
}

static void ldouble_to_str(long double x, char *buf, int size_float) {
  double factor = pow(10, size_float);
  long double value = roundl(x * factor);
  for (int i = size_float - 1; i >= 0; i--) {
    buf[i] = "0123456789"[(unsigned long long)value % 10];
    value /= 10;
  }
  buf[size_float] = '\0';
}

static void double_gG_to_str(double x, char *buf, int size_float) {
  double factor = pow(10, size_float);
  double value = round(x * factor);
  buf[size_float] = '\0';
  for (int i = size_float - 1; i >= 0; i--) {
    char ch = "0123456789"[(unsigned long long)value % 10];
    if (buf[i + 1] == '\0') {
      if (ch == '0')
        buf[i] = '\0';
      else
        buf[i] = ch;
    } else {
      buf[i] = ch;
    }
    value /= 10;
  }
}

static void ldouble_gG_to_str(long double x, char *buf, int size_float) {
  double factor = pow(10, size_float);
  long double value = roundl(x * factor);
  buf[size_float] = '\0';
  for (int i = size_float - 1; i >= 0; i--) {
    char ch = "0123456789"[(unsigned long long)value % 10];
    if (buf[i + 1] == '\0') {
      if (ch == '0')
        buf[i] = '\0';
      else
        buf[i] = ch;
    } else {
      buf[i] = ch;
    }
    value /= 10;
  }
}

static void signature(int sign, char **str) {
  if (sign == 1)
    *(*str)++ = '+';
  else if (sign == -1)
    *(*str)++ = '-';
}

static int exception_feEgG(double arg, int *sign, char **str, int flag) {
  int res = -1;
  int size = 4;
  *str = (char *)malloc((size) * sizeof(char));
  if (*str == S21_NULL) {
  } else if (isnan(arg)) {
    const char str_nan[] = "nan";
    copy_str(*str, str_nan, size);
    if (flag) *sign = 1;
    res++;
  } else if (isinf(arg) == 1) {
    const char str_inf[] = "inf";
    copy_str(*str, str_inf, size);
    if (flag) *sign = 1;
    res++;
  } else if (isinf(arg) == -1) {
    const char str_inf[] = "inf";
    copy_str(*str, str_inf, size);
    *sign = -1;
    res++;
  }
  if (res == -1) **str = '\0';
  return res;
}

static int exception_lfeEgG(long double arg, int *sign, char **str, int flag) {
  int res = -1;
  int size = 4;
  *str = (char *)malloc((size) * sizeof(char));
  if (*str == S21_NULL) {
  } else if (isnan(arg)) {
    const char str_nan[] = "nan";
    copy_str(*str, str_nan, size);
    if (flag) *sign = 1;
    res++;
  } else if (isinf(arg) == 1) {
    const char str_inf[] = "inf";
    copy_str(*str, str_inf, size);
    if (flag) *sign = 1;
    res++;
  } else if (isinf(arg) == -1) {
    const char str_inf[] = "inf";
    copy_str(*str, str_inf, size);
    *sign = -1;
    res++;
  }
  if (res == -1) **str = '\0';
  return res;
}

static void exception_c(char **str, char *str_spec) {
  int res = 0;
  while (*str_spec != '\0') {
    if (*str_spec != ' ') res++;
    str_spec++;
  }
  if (res == 0) *(*str)++ = '\0';
}