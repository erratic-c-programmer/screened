#include "../include.h"
struct winsize getwinsz() {
	struct winsize ws;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
	return ws;
}
