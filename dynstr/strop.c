#ifndef INCLUDE_STROP
#include "headers/strop.h"
#endif

/* TODO: malloc safety checks */

string *str_create(void)
{
	string *new = calloc(1, sizeof(string));
	new->str = calloc(1, sizeof(char));
	new->len = 0;
	return new;
}

void str_del(string *str)
{
	if (*str) {
		free(str->str);
		free(str);
	}
}

void str_append(string *str, const char *s, size_t bufsz)
{
	char *tmp = realloc(str->str, bufsz + str->len + 1);
	str->str = tmp;
	str->len += bufsz;
	strlcat(str->str, s, str->len);
}

void str_trunc(string *str, size_t nsz)
{
	str->str[nsz] = '\0'; /*This it a bit hacky, but it works */
	str->len = nsz;
}

void str_flush(string *str)
{
	str_trunc(str, 0); /* lol why */
}
