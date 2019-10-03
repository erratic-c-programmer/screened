#include "headers/iomanip.h"
#include "../include.h"
char getkeypress() {
	char c;
	read(STDIN_FILENO, &c, 1);
	return c;
}
