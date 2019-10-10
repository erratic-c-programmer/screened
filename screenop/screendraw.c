#include "headers/screendraw.h"
<<<<<<< HEAD
void refreshscrn(editor_status estat)
{
	str_append(estat.abuf, "\x1b[2J");
	str_append(estat.abuf, "\x1b[H");
	tildes(estat);
}

void tildes(editor_status estat)
=======
void tildes(char *abuf)
>>>>>>> parent of 4e63638... A number of bugfixes, mostly about the escape sequences.
{
	for (int i = 0; i < estat.winrows; ++i) {
		str_append(estat.abuf, "~");
		if (i < estat.wincols - 1)
			str_append(estat.abuf, "\r\n");
	}
}

void pup(editor_status estat, const char *s)
{
}
