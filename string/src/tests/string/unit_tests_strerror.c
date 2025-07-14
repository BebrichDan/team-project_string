#include <check.h>

#include "../../s21_string.h"

#ifndef __APPLE__
#define MAX_ERRLIST 134
#define MIN_ERRLIST -1
#define ERROR "Unknown error "

static const char *maserror[] = {
    "Success",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "No such device or address",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource temporarily unavailable",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Device or resource busy",
    "File exists",
    "Invalid cross-device link",
    "No such device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Numerical result out of range",
    "Resource deadlock avoided",
    "File name too long",
    "No locks available",
    "Function not implemented",
    "Directory not empty",
    "Too many levels of symbolic links",
    "Unknown error 41",
    "No message of desired type",
    "Identifier removed",
    "Channel number out of range",
    "Level 2 not synchronized",
    "Level 3 halted",
    "Level 3 reset",
    "Link number out of range",
    "Protocol driver not attached",
    "No CSI structure available",
    "Level 2 halted",
    "Invalid exchange",
    "Invalid request descriptor",
    "Exchange full",
    "No anode",
    "Invalid request code",
    "Invalid slot",
    "Unknown error 58",
    "Bad font file format",
    "Device not a stream",
    "No data available",
    "Timer expired",
    "Out of streams resources",
    "Machine is not on the network",
    "Package not installed",
    "Object is remote",
    "Link has been severed",
    "Advertise error",
    "Srmount error",
    "Communication error on send",
    "Protocol error",
    "Multihop attempted",
    "RFS specific error",
    "Bad message",
    "Value too large for defined data type",
    "Name not unique on network",
    "File descriptor in bad state",
    "Remote address changed",
    "Can not access a needed shared library",
    "Accessing a corrupted shared library",
    ".lib section in a.out corrupted",
    "Attempting to link in too many shared libraries",
    "Cannot exec a shared library directly",
    "Invalid or incomplete multibyte or wide character",
    "Interrupted system call should be restarted",
    "Streams pipe error",
    "Too many users",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol",
    "Address already in use",
    "Cannot assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Transport endpoint is already connected",
    "Transport endpoint is not connected",
    "Cannot send after transport endpoint shutdown",
    "Too many references: cannot splice",
    "Connection timed out",
    "Connection refused",
    "Host is down",
    "No route to host",
    "Operation already in progress",
    "Operation now in progress",
    "Stale file handle",
    "Structure needs cleaning",
    "Not a XENIX named type file",
    "No XENIX semaphores available",
    "Is a named type file",
    "Remote I/O error",
    "Disk quota exceeded",
    "No medium found",
    "Wrong medium type",
    "Operation canceled",
    "Required key not available",
    "Key has expired",
    "Key has been revoked",
    "Key was rejected by service",
    "Owner died",
    "State not recoverable",
    "Operation not possible due to RF-kill",
    "Memory page has hardware error"};

#else
#define MAX_ERRLIST 107
#define MIN_ERRLIST -1
#define ERROR "Unknown error: "

const char *maserror[] = {"Undefined error: 0",
                          "Operation not permitted",
                          "No such file or directory",
                          "No such process",
                          "Stale NFS file handle",
                          "Too many levels of remote in path",
                          "RPC struct is bad",
                          "RPC version wrong",
                          "RPC prog. not avail",
                          "Program version wrong",
                          "Bad procedure for program",
                          "No locks available",
                          "Function not implemented",
                          "Inappropriate file type or format",
                          "Authentication error",
                          "Need authenticator",
                          "Device power is off",
                          "Device error",
                          "Value too large to be stored in data type",
                          "Bad executable (or shared library)",
                          "Bad CPU type in executable",
                          "Shared library version mismatch",
                          "Malformed Mach-o file",
                          "Operation canceled",
                          "Identifier removed",
                          "No message of desired type",
                          "Illegal byte sequence",
                          "Attribute not found",
                          "Bad message",
                          "EMULTIHOP (Reserved)",
                          "No message available on STREAM",
                          "ENOLINK (Reserved)",
                          "No STREAM resources",
                          "Not a STREAM",
                          "Protocol error",
                          "STREAM ioctl timeout",
                          "Operation not supported on socket",
                          "Policy not found",
                          "State not recoverable",
                          "Previous owner died",
                          "Interface output queue is full"};

#endif

extern void s21_errnum_tostring(char *str, int num);

// Тест 1: Валидный errnum (в пределах массива)
START_TEST(test_s21_strerror_valid_errnum) {
  int errnum = 2;
  char *expected = (char *)maserror[errnum];
  ck_assert_str_eq(s21_strerror(errnum), expected);
}
END_TEST

// Тест 2: errnum = 0
START_TEST(test_s21_strerror_zero_errnum) {
  int errnum = 0;
  char *expected = (char *)maserror[errnum];

  ck_assert_str_eq(s21_strerror(errnum), expected);
}
END_TEST

// Тест 3: errnum = MAX_ERRLIST - 1
START_TEST(test_s21_strerror_max_errnum_minus_one) {
  int errnum = MAX_ERRLIST - 1;
  char *expected = (char *)maserror[errnum];

  ck_assert_str_eq(s21_strerror(errnum), expected);
}
END_TEST

// Тест 4: errnum = MIN_ERRLIST + 1
START_TEST(test_s21_strerror_min_errnum_plus_one) {
  int errnum = MIN_ERRLIST + 1;
  char *expected = (char *)maserror[errnum];
  char *res = s21_strerror(errnum);
  ck_assert_str_eq(res, expected);
}
END_TEST
// Тест 5: errnum > MAX_ERRLIST
START_TEST(test_s21_strerror_greater_than_max) {
  int errnum = MAX_ERRLIST + 1;
  char expected_str[64];
  s21_strncpy(expected_str, ERROR, sizeof(expected_str) - 1);
  expected_str[sizeof(expected_str) - 1] = '\0';
  char temp[33];
  s21_errnum_tostring(temp, errnum);
  s21_strncat(expected_str, temp,
              sizeof(expected_str) - s21_strlen(expected_str) - 1);
  char *res = s21_strerror(errnum);

  ck_assert_str_eq(res, expected_str);
}
END_TEST
// Тест 6: errnum < MIN_ERRLIST
START_TEST(test_s21_strerror_less_than_min) {
  int errnum = MIN_ERRLIST - 1;
  char expected_str[64];
  s21_strncpy(expected_str, ERROR, sizeof(expected_str) - 1);
  expected_str[sizeof(expected_str) - 1] = '\0';
  char temp[33];
  s21_errnum_tostring(temp, errnum);
  s21_strncat(expected_str, temp,
              sizeof(expected_str) - s21_strlen(expected_str) - 1);
  char *res = s21_strerror(errnum);

  ck_assert_str_eq(res, expected_str);
}
END_TEST

Suite *strerror_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strerror");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strerror_valid_errnum);
  tcase_add_test(tc_core, test_s21_strerror_zero_errnum);
  tcase_add_test(tc_core, test_s21_strerror_max_errnum_minus_one);
  tcase_add_test(tc_core, test_s21_strerror_min_errnum_plus_one);
  tcase_add_test(tc_core, test_s21_strerror_greater_than_max);
  tcase_add_test(tc_core, test_s21_strerror_less_than_min);

  suite_add_tcase(s, tc_core);

  return s;
}