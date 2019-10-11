#include "headers/screendraw.h"
void refreshscrn(editor_status *estat)
{
	str_append(estat->abuf, "\x1b[2J");
	cursorpos(estat);
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
