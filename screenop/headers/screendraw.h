#ifndef INCLUDE_INCLUDE
#include "../../include.h"
#endif
#ifndef INCLUDE_IBUF
#include "../../dynstr/headers/strop.h"
#endif
#ifndef INCLUDE_SCREENINFO
#include "screeninfo.h"
#endif
#ifndef INCLUDE_SCREENMANIP
#include "screenmanip.h"
#endif
#define INCLUDE_SCREENDRAW
void refreshscrn(editor_status *estat);
void tildes(editor_status *estat, short unsigned int startrow);
void ptop(editor_status *estat, const char *s);
void pmid(editor_status *estat, const char *s);
void pbot(editor_status *estat, const char *s);
