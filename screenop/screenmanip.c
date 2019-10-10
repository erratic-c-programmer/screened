#include "headers/screenmanip.h"

void enableraw(editor_status estat)
{
	tcgetattr(STDIN_FILENO, &estat.orig_termios);
	struct termios raw = estat.orig_termios;
	raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	raw.c_oflag &= ~(OPOST);
	raw.c_cflag |= (CS8);
	raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void disableraw(editor_status estat)
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &estat.orig_termios);
}

void refreshscrn(char *abuf)
{
	str_append(abuf, "\x1b[2J");
	str_append(abuf, "x1b[H");
	tildes(abuf);
}

void cursor_up(void)
{
}
