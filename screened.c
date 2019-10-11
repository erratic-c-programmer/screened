#include "include.h"
#include "dynstr/headers/strop.h"
#include "iomanip/headers/iomanip.h"
#include "screenop/headers/screenmanip.h"
#include "screenop/headers/screendraw.h"
#include "screenop/headers/screeninfo.h"

#define CTRL_KEY(k) ((k) & 0x1f)
struct termios orig_termios; 
void insert_mode(editor_status *estat);
int prockeypress(editor_status *estat);
void init_editor(void);

int main(void)
{
	init_editor();
	return 0;
}


/* program-specific functions */

void insert_mode(editor_status *estat)
{
	str_append(estat->abuf, "Entered insert!\r\n");
}

int prockeypress(editor_status *estat)
{
	char c = getkeypress();
	switch (c) {
		case CTRL_KEY('c'):
			estat->output = false;
			return(1);
			break;
		case 'i':
			insert_mode(estat);
			estat->output = true;
			break;

		case 'c':
			refreshscrn(estat);
			estat->output = true;
			break;
			
		case 'h':
			cursorpos(estat, estat->cursrow, estat->curscol - 1);
			estat->output = true;
			break;

		case 'j':
			cursorpos(estat, estat->cursrow + 1, estat->curscol);
			estat->output = true;
			break;
		case 'k':
			cursorpos(estat, estat->cursrow - 1, estat->curscol);
			estat->output = true;
			break;

		case 'l':
			cursorpos(estat, estat->cursrow, estat->curscol + 1);
			estat->output = true;
			break;

		default:
			estat->output = false;
			break;
	}
	/* write append buffer and flush it if editor_status.output flag is set */
	/* After each case, you must set estat.output to true or false! */
	if (estat->output) {
		write(STDOUT_FILENO, "\x1b[?25h", 6); /* Make cursor invisible */
		write(STDOUT_FILENO, estat->abuf, strlen(estat->abuf));
		write(STDOUT_FILENO, "\x1b[?25h", 6); /* Make cursor visible again */
		str_trunc(estat->abuf, 0);
	}
	return 0;
}

void init_editor(void)
{
	editor_status *globl_status = malloc(sizeof(globl_status));
	globl_status->output = false;
	globl_status->winrows = getwinsz().ws_row;
	globl_status->wincols = getwinsz().ws_col;
	globl_status->cursrow = 1;
	globl_status->curscol = 1;
	globl_status->abuf = str_create();

	enableraw();
	/* Clear screen at start */
	refreshscrn(globl_status);
	write(STDOUT_FILENO, globl_status->abuf, strlen(globl_status->abuf));
	str_trunc(globl_status->abuf, 0);
	/* Finally, start keypress proccessor */
	while(!prockeypress(globl_status));
	/* Exit: */
	str_del(globl_status->abuf);
	free(globl_status);
	disableraw();
}
