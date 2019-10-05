#include "../include.h"
#include "headers/ibuf.h"
void abuf_append(abuffer *abuf, const char *s, int len) {
	char *new = realloc(abuf->buf, abuf->len + len);
	abuf->buf = new;
	abuf->len += len;
}

void abuf_free(abuffer *abuf) {
	free(abuf->buf);
}
