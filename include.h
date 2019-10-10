#define INCLUDE_INCLUDE
#include <stdbool.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

#define _DEBUG(...) printf("%s:%s:%d: "__FILE__, __FUNCTION__, __LINE__, __VA_ARGS__)
#define CTRL_KEY(k) ((k) & 0x1f)

typedef struct {
	struct termios orig_termios;
	bool output;
	short unsigned int winrows;
	short unsigned int wincols;
	char *abuf;
} editor_status;
