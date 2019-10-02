#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

#define CTRL_KEY(k) ((k) & 0x1f)

struct termios orig_termios;

void enableraw();
void disableraw();
void insert_mode();
/* screen manupilation */
void refreshscrn();
void cursor_up();
void cursor_down();
void cursor_left();
void cursor_right();
char getkeypress();
/**/
int prockeypress();
void init_editor();
void die(const char *s); /* For debugging purposes */

int main(void) {
	init_editor();
	return 0;
}

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

/* Screen manupilation */
void refreshscrn() {
	write(STDOUT_FILENO, "\x1b[2J", 4);
	write(STDOUT_FILENO, "\x1b[H", 3);
}

void cursor_up() {
}
	
char getkeypress() {
	char c;
	read(STDIN_FILENO, &c, 1);
	return c;
}

/*---------------------------------------*
 *  program-specific/debugging functions *
 *_______________________________________*/

int prockeypress() {
	char c = getkeypress();
	switch (c) {
		case CTRL_KEY('c'):
			return(1);
			break;

		case 'i':
			insert_mode();
			break;

		case 'c':
			refreshscrn();
			break;
	}
	return 0;
}

void insert_mode() {
	printf("Entered insert!\r\n");
}

void init_editor() {
	enableraw();
	/* Call disableraw() at exit to reset terminal to canonical mode */
	atexit(disableraw);
	/* Get screen size */
	struct winsize ws;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
	/* Finally, start keypress proccessor */
	while (!prockeypress());
}

void die(const char *s) {
	perror(s);
	exit(1);
}
