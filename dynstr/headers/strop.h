#ifndef INCLUDE_INCLUDE
#include "../../include.h"
#endif
#define INCLUDE_STROP

string *str_create(void);
void str_del(string *str);
void str_append(string *str, const char *s, size_t bufsz);
void str_trunc(string *str, size_t nsz);
void str_flush(string *str);
