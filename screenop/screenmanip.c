#include "headers/screenmanip.h"

void enableraw(void)
{
	tcgetattr(STDIN_FILENO, &orig_termios);
	struct termios raw = orig_termios;
	raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	raw.c_oflag &= ~(OPOST);
	raw.c_cflag |= (CS8);
	raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void disableraw(void)
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
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
