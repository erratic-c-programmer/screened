#include "include.h"
#include "screenop/headers/screenmanip.h"
#include "iomanip/headers/ibuf.h"
#include "iomanip/headers/iomanip.h"

#define CTRL_KEY(k) ((k) & 0x1f)

struct termios orig_termios;
/**/
void insert_mode();
int prockeypress();
void init_editor();
void die(const char *s); /* For debugging purposes */


int main(void) {
	init_editor();
	return 0;
}


/*---------------------------------------*
 *  program-specific/debugging functions *
 *_______________________________________*/

inline void insert_mode() {
	printf("Entered insert!\r\n");
}

int prockeypress(abuffer *abuf) {
	char c = getkeypress();
	switch (c) {
		case CTRL_KEY('c'):
			return(1);
			break;

		case 'i':
			insert_mode();
			break;

		case 'c':
			refreshscrn(abuf);
			break;
	}
	return 0;
}

void init_editor() {
	abuffer *globl_abuf = malloc(sizeof(abuffer));
	enableraw();
	/* Call disableraw() at exit to reset terminal to canonical mode */
	atexit(disableraw);
	/* Get screen size */
	struct winsize ws;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
	/* Finally, start keypress proccessor */
	while (!prockeypress(globl_abuf));
}

void die(const char *s) {
	perror(s);
	exit(1);
}
