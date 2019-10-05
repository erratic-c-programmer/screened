#include "../include.h"
#include "../iomanip/headers/ibuf.h"
#include "headers/screeninfo.h"
void tildes(abuffer *abuf) {
	for (int i = 0; i < getwinsz().ws_row; ++i) {
		abuf_append(abuf, "~", 1);
		if (i < getwinsz().ws_row - 1)
			abuf_append(abuf, "\r\n", 2);
	}
}
