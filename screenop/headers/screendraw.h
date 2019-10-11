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
void refreshscrn(editor_status *estat);
void cursorpos(editor_status *estat);
void tildes(editor_status *estat, short unsigned int startrow);
