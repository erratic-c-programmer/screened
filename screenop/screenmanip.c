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

void cursorpos(editor_status *estat, short unsigned int cursrow, short unsigned int curscol)
{
	char buf[32];

	/* Check for overflow/underflow
	 * This is not supposed to modify the estat 
	 * struct except for the abuf, but for the 
	 * really obviously wrong positions...
	 */
	
	if ((cursrow > estat->winrows)) 
		estat->cursrow = cursrow = estat->winrows;
	if (cursrow < 1)
		estat->cursrow = cursrow = 1;
	if (curscol > estat->wincols) 
		estat->curscol = curscol = estat->wincols;
	if (curscol < 1)
		estat->curscol = curscol = 1;

	snprintf(buf, sizeof(buf), "\x1b[%d;%dH", cursrow, curscol);
	str_append(estat->abuf, buf, strlen(buf) + 1);
}
