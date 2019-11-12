#ifndef INCLUDE_INCLUDE
#include "../../include.h"
#endif
#ifndef INCLUDE_STROP
#include "../../dynstr/headers/strop.h"
#endif
#define INCLUDE_FILE

/* I have a small problem with fopen and fclose and all the standard C library
 * functions. Also, I wanted to implement my own file stuff using system calls
 * So here we are: file.c is meant as a drop-in replacement for fopen(), fclose(),
 * fread() etc..
 * But do not call these functions directly, instead, use the thin abstraction
 * layer provided by filewrapper.c; it's called a wrapper for a reason
 * Most of the stuff is in there
 */

File openfile(char *filename);
