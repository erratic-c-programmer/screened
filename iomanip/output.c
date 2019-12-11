#include "headers/output.h"
void refreshscrn(editor_status *estat)
{
	str_append(estat->abuf, "\x1b[2J", 4);
	clearscrn(estat);
	cursorpos(estat, 1, 1);
	for (int i = 0; i < estat->winrows; ++i) {
		str_append(estat->abuf, "~", 1);
		if (i < estat->winrows - 1)
			str_append(estat->abuf, "\r\n", 2);
	}
}

void clearscrn(editor_status *estat)
{
	cursorpos(estat, 1, 1);
	for (int i = 0; i < estat->winrows - 1; ++i) {
		str_append(estat->abuf, "\x1b[2K", 4);
		str_append(estat->abuf, "\x1b[1B", 4);
	}
	str_append(estat->abuf, "\x1b[2K", 4);
}

/* These three are defined for convenience */
void ptop(editor_status *estat, const char *s)
{
	cursorpos(estat, 1, 1);
	str_append(estat->abuf, s, strlen(s));
}

void pmid(editor_status *estat, const char *s)
{
	cursorpos(estat, estat->winrows / 2, estat->wincols / 2);
	str_append(estat->abuf, s, strlen(s));
}

void pbot(editor_status *estat, const char *s)
{
	cursorpos(estat, estat->winrows, 1);
	str_append(estat->abuf, s, strlen(s));
}

void pline(editor_status *estat, int ln, const char *s)
{
	cursorpos(estat, 1, ln);
	str_append(estat->abuf, s, strlen(s));
}
