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
struct termios orig_termios; /* I'm not sure why this is here */
/* Hey, that rhymes!
 * I'm not sure *snap*
 * why this is here *clap*... */

typedef struct {
	char filename[260]; /* Maximum is 255 bytes on Linux for ext4 */
	int fd;
	int crow;
	int ccol;
} File;

typedef struct {
	bool output;
	short unsigned int winrows;
	short unsigned int wincols;
	short unsigned int cursrow;
	short unsigned int curscol;
	char *abuf; /* The append buffer */
	char *filebuf; /* Append buffer for files */
	char mode; /* 1 for normal, 2 for insert */
	File curfile;
} editor_status;
