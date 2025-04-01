#ifndef S21_SPRINTF
#define S21_SPRINTF

#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <wchar.h>

#define SPECIFIERS "cdieEfgGosuxXp"
#define FLAGS "-+ #0"
#define FIGURE "0123456789"
#define LENGTH_S "hlL"
#define SIZE_NUM 10

struct Flags {
  bool minus;
  bool plus;
  bool space;
  bool zero;
  bool hash;
  bool accuracy;
};

typedef struct {
  struct Flags flag;
  char specifer;
  char width[SIZE_NUM];
  char accuracy[SIZE_NUM];
  char length;
} Specification;

#endif
