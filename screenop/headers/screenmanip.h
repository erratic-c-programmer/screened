#ifndef INCLUDE_INCLUDE
#include "../../include.h"
#endif
#ifndef INCLUDE_IBUF
#include "../../dynstr/headers/strop.h"
#endif
#define INCLUDE_SCREENINFO
void enableraw(void);
void disableraw(void);
void cursorpos(editor_status *estat);
