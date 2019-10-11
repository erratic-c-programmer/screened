#include "headers/screendraw.h"
void refreshscrn(editor_status *estat)
{
	str_append(estat->abuf, "\x1b[2J");
	cursorpos(estat);
	tildes(estat, 1);
}

void cursorpos(editor_status *estat)
{
	char buf[32];

	/* Check for overflow/underflow */
	if (estat->cursrow > estat->winrows) 
		estat->cursrow = estat->winrows;
	if (estat->cursrow < 1)
		estat->cursrow = 1;
	if (estat->curscol > estat->wincols) 
		estat->curscol = estat->wincols;
	if (estat->curscol < 1)
		estat->curscol = 1;

	snprintf(buf, sizeof(buf), "\x1b[%d;%dH", estat->cursrow, estat->curscol);
	str_append(estat->abuf, buf);
}
	
void tildes(editor_status *estat, short unsigned int startrow)
{
	for (int i = startrow - 1; i < estat->winrows; ++i) {
		str_append(estat->abuf, "~");
		if (i < estat->winrows - 1)
			str_append(estat->abuf, "\r\n");
	}
}
