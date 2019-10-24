#ifndef INCLUDE_INCLUDE
#include "../../include.h"
#endif
#ifndef INCLUDE_STROP
#include "../../dynstr/headers/strop.h"
#endif
#define INCLUDE_SCREENINFO
void enableraw(void);
void disableraw(void);
void cursorpos(editor_status *estat, short unsigned int cursrow, short unsigned int curscol);
