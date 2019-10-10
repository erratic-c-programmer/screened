#include "headers/screendraw.h"
void refreshscrn(char *abuf)
{
	str_append(abuf, "\x1b[2J");
	str_append(abuf, "\x1b[H");
	tildes(abuf);
}

void tildes(char *abuf)
{
	for (int i = 0; i < getwinsz().ws_row; ++i) {
		str_append(abuf, "~");
		if (i < getwinsz().ws_row - 1)
			str_append(abuf, "\r\n");
	}
}
