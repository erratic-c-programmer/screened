#ifndef INCLUDE_INCLUDE
#include "../../include.h"
#endif
#ifndef INCLUDE_IBUF
#include "../../iomanip/headers/ibuf.h"
#endif
#ifndef INCLUDE_SCREENDRAW
#include "screendraw.h"
#endif
#define INCLUDE_SCREENINFO
void refreshscrn(abuffer *abuf);
void enableraw(void);
void disableraw(void);
void cursor_up(void);
void cursor_down(void);
void cursor_left(void);
void cursor_right(void);
