#include "include.h"
#include "dynstr/headers/strop.h"
#include "iomanip/headers/file.h"
#include "iomanip/headers/input.h"
#include "iomanip/headers/output.h"
#include "screenop/headers/screenmanip.h"
#include "screenop/headers/screeninfo.h"

#define CTRL_KEY(k) ((k) & 0x1f)
void insert_mode(editor_status *estat);
int prockeypress(editor_status *estat);
void disp(editor_status *estat, int fd, unsigned long long int ln);
void init_editor(void);

int main(void)
{
	init_editor();
	return 0;
}

void insert_mode(editor_status *estat)
{
	pbot(estat, "--INSERT--");
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

		case 'h':
			--(estat->curscol);
			estat->output = true;
			break;

		case 'j':
			++(estat->cursrow);
			estat->output = true;
			break;
		case 'k':
			--(estat->cursrow);
			estat->output = true;
			break;

		case 'l':
			++(estat->curscol);
			estat->output = true;
			break;

		case 'G':
			estat->cursrow = (unsigned short) INFINITY;
			estat->output = true;
			break;

		default:
			estat->output = false;
			break;
	}
	/* write append buffer and flush it if editor_status.output flag is set */
	/* After each case, you must set estat.output to true or false! */
	
	if (estat->output) {
		cursorpos(estat, estat->cursrow, estat->curscol);
		write(STDOUT_FILENO, "\x1b[?25h", 6); /* Make cursor invisible */
		write(STDOUT_FILENO, estat->abuf->str, estat->abuf->len);
		write(STDOUT_FILENO, "\x1b[?25h", 6); /* Make cursor visible again */
		str_flush(estat->abuf);
	}
	return 0;
}

void init_editor(void)
{
	/* Initialise editor status and all its properties */
	editor_status *globl_status = calloc(1, sizeof(editor_status));
	globl_status->output = false;
	globl_status->winrows = getwinsz().ws_row;
	globl_status->wincols = getwinsz().ws_col;
	globl_status->cursrow = 1;
	globl_status->curscol = 1;
	globl_status->abuf = str_create();
	globl_status->filebuf = str_create();

	enableraw();
	/* Clear screen at start */
	refreshscrn(globl_status);
	/* Welcome! */
	pmid(globl_status, "Hi!");
	/* And move cursor to top */
	cursorpos(globl_status, 0, 0);
	write(STDOUT_FILENO, globl_status->abuf->str, globl_status->abuf->len);
	str_flush(globl_status->abuf);

	/* Finally, start keypress proccessor */
	while(!prockeypress(globl_status));

	/* Exit code has to be placed here, or estat wil be undefined */
	clearscrn(globl_status);
	write(STDOUT_FILENO, globl_status->abuf->str, globl_status->abuf->len);
	str_del(globl_status->abuf);
	str_del(globl_status->filebuf);
	free(globl_status);
}
