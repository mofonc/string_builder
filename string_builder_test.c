#include <stdio.h>

#include "string_builder.h"

void test1() {
  sb_t *sb = sb_new(0);

  for (int i = 0; i < 3; i++) {
    sb_append_char(sb, 'a');
  }

  char *s = sb_build(sb);
  printf("%s\n", s);
  free(s);
}

void test2() {
  sb_t *sb = sb_new(0);
  for (int i = 0; i < 3; i++) {
    sb_append_raw(sb, "hello ");
  }
  sb_append_raw(sb, "world");

  char *s = sb_build(sb);
  printf("%s\n", s);
  free(s);
}

int main(int argc, char *argv[]) {
  test1();
  test2();
  return 0;
}
