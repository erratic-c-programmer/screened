#include "../include.h"
#include "headers/screeninfo.h"
void tildes() {
	for (int i = 0; i < getwinsz().ws_row; ++i) {
		write(STDOUT_FILENO, "~", 1);
		if (i < getwinsz().ws_row - 1)
			write(STDOUT_FILENO, "\r\n", 2);
	}
}

