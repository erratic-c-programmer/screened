#include "include.h"
#include "dynstr/headers/strop.h"
#include "iomanip/headers/iomanip.h"
#include "screenop/headers/screenmanip.h"

<<<<<<< HEAD
void insert_mode(editor_status estat);
int prockeypress(editor_status estat);
=======
#define CTRL_KEY(k) ((k) & 0x1f)

struct termios orig_termios;

typedef struct {
	bool output;
} editor_status;

 /**/
void insert_mode(char *abuf);
int prockeypress(char *abuf, editor_status estat);
>>>>>>> parent of 4e63638... A number of bugfixes, mostly about the escape sequences.
void init_editor(void);
void die(const char *s);	/* For debugging purposes */


int main(void)
{
	init_editor();
	return 0;
}


/* program-specific functions */

<<<<<<< HEAD
void insert_mode(editor_status estat)
=======
inline void insert_mode(char *abuf)
>>>>>>> parent of 4e63638... A number of bugfixes, mostly about the escape sequences.
{
	str_append(estat.abuf, "Entered insert!\r\n");
}

int prockeypress(editor_status estat)
{
	char c = getkeypress();
	switch (c) {
		case CTRL_KEY('c'):
			estat.output = false;
<<<<<<< HEAD
			return(1);
			break;
		case 'i':
			insert_mode(estat);
=======
			return(1); break; case 'i':
			insert_mode(abuf);
>>>>>>> parent of 4e63638... A number of bugfixes, mostly about the escape sequences.
			estat.output = true;
			break;

		case 'c':
			refreshscrn(estat);
			estat.output = true;
			break;

		default:
			estat.output = false;
	}
	/* write append buffer and flush it if editor_status.output flag is set */
	/* After each case, you must set estat.output to true or false! */
	if (estat.output) {
<<<<<<< HEAD
		write(STDOUT_FILENO, "\x1b[?25h", 6); /* Make cursor invisible */
		write(STDOUT_FILENO, estat.abuf, strlen(estat.abuf));
		write(STDOUT_FILENO, "\x1b[?25h", 6); /* Make cursor visible again */
		str_trunc(estat.abuf, 0);
=======
		write(STDOUT_FILENO, abuf, strlen(abuf));
		str_trunc(abuf, 0);
>>>>>>> parent of 4e63638... A number of bugfixes, mostly about the escape sequences.
	}

	return 0;
}

void init_editor(void)
{
	editor_status globl_status;
	globl_status.abuf = str_create();
	enableraw();
	/* Call disableraw() at exit to reset terminal to canonical mode */
	atexit(disableraw);
<<<<<<< HEAD
	/* Get window size... */
	struct winsize ws;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
	/* ...And put it in the globl_status */
	globl_status.winrows = ws.ws_row;
	globl_status.wincols = ws.ws_col;
	/* Clear screen at start */
	refreshscrn(globl_status);
	write(STDOUT_FILENO, globl_status.abuf, strlen(globl_status.abuf));
	str_trunc(globl_status.abuf, 0);
=======
	/* Get screen size */
	struct winsize ws;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
>>>>>>> parent of 4e63638... A number of bugfixes, mostly about the escape sequences.
	/* Finally, start keypress proccessor */
	while(!prockeypress(globl_status));
	str_del(globl_status.abuf);
}

void die(const char *s)
{
	perror(s);
	exit(1);
}
