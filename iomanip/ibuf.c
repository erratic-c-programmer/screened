#include "headers/ibuf.h"
void abuf_append(abuffer *abuf, const char *s, int len)
{
	char *new = realloc(abuf->buf, abuf->len + len);
	memcpy(&new[abuf->len], s, len);
	abuf->buf = new;
	abuf->len += len;
}

void abuf_flush(abuffer *abuf)
{
	free(abuf->buf);
	abuf = malloc(0);
}

void abuf_free(abuffer *abuf)
{
	free(abuf);
}
