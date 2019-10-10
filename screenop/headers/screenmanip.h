#ifndef INCLUDE_INCLUDE
#include "../../include.h"
#endif
#ifndef INCLUDE_IBUF
#include "../../dynstr/headers/strop.h"
#endif
#ifndef INCLUDE_SCREENDRAW
#include "screendraw.h"
#endif
#define INCLUDE_SCREENINFO
<<<<<<< HEAD
void enableraw(editor_status estat);
void disableraw(editor_status estat);
=======
void refreshscrn(char *abuf);
void enableraw(void);
void disableraw(void);
>>>>>>> parent of 4e63638... A number of bugfixes, mostly about the escape sequences.
void cursor_up(void);
void cursor_down(void);
void cursor_left(void);
void cursor_right(void);
