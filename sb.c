#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sb.h"

struct sb_t {
  char *s;
  size_t len;
  size_t size;
};

SBAPI sb_t *sb_new(size_t size) {
  if (size < Default_string_builder_size) {
    size = Default_string_builder_size;
  }

  sb_t *sb = malloc(sizeof(sb_t));    // free: @func sb_build
  sb->s = calloc(size, sizeof(char)); // free: @func sb_build
  sb->len = 0;
  sb->size = size;

  return sb;
}

// free sb and sb->s
// return must be free by caller
SBAPI char *sb_build(sb_t *sb) {
  char *s = calloc(sb->len + 1, sizeof(char)); // free: @caller
  s = strncpy(s, sb->s, sb->len);

  free(sb->s);
  free(sb);

  return s;
}

SBAPI void sb_check(sb_t *sb, size_t size) {
  if (size <= sb->size) {
    return;
  }

  sb->s = realloc(sb->s, sizeof(char) * size);
  sb->size = size;
}

SBAPI void sb_append_char(sb_t *sb, char c) {
  sb_check(sb, sb->len + 1);

  sb->s[sb->len] = c;
  sb->len += 1;
}

SBAPI void sb_append_raw(sb_t *sb, const char *raw) {
  sb_check(sb, sb->len + strlen(raw));
  for (int i = 0; i < strlen(raw); i++) {
    sb_append_char(sb, raw[i]);
  }
}
