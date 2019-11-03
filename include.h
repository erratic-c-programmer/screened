#define INCLUDE_INCLUDE
#include <stdbool.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

#define CTRL_KEY(k) ((k) & 0x1f)
struct termios orig_termios;

typedef struct {
	bool output;
	short unsigned int winrows;
	short unsigned int wincols;
	short unsigned int cursrow;
	short unsigned int curscol;
	char *abuf;
	int fillrow; /* How may lines are there? */
	char mode; /* 1 for normal, 2 for insert */
	FILE *curfile;
} editor_status;

