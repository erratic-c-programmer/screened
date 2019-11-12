#include "../../include.h"
#ifndef INCLUDE_FILE
#include "file.h"
#endif
#ifndef INLCUDE_STROP
#include "../../dynstr/headers/strop.h"
#endif
#define INCLUDE_FILEWRAPPER

/*
 * An abstraction layer for file.c, and most
 * other file-related system calls like write()
 */

void file_open(editor_status *estat, char *filename);
void file_write(editor_status *estat, const char *str);
