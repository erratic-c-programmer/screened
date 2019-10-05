#include "../include.h"
#include "headers/screendraw.h"
#include "../iomanip/headers/ibuf.h"

void enableraw() {
	tcgetattr(STDIN_FILENO, &orig_termios);
	struct termios raw = orig_termios;
	raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	raw.c_oflag &= ~(OPOST);
	raw.c_cflag |= (CS8);
	raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void disableraw() {
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void refreshscrn(abuffer *abuf) {
	abuf_append(abuf, "\x1b[2J", 4);
	abuf_append(abuf, "x1b[H", 3);
	tildes(abuf);
}

void cursor_up() {
}
