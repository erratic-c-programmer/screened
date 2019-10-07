#include "include.h"
#include "iomanip/headers/ibuf.h"
#include "iomanip/headers/iomanip.h"
#include "screenop/headers/screenmanip.h"

#define CTRL_KEY(k) ((k) & 0x1f)

struct termios orig_termios;

typedef struct {
	bool output;
} editor_status;

 /**/
void insert_mode(abuffer *abuf);
int prockeypress(abuffer *abuf, editor_status estat);
void init_editor(void);
void die(const char *s);	/* For debugging purposes */


int main(void)
{
	init_editor();
	return 0;
}


/* program-specific functions */

inline void insert_mode(abuffer *abuf)
{
	abuf_append(abuf, "Entered insert!\r\n", 17);
}

int prockeypress(abuffer *abuf , editor_status estat)
{
	char c = getkeypress();
	switch (c) {
		case CTRL_KEY('c'):
			estat.output = false;
			return(1);
			break;

		case 'i':
			insert_mode(abuf);
			estat.output = true;
			break;

		case 'c':
			refreshscrn(abuf);
			estat.output = true;
			break;

		default:
			;
	}
	/* write append buffer and flush it if editor_status.output flag is set */
	if (estat.output) {
		write(STDOUT_FILENO, abuf->buf, abuf->len);
		abuf_flush(abuf);
	}

	return 0;
}

void init_editor(void)
{
	editor_status globl_status;
	abuffer *globl_abuf = malloc(sizeof(abuffer));
	enableraw();
	/* Call disableraw() at exit to reset terminal to canonical mode */
	atexit(disableraw);
	/* Get screen size */
	struct winsize ws;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
	/* Finally, start keypress proccessor */
	while(!prockeypress(globl_abuf, globl_status));
	abuf_free(globl_abuf);
}

void die(const char *s)
{
	perror(s);
	exit(1);
}
