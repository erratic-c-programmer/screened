#include "headers/screendraw.h"
void refreshscrn(editor_status *estat)
{
	str_append(estat->abuf, "\x1b[2J");
	cursorpos(estat, 1, 1);
	tildes(estat);
}

void cursorpos(editor_status *estat, short unsigned int row, short unsigned int col)
{
	char buf[32];
	snprintf(buf, sizeof(buf), "\x1b[%d;%dH", row, col);
	str_append(estat->abuf, buf);
	estat->cursrow = row;
	estat->curscol = col;
}
	
void tildes(editor_status *estat)
{
	for (int i = 0; i < estat->winrows; ++i) {
		str_append(estat->abuf, "~");
		if (i < estat->winrows - 1)
			str_append(estat->abuf, "\r\n");
	}
}
