#include "headers/screendraw.h"
void refreshscrn(editor_status *estat)
{
	str_append(estat->abuf, "\x1b[2J");
	cursorpos(estat, 1, 1);
	tildes(estat, 1);
}
	
void tildes(editor_status *estat, short unsigned int startrow)
{
	for (int i = startrow - 1; i < estat->winrows; ++i) {
		str_append(estat->abuf, "~");
		if (i < estat->winrows - 1)
			str_append(estat->abuf, "\r\n");
	}
}

void ptop(editor_status *estat, const char *s)
{
	cursorpos(estat, 1, 1);
	str_append(estat->abuf, s);
}

void pmid(editor_status *estat, const char *s)
{
	cursorpos(estat, estat->winrows / 2, estat->wincols / 2);
	str_append(estat->abuf, s);
}

void pbot(editor_status *estat, const char *s)
{
	cursorpos(estat, estat->winrows, 1);
	str_append(estat->abuf, s);
}
