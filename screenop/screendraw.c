#include "headers/screendraw.h"
void refreshscrn(editor_status *estat)
{
	str_append(estat->abuf, "\x1b[2J");
	str_append(estat->abuf, "\x1b[H");
	tildes(estat);
}

void tildes(editor_status *estat)
{
	for (int i = 0; i < estat->winrows; ++i) {
		str_append(estat->abuf, "~");
		if (i < estat->winrows - 1)
			str_append(estat->abuf, "\r\n");
	}
}
