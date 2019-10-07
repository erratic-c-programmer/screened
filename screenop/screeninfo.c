#include "headers/screeninfo.h"
struct winsize getwinsz(void)
{
	struct winsize ws;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
	return ws;
}
