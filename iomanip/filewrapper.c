#include "headers/filewrapper.h"

void file_open(editor_status *estat, char *filename)
{
	estat->curfile = openfile(filename);
}

void file_write(editor_status *estat, const char *str)
{
	str_append(estat->filebuf, str);
}

void file_save(editor_status *estat, int fd)
{
	write(estat->curfile.fd, estat->filebuf, strlen(estat->filebuf));
}
