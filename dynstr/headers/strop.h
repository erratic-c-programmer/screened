#ifndef INCLUDE_INCLUDE
#include "../../include.h"
#endif
#define INCLUDE_STROP

char *str_create(void);
void str_del(char *str);
void str_append(char *str, const char *s);
void str_trunc(char *str, size_t nsz);
void str_flush(char *str);
