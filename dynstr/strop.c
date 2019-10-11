#ifndef INCLUDE_STROP
#include "headers/strop.h"
#endif

/* This is entirely a wrapper library! But it is here to present a uniform
 * interface to dynamic strings, so the programmer does not keep on seeing
 * mallocs and such, and can tell that the operation involves a dynamic string
 */
static inline void malloc_failed()
{
	write(STDERR_FILENO, "Error! Memory could not be allocated\n", 37);
	abort();
}

char *str_create(void)
{
	/* Allocate memory for the char struct */
	char *new;
	if ((new = calloc(1, sizeof(char))) == NULL)
		malloc_failed();
	return new;
}

void str_del(char *str)
{
	free(str);
}

void str_append(char *str, const char *s)
{
	strcat(str, s);
}

void str_trunc(char *str, size_t nsz)
{
	str[nsz] = '\0'; /*This it a bit hacky, but it works */
}

void str_flush(char *str)
{
	str_trunc(str, 0);
}
