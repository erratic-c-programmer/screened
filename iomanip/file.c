#include "headers/file.h"

File openfile(char *filename)
{
	int fd = open(filename, O_RDWR);
	File r_result;
	strcpy(r_result.filename, filename);
	r_result.fd = fd;
	r_result.crow = 1;
	r_result.ccol = 1;
	return r_result;
}
