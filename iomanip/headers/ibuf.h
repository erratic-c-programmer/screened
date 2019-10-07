#include "../../include.h"
#define INCLUDE_IBUF
typedef struct {
	char *buf;
	int len;
} abuffer;

void abuf_append(abuffer *abuf, const char *s, int len);
void abuf_flush(abuffer *abuf);
void abuf_free(abuffer *abuf);
