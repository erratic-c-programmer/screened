#include "../include.h"
void abuf_append(char *abuf, const char *s) {
	*abuf = realloc(abuf, sizeof(*abuf) / sizeof(*s));
}

void abuf_free(char *abuf) {
	free(abuf);
}
