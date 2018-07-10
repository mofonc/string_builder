#include <stdio.h>

#include "string_builder.h"

static char *t_err_msg = 0;
static int t_err_ret = 0;

#define Terr(msg)                                                              \
  {                                                                            \
    t_err_msg = "" msg;                                                        \
    return __LINE__;                                                           \
  }

#define Tok() return 0

#define color(id) "\033[" id "m"

#define T(fn)                                                                  \
  {                                                                            \
    t_err_ret = fn();                                                          \
    if (t_err_ret != 0) {                                                      \
      printf(color("31") "[test] " color("33") "%s:%d: " color("0") "%s\n",    \
             __FILE__, t_err_ret, t_err_msg);                                  \
      return t_err_ret;                                                        \
    }                                                                          \
  }

int test1() {
  sb_t *sb = sb_new(0);

  for (int i = 0; i < 3; i++) {
    sb_append_char(sb, 'a');
  }

  char *s = sb_build(sb);
  printf("%s\n", s);
  free(s);
  Tok();
}

int test2() {
  sb_t *sb = sb_new(0);
  for (int i = 0; i < 3; i++) {
    sb_append_raw(sb, "hello ");
  }
  sb_append_raw(sb, "world");

  char *s = sb_build(sb);
  printf("%s\n", s);
  free(s);
  Tok();
}

int main(int argc, char *argv[]) {
  T(test1);
  T(test2);
  return 0;
}
