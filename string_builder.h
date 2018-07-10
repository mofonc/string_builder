#pragma once

#include <stdlib.h>

#define SBAPI

typedef struct sb_t sb_t;

#ifndef Default_string_builder_size
#define Default_string_builder_size 8
#endif
sb_t *sb_new(size_t size);

// free sb and sb->s
// return must be free by caller
char *sb_build(sb_t *sb);

void sb_check(sb_t *sb, size_t size);

void sb_append_char(sb_t *sb, char c);
void sb_append_raw(sb_t *sb, const char *raw);
