#include "headers/iomanip.h"
char getkeypress(void)
{
	char c;
	read(STDIN_FILENO, &c, 1);
	return c;
}
