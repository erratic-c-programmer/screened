#ifndef INCLUDE_INCLUDE
#include "../../include.h"
#endif
#ifndef INCLUDE_IBUF
#include "../../dynstr/headers/strop.h"
#endif
#ifndef INCLUDE_SCREENINFO
#include "screeninfo.h"
#endif
#define INCLUDE_SCREENDRAW
<<<<<<< HEAD
void refreshscrn(editor_status estat);
void tildes(editor_status estat);
/* Some functions defined because I was lazy; print stuff on top/middle/bottom of screen */
void pup(editor_status estat, const char *s);
void pmid(editor_status estat, const char *s);
void pbot(editor_status estat, const char *s);
=======
void tildes(char *abuf);
>>>>>>> parent of 4e63638... A number of bugfixes, mostly about the escape sequences.
